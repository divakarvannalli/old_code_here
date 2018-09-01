/********************************************************************************
** Form generated from reading UI file 'form.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_H
#define UI_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QLabel *label;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_5;
    QLineEdit *lineEdit_3;
    QLabel *label_6;
    QLineEdit *lineEdit_4;
    QLabel *label_4;
    QLineEdit *lineEdit_5;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QLabel *label_9;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_7;
    QLineEdit *lineEdit_6;
    QLabel *label_8;
    QLineEdit *lineEdit_7;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("Form"));
        Form->setEnabled(true);
        Form->resize(1125, 1694);
        QPalette palette;
        QBrush brush(QColor(85, 85, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        Form->setPalette(palette);
        Form->setMouseTracking(true);
        Form->setFocusPolicy(Qt::ClickFocus);
        Form->setAutoFillBackground(true);
        label = new QLabel(Form);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(440, 220, 151, 31));
        QPalette palette1;
        QBrush brush2(QColor(255, 0, 127, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        QBrush brush3(QColor(159, 158, 158, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        label->setPalette(palette1);
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        font.setItalic(false);
        font.setUnderline(false);
        font.setWeight(75);
        font.setStrikeOut(false);
        font.setKerning(true);
        label->setFont(font);
        label->setFrameShadow(QFrame::Sunken);
        label->setTextFormat(Qt::AutoText);
        layoutWidget = new QWidget(Form);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(330, 260, 371, 309));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout->addWidget(label_5);

        lineEdit_3 = new QLineEdit(layoutWidget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        verticalLayout->addWidget(lineEdit_3);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout->addWidget(label_6);

        lineEdit_4 = new QLineEdit(layoutWidget);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));

        verticalLayout->addWidget(lineEdit_4);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout->addWidget(label_4);

        lineEdit_5 = new QLineEdit(layoutWidget);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));

        verticalLayout->addWidget(lineEdit_5);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        lineEdit_2 = new QLineEdit(layoutWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        QFont font1;
        font1.setStyleStrategy(QFont::PreferAntialias);
        lineEdit_2->setFont(font1);

        verticalLayout->addWidget(lineEdit_2);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setAcceptDrops(true);
        lineEdit->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(lineEdit);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        label_9 = new QLabel(Form);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(840, 230, 101, 17));
        QFont font2;
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setWeight(75);
        label_9->setFont(font2);
        widget = new QWidget(Form);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(770, 260, 271, 108));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(widget);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout_2->addWidget(label_7);

        lineEdit_6 = new QLineEdit(widget);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));

        verticalLayout_2->addWidget(lineEdit_6);

        label_8 = new QLabel(widget);
        label_8->setObjectName(QStringLiteral("label_8"));

        verticalLayout_2->addWidget(label_8);

        lineEdit_7 = new QLineEdit(widget);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));

        verticalLayout_2->addWidget(lineEdit_7);

        layoutWidget->raise();
        label->raise();
        lineEdit_6->raise();
        lineEdit_7->raise();
        label_7->raise();
        label_8->raise();
        label_9->raise();
#ifndef QT_NO_SHORTCUT
#endif // QT_NO_SHORTCUT

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", 0));
        label->setText(QApplication::translate("Form", "LOGIN HERE", 0));
        label_5->setText(QApplication::translate("Form", "NAME", 0));
        lineEdit_3->setText(QApplication::translate("Form", "DIVAKAR NAIK", 0));
        label_6->setText(QApplication::translate("Form", "USN NO", 0));
        lineEdit_4->setText(QApplication::translate("Form", "1SK10EC020", 0));
        label_4->setText(QApplication::translate("Form", "MAIL ID", 0));
        lineEdit_5->setText(QApplication::translate("Form", "divakarnaik.100@gmail.com", 0));
        label_2->setText(QApplication::translate("Form", "APP USERNAME", 0));
        lineEdit_2->setText(QApplication::translate("Form", "divakar", 0));
        label_3->setText(QApplication::translate("Form", "APP PASSWORD", 0));
        lineEdit->setText(QApplication::translate("Form", "123", 0));
        pushButton->setText(QApplication::translate("Form", "login", 0));
        label_9->setText(QApplication::translate("Form", " IP SETUP", 0));
        label_7->setText(QApplication::translate("Form", "   ip address", 0));
        lineEdit_6->setText(QApplication::translate("Form", "10.20.119.70", 0));
        label_8->setText(QApplication::translate("Form", " port number", 0));
        lineEdit_7->setText(QApplication::translate("Form", "5007", 0));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H
