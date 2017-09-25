#include "dialog_for_admin.h"
#include "ui_dialog_for_admin.h"
#include "administration.h"

#include "dialog_for_admin_1.h"
#include "ui_dialog_for_admin_1.h"
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
Dialog_for_admin::Dialog_for_admin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_for_admin)
{
    ui->setupUi(this);
}

Dialog_for_admin::~Dialog_for_admin()
{
    delete ui;
}

void Dialog_for_admin::on_pushButton_clicked(){
      QString password(ui->lineEdit->text());
      QFile file(Administration::get_path_to_adm_file());
      QString pswd;
      if(password==""){
           QMessageBox::information(this,"Report","You forgot to enter password.\n");
      }else{
          pswd=Administration:: receive_admin_pswd();
          if (pswd==password){
              Dialog_for_admin_1 dialog_for_admin_1;
              dialog_for_admin_1.setModal(true);
              dialog_for_admin_1.exec();
          }else{
              QMessageBox::information(this,"Report","Password is not correct. \n");
          };
    file.close();
      }

}
