/********************************************************************************
** Form generated from reading UI file 'gamepadapp5_xMNTjJS.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef GAMEPADAPP5_XMNTJJS_H
#define GAMEPADAPP5_XMNTJJS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDial>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>
#include <QPropertyAnimation>
#include <QGraphicsColorizeEffect>
#include "ftdifunctions.h"
#include <string.h>
#include <iostream>
#include <QDebug>
#include "secondwindow.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionTesting;
    QAction *actionTesting2;
    QAction *actionUse;
    QAction *actionAbout;
    QAction *actionInstructions;
    QAction *actionFAQ;
    QAction *actionConnect;
    QWidget *centralwidget;
    QGroupBox *controllerInputs;
    QPlainTextEdit *scriptBox;
    QLineEdit *durationEdit;
    QLabel *scriptBoxLabel;
    QFrame *leftInputFrame;
    QPushButton *minusButton;
    QPushButton *lButton;
    QPushButton *captureButton;
    QPushButton *nothingButton;
    QPushButton *zlButton;
    QDial *leftJoyStick;
    QFrame *dpadFrame;
    QFrame *rightInputFrame;
    QPushButton *rButton;
    QPushButton *zrButton;
    QPushButton *xButton;
    QPushButton *aButton;
    QPushButton *yButton;
    QPushButton *bButton;
    QCheckBox *instantBox;
    QPushButton *plusButton;
    QPushButton *homeButton;
    QDial *rightJoystick;
    QPushButton *inputExpandButton;
    QCheckBox *monitorBox;
    QProgressBar *scriptStatus;
    QPushButton *clearEEPROM;
    QPushButton *flashButton;
    QPushButton *clearBox;
    QPushButton *executeButton;
    QPushButton *readEEPROM;
    QPushButton *statusButton;
    QLabel *taskStatusLabel;
    QLabel *taskStatusBarLabel;
    QTabWidget *scriptTab;
    QWidget *pkmnTab;
    QPushButton *boxReleaseButton;
    QPushButton *diggerBrothersButton;
    QPushButton *wattFarmingButton;
    QPushButton *berryFarmingButton;
    QPushButton *stowOnSideButton;
    QPushButton *lottoFarmingButton;
    QPushButton *championsCupButton;
    QPushButton *pokeJobFarmingButton;
    QComboBox *eggHatchBox;
    QComboBox *fossilReviveBox;
    QComboBox *evBox1;
    QComboBox *evBox2;
    QPushButton *evTrainButton;
    QPushButton *hatchButton;
    QPushButton *reviveButton;
    QWidget *acnhTab;
    QPushButton *starFarmingButton;
    QPushButton *diyRepetitionButton;
    QPushButton *eatFruitButton;
    QPushButton *depositBoxButton;
    QPushButton *axeBreakButton;
    QTabWidget *ftdiSendTab;
    QWidget *customTab;
    QPushButton *customSendButton;
    QLineEdit *customLineEdit;
    QWidget *ftdiTestTab;
    QPushButton *ftdiSendButton;
    QLabel *testLabel;
    QProgressBar *progressBar;
    QStatusBar *statusbar;
    QMenuBar *menuBar;
    QMenu *menuMenu;
    QLineEdit *loopCountLine;
    QLineEdit *endLine;
    QPushButton *loopButton;
    QLineEdit *startLine;

    int commandNumber = 1;
    char errorMsg = 'A';
    int statusBarValue = 0;

    void setButtonPressedGraphics(QPushButton *buttonChanged) {
        QGraphicsColorizeEffect *buttonEffect = new QGraphicsColorizeEffect(buttonChanged);
        buttonChanged->setGraphicsEffect(buttonEffect);
        QPropertyAnimation *buttonAnimation = new QPropertyAnimation(buttonEffect, "color");
        buttonAnimation->setStartValue(QColor(Qt::blue));
        buttonAnimation->setEndValue(QColor(Qt::red));
        buttonAnimation->setDuration(1000);
        buttonAnimation->start();
        return;
    }

    void setErrorBar(int errorVal) {
        scriptStatus->setValue(50);
        scriptStatus->setStyleSheet(QString::fromUtf8("QProgressBar::chunk\n"
        "{\n"
        "   background-color:rgb(179, 12, 9);\n"
        "}"));
        //scriptStatus->setStyleSheet("color:rgb(255,255,255);");
        if(errorVal == 1) taskStatusBarLabel->setText("FTDI ERROR: Reconnect FTDI Chip");
        else if(errorVal == 2) taskStatusBarLabel->setText("T/O ERROR: Reconnect FTDI + Board");
        else if (errorVal == 3) taskStatusBarLabel->setText("FTDI disconnected");
        return;
    }

    void setStartBar() {
        scriptStatus->setValue(0);
        setTaskStautsMsg(0);
        scriptStatus->setStyleSheet(QString::fromUtf8("QProgressBar::chunk\n"
        "{\n"
        "   background-color:rgb(32, 240, 75);\n"
        "}"));
        //scriptStatus->setStyleSheet("color:rgb(255,255,255);");
        return;
    }

    void setCompleteBar() {
        scriptStatus->setValue(100);
        scriptStatus->setStyleSheet(QString::fromUtf8("QProgressBar::chunk\n"
        "{\n"
        "   background-color:rgb(32, 240, 75);\n"
        "}"));
        //scriptStatus->setStyleSheet("color:rgb(255,255,255);");
        return;
    }

    void setTaskStautsMsg(int msgID) {
        if(msgID == 0) {
            taskStatusBarLabel->setText(" ");
        }
        if(msgID == 1) {
            taskStatusBarLabel->setText("Cleared text box!");
        }
        else if(msgID == 2) {
            taskStatusBarLabel->setText("Waiting for initial handshake...");
        }
        else if(msgID == 3) {
            taskStatusBarLabel->setText("Completed initial handshake.");
        }
        else if(msgID == 4) {
            taskStatusBarLabel->setText("Waiting for final handshake...");
        }
    }

    void setTaskStatusMsg(QString msgString) {
        taskStatusBarLabel->setText(msgString);
    }

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(448, 891);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setToolButtonStyle(Qt::ToolButtonIconOnly);
        MainWindow->setAnimated(true);
        actionTesting = new QAction(MainWindow);
        actionTesting->setObjectName(QString::fromUtf8("actionTesting"));
        actionTesting2 = new QAction(MainWindow);
        actionTesting2->setObjectName(QString::fromUtf8("actionTesting2"));
        actionUse = new QAction(MainWindow);
        actionUse->setObjectName(QString::fromUtf8("actionUse"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionAbout->setCheckable(false);
        actionAbout->setChecked(false);
        QFont font;
        font.setPointSize(10);
        actionAbout->setFont(font);
        actionInstructions = new QAction(MainWindow);
        actionInstructions->setObjectName(QString::fromUtf8("actionInstructions"));
        actionFAQ = new QAction(MainWindow);
        actionFAQ->setObjectName(QString::fromUtf8("actionFAQ"));
        actionConnect = new QAction(MainWindow);
        actionConnect->setObjectName(QString::fromUtf8("actionConnect"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        controllerInputs = new QGroupBox(centralwidget);
        controllerInputs->setObjectName(QString::fromUtf8("controllerInputs"));
        controllerInputs->setGeometry(QRect(10, 300, 431, 541));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(controllerInputs->sizePolicy().hasHeightForWidth());
        controllerInputs->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setPointSize(9);
        controllerInputs->setFont(font1);
        controllerInputs->setAutoFillBackground(false);
        controllerInputs->setStyleSheet(QString::fromUtf8(""));
        scriptBox = new QPlainTextEdit(controllerInputs);
        scriptBox->setObjectName(QString::fromUtf8("scriptBox"));
        scriptBox->setGeometry(QRect(145, 85, 141, 291));
        QFont font2;
        font2.setPointSize(8);
        scriptBox->setFont(font2);
        scriptBox->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0)"));
        scriptBox->setLineWrapMode(QPlainTextEdit::NoWrap);
        durationEdit = new QLineEdit(controllerInputs);
        durationEdit->setObjectName(QString::fromUtf8("durationEdit"));
        durationEdit->setGeometry(QRect(145, 35, 141, 22));
        durationEdit->setFont(font1);
        durationEdit->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0)"));
        scriptBoxLabel = new QLabel(controllerInputs);
        scriptBoxLabel->setObjectName(QString::fromUtf8("scriptBoxLabel"));
        scriptBoxLabel->setGeometry(QRect(165, 55, 91, 31));
        scriptBoxLabel->setFont(font1);
        scriptBoxLabel->setAlignment(Qt::AlignCenter);
        leftInputFrame = new QFrame(controllerInputs);
        leftInputFrame->setObjectName(QString::fromUtf8("leftInputFrame"));
        leftInputFrame->setGeometry(QRect(0, 10, 141, 381));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(leftInputFrame->sizePolicy().hasHeightForWidth());
        leftInputFrame->setSizePolicy(sizePolicy2);
        leftInputFrame->setStyleSheet(QString::fromUtf8("QFrame#leftInputFrame { background-image:url(:/:/joycon1.png) }"));
        minusButton = new QPushButton(leftInputFrame);
        minusButton->setObjectName(QString::fromUtf8("minusButton"));
        minusButton->setGeometry(QRect(95, 43, 20, 21));
        minusButton->setFont(font1);
        minusButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color: rgba(117, 117, 129,0)\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"   background-image: url(:/:/minusoverlay.png)\n"
"}"));
        minusButton->setAutoRepeat(true);
        lButton = new QPushButton(leftInputFrame);
        lButton->setObjectName(QString::fromUtf8("lButton"));
        lButton->setGeometry(QRect(30, 42, 28, 28));
        lButton->setFont(font1);
        lButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
" 	color: rgba(255, 255, 255);\n"
"    border: 2px solid #555;\n"
"    border-radius: 14px;\n"
"    border-style: outset;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"   background-color:rgba(255, 255, 255, 30);\n"
"}"));
        lButton->setAutoRepeat(true);
        captureButton = new QPushButton(leftInputFrame);
        captureButton->setObjectName(QString::fromUtf8("captureButton"));
        captureButton->setGeometry(QRect(81, 260, 20, 19));
        captureButton->setFont(font1);
        captureButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color: rgb(117, 117, 129,0)\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"   background-color:rgb(255,255,255,30);\n"
"}"));
        captureButton->setAutoRepeat(true);
        nothingButton = new QPushButton(leftInputFrame);
        nothingButton->setObjectName(QString::fromUtf8("nothingButton"));
        nothingButton->setGeometry(QRect(40, 290, 72, 28));
        nothingButton->setFont(font1);
        nothingButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
" 	color: rgba(255, 255, 255);\n"
"    border: 2px solid #555;\n"
"    border-radius: 14px;\n"
"    border-style: outset;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"   background-color:rgba(255, 255, 255, 30);\n"
"}"));
        zlButton = new QPushButton(leftInputFrame);
        zlButton->setObjectName(QString::fromUtf8("zlButton"));
        zlButton->setGeometry(QRect(60, 24, 28, 28));
        zlButton->setFont(font1);
        zlButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
" 	color: rgba(255, 255, 255);\n"
"    border: 2px solid #555;\n"
"    border-radius: 14px;\n"
"    border-style: outset;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"   background-color:rgba(255, 255, 255, 30);\n"
"}"));
        zlButton->setAutoRepeat(true);
        leftJoyStick = new QDial(leftInputFrame);
        leftJoyStick->setObjectName(QString::fromUtf8("leftJoyStick"));
        leftJoyStick->setGeometry(QRect(31, 71, 83, 73));
        leftJoyStick->setStyleSheet(QString::fromUtf8("QDial { background-color:black; }"));
        leftJoyStick->setMaximum(360);
        leftJoyStick->setTracking(true);
        leftJoyStick->setOrientation(Qt::Horizontal);
        leftJoyStick->setInvertedAppearance(false);
        leftJoyStick->setInvertedControls(false);
        leftJoyStick->setWrapping(true);
        leftJoyStick->setNotchesVisible(false);
        dpadFrame = new QFrame(leftInputFrame);
        dpadFrame->setObjectName(QString::fromUtf8("dpadFrame"));
        dpadFrame->setGeometry(QRect(30, 160, 81, 91));
        dpadFrame->setStyleSheet(QString::fromUtf8("background-image: (0,0,0,0);"));
        dpadFrame->setFrameShape(QFrame::StyledPanel);
        dpadFrame->setFrameShadow(QFrame::Raised);
        loopCountLine = new QLineEdit(leftInputFrame);
        loopCountLine->setObjectName(QString::fromUtf8("loopCountLine"));
        loopCountLine->setGeometry(QRect(20, 230, 101, 22));
        loopCountLine->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 189, 221);\n"
"border: 1px solid rgb(0, 0, 0);"));
        endLine = new QLineEdit(leftInputFrame);
        endLine->setObjectName(QString::fromUtf8("endLine"));
        endLine->setGeometry(QRect(75, 200, 41, 22));
        endLine->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 189, 221);\n"
"border: 1px solid rgb(0, 0, 0);"));
        loopButton = new QPushButton(leftInputFrame);
        loopButton->setObjectName(QString::fromUtf8("loopButton"));
        loopButton->setGeometry(QRect(20, 160, 101, 31));
        loopButton->setFont(font2);
        startLine = new QLineEdit(leftInputFrame);
        startLine->setObjectName(QString::fromUtf8("startLine"));
        startLine->setGeometry(QRect(25, 200, 41, 22));
        startLine->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 189, 221);\n"
"border: 1px solid rgb(0, 0, 0);"));
        rightInputFrame = new QFrame(controllerInputs);
        rightInputFrame->setObjectName(QString::fromUtf8("rightInputFrame"));
        rightInputFrame->setGeometry(QRect(290, 10, 141, 381));
        sizePolicy2.setHeightForWidth(rightInputFrame->sizePolicy().hasHeightForWidth());
        rightInputFrame->setSizePolicy(sizePolicy2);
        rightInputFrame->setStyleSheet(QString::fromUtf8("QFrame { background-image:url(:/:/joycon2.png) }"));
        rButton = new QPushButton(rightInputFrame);
        rButton->setObjectName(QString::fromUtf8("rButton"));
        rButton->setGeometry(QRect(87, 41, 28, 28));
        rButton->setFont(font1);
        rButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
" 	color: rgba(255, 255, 255);\n"
"    border: 2px solid #555;\n"
"    border-radius: 14px;\n"
"    border-style: outset;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"   background-color:rgba(255, 255, 255, 30);\n"
"}"));
        rButton->setAutoRepeat(true);
        zrButton = new QPushButton(rightInputFrame);
        zrButton->setObjectName(QString::fromUtf8("zrButton"));
        zrButton->setGeometry(QRect(55, 24, 29, 29));
        zrButton->setFont(font1);
        zrButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
" 	color: rgba(255, 255, 255);\n"
"    border: 2px solid #555;\n"
"    border-radius: 14px;\n"
"    border-style: outset;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"   background-color:rgba(255, 255, 255, 30);\n"
"}"));
        zrButton->setAutoRepeat(true);
        xButton = new QPushButton(rightInputFrame);
        xButton->setObjectName(QString::fromUtf8("xButton"));
        xButton->setGeometry(QRect(58, 69, 28, 28));
        xButton->setFont(font1);
        xButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
" 	color: rgba(255, 255, 255, 0);\n"
"    border: 2px solid #555;\n"
"    border-radius: 14px;\n"
"    border-style: outset;\n"
"	border-color: rgba(255, 255, 255, 0);\n"
"	/*\n"
"    background: qradialgradient(\n"
"        cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"        radius: 1.85, stop: 0 #fff, stop: 1 #888\n"
"        );\n"
"	*/\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"   background-color:rgba(255, 255, 255, 30);\n"
"}"));
        xButton->setAutoRepeat(true);
        aButton = new QPushButton(rightInputFrame);
        aButton->setObjectName(QString::fromUtf8("aButton"));
        aButton->setGeometry(QRect(86, 94, 28, 28));
        aButton->setFont(font1);
        aButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
