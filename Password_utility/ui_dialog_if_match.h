/********************************************************************************
** Form generated from reading UI file 'dialog_if_match.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_IF_MATCH_H
#define UI_DIALOG_IF_MATCH_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog_if_match
{
public:
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QLineEdit *lineEdit_for_service_name;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *lineEdit_for_password;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *lineEdit_for_old_PIN;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QLineEdit *lineEdit_for_new_PIN;

    void setupUi(QDialog *Dialog_if_match)
    {
        if (Dialog_if_match->objectName().isEmpty())
            Dialog_if_match->setObjectName(QStringLiteral("Dialog_if_match"));
        Dialog_if_match->resize(648, 386);
        layoutWidget_2 = new QWidget(Dialog_if_match);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(500, 320, 141, 51));
        horizontalLayout = new QHBoxLayout(layoutWidget_2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_3 = new QPushButton(layoutWidget_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(layoutWidget_2);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        horizontalLayout->addWidget(pushButton_4);

        layoutWidget = new QWidget(Dialog_if_match);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(160, 148, 307, 136));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        QFont font;
        font.setPointSize(15);
        label_3->setFont(font);

        horizontalLayout_5->addWidget(label_3);

        lineEdit_for_service_name = new QLineEdit(layoutWidget);
        lineEdit_for_service_name->setObjectName(QStringLiteral("lineEdit_for_service_name"));

        horizontalLayout_5->addWidget(lineEdit_for_service_name);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        horizontalLayout_4->addWidget(label_4);

        lineEdit_for_password = new QLineEdit(layoutWidget);
        lineEdit_for_password->setObjectName(QStringLiteral("lineEdit_for_password"));

        horizontalLayout_4->addWidget(lineEdit_for_password);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        horizontalLayout_3->addWidget(label_2);

        lineEdit_for_old_PIN = new QLineEdit(layoutWidget);
        lineEdit_for_old_PIN->setObjectName(QStringLiteral("lineEdit_for_old_PIN"));
        lineEdit_for_old_PIN->setEchoMode(QLineEdit::Password);

        horizontalLayout_3->addWidget(lineEdit_for_old_PIN);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);

        horizontalLayout_2->addWidget(label_5);

        lineEdit_for_new_PIN = new QLineEdit(layoutWidget);
        lineEdit_for_new_PIN->setObjectName(QStringLiteral("lineEdit_for_new_PIN"));
        lineEdit_for_new_PIN->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(lineEdit_for_new_PIN);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(Dialog_if_match);
        QObject::connect(pushButton_3, SIGNAL(clicked()), Dialog_if_match, SLOT(close()));
        QObject::connect(pushButton_4, SIGNAL(clicked()), Dialog_if_match, SLOT(close()));

        QMetaObject::connectSlotsByName(Dialog_if_match);
    } // setupUi

    void retranslateUi(QDialog *Dialog_if_match)
    {
        Dialog_if_match->setWindowTitle(QApplication::translate("Dialog_if_match", "Dialog", 0));
        pushButton_3->setText(QApplication::translate("Dialog_if_match", "OK", 0));
        pushButton_4->setText(QApplication::translate("Dialog_if_match", "Cansel", 0));
        label_3->setText(QApplication::translate("Dialog_if_match", "Service:", 0));
        label_4->setText(QApplication::translate("Dialog_if_match", "Password:", 0));
        label_2->setText(QApplication::translate("Dialog_if_match", "Enter  your old  PIN code:", 0));
        label_5->setText(QApplication::translate("Dialog_if_match", "Enter  your  new PIN code:", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog_if_match: public Ui_Dialog_if_match {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_IF_MATCH_H
