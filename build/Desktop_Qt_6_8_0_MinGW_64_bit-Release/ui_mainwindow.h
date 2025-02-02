/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *labelRegister;
    QTextEdit *screen;
    QTableWidget *Register;
    QTableWidget *Memory;
    QLabel *labelMemory;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton;
    QPushButton *bttnDecode;
    QPushButton *bttnInsert;
    QPushButton *bttnRun;
    QLabel *label;
    QLineEdit *IR;
    QLineEdit *PC;
    QLabel *label_2;
    QLabel *label_3;
    QTextEdit *Decode;
    QLabel *label_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->setEnabled(true);
        MainWindow->resize(1056, 763);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(1056, 0));
        MainWindow->setBaseSize(QSize(0, 0));
        QFont font;
        font.setPointSize(10);
        font.setBold(false);
        MainWindow->setFont(font);
        MainWindow->setStyleSheet(QString::fromUtf8("/* Set a background color for the central widget that will \"show through\" the rounded corners */\n"
"QWidget#centralWidget {\n"
"    background-color: #3498db; /* This color will act as the \"border-radius color\" */\n"
"}\n"
"\n"
"/* Style the QMainWindow */\n"
"QMainWindow {\n"
"    background-color: #202020; /* Main background color of the window */\n"
"    border: 2px solid #3498db; /* Border color around the window */\n"
"    border-radius: 20px;       /* Rounded corners */\n"
"}\n"
""));
        MainWindow->setIconSize(QSize(30, 30));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        labelRegister = new QLabel(centralwidget);
        labelRegister->setObjectName("labelRegister");
        labelRegister->setGeometry(QRect(40, 0, 91, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Segoe UI Semibold")});
        font1.setPointSize(14);
        font1.setBold(true);
        labelRegister->setFont(font1);
        screen = new QTextEdit(centralwidget);
        screen->setObjectName("screen");
        screen->setEnabled(false);
        screen->setGeometry(QRect(410, 510, 621, 100));
        Register = new QTableWidget(centralwidget);
        if (Register->columnCount() < 1)
            Register->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        Register->setHorizontalHeaderItem(0, __qtablewidgetitem);
        if (Register->rowCount() < 16)
            Register->setRowCount(16);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        Register->setVerticalHeaderItem(0, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        Register->setVerticalHeaderItem(1, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        Register->setVerticalHeaderItem(2, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        Register->setVerticalHeaderItem(3, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        Register->setVerticalHeaderItem(4, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        Register->setVerticalHeaderItem(5, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        Register->setVerticalHeaderItem(6, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        Register->setVerticalHeaderItem(7, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        Register->setVerticalHeaderItem(8, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        Register->setVerticalHeaderItem(9, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        Register->setVerticalHeaderItem(10, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        Register->setVerticalHeaderItem(11, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        Register->setVerticalHeaderItem(12, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        Register->setVerticalHeaderItem(13, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        Register->setVerticalHeaderItem(14, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        Register->setVerticalHeaderItem(15, __qtablewidgetitem16);
        Register->setObjectName("Register");
        Register->setEnabled(false);
        Register->setGeometry(QRect(10, 30, 151, 421));
        Register->setStyleSheet(QString::fromUtf8(""));
        Register->verticalHeader()->setCascadingSectionResizes(false);
        Register->verticalHeader()->setMinimumSectionSize(24);
        Register->verticalHeader()->setDefaultSectionSize(24);
        Memory = new QTableWidget(centralwidget);
        if (Memory->columnCount() < 16)
            Memory->setColumnCount(16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        Memory->setHorizontalHeaderItem(0, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        Memory->setHorizontalHeaderItem(1, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        Memory->setHorizontalHeaderItem(2, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        Memory->setHorizontalHeaderItem(3, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        Memory->setHorizontalHeaderItem(4, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        Memory->setHorizontalHeaderItem(5, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        Memory->setHorizontalHeaderItem(6, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        Memory->setHorizontalHeaderItem(7, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        Memory->setHorizontalHeaderItem(8, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        Memory->setHorizontalHeaderItem(9, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        Memory->setHorizontalHeaderItem(10, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        Memory->setHorizontalHeaderItem(11, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        Memory->setHorizontalHeaderItem(12, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        Memory->setHorizontalHeaderItem(13, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        Memory->setHorizontalHeaderItem(14, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        Memory->setHorizontalHeaderItem(15, __qtablewidgetitem32);
        if (Memory->rowCount() < 16)
            Memory->setRowCount(16);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        Memory->setVerticalHeaderItem(0, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        Memory->setVerticalHeaderItem(1, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        Memory->setVerticalHeaderItem(2, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        Memory->setVerticalHeaderItem(3, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        Memory->setVerticalHeaderItem(4, __qtablewidgetitem37);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        Memory->setVerticalHeaderItem(5, __qtablewidgetitem38);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        Memory->setVerticalHeaderItem(6, __qtablewidgetitem39);
        QTableWidgetItem *__qtablewidgetitem40 = new QTableWidgetItem();
        Memory->setVerticalHeaderItem(7, __qtablewidgetitem40);
        QTableWidgetItem *__qtablewidgetitem41 = new QTableWidgetItem();
        Memory->setVerticalHeaderItem(8, __qtablewidgetitem41);
        QTableWidgetItem *__qtablewidgetitem42 = new QTableWidgetItem();
        Memory->setVerticalHeaderItem(9, __qtablewidgetitem42);
        QTableWidgetItem *__qtablewidgetitem43 = new QTableWidgetItem();
        Memory->setVerticalHeaderItem(10, __qtablewidgetitem43);
        QTableWidgetItem *__qtablewidgetitem44 = new QTableWidgetItem();
        Memory->setVerticalHeaderItem(11, __qtablewidgetitem44);
        QTableWidgetItem *__qtablewidgetitem45 = new QTableWidgetItem();
        Memory->setVerticalHeaderItem(12, __qtablewidgetitem45);
        QTableWidgetItem *__qtablewidgetitem46 = new QTableWidgetItem();
        Memory->setVerticalHeaderItem(13, __qtablewidgetitem46);
        QTableWidgetItem *__qtablewidgetitem47 = new QTableWidgetItem();
        Memory->setVerticalHeaderItem(14, __qtablewidgetitem47);
        QTableWidgetItem *__qtablewidgetitem48 = new QTableWidgetItem();
        Memory->setVerticalHeaderItem(15, __qtablewidgetitem48);
        QTableWidgetItem *__qtablewidgetitem49 = new QTableWidgetItem();
        Memory->setItem(0, 0, __qtablewidgetitem49);
        QTableWidgetItem *__qtablewidgetitem50 = new QTableWidgetItem();
        Memory->setItem(9, 0, __qtablewidgetitem50);
        Memory->setObjectName("Memory");
        Memory->setEnabled(false);
        Memory->setGeometry(QRect(200, 30, 851, 421));
        QFont font2;
        font2.setBold(false);
        Memory->setFont(font2);
        Memory->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
"                                border-radius: 20px;\n"
"   border: 200px solid #3D3D3D;\"  // Optional: add a border around the                background-color: #202020;  // Set table background\n"
"                                }\n"
"\n"
"\n"
"\"QTableWidget::item {\"\n"
"    \"   background-color: light gray;\"  // Background color for table cells\n"
"    \"   color: cyan\"                 // Text color for table cells\n"
"    \"}\""));
        Memory->horizontalHeader()->setMinimumSectionSize(50);
        Memory->horizontalHeader()->setDefaultSectionSize(50);
        Memory->verticalHeader()->setMinimumSectionSize(24);
        Memory->verticalHeader()->setDefaultSectionSize(24);
        labelMemory = new QLabel(centralwidget);
        labelMemory->setObjectName("labelMemory");
        labelMemory->setGeometry(QRect(550, 0, 111, 31));
        labelMemory->setFont(font1);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(410, 620, 621, 61));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName("pushButton");
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Segoe UI Semibold")});
        font3.setPointSize(10);
        font3.setBold(true);
        pushButton->setFont(font3);

        horizontalLayout_2->addWidget(pushButton);

        bttnDecode = new QPushButton(layoutWidget);
        bttnDecode->setObjectName("bttnDecode");
        bttnDecode->setFont(font3);

        horizontalLayout_2->addWidget(bttnDecode);

        bttnInsert = new QPushButton(layoutWidget);
        bttnInsert->setObjectName("bttnInsert");
        bttnInsert->setFont(font3);

        horizontalLayout_2->addWidget(bttnInsert);

        bttnRun = new QPushButton(layoutWidget);
        bttnRun->setObjectName("bttnRun");
        bttnRun->setFont(font3);

        horizontalLayout_2->addWidget(bttnRun);

        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(680, 470, 91, 31));
        label->setFont(font1);
        IR = new QLineEdit(centralwidget);
        IR->setObjectName("IR");
        IR->setGeometry(QRect(240, 640, 100, 30));
        PC = new QLineEdit(centralwidget);
        PC->setObjectName("PC");
        PC->setGeometry(QRect(110, 640, 70, 30));
        PC->setBaseSize(QSize(10, 10));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(210, 640, 21, 20));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Segoe UI Semibold")});
        font4.setPointSize(10);
        label_2->setFont(font4);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(80, 640, 31, 20));
        label_3->setFont(font4);
        Decode = new QTextEdit(centralwidget);
        Decode->setObjectName("Decode");
        Decode->setEnabled(false);
        Decode->setGeometry(QRect(20, 510, 361, 100));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(150, 480, 101, 20));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Segoe UI Semibold")});
        font5.setPointSize(14);
        font5.setBold(false);
        label_4->setFont(font5);
        MainWindow->setCentralWidget(centralwidget);
        labelMemory->raise();
        labelRegister->raise();
        screen->raise();
        Register->raise();
        Memory->raise();
        layoutWidget->raise();
        label->raise();
        IR->raise();
        PC->raise();
        label_2->raise();
        label_3->raise();
        Decode->raise();
        label_4->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1056, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        labelRegister->setText(QCoreApplication::translate("MainWindow", "Register", nullptr));
        screen->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        QTableWidgetItem *___qtablewidgetitem = Register->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Hex", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = Register->verticalHeaderItem(0);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "R0", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = Register->verticalHeaderItem(1);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "R1", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = Register->verticalHeaderItem(2);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "R2", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = Register->verticalHeaderItem(3);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "R3", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = Register->verticalHeaderItem(4);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "R4", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = Register->verticalHeaderItem(5);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "R5", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = Register->verticalHeaderItem(6);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "R6", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = Register->verticalHeaderItem(7);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "R7", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = Register->verticalHeaderItem(8);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "R8", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = Register->verticalHeaderItem(9);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "R9", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = Register->verticalHeaderItem(10);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("MainWindow", "RA", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = Register->verticalHeaderItem(11);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("MainWindow", "RB", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = Register->verticalHeaderItem(12);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("MainWindow", "RC", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = Register->verticalHeaderItem(13);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("MainWindow", "RD", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = Register->verticalHeaderItem(14);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("MainWindow", "RE", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = Register->verticalHeaderItem(15);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("MainWindow", "RF", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = Memory->horizontalHeaderItem(0);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = Memory->horizontalHeaderItem(1);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = Memory->horizontalHeaderItem(2);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = Memory->horizontalHeaderItem(3);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = Memory->horizontalHeaderItem(4);
        ___qtablewidgetitem21->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = Memory->horizontalHeaderItem(5);
        ___qtablewidgetitem22->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = Memory->horizontalHeaderItem(6);
        ___qtablewidgetitem23->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = Memory->horizontalHeaderItem(7);
        ___qtablewidgetitem24->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = Memory->horizontalHeaderItem(8);
        ___qtablewidgetitem25->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        QTableWidgetItem *___qtablewidgetitem26 = Memory->horizontalHeaderItem(9);
        ___qtablewidgetitem26->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        QTableWidgetItem *___qtablewidgetitem27 = Memory->horizontalHeaderItem(10);
        ___qtablewidgetitem27->setText(QCoreApplication::translate("MainWindow", "A", nullptr));
        QTableWidgetItem *___qtablewidgetitem28 = Memory->horizontalHeaderItem(11);
        ___qtablewidgetitem28->setText(QCoreApplication::translate("MainWindow", "B", nullptr));
        QTableWidgetItem *___qtablewidgetitem29 = Memory->horizontalHeaderItem(12);
        ___qtablewidgetitem29->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        QTableWidgetItem *___qtablewidgetitem30 = Memory->horizontalHeaderItem(13);
        ___qtablewidgetitem30->setText(QCoreApplication::translate("MainWindow", "D", nullptr));
        QTableWidgetItem *___qtablewidgetitem31 = Memory->horizontalHeaderItem(14);
        ___qtablewidgetitem31->setText(QCoreApplication::translate("MainWindow", "E", nullptr));
        QTableWidgetItem *___qtablewidgetitem32 = Memory->horizontalHeaderItem(15);
        ___qtablewidgetitem32->setText(QCoreApplication::translate("MainWindow", "F", nullptr));
        QTableWidgetItem *___qtablewidgetitem33 = Memory->verticalHeaderItem(0);
        ___qtablewidgetitem33->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem34 = Memory->verticalHeaderItem(1);
        ___qtablewidgetitem34->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem35 = Memory->verticalHeaderItem(2);
        ___qtablewidgetitem35->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        QTableWidgetItem *___qtablewidgetitem36 = Memory->verticalHeaderItem(3);
        ___qtablewidgetitem36->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        QTableWidgetItem *___qtablewidgetitem37 = Memory->verticalHeaderItem(4);
        ___qtablewidgetitem37->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        QTableWidgetItem *___qtablewidgetitem38 = Memory->verticalHeaderItem(5);
        ___qtablewidgetitem38->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        QTableWidgetItem *___qtablewidgetitem39 = Memory->verticalHeaderItem(6);
        ___qtablewidgetitem39->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        QTableWidgetItem *___qtablewidgetitem40 = Memory->verticalHeaderItem(7);
        ___qtablewidgetitem40->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        QTableWidgetItem *___qtablewidgetitem41 = Memory->verticalHeaderItem(8);
        ___qtablewidgetitem41->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        QTableWidgetItem *___qtablewidgetitem42 = Memory->verticalHeaderItem(9);
        ___qtablewidgetitem42->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        QTableWidgetItem *___qtablewidgetitem43 = Memory->verticalHeaderItem(10);
        ___qtablewidgetitem43->setText(QCoreApplication::translate("MainWindow", "A", nullptr));
        QTableWidgetItem *___qtablewidgetitem44 = Memory->verticalHeaderItem(11);
        ___qtablewidgetitem44->setText(QCoreApplication::translate("MainWindow", "B", nullptr));
        QTableWidgetItem *___qtablewidgetitem45 = Memory->verticalHeaderItem(12);
        ___qtablewidgetitem45->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        QTableWidgetItem *___qtablewidgetitem46 = Memory->verticalHeaderItem(13);
        ___qtablewidgetitem46->setText(QCoreApplication::translate("MainWindow", "D", nullptr));
        QTableWidgetItem *___qtablewidgetitem47 = Memory->verticalHeaderItem(14);
        ___qtablewidgetitem47->setText(QCoreApplication::translate("MainWindow", "E", nullptr));
        QTableWidgetItem *___qtablewidgetitem48 = Memory->verticalHeaderItem(15);
        ___qtablewidgetitem48->setText(QCoreApplication::translate("MainWindow", "F", nullptr));

        const bool __sortingEnabled = Memory->isSortingEnabled();
        Memory->setSortingEnabled(false);
        Memory->setSortingEnabled(__sortingEnabled);

        labelMemory->setText(QCoreApplication::translate("MainWindow", "Memory", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "clear", nullptr));
        bttnDecode->setText(QCoreApplication::translate("MainWindow", "One Cycle", nullptr));
        bttnInsert->setText(QCoreApplication::translate("MainWindow", "Insert", nullptr));
        bttnRun->setText(QCoreApplication::translate("MainWindow", "Run", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Screen", nullptr));
        IR->setText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "IR", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "PC", nullptr));
        Decode->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Decode", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