" 	color: rgba(255, 255, 255, 0);\n"
"    border: 2px solid #555;\n"
"    border-radius: 14px;\n"
"    border-style: outset;\n"
"	border-color: rgba(255, 255, 255, 0);\n"
"	/*\n"
"    background: qradialgradient(\n"
"        cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"        radius: 1.85, stop: 0 #fff, stop: 1 #888\n"
"        );\n"
"	*/\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"   background-color:rgba(255, 255, 255, 30);\n"
"}"));
        aButton->setAutoRepeat(true);
        yButton = new QPushButton(rightInputFrame);
        yButton->setObjectName(QString::fromUtf8("yButton"));
        yButton->setGeometry(QRect(31, 94, 28, 28));
        yButton->setFont(font1);
        yButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
" 	color: rgba(255, 255, 255, 0);\n"
"    border: 2px solid #555;\n"
"    border-radius: 14px;\n"
"    border-style: outset;\n"
"	border-color: rgba(255, 255, 255, 0);\n"
"	/*\n"
"    background: qradialgradient(\n"
"        cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"        radius: 1.85, stop: 0 #fff, stop: 1 #888\n"
"        );\n"
"	*/\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"   background-color:rgba(255, 255, 255, 30);\n"
"}"));
        yButton->setAutoRepeat(true);
        bButton = new QPushButton(rightInputFrame);
        bButton->setObjectName(QString::fromUtf8("bButton"));
        bButton->setGeometry(QRect(58, 121, 28, 28));
        bButton->setFont(font1);
        bButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
