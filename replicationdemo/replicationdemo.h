#pragma once

#include <QtWidgets/QDialog>
#include "ui_replicationdemo.h"
#include "datatype.h"

class QSettings;
class replicationdemo : public QDialog
{
    Q_OBJECT

public:
    replicationdemo(QWidget *parent = Q_NULLPTR);
    ~replicationdemo();
    void log(const QString &str);

    void updateDB();
    void queryDB();
    int getTotalSize();

signals:
    void sigLog(const QString&);

private slots:
    void onOpen();
    void onPrimary();
    void onStandby();
    void onClear();
    void onLog(const QString&);
    void onGetData();
    void onUpdateData();
    void onAutoToggle(int state);
    void onTimer();

private:
    Ui::replicationdemoClass ui;
    dbReplicatedDatabase *db;
    QTimer *timer;
    QSettings *settings;
    bool waitOpen;
    bool isOpen;
};
