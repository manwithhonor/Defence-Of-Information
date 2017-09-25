/********************************************************************************
** Form generated from reading UI file 'dialog_for_delete.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_FOR_DELETE_H
#define UI_DIALOG_FOR_DELETE_H

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

class Ui_Dialog_for_delete
{
public:
    QLabel *label_4;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;

    void setupUi(QDialog *Dialog_for_delete)
    {
        if (Dialog_for_delete->objectName().isEmpty())
            Dialog_for_delete->setObjectName(QStringLiteral("Dialog_for_delete"));
        Dialog_for_delete->resize(394, 273);
        label_4 = new QLabel(Dialog_for_delete);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(60, 20, 271, 51));
        QFont font;
        font.setPointSize(18);
        label_4->setFont(font);
        layoutWidget = new QWidget(Dialog_for_delete);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 90, 341, 66));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font1;
        font1.setPointSize(15);
        label->setFont(font1);

        horizontalLayout_2->addWidget(label);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout_2->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font1);

        horizontalLayout_3->addWidget(label_2);

        lineEdit_2 = new QLineEdit(layoutWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setEchoMode(QLineEdit::Password);

        horizontalLayout_3->addWidget(lineEdit_2);


        verticalLayout->addLayout(horizontalLayout_3);

        layoutWidget_2 = new QWidget(Dialog_for_delete);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(250, 220, 141, 51));
        horizontalLayout = new QHBoxLayout(layoutWidget_2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_3 = new QPushButton(layoutWidget_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(layoutWidget_2);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        horizontalLayout->addWidget(pushButton_4);


        retranslateUi(Dialog_for_delete);
        QObject::connect(pushButton_3, SIGNAL(clicked()), Dialog_for_delete, SLOT(close()));
        QObject::connect(pushButton_4, SIGNAL(clicked()), Dialog_for_delete, SLOT(close()));

        QMetaObject::connectSlotsByName(Dialog_for_delete);
    } // setupUi

    void retranslateUi(QDialog *Dialog_for_delete)
    {
        Dialog_for_delete->setWindowTitle(QApplication::translate("Dialog_for_delete", "Dialog", 0));
        label_4->setText(QApplication::translate("Dialog_for_delete", "Deleting from data base.", 0));
        label->setText(QApplication::translate("Dialog_for_delete", "Enter  name of service:", 0));
        label_2->setText(QApplication::translate("Dialog_for_delete", "Enter  your PIN code:", 0));
        pushButton_3->setText(QApplication::translate("Dialog_for_delete", "OK", 0));
        pushButton_4->setText(QApplication::translate("Dialog_for_delete", "Cansel", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog_for_delete: public Ui_Dialog_for_delete {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_FOR_DELETE_H
