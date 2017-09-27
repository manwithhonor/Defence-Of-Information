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
#include "dialog_if_match.h"
#include "ui_dialog_if_match.h"
#include "dialog2.h"
#include "ui_dialog2.h"


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this); 
}

Dialog::~Dialog()
{
    delete ui;
}



void Dialog::onButtonSend()
{
   emit sendData(ui->lineEdit_for_service_name->text(),ui->lineEdit_for_password->text(),ui->lineEdit_for_PIN->text());
}


void output_to_data_base(QString pswd,QString service_name){

    QByteArray password = pswd.toLocal8Bit();
    QFile file(Administration::receive_path_to_data_base());




    QList<QByteArray> rows;
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
        while (!file.atEnd())
            rows.append(file.readLine());
    }else{
        QMessageBox::information(0,"Report","Administration file doesn't open. You should contact your administrator.\n");
    }
    file.close();

    password= service_name.toLatin1() +" "+ password +"\n";
    rows.append(password);
    file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text);
    QByteArray r;
    foreach(r,rows)
        file.write(r);
    file.close();
}

void Dialog::on_pushButton_clicked(){
    QString password(ui->lineEdit_for_password->text());
    QString service_name(ui->lineEdit_for_service_name->text());
    unsigned long PIN=ui->lineEdit_for_PIN->text().toULong();
    Password pswd;
    if(service_name==""){
        QMessageBox::information(this,"Report","You forgot to enter service name.\n");
    }else{
        if(pswd.in_data_base_search(service_name)==""){
            if(password==""){
                 QMessageBox::information(this,"Report","You forgot to enter password.\n");}
            else{
                if(PIN=='\0'){
                     QMessageBox::information(this,"Report","You forgot to enter PIN.\n");}
                 else{
                        Config cfg;
                        cfg=  pswd.check_all(password, cfg);
                        if (cfg.policy){
                   // if (1)
                           password=password+" "+service_name;
                            Cipher  str1= Cipher(password,service_name+PIN);
                            output_to_data_base(str1.myEncryption(),service_name);
                        }
                     }
            }
        }
        else{
            QMessageBox::StandardButton   reply = QMessageBox::information(this,"Report","Password already exist in data base for this service.\nIf you want to replace password to a new one, just click Yes", QMessageBox::Yes|QMessageBox::No);
            if (reply == QMessageBox::Yes) {
                dialog_if_match = new Dialog_if_match();
                connect(this, SIGNAL( trigger_my()), dialog_if_match, SLOT(show()));
                connect(this, SIGNAL( trigger_my()), this, SLOT(onButtonSend()));
                connect(this, SIGNAL(sendData(QString,QString,QString)), dialog_if_match, SLOT(recieveData(QString,QString,QString)));
                emit  trigger_my();
            } else {
                this->close();
            }
        }
    }
    this->close();
}
