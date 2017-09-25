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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAdd_to_base;
    QAction *actionReceive_from_base;
    QAction *actionAdministration;
    QAction *actionDelete_from_base;
    QAction *actionChange_in_base;
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *pushButton_3;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_5;
    QPushButton *pushButton_4;
    QMenuBar *menubar;
    QMenu *menuMenu;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(503, 410);
        QFont font;
        font.setPointSize(15);
        MainWindow->setFont(font);
        actionAdd_to_base = new QAction(MainWindow);
        actionAdd_to_base->setObjectName(QStringLiteral("actionAdd_to_base"));
        actionReceive_from_base = new QAction(MainWindow);
        actionReceive_from_base->setObjectName(QStringLiteral("actionReceive_from_base"));
        actionAdministration = new QAction(MainWindow);
        actionAdministration->setObjectName(QStringLiteral("actionAdministration"));
        actionDelete_from_base = new QAction(MainWindow);
        actionDelete_from_base->setObjectName(QStringLiteral("actionDelete_from_base"));
        actionChange_in_base = new QAction(MainWindow);
        actionChange_in_base->setObjectName(QStringLiteral("actionChange_in_base"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 0, 441, 101));
        QFont font1;
        font1.setPointSize(24);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(170, 300, 151, 61));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(160, 100, 187, 152));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setFont(font);

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        pushButton_5 = new QPushButton(widget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setFont(font);

        verticalLayout->addWidget(pushButton_5);

        pushButton_4 = new QPushButton(widget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        verticalLayout->addWidget(pushButton_4);

        MainWindow->setCentralWidget(centralwidget);
        label->raise();
        pushButton->raise();
        pushButton_2->raise();
        pushButton_3->raise();
        pushButton_4->raise();
        pushButton_5->raise();
        pushButton_2->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 503, 31));
        menuMenu = new QMenu(menubar);
        menuMenu->setObjectName(QStringLiteral("menuMenu"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuMenu->menuAction());
        menuMenu->addAction(actionAdd_to_base);
        menuMenu->addAction(actionReceive_from_base);
        menuMenu->addAction(actionDelete_from_base);
        menuMenu->addAction(actionAdministration);
        menuMenu->addAction(actionChange_in_base);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionAdd_to_base->setText(QApplication::translate("MainWindow", "Add to base", 0));
        actionReceive_from_base->setText(QApplication::translate("MainWindow", "Receive from base", 0));
        actionAdministration->setText(QApplication::translate("MainWindow", "Administration", 0));
        actionDelete_from_base->setText(QApplication::translate("MainWindow", "Delete from base", 0));
        actionChange_in_base->setText(QApplication::translate("MainWindow", "Change in base", 0));
        label->setText(QApplication::translate("MainWindow", "Welcome to Password utility!", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "Asdministration", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Add to base", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "Receive from base", 0));
        pushButton_5->setText(QApplication::translate("MainWindow", "Change in base", 0));
        pushButton_4->setText(QApplication::translate("MainWindow", "Delete from base", 0));
        menuMenu->setTitle(QApplication::translate("MainWindow", "Menu", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