" 	color: rgba(255, 255, 255, 0);\n"
"    border: 2px solid #555;\n"
"    border-radius: 14px;\n"
"    border-style: outset;\n"
"	border-color: rgba(255, 255, 255, 0);\n"
"	/*\n"
"    background: qradialgradient(\n"
"        cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"        radius: 1.85, stop: 0 #fff, stop: 1 #888\n"
"        );\n"
"	*/\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"   background-color:rgba(255, 255, 255, 30);\n"
"}"));
        bButton->setAutoRepeat(true);
        instantBox = new QCheckBox(rightInputFrame);
        instantBox->setObjectName(QString::fromUtf8("instantBox"));
        instantBox->setGeometry(QRect(40, 290, 81, 20));
        instantBox->setFont(font1);
        instantBox->setAutoFillBackground(false);
        plusButton = new QPushButton(rightInputFrame);
        plusButton->setObjectName(QString::fromUtf8("plusButton"));
        plusButton->setGeometry(QRect(26, 45, 20, 21));
        plusButton->setFont(font1);
        plusButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color: rgba(117, 117, 129,0)\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"   background-image: url(:/:/plusoverlay.png)\n"
"}"));
        plusButton->setAutoRepeat(true);
        homeButton = new QPushButton(rightInputFrame);
        homeButton->setObjectName(QString::fromUtf8("homeButton"));
        homeButton->setGeometry(QRect(39, 256, 29, 29));
        homeButton->setFont(font1);
        homeButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
" 	color: rgba(255, 255, 255, 0);\n"
"    border: 2px solid #555;\n"
"    border-radius: 14px;\n"
"    border-style: outset;\n"
"	border-color: rgba(255, 255, 255, 0);\n"
"	/*\n"
"    background: qradialgradient(\n"
"        cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"        radius: 1.85, stop: 0 #fff, stop: 1 #888\n"
"        );\n"
"	*/\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"   background-color:rgba(255, 255, 255, 50);\n"
"}"));
        homeButton->setAutoRepeat(true);
        rightJoystick = new QDial(rightInputFrame);
        rightJoystick->setObjectName(QString::fromUtf8("rightJoystick"));
        rightJoystick->setGeometry(QRect(31, 169, 83, 73));
        rightJoystick->setStyleSheet(QString::fromUtf8("QDial { background-color:black; }"));
        rightJoystick->setMaximum(360);
        rightJoystick->setWrapping(true);
        inputExpandButton = new QPushButton(rightInputFrame);
        inputExpandButton->setObjectName(QString::fromUtf8("inputExpandButton"));
        inputExpandButton->setGeometry(QRect(117, -2, 31, 21));
        inputExpandButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
