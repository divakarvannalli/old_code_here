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
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTextEdit *textEdit_3;
    QLCDNumber *lcdNumber;
    QTextEdit *textEdit;
    QLabel *label;
    QLabel *label_3;
    QPushButton *pushButton;
    QLabel *label_2;
    QTextEdit *textEdit_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLabel *label_4;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButton_1;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QLCDNumber *lcdNumber_2;
    QPushButton *pushButton_4;
    QMenuBar *menuBar;
    QMenu *menuEXAM;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1189, 1003);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        MainWindow->setPalette(palette);
        MainWindow->setAutoFillBackground(true);
        MainWindow->setIconSize(QSize(24, 22));
        MainWindow->setTabShape(QTabWidget::Rounded);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        textEdit_3 = new QTextEdit(centralWidget);
        textEdit_3->setObjectName(QStringLiteral("textEdit_3"));
        textEdit_3->setGeometry(QRect(60, 30, 1101, 831));
        QPalette palette1;
        QBrush brush1(QColor(255, 170, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush);
        textEdit_3->setPalette(palette1);
        QFont font;
        font.setPointSize(16);
        textEdit_3->setFont(font);
        textEdit_3->setReadOnly(true);
        lcdNumber = new QLCDNumber(centralWidget);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(830, 80, 151, 70));
        QPalette palette2;
        QBrush brush2(QColor(85, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        lcdNumber->setPalette(palette2);
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        lcdNumber->setFont(font1);
        lcdNumber->setFrameShape(QFrame::Box);
        lcdNumber->setFrameShadow(QFrame::Raised);
        lcdNumber->setLineWidth(3);
        lcdNumber->setMidLineWidth(0);
        lcdNumber->setSmallDecimalPoint(false);
        lcdNumber->setSegmentStyle(QLCDNumber::Filled);
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(280, 200, 881, 121));
        QPalette palette3;
        QBrush brush3(QColor(170, 85, 255, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush3);
        QBrush brush4(QColor(0, 255, 127, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush3);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush4);
        QBrush brush5(QColor(159, 158, 158, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush5);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush4);
        textEdit->setPalette(palette3);
        QFont font2;
        font2.setFamily(QStringLiteral("Ubuntu"));
        font2.setPointSize(16);
        font2.setBold(true);
        font2.setWeight(75);
        font2.setKerning(false);
        font2.setStyleStrategy(QFont::PreferDefault);
        textEdit->setFont(font2);
        textEdit->setFocusPolicy(Qt::WheelFocus);
        textEdit->setFrameShape(QFrame::Box);
        textEdit->setFrameShadow(QFrame::Plain);
        textEdit->setLineWidth(3);
        textEdit->setReadOnly(true);
        textEdit->setTextInteractionFlags(Qt::NoTextInteraction);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 30, 231, 21));
        QFont font3;
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setItalic(false);
        font3.setUnderline(true);
        font3.setWeight(75);
        label->setFont(font3);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(280, 350, 381, 31));
        QFont font4;
        font4.setPointSize(12);
        font4.setBold(true);
        font4.setUnderline(true);
        font4.setWeight(75);
        font4.setStrikeOut(false);
        label_3->setFont(font4);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(530, 900, 151, 31));
        QFont font5;
        font5.setPointSize(16);
        font5.setBold(true);
        font5.setWeight(75);
        pushButton->setFont(font5);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(910, 30, 171, 51));
        QFont font6;
        font6.setPointSize(12);
        font6.setBold(true);
        font6.setUnderline(true);
        font6.setWeight(75);
        label_2->setFont(font6);
        textEdit_2 = new QTextEdit(centralWidget);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));
        textEdit_2->setGeometry(QRect(30, 60, 211, 821));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush);
        palette4.setBrush(QPalette::Active, QPalette::Light, brush);
        palette4.setBrush(QPalette::Active, QPalette::Midlight, brush);
        QBrush brush6(QColor(0, 0, 127, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::Dark, brush6);
        QBrush brush7(QColor(0, 0, 170, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::Mid, brush7);
        QBrush brush8(QColor(0, 0, 0, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush8);
        palette4.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush8);
        QBrush brush9(QColor(255, 85, 255, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush9);
        QBrush brush10(QColor(255, 85, 0, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush10);
        QBrush brush11(QColor(255, 255, 127, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::Shadow, brush11);
        QBrush brush12(QColor(85, 170, 0, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::AlternateBase, brush12);
        QBrush brush13(QColor(255, 0, 255, 255));
        brush13.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::NoRole, brush13);
        palette4.setBrush(QPalette::Active, QPalette::ToolTipText, brush8);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Dark, brush6);
        palette4.setBrush(QPalette::Inactive, QPalette::Mid, brush7);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush8);
        palette4.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush8);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush9);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush10);
        palette4.setBrush(QPalette::Inactive, QPalette::Shadow, brush11);
        palette4.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush12);
        palette4.setBrush(QPalette::Inactive, QPalette::NoRole, brush13);
        palette4.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush8);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Light, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Dark, brush6);
        palette4.setBrush(QPalette::Disabled, QPalette::Mid, brush7);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette4.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush10);
        palette4.setBrush(QPalette::Disabled, QPalette::Shadow, brush11);
        palette4.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush12);
        palette4.setBrush(QPalette::Disabled, QPalette::NoRole, brush13);
        palette4.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush8);
        textEdit_2->setPalette(palette4);
        textEdit_2->setFont(font1);
        textEdit_2->setReadOnly(true);
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(530, 900, 171, 41));
        pushButton_2->setFont(font5);
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(1030, 900, 161, 41));
        pushButton_3->setFont(font5);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(280, 160, 181, 41));
        label_4->setFont(font6);
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(280, 390, 361, 251));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        radioButton_1 = new QRadioButton(layoutWidget);
        radioButton_1->setObjectName(QStringLiteral("radioButton_1"));
        radioButton_1->setFont(font5);
        radioButton_1->setAutoFillBackground(true);

        verticalLayout->addWidget(radioButton_1);

        radioButton_2 = new QRadioButton(layoutWidget);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        QFont font7;
        font7.setPointSize(16);
        font7.setBold(true);
        font7.setWeight(75);
        font7.setStyleStrategy(QFont::PreferDefault);
        radioButton_2->setFont(font7);
        radioButton_2->setCursor(QCursor(Qt::ArrowCursor));

        verticalLayout->addWidget(radioButton_2);

        radioButton_3 = new QRadioButton(layoutWidget);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));
        radioButton_3->setFont(font5);

        verticalLayout->addWidget(radioButton_3);

        radioButton_4 = new QRadioButton(layoutWidget);
        radioButton_4->setObjectName(QStringLiteral("radioButton_4"));
        radioButton_4->setFont(font5);
        radioButton_4->setAutoFillBackground(false);

        verticalLayout->addWidget(radioButton_4);

        lcdNumber_2 = new QLCDNumber(centralWidget);
        lcdNumber_2->setObjectName(QStringLiteral("lcdNumber_2"));
        lcdNumber_2->setGeometry(QRect(990, 100, 71, 51));
        QFont font8;
        font8.setPointSize(11);
        lcdNumber_2->setFont(font8);
        lcdNumber_2->setCursor(QCursor(Qt::ArrowCursor));
        lcdNumber_2->setContextMenuPolicy(Qt::DefaultContextMenu);
        lcdNumber_2->setFrameShadow(QFrame::Raised);
        lcdNumber_2->setLineWidth(3);
        lcdNumber_2->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber_2->setProperty("value", QVariant(0));
        lcdNumber_2->setProperty("intValue", QVariant(0));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(50, 900, 161, 41));
        pushButton_4->setFont(font5);
        MainWindow->setCentralWidget(centralWidget);
        layoutWidget->raise();
        textEdit_3->raise();
        textEdit->raise();
        label_3->raise();
        pushButton->raise();
        label->raise();
        label_4->raise();
        label_2->raise();
        lcdNumber->raise();
        textEdit_2->raise();
        pushButton_2->raise();
        pushButton_3->raise();
        lcdNumber_2->raise();
        pushButton_4->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1189, 25));
        menuEXAM = new QMenu(menuBar);
        menuEXAM->setObjectName(QStringLiteral("menuEXAM"));
        QPalette palette5;
        QBrush brush14(QColor(255, 170, 0, 255));
        brush14.setStyle(Qt::SolidPattern);
        palette5.setBrush(QPalette::Active, QPalette::Base, brush14);
        QBrush brush15(QColor(85, 255, 127, 255));
        brush15.setStyle(Qt::SolidPattern);
        palette5.setBrush(QPalette::Active, QPalette::Window, brush15);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush14);
        palette5.setBrush(QPalette::Inactive, QPalette::Window, brush15);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush15);
        palette5.setBrush(QPalette::Disabled, QPalette::Window, brush15);
        menuEXAM->setPalette(palette5);
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(pushButton, radioButton_3);
        QWidget::setTabOrder(radioButton_3, textEdit_3);
        QWidget::setTabOrder(textEdit_3, textEdit);
        QWidget::setTabOrder(textEdit, radioButton_2);

        menuBar->addAction(menuEXAM->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        textEdit_3->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:16pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:11pt;\"><br /></p></body></html>", 0));
#ifndef QT_NO_STATUSTIP
        lcdNumber->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        textEdit->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:16pt; font-weight:600; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:11pt; font-weight:400;\"><br /></p></body></html>", 0));
        textEdit->setPlaceholderText(QString());
        label->setText(QApplication::translate("MainWindow", "SELECT THE QUESTION HERE", 0));
        label_3->setText(QApplication::translate("MainWindow", "SELECT THE ANSWER HERE", 0));
        pushButton->setText(QApplication::translate("MainWindow", "NEXT", 0));
        label_2->setText(QApplication::translate("MainWindow", "REMAINING TIME", 0));
        textEdit_2->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:600; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:400;\"><br /></p></body></html>", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "submit", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "exit", 0));
        label_4->setText(QApplication::translate("MainWindow", "QUESTION", 0));
        radioButton_1->setText(QString());
        radioButton_2->setText(QString());
        radioButton_3->setText(QString());
        radioButton_4->setText(QString());
#ifndef QT_NO_TOOLTIP
        lcdNumber_2->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_4->setText(QApplication::translate("MainWindow", "next", 0));
        menuEXAM->setTitle(QApplication::translate("MainWindow", "EXAM", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
