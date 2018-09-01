/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QPushButton *pushButton_2;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *lineEdit_3;
    QLabel *label_2;
    QLineEdit *lineEdit_4;
    QLabel *label_3;
    QLineEdit *lineEdit_5;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_6;
    QLineEdit *lineEdit_8;
    QLabel *label_4;
    QLineEdit *lineEdit_6;
    QLabel *label_5;
    QLineEdit *lineEdit_7;
    QLabel *label_7;
    QLineEdit *lineEdit_9;
    QLineEdit *lineEdit_10;
    QLabel *label_8;
    QLineEdit *lineEdit_11;
    QLabel *label_9;
    QWidget *tab_2;
    QPushButton *pushButton_5;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_1;
    QPushButton *pushButton_3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(968, 1096);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(60, 200, 801, 491));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        pushButton_2 = new QPushButton(tab);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(180, 380, 121, 41));
        layoutWidget = new QWidget(tab);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 70, 171, 164));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        lineEdit_3 = new QLineEdit(layoutWidget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        verticalLayout->addWidget(lineEdit_3);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        lineEdit_4 = new QLineEdit(layoutWidget);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));

        verticalLayout->addWidget(lineEdit_4);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        lineEdit_5 = new QLineEdit(layoutWidget);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));

        verticalLayout->addWidget(lineEdit_5);

        layoutWidget1 = new QWidget(tab);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(270, 70, 421, 220));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout_2->addWidget(label_6);

        lineEdit_8 = new QLineEdit(layoutWidget1);
        lineEdit_8->setObjectName(QStringLiteral("lineEdit_8"));

        verticalLayout_2->addWidget(lineEdit_8);

        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_2->addWidget(label_4);

        lineEdit_6 = new QLineEdit(layoutWidget1);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));

        verticalLayout_2->addWidget(lineEdit_6);

        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_2->addWidget(label_5);

        lineEdit_7 = new QLineEdit(layoutWidget1);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));

        verticalLayout_2->addWidget(lineEdit_7);

        label_7 = new QLabel(layoutWidget1);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout_2->addWidget(label_7);

        lineEdit_9 = new QLineEdit(layoutWidget1);
        lineEdit_9->setObjectName(QStringLiteral("lineEdit_9"));

        verticalLayout_2->addWidget(lineEdit_9);

        lineEdit_10 = new QLineEdit(tab);
        lineEdit_10->setObjectName(QStringLiteral("lineEdit_10"));
        lineEdit_10->setGeometry(QRect(10, 260, 171, 31));
        label_8 = new QLabel(tab);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 240, 131, 20));
        lineEdit_11 = new QLineEdit(tab);
        lineEdit_11->setObjectName(QStringLiteral("lineEdit_11"));
        lineEdit_11->setGeometry(QRect(270, 320, 421, 31));
        label_9 = new QLabel(tab);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(270, 300, 271, 20));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        pushButton_5 = new QPushButton(tab_2);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(260, 170, 101, 41));
        lineEdit_2 = new QLineEdit(tab_2);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(90, 120, 371, 31));
        lineEdit = new QLineEdit(tab_2);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(90, 40, 371, 31));
        lineEdit_1 = new QLineEdit(tab_2);
        lineEdit_1->setObjectName(QStringLiteral("lineEdit_1"));
        lineEdit_1->setGeometry(QRect(90, 80, 371, 31));
        pushButton_3 = new QPushButton(tab_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(460, 80, 81, 27));
        tabWidget->addTab(tab_2, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 968, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "OK", 0));
        label->setText(QApplication::translate("MainWindow", "time duration in minutes", 0));
        lineEdit_3->setText(QApplication::translate("MainWindow", "60", 0));
        label_2->setText(QApplication::translate("MainWindow", "no of questions", 0));
        lineEdit_4->setText(QApplication::translate("MainWindow", "60", 0));
        label_3->setText(QApplication::translate("MainWindow", "No of students", 0));
        lineEdit_5->setText(QApplication::translate("MainWindow", "60", 0));
        label_6->setText(QApplication::translate("MainWindow", "question file path", 0));
        lineEdit_8->setText(QApplication::translate("MainWindow", "/home/user/examapp1/question.txt", 0));
        label_4->setText(QApplication::translate("MainWindow", "option's file path", 0));
        lineEdit_6->setText(QApplication::translate("MainWindow", "/home/user/examapp1/options.txt", 0));
        label_5->setText(QApplication::translate("MainWindow", "instruction file path", 0));
        lineEdit_7->setText(QApplication::translate("MainWindow", "/home/user/examapp1/instructions.txt", 0));
        label_7->setText(QApplication::translate("MainWindow", "answers file path", 0));
        lineEdit_9->setText(QApplication::translate("MainWindow", "/home/user/examapp1", 0));
        lineEdit_10->setText(QApplication::translate("MainWindow", "15", 0));
        label_8->setText(QApplication::translate("MainWindow", "instruction time", 0));
        lineEdit_11->setText(QApplication::translate("MainWindow", "5007", 0));
        label_9->setText(QApplication::translate("MainWindow", "port no", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "set exam", 0));
        pushButton_5->setText(QApplication::translate("MainWindow", "verify", 0));
        lineEdit_2->setText(QApplication::translate("MainWindow", "/home/user/examapp1/result_folder", 0));
        lineEdit->setText(QApplication::translate("MainWindow", "/home/user/examapp1/answer_sheet", 0));
        lineEdit_1->setText(QApplication::translate("MainWindow", "answers file", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "load", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "verify tab", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