" 	color: rgba(255, 255, 255, 0);\n"
"    border: 2px solid #555;\n"
"    border-radius: 14px;\n"
"    border-style: outset;\n"
"	border-color: rgba(255, 255, 255, 0);\n"
"	/*\n"
"    background: qradialgradient(\n"
"        cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"        radius: 1.85, stop: 0 #fff, stop: 1 #888\n"
"        );\n"
"	*/\n"
"    padding: 5px;\n"
"	background-image: url(:/:/arrowicon.png);\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"   background-image: url(:/:/arrowiconhover.png);\n"
"}"));
        monitorBox = new QCheckBox(rightInputFrame);
        monitorBox->setObjectName(QString::fromUtf8("monitorBox"));
        monitorBox->setGeometry(QRect(40, 310, 81, 20));
        monitorBox->setFont(font1);
        monitorBox->setAutoFillBackground(false);
        scriptStatus = new QProgressBar(controllerInputs);
        scriptStatus->setObjectName(QString::fromUtf8("scriptStatus"));
        scriptStatus->setGeometry(QRect(140, 480, 261, 23));
        scriptStatus->setValue(0);
        scriptStatus->setAlignment(Qt::AlignCenter);
        clearEEPROM = new QPushButton(controllerInputs);
        clearEEPROM->setObjectName(QString::fromUtf8("clearEEPROM"));
        clearEEPROM->setGeometry(QRect(10, 435, 121, 31));
        clearEEPROM->setFont(font1);
        flashButton = new QPushButton(controllerInputs);
        flashButton->setObjectName(QString::fromUtf8("flashButton"));
        flashButton->setGeometry(QRect(10, 400, 121, 31));
        flashButton->setFont(font1);
        clearBox = new QPushButton(controllerInputs);
        clearBox->setObjectName(QString::fromUtf8("clearBox"));
        clearBox->setGeometry(QRect(155, 400, 121, 31));
        clearBox->setFont(font1);
        executeButton = new QPushButton(controllerInputs);
        executeButton->setObjectName(QString::fromUtf8("executeButton"));
        executeButton->setGeometry(QRect(155, 435, 121, 31));
        executeButton->setFont(font1);
        readEEPROM = new QPushButton(controllerInputs);
        readEEPROM->setObjectName(QString::fromUtf8("readEEPROM"));
        readEEPROM->setGeometry(QRect(300, 435, 121, 31));
        readEEPROM->setFont(font1);
        statusButton = new QPushButton(controllerInputs);
        statusButton->setObjectName(QString::fromUtf8("statusButton"));
        statusButton->setGeometry(QRect(300, 400, 121, 31));
        statusButton->setFont(font1);
        taskStatusLabel = new QLabel(controllerInputs);
        taskStatusLabel->setObjectName(QString::fromUtf8("taskStatusLabel"));
        taskStatusLabel->setGeometry(QRect(30, 483, 91, 16));
        taskStatusLabel->setFont(font1);
        taskStatusBarLabel = new QLabel(controllerInputs);
        taskStatusBarLabel->setObjectName(QString::fromUtf8("taskStatusBarLabel"));
        taskStatusBarLabel->setGeometry(QRect(120, 510, 301, 21));
        taskStatusBarLabel->setFont(font1);
        taskStatusBarLabel->setAlignment(Qt::AlignCenter);
        scriptTab = new QTabWidget(centralwidget);
        scriptTab->setObjectName(QString::fromUtf8("scriptTab"));
        scriptTab->setGeometry(QRect(10, 100, 431, 191));
        scriptTab->setFont(font1);
        scriptTab->setFocusPolicy(Qt::NoFocus);
        scriptTab->setAcceptDrops(false);
        scriptTab->setLayoutDirection(Qt::LeftToRight);
        scriptTab->setStyleSheet(QString::fromUtf8("QTabWidget::pane\n"
"{\n"
"border: 0px;\n"
"top: 0.1em;\n"
"border-width: 1px;\n"
"border-style: solid;\n"
"border-color: rgb(226,226,226);\n"
"}"));
        scriptTab->setTabShape(QTabWidget::Rounded);
        pkmnTab = new QWidget();
        pkmnTab->setObjectName(QString::fromUtf8("pkmnTab"));
        boxReleaseButton = new QPushButton(pkmnTab);
        boxReleaseButton->setObjectName(QString::fromUtf8("boxReleaseButton"));
        boxReleaseButton->setGeometry(QRect(10, 40, 121, 28));
        boxReleaseButton->setFont(font1);
        diggerBrothersButton = new QPushButton(pkmnTab);
        diggerBrothersButton->setObjectName(QString::fromUtf8("diggerBrothersButton"));
        diggerBrothersButton->setGeometry(QRect(10, 100, 121, 28));
        diggerBrothersButton->setFont(font1);
        wattFarmingButton = new QPushButton(pkmnTab);
        wattFarmingButton->setObjectName(QString::fromUtf8("wattFarmingButton"));
        wattFarmingButton->setGeometry(QRect(148, 130, 131, 28));
        wattFarmingButton->setFont(font1);
        berryFarmingButton = new QPushButton(pkmnTab);
        berryFarmingButton->setObjectName(QString::fromUtf8("berryFarmingButton"));
        berryFarmingButton->setGeometry(QRect(10, 10, 121, 28));
        berryFarmingButton->setFont(font1);
        stowOnSideButton = new QPushButton(pkmnTab);
        stowOnSideButton->setObjectName(QString::fromUtf8("stowOnSideButton"));
        stowOnSideButton->setGeometry(QRect(295, 100, 121, 28));
        stowOnSideButton->setFont(font1);
        lottoFarmingButton = new QPushButton(pkmnTab);
        lottoFarmingButton->setObjectName(QString::fromUtf8("lottoFarmingButton"));
        lottoFarmingButton->setGeometry(QRect(10, 130, 121, 28));
        lottoFarmingButton->setFont(font1);
        championsCupButton = new QPushButton(pkmnTab);
        championsCupButton->setObjectName(QString::fromUtf8("championsCupButton"));
        championsCupButton->setGeometry(QRect(10, 70, 121, 28));
        championsCupButton->setFont(font1);
        pokeJobFarmingButton = new QPushButton(pkmnTab);
        pokeJobFarmingButton->setObjectName(QString::fromUtf8("pokeJobFarmingButton"));
        pokeJobFarmingButton->setGeometry(QRect(148, 100, 131, 28));
        pokeJobFarmingButton->setFont(font1);
        eggHatchBox = new QComboBox(pkmnTab);
        eggHatchBox->addItem(QString());
        eggHatchBox->addItem(QString());
        eggHatchBox->addItem(QString());
        eggHatchBox->addItem(QString());
        eggHatchBox->addItem(QString());
        eggHatchBox->addItem(QString());
        eggHatchBox->addItem(QString());
        eggHatchBox->addItem(QString());
        eggHatchBox->setObjectName(QString::fromUtf8("eggHatchBox"));
        eggHatchBox->setGeometry(QRect(148, 41, 131, 26));
        eggHatchBox->setFont(font1);
        eggHatchBox->setLayoutDirection(Qt::LeftToRight);
        fossilReviveBox = new QComboBox(pkmnTab);
        fossilReviveBox->addItem(QString());
        fossilReviveBox->addItem(QString());
        fossilReviveBox->addItem(QString());
        fossilReviveBox->addItem(QString());
        fossilReviveBox->addItem(QString());
        fossilReviveBox->setObjectName(QString::fromUtf8("fossilReviveBox"));
        fossilReviveBox->setGeometry(QRect(148, 71, 131, 26));
        fossilReviveBox->setFont(font1);
        fossilReviveBox->setLayoutDirection(Qt::LeftToRight);
        evBox1 = new QComboBox(pkmnTab);
        evBox1->addItem(QString());
        evBox1->addItem(QString());
        evBox1->addItem(QString());
        evBox1->addItem(QString());
        evBox1->addItem(QString());
        evBox1->addItem(QString());
        evBox1->setObjectName(QString::fromUtf8("evBox1"));
        evBox1->setGeometry(QRect(148, 11, 61, 26));
        evBox1->setFont(font1);
        evBox1->setLayoutDirection(Qt::LeftToRight);
        evBox2 = new QComboBox(pkmnTab);
        evBox2->addItem(QString());
        evBox2->addItem(QString());
        evBox2->addItem(QString());
        evBox2->addItem(QString());
        evBox2->addItem(QString());
        evBox2->addItem(QString());
        evBox2->setObjectName(QString::fromUtf8("evBox2"));
        evBox2->setGeometry(QRect(218, 11, 61, 26));
        evBox2->setFont(font1);
        evBox2->setLayoutDirection(Qt::LeftToRight);
        evTrainButton = new QPushButton(pkmnTab);
        evTrainButton->setObjectName(QString::fromUtf8("evTrainButton"));
        evTrainButton->setGeometry(QRect(295, 10, 121, 28));
        evTrainButton->setFont(font1);
        hatchButton = new QPushButton(pkmnTab);
        hatchButton->setObjectName(QString::fromUtf8("hatchButton"));
        hatchButton->setGeometry(QRect(295, 40, 121, 28));
        hatchButton->setFont(font1);
        reviveButton = new QPushButton(pkmnTab);
        reviveButton->setObjectName(QString::fromUtf8("reviveButton"));
        reviveButton->setGeometry(QRect(295, 70, 121, 28));
        reviveButton->setFont(font1);
        scriptTab->addTab(pkmnTab, QString());
        acnhTab = new QWidget();
        acnhTab->setObjectName(QString::fromUtf8("acnhTab"));
        acnhTab->setStyleSheet(QString::fromUtf8("QTabWidget: {background-color: rgb(255, 255, 255); }"));
        starFarmingButton = new QPushButton(acnhTab);
        starFarmingButton->setObjectName(QString::fromUtf8("starFarmingButton"));
        starFarmingButton->setGeometry(QRect(10, 10, 131, 28));
        starFarmingButton->setFont(font1);
        starFarmingButton->setStyleSheet(QString::fromUtf8(""));
        diyRepetitionButton = new QPushButton(acnhTab);
        diyRepetitionButton->setObjectName(QString::fromUtf8("diyRepetitionButton"));
        diyRepetitionButton->setGeometry(QRect(10, 40, 131, 28));
        diyRepetitionButton->setFont(font1);
        diyRepetitionButton->setStyleSheet(QString::fromUtf8(""));
        eatFruitButton = new QPushButton(acnhTab);
        eatFruitButton->setObjectName(QString::fromUtf8("eatFruitButton"));
        eatFruitButton->setGeometry(QRect(10, 70, 131, 28));
        eatFruitButton->setFont(font1);
        eatFruitButton->setStyleSheet(QString::fromUtf8(""));
        depositBoxButton = new QPushButton(acnhTab);
        depositBoxButton->setObjectName(QString::fromUtf8("depositBoxButton"));
        depositBoxButton->setGeometry(QRect(10, 100, 131, 28));
        depositBoxButton->setFont(font1);
        depositBoxButton->setStyleSheet(QString::fromUtf8(""));
        axeBreakButton = new QPushButton(acnhTab);
        axeBreakButton->setObjectName(QString::fromUtf8("axeBreakButton"));
        axeBreakButton->setGeometry(QRect(10, 130, 131, 28));
        axeBreakButton->setFont(font1);
        axeBreakButton->setStyleSheet(QString::fromUtf8(""));
        scriptTab->addTab(acnhTab, QString());
        ftdiSendTab = new QTabWidget(centralwidget);
        ftdiSendTab->setObjectName(QString::fromUtf8("ftdiSendTab"));
        ftdiSendTab->setGeometry(QRect(10, 10, 431, 81));
        ftdiSendTab->setFont(font1);
        ftdiSendTab->setStyleSheet(QString::fromUtf8("QTabWidget::pane\n"
"{\n"
"border: 0px;\n"
"top: 0.1em;\n"
"border-width: 1px;\n"
"border-style: solid;\n"
"border-color: rgb(226,226,226);\n"
"}"));
        customTab = new QWidget();
        customTab->setObjectName(QString::fromUtf8("customTab"));
        customSendButton = new QPushButton(customTab);
        customSendButton->setObjectName(QString::fromUtf8("customSendButton"));
        customSendButton->setGeometry(QRect(340, 10, 71, 28));
        customSendButton->setFont(font1);
        customLineEdit = new QLineEdit(customTab);
        customLineEdit->setObjectName(QString::fromUtf8("customLineEdit"));
        customLineEdit->setGeometry(QRect(10, 10, 311, 31));
        customLineEdit->setFont(font1);
        customLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0)"));
        ftdiSendTab->addTab(customTab, QString());
        ftdiTestTab = new QWidget();
        ftdiTestTab->setObjectName(QString::fromUtf8("ftdiTestTab"));
        ftdiSendButton = new QPushButton(ftdiTestTab);
        ftdiSendButton->setObjectName(QString::fromUtf8("ftdiSendButton"));
        ftdiSendButton->setGeometry(QRect(10, 10, 71, 28));
        ftdiSendButton->setFont(font1);
        testLabel = new QLabel(ftdiTestTab);
        testLabel->setObjectName(QString::fromUtf8("testLabel"));
        testLabel->setGeometry(QRect(270, 10, 141, 31));
        progressBar = new QProgressBar(ftdiTestTab);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(100, 13, 161, 23));
        progressBar->setFont(font1);
        progressBar->setValue(0);
        progressBar->setAlignment(Qt::AlignCenter);
        ftdiSendTab->addTab(ftdiTestTab, QString());
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 448, 26));
        menuMenu = new QMenu(menuBar);
        menuMenu->setObjectName(QString::fromUtf8("menuMenu"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuMenu->menuAction());
        menuMenu->addAction(actionAbout);
        menuMenu->addAction(actionInstructions);
        menuMenu->addAction(actionFAQ);
        menuMenu->addAction(actionConnect);



        retranslateUi(MainWindow);
        QObject::connect(berryFarmingButton, &QPushButton::clicked, [=](){
            ftdiFunctions ftdi;
            ftdi.ftdiStartup();
            ftdi.sendButton("berryFarming");
            setButtonPressedGraphics(berryFarmingButton);
        });
        QObject::connect(boxReleaseButton, &QPushButton::clicked, [=](){
            ftdiFunctions ftdi;
            ftdi.ftdiStartup();
            ftdi.sendButton("boxRelease");
            setButtonPressedGraphics(boxReleaseButton);
        });
        QObject::connect(championsCupButton, &QPushButton::clicked, [=](){
            ftdiFunctions ftdi;
            ftdi.ftdiStartup();
            ftdi.sendButton("championsCup");
            setButtonPressedGraphics(championsCupButton);
        });
        QObject::connect(diggerBrothersButton, &QPushButton::clicked, [=](){
            ftdiFunctions ftdi;
            ftdi.ftdiStartup();
            ftdi.sendButton("diggerBrothers");
            setButtonPressedGraphics(diggerBrothersButton);
        });
        QObject::connect(lottoFarmingButton, &QPushButton::clicked, [=](){
            ftdiFunctions ftdi;
            ftdi.ftdiStartup();
            ftdi.sendButton("lottoFarm");
            setButtonPressedGraphics(lottoFarmingButton);
        });
        QObject::connect(pokeJobFarmingButton, &QPushButton::clicked, [=](){
            ftdiFunctions ftdi;
            ftdi.ftdiStartup();
            ftdi.sendButton("pokeJob");
            setButtonPressedGraphics(pokeJobFarmingButton);
        });
        QObject::connect(stowOnSideButton, &QPushButton::clicked, [=](){
            ftdiFunctions ftdi;
            ftdi.ftdiStartup();
            ftdi.sendButton("stowOnSide");
            setButtonPressedGraphics(stowOnSideButton);
        });

        QObject::connect(evTrainButton, &QPushButton::clicked, [=](){
            ftdiFunctions ftdi;
            ftdi.ftdiStartup();
            if((evBox1->currentText().toStdString() != "EV 1") && (evBox2->currentText().toStdString() != "EV 2")) {
                ftdi.sendButton((evBox1->currentText()+ QVariant("&").toString() + evBox2->currentText()).toStdString());
            }
            else {
                ftdi.ftdiClose();
            }
            setButtonPressedGraphics(evTrainButton);
        });
        QObject::connect(hatchButton, &QPushButton::clicked, [=](){
            ftdiFunctions ftdi;
            ftdi.ftdiStartup();
            if(eggHatchBox->currentText().toStdString() != "Egg Hatching") {
                ftdi.sendButton(eggHatchBox->currentText().toStdString());
            }
            else {
                ftdi.ftdiClose();
            }
            setButtonPressedGraphics(hatchButton);
        });
        QObject::connect(reviveButton, &QPushButton::clicked, [=](){
            ftdiFunctions ftdi;
            ftdi.ftdiStartup();
            if(fossilReviveBox->currentText().toStdString() != "Fossil Reviving") {
                ftdi.sendButton(fossilReviveBox->currentText().toStdString());
            }
            else {
                ftdi.ftdiClose();
            }
            setButtonPressedGraphics(reviveButton);
        });
        QObject::connect(starFarmingButton, &QPushButton::clicked, [=](){
            ftdiFunctions ftdi;
            ftdi.ftdiStartup();
            ftdi.sendButton("starFarming");
            setButtonPressedGraphics(starFarmingButton);
        });
        QObject::connect(diyRepetitionButton, &QPushButton::clicked, [=](){
            ftdiFunctions ftdi;
            ftdi.ftdiStartup();
            ftdi.sendButton("diyRepetition");
            setButtonPressedGraphics(diyRepetitionButton);
        });
        QObject::connect(eatFruitButton, &QPushButton::clicked, [=](){
            ftdiFunctions ftdi;
            ftdi.ftdiStartup();
            ftdi.sendButton("eatFruit");
            setButtonPressedGraphics(eatFruitButton);
        });
        QObject::connect(depositBoxButton, &QPushButton::clicked, [=](){
            ftdiFunctions ftdi;
            ftdi.ftdiStartup();
            ftdi.sendButton("depositBox");
            setButtonPressedGraphics(depositBoxButton);
        });
        QObject::connect(axeBreakButton, &QPushButton::clicked, [=](){
            ftdiFunctions ftdi;
            ftdi.ftdiStartup();
            ftdi.sendButton("axeBreak");
            setButtonPressedGraphics(axeBreakButton);
        });
        QObject::connect(wattFarmingButton, &QPushButton::clicked, [=](){
            ftdiFunctions ftdi;
            ftdi.ftdiStartup();
            ftdi.sendButton("wattFarming");
            setButtonPressedGraphics(wattFarmingButton);
        });
        QObject::connect(ftdiSendButton, &QPushButton::clicked, [=](){
           progressBar->reset();
           ftdiFunctions ftdi;
           progressBar->setValue(25);
           ftdi.ftdiStartup();
           progressBar->setValue(50);
           if(ftdi.testFtdi()) {
               progressBar->setValue(100);
               testLabel->setStyleSheet("QLabel { color : blue; }");
               testLabel->setText("FTDI CHIP FOUND");
           }
           else {
               progressBar->setValue(0);
               testLabel->setStyleSheet("QLabel { color : red; }");
               testLabel->setText("NO FTDI CHIP FOUND");
           }
           ftdi.ftdiClose();
       });
       QObject::connect(customSendButton, &QPushButton::clicked, [=](){
           ftdiFunctions ftdi;
           ftdi.ftdiStartup();
           ftdi.sendButton(customLineEdit->text().toStdString());
       });
       QObject::connect(aButton, &QPushButton::clicked, [=](){
           ftdiFunctions ftdi;
           ftdi.ftdiStartup();
           if((instantBox->isChecked()) && (ftdi.validateInt(durationEdit->text().toStdString()))) ftdi.sendButton("A");
           if(ftdi.validateInt(durationEdit->text().toStdString())) {
               scriptBox->appendPlainText(QString::number(commandNumber) + ". aButton("+durationEdit->text()+");");
               ++commandNumber;
           }
       });
       QObject::connect(bButton, &QPushButton::clicked, [=](){
           ftdiFunctions ftdi;
           ftdi.ftdiStartup();
           if((instantBox->isChecked()) && (ftdi.validateInt(durationEdit->text().toStdString()))) ftdi.sendButton("B");
           if(ftdi.validateInt(durationEdit->text().toStdString())) {
               scriptBox->appendPlainText(QString::number(commandNumber) + ". bButton("+durationEdit->text()+");");
               ++commandNumber;
           }
       });
       QObject::connect(xButton, &QPushButton::clicked, [=](){
           ftdiFunctions ftdi;
           ftdi.ftdiStartup();
           if((instantBox->isChecked()) && (ftdi.validateInt(durationEdit->text().toStdString()))) ftdi.sendButton("X");
           if(ftdi.validateInt(durationEdit->text().toStdString())) {
               scriptBox->appendPlainText(QString::number(commandNumber) + ". xButton("+durationEdit->text()+");");
               ++commandNumber;
           }
       });
       QObject::connect(yButton, &QPushButton::clicked, [=](){
           ftdiFunctions ftdi;
           ftdi.ftdiStartup();
           if((instantBox->isChecked()) && (ftdi.validateInt(durationEdit->text().toStdString()))) ftdi.sendButton("Y");
           if(ftdi.validateInt(durationEdit->text().toStdString())) {
               scriptBox->appendPlainText(QString::number(commandNumber) + ". yButton("+durationEdit->text()+");");
               ++commandNumber;
           }
       });
        QObject::connect(captureButton, &QPushButton::clicked, [=](){
           ftdiFunctions ftdi;
           ftdi.ftdiStartup();
           if((instantBox->isChecked()) && (ftdi.validateInt(durationEdit->text().toStdString()))) ftdi.sendButton("capture");
           if(ftdi.validateInt(durationEdit->text().toStdString())) {
               scriptBox->appendPlainText(QString::number(commandNumber) + ". captureButton("+durationEdit->text()+");");
               ++commandNumber;
           }
       });
        QObject::connect(homeButton, &QPushButton::clicked, [=](){
           ftdiFunctions ftdi;
           ftdi.ftdiStartup();
           if((instantBox->isChecked()) && (ftdi.validateInt(durationEdit->text().toStdString()))) ftdi.sendButton("home");
           if(ftdi.validateInt(durationEdit->text().toStdString())) {
               scriptBox->appendPlainText(QString::number(commandNumber) + ". homeButton("+durationEdit->text()+");");
               ++commandNumber;
           }
       });
        QObject::connect(plusButton, &QPushButton::clicked, [=](){
           ftdiFunctions ftdi;
           ftdi.ftdiStartup();
           if((instantBox->isChecked()) && (ftdi.validateInt(durationEdit->text().toStdString()))) ftdi.sendButton("plus");
           if(ftdi.validateInt(durationEdit->text().toStdString())) {
               scriptBox->appendPlainText(QString::number(commandNumber) + ". plusButton("+durationEdit->text()+");");
               ++commandNumber;
           }
       });
        QObject::connect(minusButton, &QPushButton::clicked, [=](){
           ftdiFunctions ftdi;
           ftdi.ftdiStartup();
           if((instantBox->isChecked()) && (ftdi.validateInt(durationEdit->text().toStdString()))) ftdi.sendButton("minus");
           if(ftdi.validateInt(durationEdit->text().toStdString())) {
               scriptBox->appendPlainText(QString::number(commandNumber) + ". minusButton("+durationEdit->text()+");");
               ++commandNumber;
           }
       });
       QObject::connect(zlButton, &QPushButton::clicked, [=](){
           ftdiFunctions ftdi;
           ftdi.ftdiStartup();
           if((instantBox->isChecked()) && (ftdi.validateInt(durationEdit->text().toStdString()))) ftdi.sendButton("zl");
           if(ftdi.validateInt(durationEdit->text().toStdString())) {
               scriptBox->appendPlainText(QString::number(commandNumber) + ". zlButton("+durationEdit->text()+");");
               ++commandNumber;
           }
       });
       QObject::connect(zrButton, &QPushButton::clicked, [=](){
           ftdiFunctions ftdi;
           ftdi.ftdiStartup();
           if((instantBox->isChecked()) && (ftdi.validateInt(durationEdit->text().toStdString()))) ftdi.sendButton("zr");
           if(ftdi.validateInt(durationEdit->text().toStdString())) {
               scriptBox->appendPlainText(QString::number(commandNumber) + ". zrButton("+durationEdit->text()+");");
               ++commandNumber;
           }
       });
       QObject::connect(lButton, &QPushButton::clicked, [=](){
           ftdiFunctions ftdi;
           ftdi.ftdiStartup();
           if((instantBox->isChecked()) && (ftdi.validateInt(durationEdit->text().toStdString()))) ftdi.sendButton("l");
           if(ftdi.validateInt(durationEdit->text().toStdString())) {
               scriptBox->appendPlainText(QString::number(commandNumber) + ". lButton("+durationEdit->text()+");");
               ++commandNumber;
           }
       });
       QObject::connect(rButton, &QPushButton::clicked, [=](){
           ftdiFunctions ftdi;
           ftdi.ftdiStartup();
           if((instantBox->isChecked()) && (ftdi.validateInt(durationEdit->text().toStdString()))) ftdi.sendButton("r");
           if(ftdi.validateInt(durationEdit->text().toStdString())) {
               scriptBox->appendPlainText(QString::number(commandNumber) + ". rButton("+durationEdit->text()+");");
               ++commandNumber;
           }
       });
       QObject::connect(nothingButton, &QPushButton::clicked, [=](){
           ftdiFunctions ftdi;
           ftdi.ftdiStartup();
           if((instantBox->isChecked()) && (ftdi.validateInt(durationEdit->text().toStdString()))) ftdi.sendButton("nothing");
           if(ftdi.validateInt(durationEdit->text().toStdString())) {
               scriptBox->appendPlainText(QString::number(commandNumber) + ". nothing("+durationEdit->text()+");");
               ++commandNumber;
           }
       });
       QObject::connect(loopButton, &QPushButton::clicked, [=](){
           ftdiFunctions ftdi;
           ftdi.ftdiStartup();
           if((ftdi.validateInt(startLine->text().toStdString())) && (ftdi.validateInt(endLine->text().toStdString())) &&
                   (ftdi.validateInt(loopCountLine->text().toStdString())) && (commandNumber > 1)) {
               scriptBox->appendPlainText(QString::number(commandNumber) + ". Start(" + startLine->text()+");");
               commandNumber++;
               scriptBox->appendPlainText(QString::number(commandNumber) + ". End(" + endLine->text()+");");
               commandNumber++;
               scriptBox->appendPlainText(QString::number(commandNumber) + ". Times(" + loopCountLine->text()+");");
               commandNumber++;
           }
       });
       QObject::connect(clearBox, &QPushButton::clicked, [=](){
           scriptBox->clear();
           commandNumber = 1;
           setCompleteBar();
           setTaskStautsMsg(1);

       });
       QObject::connect(statusButton, &QPushButton::clicked, [=](){
           QFrame *secondWindow = new QFrame;
           Ui::statusFrame statusUi;
           statusUi.setupUi(secondWindow);
           //secondWindow->hide();
           secondWindow->show();
       });
       QObject::connect(clearEEPROM, &QPushButton::clicked, [=](){
           setStartBar();
           ftdiFunctions ftdi;
           std::string messageComplete = "";
           std::string incomingMessage = "";
           std::string receivedMsg = "waiting";
           while (receivedMsg != "READYFOREXCH") {
               ftdi.ftdiWrite("CLEAR");
               receivedMsg = ftdi.ftdiRead();
               QApplication::processEvents();
               scriptStatus->setValue(25);
               if (receivedMsg == "ERROR")
               {
                    std::cout << receivedMsg << "\n";
                    setErrorBar(1);
                    return;
               }
           }
           scriptStatus->setValue(55);
           std::cout << "Received message: " << receivedMsg << "\n";
           while (receivedMsg != "COMPLETEEXCH") {
               if (receivedMsg == "ERROR")
               {
                    std::cout << receivedMsg << "\n";
                    setErrorBar(2);
                    return;
               }
               ftdi.ftdiWrite("INITIATE");
               scriptStatus->setValue(75);
               receivedMsg = ftdi.ftdiRead();
               std::cout << "2nd Received message: " << receivedMsg << "\n";
               QApplication::processEvents();
           }
           scriptStatus->setValue(100);
       });
       QObject::connect(flashButton, &QPushButton::clicked, [=](){
           setStartBar();
           setTaskStautsMsg(2);
           double progressPercent = 0.0;
           QString statusMsgString = "";
           //int progressNumber = 0;
           QStringList lines = scriptBox->toPlainText().split('\n', QString::SkipEmptyParts);
           ftdiFunctions ftdi;
           std::string receivedMsg = "waiting";
           std::string messageComplete = "";
           while (receivedMsg != "READYFOREXCH") {
               ftdi.ftdiWrite("FLASH");
               receivedMsg = ftdi.ftdiRead();
               QApplication::processEvents();
               if (receivedMsg == "ERROR")
               {
                    std::cout << receivedMsg << "\n";
                    setErrorBar(1);
                    return;
               }
           }
           setTaskStautsMsg(3);
           int i = 0;
           while (i < lines.size()) {

               if (i > 0) {
                   progressPercent = static_cast<double>(10*i)/static_cast<double>(10*lines.size());
                   std::cout << "Percent: " << static_cast<int>(100*progressPercent) << "\n";
                   scriptStatus->setValue(static_cast<int>(100*progressPercent));
                   setTaskStatusMsg("Completing handshake for line " + QString::number(i+1));
                   QApplication::processEvents();
               }
               if (i < 9) ftdi.ftdiWrite("00"+lines[i].toStdString());
               else if ((i >= 9) && (i < 99)) ftdi.ftdiWrite("0"+lines[i].toStdString());
               else if (i >= 99) ftdi.ftdiWrite(lines[i].toStdString());
               receivedMsg = ftdi.ftdiRead();
               if (receivedMsg == "ERROR") return;
               if(i < 9) messageComplete = "00"+lines[i].toStdString().substr(0,1) + " Complete";
               else if ((i >= 9) && (i < 99)) messageComplete = "0"+lines[i].toStdString().substr(0,2) + " Complete";
               else if (i >= 99) messageComplete = lines[i].toStdString().substr(0,3) + " Complete";
               std::cout << "Incoming message: " << receivedMsg << " Comparison point: " << messageComplete << "\n";
               if (receivedMsg == messageComplete) {
                   ++i;
               }
           }
           while (receivedMsg.find("Complete") != std::string::npos)
           {
               ftdi.ftdiWrite("COMPLETE");
               setTaskStautsMsg(4);
               receivedMsg = ftdi.ftdiRead();
           }
           setTaskStatusMsg("EEPROM Flash complete. Ready for Execute.");
           scriptStatus->setValue(100);
       });
       QObject::connect(executeButton, &QPushButton::clicked, [=](){
           setStartBar();
           setTaskStatusMsg("Executing. Disconnect to end.");
           std::string executeMonitorMsg;
           statusBarValue = 0;
           ftdiFunctions ftdi;
           for (int k = 0; k < 3; k++) {
               ftdi.ftdiWrite("EXECUTE");
               executeMonitorMsg = ftdi.ftdiRead();
               std::cout << executeMonitorMsg << "\n";
               if (executeMonitorMsg == "ERROR")
               {
                   setErrorBar(1);
                   return;
               }
               statusBarValue = statusBarValue + 33;
               scriptStatus->setValue(statusBarValue);
               QApplication::processEvents();
           }
           while (monitorBox->isChecked()) {
               executeMonitorMsg = ftdi.ftdiRead();
               std::cout << executeMonitorMsg << "\n";
               if (executeMonitorMsg == "ERROR") {
                   setErrorBar(3);
                   return;
               }
               QApplication::processEvents();
           }
       });
       QObject::connect(leftJoyStick, &QDial::sliderPressed, [=](){
           //scriptBox->appendPlainText(QString::number(leftJoyStick->value()));
           ftdiFunctions ftdi;
           if(ftdi.validateInt(durationEdit->text().toStdString())) {
               if ((leftJoyStick->value() < 45) || (leftJoyStick->value() >= 315)) {
                   scriptBox->appendPlainText(QString::number(commandNumber) + ". ljsDown("+durationEdit->text()+");");
                   ++commandNumber;
               }
               else if ((leftJoyStick->value() >= 45) && (leftJoyStick->value() < 135)) {
                   scriptBox->appendPlainText(QString::number(commandNumber) + ". ljsLeft("+durationEdit->text()+");");
                   ++commandNumber;
               }
               else if ((leftJoyStick->value() >= 45) && (leftJoyStick->value() < 225)) {
                   scriptBox->appendPlainText(QString::number(commandNumber) + ". ljsUp("+durationEdit->text()+");");
                   ++commandNumber;
               }
               else {
                   scriptBox->appendPlainText(QString::number(commandNumber) + ". ljsRight("+durationEdit->text()+");");
                   ++commandNumber;
               }
           }
       });
       QObject::connect(rightJoystick, &QDial::sliderPressed, [=](){
           //scriptBox->appendPlainText(QString::number(rightJoystick->value()));
           ftdiFunctions ftdi;
           if(ftdi.validateInt(durationEdit->text().toStdString())) {
               if ((rightJoystick->value() < 45) || (rightJoystick->value() >= 315)) {
                   scriptBox->appendPlainText(QString::number(commandNumber) + ". rjsDown("+durationEdit->text()+");");
                   ++commandNumber;
               }
               else if ((rightJoystick->value() >= 45) && (rightJoystick->value() < 135)) {
                   scriptBox->appendPlainText(QString::number(commandNumber) + ". rjsLeft("+durationEdit->text()+");");
                   ++commandNumber;
               }
               else if ((rightJoystick->value() >= 45) && (rightJoystick->value() < 225)) {
                   scriptBox->appendPlainText(QString::number(commandNumber) + ". rjsUp("+durationEdit->text()+");");
                   ++commandNumber;
               }
               else {
                   scriptBox->appendPlainText(QString::number(commandNumber) + ". rjsRight("+durationEdit->text()+");");
                   ++commandNumber;
               }
           }
       });

        scriptTab->setCurrentIndex(1);
        ftdiSendTab->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi


    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "USB to Switch", nullptr));
        actionTesting->setText(QCoreApplication::translate("MainWindow", "Testing", nullptr));
        actionTesting2->setText(QCoreApplication::translate("MainWindow", "Testing2", nullptr));
        actionUse->setText(QCoreApplication::translate("MainWindow", "Use", nullptr));
        actionAbout->setText(QCoreApplication::translate("MainWindow", "About", nullptr));
        actionInstructions->setText(QCoreApplication::translate("MainWindow", "Instructions", nullptr));
        actionFAQ->setText(QCoreApplication::translate("MainWindow", "FAQ", nullptr));
        actionConnect->setText(QCoreApplication::translate("MainWindow", "Connect with me", nullptr));
