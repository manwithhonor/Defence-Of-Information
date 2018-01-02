#include "dialog_for_delete.h"
#include "ui_dialog_for_delete.h"
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
Dialog_for_delete::Dialog_for_delete(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_for_delete)
{
    ui->setupUi(this);
}

Dialog_for_delete::~Dialog_for_delete()
{
    delete ui;
}

void Dialog_for_delete::on_pushButton_3_clicked(){
    QString service_name(ui->lineEdit->text());
    QByteArray password;
    Password pswd;
    unsigned long PIN=ui->lineEdit_2->text().toULong();

    if(service_name==""){
          QMessageBox::information(this,"Report","You forgot to enter service name.\n");}
     else{
        if(PIN=='\0'){
            QMessageBox::information(this,"Report","You forgot to enter PIN.\n");
        }else{
            password=pswd.in_data_base_search(service_name);
            if (password!="") {
                password=password.mid(0,password.size()-1);
                Cipher  str1= Cipher(password, service_name+PIN);
                QString h = str1.myDecryption();
                QStringList lst =  h.split('_');
                if(lst.count()>=2){
                   if( (lst[1]==service_name) || (lst[2].split(" ")[0].toInt()   ==PIN) ){
                        pswd.from_data_base_delete(service_name);
                        QMessageBox::information(this,"Report","Your password was succesfully delete");
                    }else{
                        QMessageBox::information(this,"Report","Your password wasn't found or entered service's name is wrong.");
                    }
                }else{
                    QMessageBox::information(this,"Report","Entered data is not correct.");
                }
            }else{
                QMessageBox::information(this,"Report","Your password wasn't found or entered service's name is wrong.");
            }
        }
    }
}
