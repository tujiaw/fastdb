/********************************************************************************
** Form generated from reading UI file 'replicationdemo.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPLICATIONDEMO_H
#define UI_REPLICATIONDEMO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_replicationdemoClass
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLineEdit *leName;
    QLineEdit *leNodeId;
    QLabel *label;
    QLabel *label_4;
    QLabel *labelStatus;
    QLineEdit *leIpList;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_5;
    QCheckBox *cbAutoToggle;
    QHBoxLayout *horizontalLayout;
    QPushButton *pbOpen;
    QPushButton *pbPrimary;
    QPushButton *pbClear;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pbRecovery;
    QPushButton *pbGetData;
    QPushButton *pbUpdateData;
    QPlainTextEdit *teLog;

    void setupUi(QDialog *replicationdemoClass)
    {
        if (replicationdemoClass->objectName().isEmpty())
            replicationdemoClass->setObjectName(QStringLiteral("replicationdemoClass"));
        replicationdemoClass->resize(371, 463);
        verticalLayout = new QVBoxLayout(replicationdemoClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        leName = new QLineEdit(replicationdemoClass);
        leName->setObjectName(QStringLiteral("leName"));

        gridLayout->addWidget(leName, 2, 1, 1, 1);

        leNodeId = new QLineEdit(replicationdemoClass);
        leNodeId->setObjectName(QStringLiteral("leNodeId"));

        gridLayout->addWidget(leNodeId, 3, 1, 1, 1);

        label = new QLabel(replicationdemoClass);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 2, 0, 1, 1);

        label_4 = new QLabel(replicationdemoClass);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        labelStatus = new QLabel(replicationdemoClass);
        labelStatus->setObjectName(QStringLiteral("labelStatus"));

        gridLayout->addWidget(labelStatus, 0, 1, 1, 1);

        leIpList = new QLineEdit(replicationdemoClass);
        leIpList->setObjectName(QStringLiteral("leIpList"));

        gridLayout->addWidget(leIpList, 1, 1, 1, 1);

        label_2 = new QLabel(replicationdemoClass);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 3, 0, 1, 1);

        label_3 = new QLabel(replicationdemoClass);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        label_5 = new QLabel(replicationdemoClass);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        cbAutoToggle = new QCheckBox(replicationdemoClass);
        cbAutoToggle->setObjectName(QStringLiteral("cbAutoToggle"));

        gridLayout->addWidget(cbAutoToggle, 4, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pbOpen = new QPushButton(replicationdemoClass);
        pbOpen->setObjectName(QStringLiteral("pbOpen"));

        horizontalLayout->addWidget(pbOpen);

        pbPrimary = new QPushButton(replicationdemoClass);
        pbPrimary->setObjectName(QStringLiteral("pbPrimary"));

        horizontalLayout->addWidget(pbPrimary);

        pbClear = new QPushButton(replicationdemoClass);
        pbClear->setObjectName(QStringLiteral("pbClear"));

        horizontalLayout->addWidget(pbClear);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, -1, -1, 0);
        pbRecovery = new QPushButton(replicationdemoClass);
        pbRecovery->setObjectName(QStringLiteral("pbRecovery"));

        horizontalLayout_2->addWidget(pbRecovery);

        pbGetData = new QPushButton(replicationdemoClass);
        pbGetData->setObjectName(QStringLiteral("pbGetData"));

        horizontalLayout_2->addWidget(pbGetData);

        pbUpdateData = new QPushButton(replicationdemoClass);
        pbUpdateData->setObjectName(QStringLiteral("pbUpdateData"));

        horizontalLayout_2->addWidget(pbUpdateData);


        verticalLayout->addLayout(horizontalLayout_2);

        teLog = new QPlainTextEdit(replicationdemoClass);
        teLog->setObjectName(QStringLiteral("teLog"));

        verticalLayout->addWidget(teLog);


        retranslateUi(replicationdemoClass);

        QMetaObject::connectSlotsByName(replicationdemoClass);
    } // setupUi

    void retranslateUi(QDialog *replicationdemoClass)
    {
        replicationdemoClass->setWindowTitle(QApplication::translate("replicationdemoClass", "replicationdemo", 0));
        label->setText(QApplication::translate("replicationdemoClass", "FastDB\345\220\215\345\255\227\357\274\232", 0));
        label_4->setText(QApplication::translate("replicationdemoClass", "\345\275\223\345\211\215\347\212\266\346\200\201\357\274\232", 0));
        labelStatus->setText(QString());
        label_2->setText(QApplication::translate("replicationdemoClass", "\345\275\223\345\211\215\350\212\202\347\202\271ID\357\274\232", 0));
        label_3->setText(QApplication::translate("replicationdemoClass", "\344\270\273\345\244\207IP\345\210\227\350\241\250\357\274\232", 0));
        label_5->setText(QApplication::translate("replicationdemoClass", "\350\207\252\345\212\250\345\210\207\346\215\242", 0));
        cbAutoToggle->setText(QApplication::translate("replicationdemoClass", "\345\213\276\351\200\211\345\274\200\345\220\257\350\207\252\345\212\250\345\210\207\346\215\242", 0));
        pbOpen->setText(QApplication::translate("replicationdemoClass", "\346\211\223\345\274\200", 0));
        pbPrimary->setText(QApplication::translate("replicationdemoClass", "\346\277\200\346\264\273\344\270\272\344\270\273\350\212\202\347\202\271", 0));
        pbClear->setText(QApplication::translate("replicationdemoClass", "\346\270\205\347\220\206\346\227\245\345\277\227", 0));
        pbRecovery->setText(QApplication::translate("replicationdemoClass", "Recovery", 0));
        pbGetData->setText(QApplication::translate("replicationdemoClass", "\350\216\267\345\217\226\346\225\260\346\215\256", 0));
        pbUpdateData->setText(QApplication::translate("replicationdemoClass", "\346\233\264\346\226\260\346\225\260\346\215\256", 0));
    } // retranslateUi

};

namespace Ui {
    class replicationdemoClass: public Ui_replicationdemoClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPLICATIONDEMO_H