#if QT_CONFIG(tooltip)
        controllerInputs->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        controllerInputs->setTitle(QCoreApplication::translate("MainWindow", "Controller Inputs", nullptr));
        scriptBox->setPlainText(QString());
        durationEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter Duration...", nullptr));
        scriptBoxLabel->setText(QCoreApplication::translate("MainWindow", "Script", nullptr));
#if QT_CONFIG(whatsthis)
        minusButton->setWhatsThis(QCoreApplication::translate("MainWindow", "Minus Button", nullptr));
#endif // QT_CONFIG(whatsthis)
        minusButton->setText(QString());
#if QT_CONFIG(whatsthis)
        lButton->setWhatsThis(QCoreApplication::translate("MainWindow", "L Button", nullptr));
#endif // QT_CONFIG(whatsthis)
        lButton->setText(QCoreApplication::translate("MainWindow", "L", nullptr));
#if QT_CONFIG(whatsthis)
        captureButton->setWhatsThis(QCoreApplication::translate("MainWindow", "Capture button", nullptr));
#endif // QT_CONFIG(whatsthis)
        captureButton->setText(QString());
#if QT_CONFIG(whatsthis)
        nothingButton->setWhatsThis(QCoreApplication::translate("MainWindow", "Nothing Button", nullptr));
