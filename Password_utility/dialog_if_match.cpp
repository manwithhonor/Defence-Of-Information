#include "dialog_if_match.h"
#include "ui_dialog_if_match.h"
#include "dialog.h"
#include "ui_dialog.h"
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

Dialog_if_match::Dialog_if_match(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_if_match)
{
    ui->setupUi(this);
}

Dialog_if_match::~Dialog_if_match()
{
    delete ui;
}

void Dialog_if_match::recieveData(QString str,QString str1,QString str2)
{   ui->lineEdit_for_service_name->setText(str);
    ui->lineEdit_for_password->setText(str1);
    ui->lineEdit_for_old_PIN->setText(str2);
}

void Dialog_if_match::on_pushButton_3_clicked(){
    QString new_password(ui->lineEdit_for_password->text());
    QByteArray old_password;
    QString service_name(ui->lineEdit_for_service_name->text());
    unsigned long old_PIN=ui->lineEdit_for_old_PIN->text().toULong();
    unsigned long new_PIN=ui->lineEdit_for_new_PIN->text().toULong();
    Password pswd;
    if(service_name==""){
        QMessageBox::information(this,"Report","You forgot to enter service name.\n");
    }else{
        old_password=pswd.in_data_base_search(service_name);
        if(old_password!=""){
            if(new_password==""){
                QMessageBox::information(this,"Report","You forgot to enter password.\n");
            }else{
                if(old_PIN=='\0'){
                    QMessageBox::information(this,"Report","You forgot to enter old PIN.\n");
                }else{
                    if(new_PIN=='\0'){
                        QMessageBox::information(this,"Report","You forgot to enter new PIN.\n");
                    }else{
                        old_password=old_password.mid(0,old_password.size()-1);
                        Cipher  str1= Cipher(old_password,service_name+old_PIN);
                        QByteArray h = str1.myDecryption().toLocal8Bit();
                        QList<QByteArray> lst =  h.split(' ');
                        if(lst.count()>=2){
                            if(lst[1]==service_name){
                                 Config cfg;
                                cfg=  pswd.check_all(new_password, cfg);
                                if (cfg.policy){
                                //if (1){
                                    new_password=new_password+" "+service_name;
                                    str1= Cipher(new_password.toLatin1(),service_name+new_PIN);
                                    h=str1.myEncryption().toLocal8Bit();
                                    pswd.replace_in_data_base(service_name,  h);
                                    QMessageBox::information(this,"Report","Your password was succesfully replaced");
                                }
                            }else{
                                QMessageBox::information(this,"Report","Your password wasn't found or entered service's name is wrong.");
                            }
                        }else{
                            QMessageBox::information(this,"Report","Entered PIN is not correct.");
                        }
                    }
               }
           }
       }else{
            QMessageBox::information(this,"Report","Your service wasn't found.");
        }
    }
}
