/********************************************************************************
** Form generated from reading UI file 'designerPeghps.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef DESIGNERPEGHPS_H
#define DESIGNERPEGHPS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>
#include <QtWidgets/QScrollBar>
#include <QStringList>
#include <ftdifunctions.h>
#include <iostream>

QT_BEGIN_NAMESPACE

class Ui_statusFrame
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QTableWidget *statusTable;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *getStatus;
    QProgressBar *getStatusBar;

    void setupUi(QFrame *statusFrame)
    {
        if (statusFrame->objectName().isEmpty())
            statusFrame->setObjectName(QString::fromUtf8("statusFrame"));
        statusFrame->resize(380, 568);
        gridLayoutWidget = new QWidget(statusFrame);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(40, 420, 311, 131));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        QFont font;
        font.setPointSize(9);
        if (statusFrame->objectName().isEmpty())
            statusFrame->setObjectName(QString::fromUtf8("statusFrame"));
        statusFrame->resize(376, 425);
        statusTable = new QTableWidget(statusFrame);
        if (statusTable->columnCount() < 2)
            statusTable->setColumnCount(2);
        if (statusTable->rowCount() < 3)
            statusTable->setRowCount(3);
        statusTable->setObjectName(QString::fromUtf8("statusTable"));
        statusTable->setGeometry(QRect(10, 10, 360, 360));

        QTableWidget *statusTable = new QTableWidget(statusFrame);
        if (statusTable->columnCount() < 2)
            statusTable->setColumnCount(2);
        if (statusTable->rowCount() < 3)
            statusTable->setRowCount(3);
        statusTable->setObjectName(QString::fromUtf8("statusTable"));
        statusTable->setGeometry(QRect(10, 10, 360, 360));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(statusTable->sizePolicy().hasHeightForWidth());
        statusTable->setSizePolicy(sizePolicy);
        statusTable->setAlternatingRowColors(true);
        statusTable->setRowCount(3);
        statusTable->setColumnCount(2);
        statusTable->horizontalHeader()->setVisible(false);
        statusTable->horizontalHeader()->setHighlightSections(false);
        statusTable->verticalHeader()->setVisible(false);
        statusTable->verticalHeader()->setHighlightSections(false);
        horizontalLayoutWidget = new QWidget(statusFrame);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(20, 370, 341, 51));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        getStatus = new QPushButton(horizontalLayoutWidget);
        getStatus->setObjectName(QString::fromUtf8("getStatus"));
        getStatus->setFont(font);

        int columnNumber = 2;
        QStringList statusCategories = { "Status", "Response Time", "EEPROM Status", "Commands Stored", "Last EEPROM Index", "Commands Match Index"};
        int rowNumber = 10;

        for (int i = 0; i <= columnNumber; i++) {
            statusTable->setColumnWidth(i, 180);
        }
        rowNumber = rowNumber-1;
        statusTable->setRowCount(rowNumber);
        for (int i = 0; i < rowNumber; i++) {
            statusTable->setRowHeight(i, 40);
        }
        for(int i = 0; i < statusCategories.size(); i++) {
            statusTable->setItem(i,0, new QTableWidgetItem(statusCategories[i]));
            statusTable->setItem(i,1, new QTableWidgetItem("-"));
        }
        statusTable->horizontalScrollBar()->setDisabled(true);
        statusTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        statusTable->verticalScrollBar()->setDisabled(true);
        statusTable->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);



        horizontalLayout->addWidget(getStatus);

        QProgressBar *getStatusBar = new QProgressBar(horizontalLayoutWidget);
        getStatusBar->setObjectName(QString::fromUtf8("getStatusBar"));
        getStatusBar->setFont(font);
        getStatusBar->setValue(0);
        getStatusBar->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(getStatusBar);


        QObject::connect(getStatus, &QPushButton::clicked, [=](){

            getStatusBar->setValue(0);
            getStatusBar->setStyleSheet("color: black");
            ftdiFunctions ftdi;
            std::string messageComplete = "";
            std::string incomingMessage = "";
            std::string receivedMsg = "waiting";
            //ADD TIMEOUT/
            while (receivedMsg != "STATUSEXCHAN") {
                ftdi.ftdiWrite("STATUS");
                //ftdi.ftdiWrite("CLEAR");
                receivedMsg = ftdi.ftdiRead();
                QApplication::processEvents();
                getStatusBar->setValue(25);
                if (receivedMsg == "ERROR")
                {
                     std::cout << receivedMsg << "\n";
                     getStatusBar->setValue(50);
                     getStatusBar->setStyleSheet("background-color: rgb(150,150,150);");
                     return;
                }
            }
            getStatusBar->setValue(50);
            std::cout << "Received message: " << receivedMsg << "\n";
            int timeoutValue = 0;
            int receivedIndicator = 0;
            while (receivedIndicator == 0) {
                if (receivedMsg == "ERROR")
                {
                     std::cout << receivedMsg << "\n";
                     //getStatusBar->setValue(50);
                     //getStatusBar->setStyleSheet("color: red");
                     statusTable->setItem(0, 1, new QTableWidgetItem("FTDI read error. Unplug FTDI chip and try again."));
                     statusTable->item(0, 1)->setBackground(Qt::red);

                     return;
                }
                //ftdi.ftdiWrite("COMPLETEMSG!");
                getStatusBar->setValue(75);
                receivedMsg = ftdi.ftdiRead();
                ftdi.ftdiWrite("DATASENDTHING");
                if (receivedMsg.find("XXX") != std::string::npos) receivedIndicator = 1;
                std::cout << "2nd Received message: " << receivedMsg << "\n";
                QApplication::processEvents();
                timeoutValue++;
                //std::cout << "Timeout: " << timeoutValue << "\n";
                if (timeoutValue >= 10) {
                     std::cout << "TIMEOUT\n";
                     getStatusBar->setValue(50);
                     getStatusBar->setStyleSheet("color: red");
                     statusTable->setItem(0, 1, new QTableWidgetItem("Board response timed out. Unplug microcontroller and try again."));
                     statusTable->item(0, 1)->setBackground(Qt::red);
                     return;
                }
            }
            getStatusBar->setValue(90);
            statusTable->setItem(3, 1, new QTableWidgetItem(QString::fromStdString(receivedMsg.substr(0,3))));
            if (std::stoi(receivedMsg.substr(0,3)) == 0) {
                statusTable->setItem(2, 1, new QTableWidgetItem("No data"));
                statusTable->item(2, 1)->setBackground(Qt::yellow);
                statusTable->item(3, 1)->setBackground(Qt::yellow);
            }
            else {
                statusTable->setItem(2, 1, new QTableWidgetItem("Has data"));
                statusTable->item(2, 1)->setBackground(Qt::green);

                statusTable->item(3, 1)->setBackground(Qt::green);
            }
            while (receivedMsg.find("XXX") != std::string::npos) {
                ftdi.ftdiWrite("COMPLETEMSG!");
                receivedMsg = ftdi.ftdiRead();
                std::cout << "Waiting for end...\n";
                QApplication::processEvents();
            }



            getStatusBar->setValue(100);
            getStatusBar->setStyleSheet("color: white");
            std::cout << "Complete!\n";

            statusTable->setItem(0, 1, new QTableWidgetItem("Functional"));
            statusTable->item(0, 1)->setBackground(Qt::green);
            return;
        });

        retranslateUi(statusFrame);

        QMetaObject::connectSlotsByName(statusFrame);
    } // setupUi

    void retranslateUi(QFrame *statusFrame)
    {
        statusFrame->setWindowTitle(QCoreApplication::translate("statusFrame", "Frame", nullptr));
        getStatus->setText(QCoreApplication::translate("statusFrame", "Get Status", nullptr));
    } // retranslateUi

};

namespace Ui {
    class statusFrame: public Ui_statusFrame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // DESIGNERPEGHPS_H
