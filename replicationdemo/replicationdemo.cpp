#include "replicationdemo.h"
#include <thread>
#include <functional>
#include <QTimer>
#include <QDebug>
#include <QSettings>
#include "cli.h"
#include "globalsignal.h"

class Defer {
public:
    Defer(const std::function<void()> &fn) : fn_(fn) {}
    ~Defer() { fn_(); }
    Defer(const Defer&) = delete;
    Defer& operator=(const Defer&) = delete;

private:
    std::function<void()> fn_;
};

QString getShowStatus(int status)
{
    switch (status) {
    case 0:
        return "Offline";
    case 1:
        return "Online";
    case 2:
        return "Active";
    case 3:
        return "Standby";
    case 4:
        return "Recovered";
    default:
        return "Error";
    }
}

void threadSleep(int millisecond)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(millisecond));
}

void fastdbLog(char *msg)
{
    QString str = QString::fromStdString(msg);
    str = str.remove("\n");
    emit GlobalSignal::instance()->sigFastdbLog(str);
}

const QString AUTO_TOGGLE = QStringLiteral("自动切换");
const QString DISABLE_AUTO_TOGGLE = QStringLiteral("禁止自动切换");

replicationdemo::replicationdemo(QWidget *parent)
    : QDialog(parent), db(nullptr), waitOpen(false), isOpen(false)
{
    ui.setupUi(this);
    timer = new QTimer(this);
    timer->setInterval(1000);
    connect(timer, &QTimer::timeout, this, &replicationdemo::onTimer);
    timer->start();

    connect(ui.pbOpen, &QPushButton::clicked, this, &replicationdemo::onOpen);
    connect(ui.pbPrimary, &QPushButton::clicked, this, &replicationdemo::onPrimary);
    connect(ui.pbClear, &QPushButton::clicked, this, &replicationdemo::onClear);
    connect(this, &replicationdemo::sigLog, this, &replicationdemo::onLog, Qt::QueuedConnection);
    connect(ui.pbGetData, &QPushButton::clicked, this, &replicationdemo::onGetData);
    connect(ui.pbUpdateData, &QPushButton::clicked, this, &replicationdemo::onUpdateData);
    connect(ui.cbAutoToggle, &QCheckBox::stateChanged, this, &replicationdemo::onAutoToggle);
    connect(GlobalSignal::instance(), &GlobalSignal::sigFastdbLog, this, &replicationdemo::sigLog);
    
    settings = new QSettings("config.ini", QSettings::IniFormat, this);
    ui.leIpList->setText(settings->value("servers", "127.0.0.1:21020;127.0.0.1:21021").toString());
    ui.leName->setText(settings->value("name", "demo0").toString());
    ui.leNodeId->setText(settings->value("id", "0").toString());
    ui.cbAutoToggle->setChecked(settings->value("autoToggle", true).toBool());
    dbReplicatedDatabase::setDisableAutoToggle(!ui.cbAutoToggle->isChecked());

    cli_set_trace_function(fastdbLog);
}

replicationdemo::~replicationdemo()
{
    if (db) {
        delete db;
        db = nullptr;
    }
}

void replicationdemo::log(const QString &str)
{
    emit sigLog(str);
}

void replicationdemo::onOpen()
{
    bool ok = false;
    QString name = ui.leName->text().trimmed();
    int nodeId = ui.leNodeId->text().trimmed().toInt(&ok);
    QStringList serverList = ui.leIpList->text().trimmed().split(";");
    if (name.isEmpty() || !ok || nodeId < 0 || serverList.isEmpty()) {
        log("config info error!");
        return;
    }

    if (waitOpen) {
        log("waitting open...");
        return;
    }

    if (db) {
        isOpen = false;
        db->close();
        delete db;
        db = nullptr;
    }

    settings->setValue("servers", serverList.join(";"));
    settings->setValue("name", name);
    settings->setValue("id", nodeId);

    waitOpen = true;
    std::thread t([=]() {
        char **servers = new char*[serverList.size()];
        for (std::size_t i = 0; i < serverList.size(); i++) {
            int len = serverList[i].size();
            servers[i] = new char[len + 1];
            memset(servers[i], 0, len + 1);
            memcpy(servers[i], serverList[i].toStdString().c_str(), len);
        }
        std::string strName = name.toStdString();
        const char_t *pname = strName.c_str();
        db = new dbReplicatedDatabase(dbDatabase::dbAllAccess, dbDefaultInitDatabaseSize, dbDefaultExtensionQuantum, dbDefaultInitIndexSize, 1);
        if (db->open(pname, pname, nodeId, servers, serverList.size())) {
            this->isOpen = true;
            log("open fastdb success");
            int totalSize = getTotalSize();
            if (totalSize == 0) {
                db->attach();
                Shipment item;
                item.price = 0;
                item.quantity = 0;
                db->insert(item);
                db->detach();
            }
        } else {
            log("open fastdb failed!");
        }
        this->waitOpen = false;
    });
    t.detach();
}

void replicationdemo::onPrimary()
{
    //if (!isOpen) {
    //    return;
    //}
    if (db) {
        db->changeActiveNode();
    }
}

void replicationdemo::onStandby()
{
}

void replicationdemo::onClear()
{
    ui.teLog->clear();
}

void replicationdemo::onLog(const QString &str)
{
    ui.teLog->appendPlainText(str);
}

void replicationdemo::onGetData()
{
    queryDB();
}

void replicationdemo::onUpdateData()
{
    updateDB();
    queryDB();
}

void replicationdemo::onAutoToggle(int state)
{
    settings->setValue("autoToggle", state == Qt::Checked);
    dbReplicatedDatabase::setDisableAutoToggle(state != Qt::Checked);
}

void replicationdemo::onTimer()
{
    if (db) {
        int status = db->getCurrentStatus();
        ui.labelStatus->setText(getShowStatus(status));
    }
}

void replicationdemo::updateDB()
{
    static int index = 0;
    if (!isOpen) {
        return;
    }

    if (db->getCurrentStatus() != 2) {
        log("not active node");
        return;
    }

    db->attach();
    Defer defer([&]() { db->detach(); });

    dbCursor<Shipment> cursor(dbCursorForUpdate);
    dbQuery q;
    q = "";
    cursor.select(q);
    do {
        Shipment *item = cursor.get();
        item->price = item->price + 1;
        cursor.update();
        break;
    } while (cursor.next());
    db->commit();
}

int replicationdemo::getTotalSize()
{
    if (isOpen) {
        dbQuery q;
        q = "";
        db->attach();
        Defer defer([&]() { db->detach(); });
        dbCursor<Shipment> cursor;
        return cursor.select(q);
    }
    return -1;
}

void replicationdemo::queryDB()
{
    if (!isOpen) {
        return;
    }

    db->attach();
    Defer defer([&]() { db->detach(); });

    dbCursor<Shipment> cursor;
    dbQuery q;
    q = "";
    cursor.select(q);
    do {
        Shipment item = *cursor.get();
        log(QString("queryDB price:%1").arg(item.price));
    } while (cursor.next());
}
