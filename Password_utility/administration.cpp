#include "administration.h"
#include "Password.h"
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
#include "Config.h"
#include "dialog.h"
#include "ui_dialog.h"
#include "Cipher.h"
#include <QtCore>
#include <QtGui>
#include <QCoreApplication>
#include <QDebug>
#include <iostream>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "administration.h"
#include <QFile>
#include "dialog_for_admin.h"
#include "ui_dialog_for_admin.h"
#include "Password.h"
#include <QString>
#include "dialog_for_admin_1.h"
#include "ui_dialog_for_admin_1.h"
#include "Config.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
#include <stdexcept>
#include <sstream>
#include "Kuznyechik.h"
#include "mycrypto.h"
#include <vector>
#include <string>

QString Administration:: get_path_to_adm_file(){
     QString path(QDir::currentPath());
     int index,counter=0;
     foreach(QChar c, path){
         if ( (c=='/') ||(c=='\\' ) )   {
         index=counter;
         }
         counter+=1;
    }
    QString k = path.mid(0, index+1);
    k=k+"Administration.txt";
    return k;
}

char Administration::to_char(bool parametr){
    char symbol;
      if(parametr==1) {
          symbol='1';
      }else {
          symbol='0';
      }
    return symbol;
}

bool Administration:: to_bool(char symbol){
    bool parametr;
    if(symbol=='0'){
        parametr=0;
    } else{
        parametr=1;
    }
    return parametr;
}

Config Administration::config_read(Config cfg){
    QFile file(Administration::get_path_to_adm_file());
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QList<QByteArray> rows;
    while (!file.atEnd())
        rows.append(file.readLine());
    file.close();
    bool flag;

    for (int counter=4; counter<10; counter++ ){
        flag=Administration::to_bool(rows[counter].data()[rows[counter].size()-2]);
        qDebug()<<flag<<endl;
        switch(counter){
        case 4 :
            cfg.number=flag;
            break;
        case 5 :
            cfg.spec_char=flag;
            break;
        case 6 :
            cfg.small_letter=flag;
            break;
        case 7 :
            cfg.big_letter=flag;
            break;
        case 8 :
            cfg.in_dictionary=flag;
            break;
        case 9 :
            cfg.simple_sequence=flag;
            break;
        }

    }
    return cfg;
}

void Administration::config_output(Config cfg, QString dic ,QString base){
        QFile file(Administration::get_path_to_adm_file());
        QList<QByteArray> rows;
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
            while (!file.atEnd())
            rows.append(file.readLine());
        }
        else{
             QMessageBox::information(0,"Report","Administration file doesn't open. You should contact your administrator.\n");
        }
        file.close();
        dic= "Path to dictionary=" + dic +"\n";        
        base="Path to data base=" + base +"\n";
        rows[1]=dic.toLatin1();
        rows[2]=base.toLatin1();
        bool flag=0;


        for (int counter=4; counter<10; counter++ ){
            switch(counter){
            case 4 :
                flag=cfg.number;
                break;
            case 5 :
                flag=cfg.spec_char;
                break;
            case 6 :
                flag=cfg.small_letter;
                break;
            case 7 :
                flag=cfg.big_letter;
                break;
            case 8 :
                flag=cfg.in_dictionary;
                break;
            case 9 :
                flag=cfg.simple_sequence;
                break;
            }
            rows[counter].data()[rows[counter].size()-2]=Administration:: to_char(flag);
        }


       file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text);
       QByteArray r;
       foreach(r,rows)
           file.write(r);
       file.close();
}

void Administration:: change_admin_pswd(QString pswd){
    QFile file(Administration::get_path_to_adm_file());
    QList<QByteArray> rows;
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
    while (!file.atEnd())
    rows.append(file.readLine());
    }
    else{
         QMessageBox::information(0,"Report","Administration file doesn't open. You should contact your administrator.\n");
    }
    file.close();

    pswd= "Password=" + pswd +"\n";
    for (int counter; counter<rows.length(); counter++ ){
        QString stra=rows[counter];
        QStringList  lst = stra.split("=");
        if ("Password"  == lst[0]){
            rows[counter]=pswd.toLatin1();
            }
    }


    file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text);
    QByteArray r;
    foreach(r,rows)
        file.write(r);
    file.close();
}

QString Administration:: receive_admin_pswd(){
    QString admin_pswd;
    QFile file(Administration::get_path_to_adm_file());
    if(file.open(QIODevice::ReadOnly |QIODevice::Text)){
        while (!file.atEnd()){
            QString line = file.readLine();
            QStringList  lst = line.split("=");
            if ("Password"  == lst[0]){
                admin_pswd=lst[1];
                admin_pswd=admin_pswd.mid(0,admin_pswd.size()-1);
                }
        }
    }
        else
        {
           QMessageBox::information(0,"Report","Administration file doesn't open. You should contact your administrator.\n");
        }
                file.close();
                return admin_pswd;
}

QString Administration::receive_path_to_dictionary(){
    QString path_to_dic;
    QFile file(Administration::get_path_to_adm_file());
    if(file.open(QIODevice::ReadOnly |QIODevice::Text)){
        while (!file.atEnd()){
            QString line = file.readLine();
            QStringList  lst = line.split("=");
            if ("Path to dictionary"  == lst[0]){
                path_to_dic=lst[1];
                path_to_dic=path_to_dic.mid(0,path_to_dic.size()-1);
                }
        }
    }
        else
        {
           QMessageBox::information(0,"Report","Administration file doesn't open. You should contact your administrator.\n");
        }
                file.close();
                return path_to_dic;
}

QString Administration:: receive_path_to_data_base(){
    QString path_to_base;
    QFile file(Administration::get_path_to_adm_file());
    if(file.open(QIODevice::ReadOnly |QIODevice::Text)){
        while (!file.atEnd()){
            QString line = file.readLine();
            QStringList  lst = line.split("=");
            if ("Path to data base"  == lst[0]){
                path_to_base=lst[1];
                path_to_base=path_to_base.mid(0,path_to_base.size()-1);
                }
            }
    }
    else{
        QMessageBox::information(0,"Report","Administration file doesn't open. You should contact your administrator.\n");
        }
    file.close();
    return path_to_base;
}

QString Administration:: receive_key(){
    QString key;
    QFile file(Administration::get_path_to_adm_file());
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
        while (!file.atEnd()){
            QString line = file.readLine();
            QStringList  lst = line.split("=");
            if ("KEY"  == lst[0]){
                key=lst[1];
                key=key.mid(0,key.size()-1);
                }
        }
    }
    else{
         QMessageBox::information(0,"Report","Administration file doesn't open. You should contact your administrator.\n");
    }
    return key;
}

QString Administration:: receive_iv(){
    QString iv;
    QFile file(Administration::get_path_to_adm_file());
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
    while (!file.atEnd()){
                QString line = file.readLine();
                QStringList  lst = line.split("=");
                if ("IV"  == lst[0]){
                    iv=lst[1];
                    iv=iv.mid(0,iv.size()-1);

                }
         }
    }
    else{
         QMessageBox::information(0,"Report","Administration file doesn't open. You should contact your administrator.\n");
    }
    return iv;
}