#endif // QT_CONFIG(whatsthis)
        nothingButton->setText(QCoreApplication::translate("MainWindow", "Nothing", nullptr));
#if QT_CONFIG(whatsthis)
        zlButton->setWhatsThis(QCoreApplication::translate("MainWindow", "ZL Button", nullptr));
#endif // QT_CONFIG(whatsthis)
        zlButton->setText(QCoreApplication::translate("MainWindow", "ZL", nullptr));
#if QT_CONFIG(whatsthis)
        leftJoyStick->setWhatsThis(QCoreApplication::translate("MainWindow", "Left Joystick", nullptr));
#endif // QT_CONFIG(whatsthis)
#if QT_CONFIG(whatsthis)
        dpadFrame->setWhatsThis(QCoreApplication::translate("MainWindow", "Disabled inputs", nullptr));
#endif // QT_CONFIG(whatsthis)
        loopCountLine->setPlaceholderText(QCoreApplication::translate("MainWindow", "loop count", nullptr));
        endLine->setPlaceholderText(QCoreApplication::translate("MainWindow", "end", nullptr));
        loopButton->setText(QCoreApplication::translate("MainWindow", "Add Loop", nullptr));
        startLine->setPlaceholderText(QCoreApplication::translate("MainWindow", "start", nullptr));


