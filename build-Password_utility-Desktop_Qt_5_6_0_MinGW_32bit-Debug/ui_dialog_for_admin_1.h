/********************************************************************************
** Form generated from reading UI file 'dialog_for_admin_1.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_FOR_ADMIN_1_H
#define UI_DIALOG_FOR_ADMIN_1_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog_for_admin_1
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *lineEdit_dictionary;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *lineEdit_base;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QVBoxLayout *verticalLayout;
    QCheckBox *checkBox_numbers;
    QCheckBox *checkBox__spec_char;
    QCheckBox *checkBox_small_letters;
    QCheckBox *checkBox_big_letters;
    QCheckBox *checkBox_dictionary;
    QCheckBox *checkBox_simple_sequence;
    QLabel *label_4;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_5;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_6;
    QLineEdit *lineEdit_old_pswd;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_7;
    QLineEdit *lineEdit_new_pwsd;

    void setupUi(QDialog *Dialog_for_admin_1)
    {
        if (Dialog_for_admin_1->objectName().isEmpty())
            Dialog_for_admin_1->setObjectName(QStringLiteral("Dialog_for_admin_1"));
        Dialog_for_admin_1->resize(608, 446);
        layoutWidget = new QWidget(Dialog_for_admin_1);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(460, 400, 141, 41));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_3->addWidget(pushButton);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_3->addWidget(pushButton_2);

        layoutWidget1 = new QWidget(Dialog_for_admin_1);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 80, 591, 66));
        verticalLayout_3 = new QVBoxLayout(layoutWidget1);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font;
        font.setPointSize(15);
        label_2->setFont(font);

        horizontalLayout->addWidget(label_2);

        lineEdit_dictionary = new QLineEdit(layoutWidget1);
        lineEdit_dictionary->setObjectName(QStringLiteral("lineEdit_dictionary"));

        horizontalLayout->addWidget(lineEdit_dictionary);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        horizontalLayout_2->addWidget(label_3);

        lineEdit_base = new QLineEdit(layoutWidget1);
        lineEdit_base->setObjectName(QStringLiteral("lineEdit_base"));

        horizontalLayout_2->addWidget(lineEdit_base);


        verticalLayout_3->addLayout(horizontalLayout_2);

        layoutWidget_2 = new QWidget(Dialog_for_admin_1);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(10, 170, 205, 195));
        verticalLayout_2 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget_2);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        verticalLayout_2->addWidget(label);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        checkBox_numbers = new QCheckBox(layoutWidget_2);
        checkBox_numbers->setObjectName(QStringLiteral("checkBox_numbers"));

        verticalLayout->addWidget(checkBox_numbers);

        checkBox__spec_char = new QCheckBox(layoutWidget_2);
        checkBox__spec_char->setObjectName(QStringLiteral("checkBox__spec_char"));

        verticalLayout->addWidget(checkBox__spec_char);

        checkBox_small_letters = new QCheckBox(layoutWidget_2);
        checkBox_small_letters->setObjectName(QStringLiteral("checkBox_small_letters"));

        verticalLayout->addWidget(checkBox_small_letters);

        checkBox_big_letters = new QCheckBox(layoutWidget_2);
        checkBox_big_letters->setObjectName(QStringLiteral("checkBox_big_letters"));

        verticalLayout->addWidget(checkBox_big_letters);

        checkBox_dictionary = new QCheckBox(layoutWidget_2);
        checkBox_dictionary->setObjectName(QStringLiteral("checkBox_dictionary"));

        verticalLayout->addWidget(checkBox_dictionary);

        checkBox_simple_sequence = new QCheckBox(layoutWidget_2);
        checkBox_simple_sequence->setObjectName(QStringLiteral("checkBox_simple_sequence"));

        verticalLayout->addWidget(checkBox_simple_sequence);


        verticalLayout_2->addLayout(verticalLayout);

        label_4 = new QLabel(Dialog_for_admin_1);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(190, 10, 331, 51));
        QFont font1;
        font1.setPointSize(18);
        label_4->setFont(font1);
        layoutWidget2 = new QWidget(Dialog_for_admin_1);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(270, 170, 301, 97));
        verticalLayout_5 = new QVBoxLayout(layoutWidget2);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);

        verticalLayout_5->addWidget(label_5);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_6 = new QLabel(layoutWidget2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font);

        horizontalLayout_4->addWidget(label_6);

        lineEdit_old_pswd = new QLineEdit(layoutWidget2);
        lineEdit_old_pswd->setObjectName(QStringLiteral("lineEdit_old_pswd"));

        horizontalLayout_4->addWidget(lineEdit_old_pswd);


        verticalLayout_4->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_7 = new QLabel(layoutWidget2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font);

        horizontalLayout_5->addWidget(label_7);

        lineEdit_new_pwsd = new QLineEdit(layoutWidget2);
        lineEdit_new_pwsd->setObjectName(QStringLiteral("lineEdit_new_pwsd"));

        horizontalLayout_5->addWidget(lineEdit_new_pwsd);


        verticalLayout_4->addLayout(horizontalLayout_5);


        verticalLayout_5->addLayout(verticalLayout_4);


        retranslateUi(Dialog_for_admin_1);
        QObject::connect(pushButton, SIGNAL(clicked()), Dialog_for_admin_1, SLOT(close()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), Dialog_for_admin_1, SLOT(close()));

        QMetaObject::connectSlotsByName(Dialog_for_admin_1);
    } // setupUi

    void retranslateUi(QDialog *Dialog_for_admin_1)
    {
        Dialog_for_admin_1->setWindowTitle(QApplication::translate("Dialog_for_admin_1", "Dialog", 0));
        pushButton->setText(QApplication::translate("Dialog_for_admin_1", "OK", 0));
        pushButton_2->setText(QApplication::translate("Dialog_for_admin_1", "Cansel", 0));
        label_2->setText(QApplication::translate("Dialog_for_admin_1", "Set path to dictionary:", 0));
        label_3->setText(QApplication::translate("Dialog_for_admin_1", "Set path to data base:", 0));
        label->setText(QApplication::translate("Dialog_for_admin_1", "Criteria's for checking:", 0));
        checkBox_numbers->setText(QApplication::translate("Dialog_for_admin_1", "numbers", 0));
        checkBox__spec_char->setText(QApplication::translate("Dialog_for_admin_1", "special symbols", 0));
        checkBox_small_letters->setText(QApplication::translate("Dialog_for_admin_1", "small letters", 0));
        checkBox_big_letters->setText(QApplication::translate("Dialog_for_admin_1", "big letters", 0));
        checkBox_dictionary->setText(QApplication::translate("Dialog_for_admin_1", "dictionary", 0));
        checkBox_simple_sequence->setText(QApplication::translate("Dialog_for_admin_1", "not a simple sequence", 0));
        label_4->setText(QApplication::translate("Dialog_for_admin_1", "Administraion tools.", 0));
        label_5->setText(QApplication::translate("Dialog_for_admin_1", "Changing admin password:", 0));
        label_6->setText(QApplication::translate("Dialog_for_admin_1", "Enter old password:", 0));
        label_7->setText(QApplication::translate("Dialog_for_admin_1", "Enter new password:", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog_for_admin_1: public Ui_Dialog_for_admin_1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_FOR_ADMIN_1_H
