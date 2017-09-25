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
#include "administration.h"

Dialog_for_admin_1::Dialog_for_admin_1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_for_admin_1)
{
    ui->setupUi(this);
    receive_value();
    Config cfg;
    QString path_to_base=Administration:: receive_path_to_data_base();
    QString path_to_dic=Administration:: receive_path_to_dictionary();
    ui->lineEdit_dictionary->setText(path_to_dic);
    ui->lineEdit_base->setText(path_to_base);

}

Dialog_for_admin_1::~Dialog_for_admin_1()
{
    delete ui;
}

Config  Dialog_for_admin_1:: set_value(){
    Config cfg;
    if(ui->checkBox_numbers->isChecked()) {
        cfg.number=1;
    } else{
        cfg.number=0;
    }

    if(ui->checkBox__spec_char->isChecked()) {
         cfg.spec_char=1;
     } else{
         cfg.spec_char=0;
     }

     if(ui->checkBox_small_letters->isChecked()) {
         cfg.small_letter=1;
     } else{
         cfg.small_letter=0;
     }

     if(ui->checkBox_big_letters->isChecked()) {
         cfg.big_letter=1;
     } else{
         cfg.big_letter=0;
     }

     if(ui->checkBox_dictionary->isChecked()) {
         cfg.in_dictionary=1;
     } else{
         cfg.in_dictionary=0;
     }

     if(ui->checkBox_simple_sequence->isChecked()) {
         cfg.simple_sequence=1;
     } else{
         cfg.simple_sequence=0;
     }
     return cfg;
}

void Dialog_for_admin_1:: receive_value(){
    Config cfg;
    cfg= Administration::config_read(cfg);
    if(cfg.number==1){
        ui->checkBox_numbers->setChecked(true);
    }
    else{
        ui->checkBox_numbers->setChecked(false);
    }
    if(cfg.spec_char==1){
        ui->checkBox__spec_char->setChecked(true);
    }
    else{
        ui->checkBox__spec_char->setChecked(false);
    }

    if(cfg.small_letter==1){
        ui->checkBox_small_letters->setChecked(true);
    }
    else{
        ui->checkBox_small_letters->setChecked(false);
    }

    if(cfg.big_letter==1){
        ui->checkBox_big_letters->setChecked(true);
    }
    else{
        ui->checkBox_big_letters->setChecked(false);
    }

    if(cfg.in_dictionary==1){
        ui->checkBox_dictionary->setChecked(true);
    }
    else{
        ui->checkBox_dictionary->setChecked(false);
    }

    if(cfg.simple_sequence==1){
        ui->checkBox_simple_sequence->setChecked(true);
    }
    else{
        ui->checkBox_simple_sequence->setChecked(false);
    }
  }

void Dialog_for_admin_1::on_pushButton_clicked(){
    Config cfg=set_value();
    QString dic(ui->lineEdit_dictionary->text());
    QString base(ui->lineEdit_base->text());
    Administration:: config_output(cfg,dic, base);

    if((ui->lineEdit_old_pswd->text() !="") && (    ui->lineEdit_new_pwsd->text()!="") ){
        if(ui->lineEdit_old_pswd->text()==Administration::receive_admin_pswd()){
            qDebug() << ui->lineEdit_new_pwsd->text();
            Administration::change_admin_pswd( ui->lineEdit_new_pwsd->text());
        }
        else{
            QMessageBox::information(this,"Report","Entered \"old password\" doesn't match with real one.\n");
        }
    }
    QMessageBox::information(this,"Report","Policy was succesfully changed.\n");

}