#if QT_CONFIG(whatsthis)
        rButton->setWhatsThis(QCoreApplication::translate("MainWindow", "R Button", nullptr));
#endif // QT_CONFIG(whatsthis)
        rButton->setText(QCoreApplication::translate("MainWindow", "R", nullptr));
#if QT_CONFIG(whatsthis)
        zrButton->setWhatsThis(QCoreApplication::translate("MainWindow", "ZR Button", nullptr));
#endif // QT_CONFIG(whatsthis)
        zrButton->setText(QCoreApplication::translate("MainWindow", "ZR", nullptr));
#if QT_CONFIG(whatsthis)
        xButton->setWhatsThis(QCoreApplication::translate("MainWindow", "X Button", nullptr));
#endif // QT_CONFIG(whatsthis)
        xButton->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
#if QT_CONFIG(whatsthis)
        aButton->setWhatsThis(QCoreApplication::translate("MainWindow", "A Button", nullptr));
#endif // QT_CONFIG(whatsthis)
        aButton->setText(QCoreApplication::translate("MainWindow", "A", nullptr));
#if QT_CONFIG(whatsthis)
        yButton->setWhatsThis(QCoreApplication::translate("MainWindow", "Y Button", nullptr));
#endif // QT_CONFIG(whatsthis)
        yButton->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
