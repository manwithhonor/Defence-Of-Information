/********************************************************************************
** Form generated from reading UI file 'dialog_for_admin.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_FOR_ADMIN_H
#define UI_DIALOG_FOR_ADMIN_H

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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog_for_admin
{
public:
    QLabel *label_4;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Dialog_for_admin)
    {
        if (Dialog_for_admin->objectName().isEmpty())
            Dialog_for_admin->setObjectName(QStringLiteral("Dialog_for_admin"));
        Dialog_for_admin->resize(383, 210);
        label_4 = new QLabel(Dialog_for_admin);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(40, 10, 331, 51));
        QFont font;
        font.setPointSize(18);
        label_4->setFont(font);
        layoutWidget = new QWidget(Dialog_for_admin);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(60, 70, 264, 29));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font1;
        font1.setPointSize(15);
        label->setFont(font1);

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        layoutWidget1 = new QWidget(Dialog_for_admin);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(250, 150, 131, 51));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(layoutWidget1);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_2->addWidget(pushButton);

        pushButton_2 = new QPushButton(layoutWidget1);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_2->addWidget(pushButton_2);


        retranslateUi(Dialog_for_admin);
        QObject::connect(pushButton_2, SIGNAL(clicked()), Dialog_for_admin, SLOT(close()));

        QMetaObject::connectSlotsByName(Dialog_for_admin);
    } // setupUi

    void retranslateUi(QDialog *Dialog_for_admin)
    {
        Dialog_for_admin->setWindowTitle(QApplication::translate("Dialog_for_admin", "Dialog", 0));
        label_4->setText(QApplication::translate("Dialog_for_admin", "Access to administraion tools.", 0));
        label->setText(QApplication::translate("Dialog_for_admin", "Enter password:", 0));
        pushButton->setText(QApplication::translate("Dialog_for_admin", "OK", 0));
        pushButton_2->setText(QApplication::translate("Dialog_for_admin", "Cancell", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog_for_admin: public Ui_Dialog_for_admin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_FOR_ADMIN_H
