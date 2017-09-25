#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include "ui_dialog.h"
#include "dialog_for_admin.h"
#include "ui_dialog_for_admin.h"
#include "dialog2.h"
#include "ui_dialog2.h"
#include <QtCore>
#include <QtGui>
#include <QCoreApplication>
#include <QDebug>
#include <iostream>
#include <QString>
#include <QFile>
#include <QMessageBox>
#include "Cipher.h"
#include <time.h>
#include "Password.h"
#include "Mem_cleaning.h"
#include "Config.h"
#include "administration.h"
#include "dialog_for_delete.h"
#include "ui_dialog_for_delete.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionAdd_to_base_triggered()
{
    Dialog dialog;
dialog.setModal(true);
dialog.exec();
}

void MainWindow::on_actionReceive_from_base_triggered()
{
    Dialog2 dialog2;
dialog2.setModal(true);
dialog2.exec();
}

void MainWindow::on_pushButton_clicked()
{
    Dialog dialog;
dialog.setModal(true);
dialog.exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    Dialog2 dialog2;
dialog2.setModal(true);
dialog2.exec();
}

void MainWindow::on_pushButton_3_clicked()
{
    Dialog_for_admin dialog_for_admin;
dialog_for_admin.setModal(true);
dialog_for_admin.exec();
}

void MainWindow::on_actionAdministration_triggered()
{

    Dialog_for_admin dialog_for_admin;
dialog_for_admin.setModal(true);
dialog_for_admin.exec();
}

void MainWindow::on_pushButton_4_clicked()
{
    Dialog_for_delete dialog_for_delete;
dialog_for_delete.setModal(true);
dialog_for_delete.exec();

}

void MainWindow::on_actionDelete_from_base_triggered()
{
    Dialog_for_delete dialog_for_delete;
dialog_for_delete.setModal(true);
dialog_for_delete.exec();
}

void MainWindow::on_pushButton_5_clicked()
{
    Dialog_if_match dialog_if_match;
dialog_if_match.setModal(true);
dialog_if_match.exec();
}

void MainWindow::on_actionChange_in_base_triggered()
{
    Dialog_if_match dialog_if_match;
dialog_if_match.setModal(true);
dialog_if_match.exec();
}