#if QT_CONFIG(whatsthis)
        bButton->setWhatsThis(QCoreApplication::translate("MainWindow", "B Button", nullptr));
#endif // QT_CONFIG(whatsthis)
        bButton->setText(QCoreApplication::translate("MainWindow", "B", nullptr));
#if QT_CONFIG(whatsthis)
        instantBox->setWhatsThis(QCoreApplication::translate("MainWindow", "Enables immediate inputs to be sent to the switch", nullptr));
#endif // QT_CONFIG(whatsthis)
        instantBox->setText(QCoreApplication::translate("MainWindow", "Instant", nullptr));
#if QT_CONFIG(whatsthis)
        plusButton->setWhatsThis(QCoreApplication::translate("MainWindow", "Plus Button", nullptr));
#endif // QT_CONFIG(whatsthis)
        plusButton->setText(QString());
#if QT_CONFIG(whatsthis)
        homeButton->setWhatsThis(QCoreApplication::translate("MainWindow", "Home Button", nullptr));
#endif // QT_CONFIG(whatsthis)
        homeButton->setText(QCoreApplication::translate("MainWindow", "Home", nullptr));
#if QT_CONFIG(whatsthis)
        rightJoystick->setWhatsThis(QCoreApplication::translate("MainWindow", "Right Joystick", nullptr));
#endif // QT_CONFIG(whatsthis)
        inputExpandButton->setText(QString());
#if QT_CONFIG(tooltip)
        monitorBox->setToolTip(QCoreApplication::translate("MainWindow", "Monitors input messages from console", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        monitorBox->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        monitorBox->setText(QCoreApplication::translate("MainWindow", "Monitor", nullptr));
        clearEEPROM->setText(QCoreApplication::translate("MainWindow", "Clear EEPROM", nullptr));
        flashButton->setText(QCoreApplication::translate("MainWindow", "Flash EEPROM", nullptr));
        clearBox->setText(QCoreApplication::translate("MainWindow", "Clear Box", nullptr));
        executeButton->setText(QCoreApplication::translate("MainWindow", "Execute Script", nullptr));
        readEEPROM->setText(QCoreApplication::translate("MainWindow", "Read EEPROM", nullptr));
        statusButton->setText(QCoreApplication::translate("MainWindow", "Status", nullptr));
        taskStatusLabel->setText(QCoreApplication::translate("MainWindow", "Task Status", nullptr));
        taskStatusBarLabel->setText(QString());
        boxReleaseButton->setText(QCoreApplication::translate("MainWindow", "Box Release", nullptr));
        diggerBrothersButton->setText(QCoreApplication::translate("MainWindow", "Digger Brothers", nullptr));
        wattFarmingButton->setText(QCoreApplication::translate("MainWindow", "Watt Farming", nullptr));
        berryFarmingButton->setText(QCoreApplication::translate("MainWindow", "Berry Farming", nullptr));
        stowOnSideButton->setText(QCoreApplication::translate("MainWindow", "Stow On Side", nullptr));
        lottoFarmingButton->setText(QCoreApplication::translate("MainWindow", "Lotto Farming", nullptr));
        championsCupButton->setText(QCoreApplication::translate("MainWindow", "Champions Cup", nullptr));
        pokeJobFarmingButton->setText(QCoreApplication::translate("MainWindow", "Poke Job Farming", nullptr));
        eggHatchBox->setItemText(0, QCoreApplication::translate("MainWindow", "Egg Hatching", nullptr));
        eggHatchBox->setItemText(1, QCoreApplication::translate("MainWindow", "2560 Steps", nullptr));
        eggHatchBox->setItemText(2, QCoreApplication::translate("MainWindow", "3840 Steps", nullptr));
        eggHatchBox->setItemText(3, QCoreApplication::translate("MainWindow", "5120 Steps", nullptr));
        eggHatchBox->setItemText(4, QCoreApplication::translate("MainWindow", "6400 Steps", nullptr));
        eggHatchBox->setItemText(5, QCoreApplication::translate("MainWindow", "7680 Steps", nullptr));
        eggHatchBox->setItemText(6, QCoreApplication::translate("MainWindow", "8960 Steps", nullptr));
        eggHatchBox->setItemText(7, QCoreApplication::translate("MainWindow", "10240 Steps", nullptr));

        fossilReviveBox->setItemText(0, QCoreApplication::translate("MainWindow", "Fossil Reviving", nullptr));
        fossilReviveBox->setItemText(1, QCoreApplication::translate("MainWindow", "Arctovish", nullptr));
        fossilReviveBox->setItemText(2, QCoreApplication::translate("MainWindow", "Arctozolt", nullptr));
        fossilReviveBox->setItemText(3, QCoreApplication::translate("MainWindow", "Dracovish", nullptr));
        fossilReviveBox->setItemText(4, QCoreApplication::translate("MainWindow", "Dracozolt", nullptr));

        fossilReviveBox->setCurrentText(QCoreApplication::translate("MainWindow", "Fossil Reviving", nullptr));
        evBox1->setItemText(0, QCoreApplication::translate("MainWindow", "EV 1", nullptr));
        evBox1->setItemText(1, QCoreApplication::translate("MainWindow", "ATK", nullptr));
        evBox1->setItemText(2, QCoreApplication::translate("MainWindow", "DEF", nullptr));
        evBox1->setItemText(3, QCoreApplication::translate("MainWindow", "SPATK", nullptr));
        evBox1->setItemText(4, QCoreApplication::translate("MainWindow", "SPDEF", nullptr));
        evBox1->setItemText(5, QCoreApplication::translate("MainWindow", "HP", nullptr));

        evBox2->setItemText(0, QCoreApplication::translate("MainWindow", "EV 2", nullptr));
        evBox2->setItemText(1, QCoreApplication::translate("MainWindow", "ATK", nullptr));
        evBox2->setItemText(2, QCoreApplication::translate("MainWindow", "DEF", nullptr));
        evBox2->setItemText(3, QCoreApplication::translate("MainWindow", "SPATK", nullptr));
        evBox2->setItemText(4, QCoreApplication::translate("MainWindow", "SPDEF", nullptr));
        evBox2->setItemText(5, QCoreApplication::translate("MainWindow", "HP", nullptr));

        evTrainButton->setText(QCoreApplication::translate("MainWindow", "EV Train", nullptr));
        hatchButton->setText(QCoreApplication::translate("MainWindow", "Hatch", nullptr));
        reviveButton->setText(QCoreApplication::translate("MainWindow", "Revive", nullptr));
        scriptTab->setTabText(scriptTab->indexOf(pkmnTab), QCoreApplication::translate("MainWindow", "PKMN SW/SH", nullptr));
        starFarmingButton->setText(QCoreApplication::translate("MainWindow", "Star Farming", nullptr));
        diyRepetitionButton->setText(QCoreApplication::translate("MainWindow", "DIY Repetition", nullptr));
        eatFruitButton->setText(QCoreApplication::translate("MainWindow", "Eat 10 Fruit", nullptr));
        depositBoxButton->setText(QCoreApplication::translate("MainWindow", "Deposit Box", nullptr));
        axeBreakButton->setText(QCoreApplication::translate("MainWindow", "Axe Break", nullptr));
        scriptTab->setTabText(scriptTab->indexOf(acnhTab), QCoreApplication::translate("MainWindow", "ACNH", nullptr));
        customSendButton->setText(QCoreApplication::translate("MainWindow", "Send", nullptr));
        customLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter Message...", nullptr));
        ftdiSendTab->setTabText(ftdiSendTab->indexOf(customTab), QCoreApplication::translate("MainWindow", "Custom Message", nullptr));
        ftdiSendButton->setText(QCoreApplication::translate("MainWindow", "Test", nullptr));
        testLabel->setText(QString());
        ftdiSendTab->setTabText(ftdiSendTab->indexOf(ftdiTestTab), QCoreApplication::translate("MainWindow", "FTDI Test", nullptr));
        menuMenu->setTitle(QCoreApplication::translate("MainWindow", "Menu", nullptr));
    } // retranslateUi

 };

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // GAMEPADAPP5_XMNTJJS_H
