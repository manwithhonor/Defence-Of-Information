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
#include "administration.h"

int Password::  my_hash(QString str)
{
   int counter,sum=0;

   for(counter=0;counter<str.size();counter++){
       int value=static_cast<int>(str.data()[counter].toLatin1());
       sum+=value;
   }
   return sum;
}

bool Password:: rabbin_carp(QString str,Config cfg){
    QString  keyboard("qwertyuiop[]][poiuytrewqasdfghjkl;'\\';lkjhgfdsazxcvbnm,.//.,mnbvcxzQWERTYUIOP[]][POIUYTREWQASDFGHJKL;'\\';LKJHGFDSAZXCVBNM,.//.,MNBVCXZ");
    QString strt;
    int hash,hash0,counter;
    int difference=keyboard.size()-str.size();


    hash0= my_hash(str);
    strt= keyboard.mid(0,str.size());
    hash= my_hash(strt);

    for(counter=0;counter<=difference;counter++)
    {
        if(hash==hash0)
        {   strt= keyboard.mid(0,str.size());
            if(strt==str)
            {
                cfg.simple_sequence=1;
                break;
            }
        }        
        hash-=keyboard.data()[0].toLatin1();
        keyboard= keyboard.mid(1);
        hash+=keyboard.data()[str.size()-1].toLatin1();
    }
    return cfg.simple_sequence;
}

void Password::replace_in_data_base(QString service_name, QByteArray password){
    QFile file(Administration:: receive_path_to_data_base());
    QList<QByteArray> rows;
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
        while (!file.atEnd())
            rows.append(file.readLine());
    }
    else{
        QMessageBox::information(0,"Report","Administration file doesn't open. You should contact your administrator.\n");
    }
    file.close();

    for(int counter=0;counter<=rows.size()-1;counter++){
        QList<QByteArray> lst =  rows[counter].split(' ');
        if(service_name==lst[0]){           
            password= service_name.toLatin1() +" "+ password +"\n";
            rows[counter]=password;
        }
    }
   file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text);
   QByteArray r;
   foreach(r,rows)
       file.write(r);
   file.close();
}

void Password:: from_data_base_delete(QString service_name){
    QFile file(Administration::receive_path_to_data_base());
    QList<QByteArray> rows;
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
        while (!file.atEnd())
            rows.append(file.readLine());
    }
    else{
         QMessageBox::information(0,"Report","Administration file doesn't open. You should contact your administrator.\n");
    }
    file.close();

    for(int counter=0;counter<=rows.size()-1;counter++){
        QList<QByteArray> lst =  rows[counter].split(' ');
        if(service_name==lst[0]){
            int counter2=counter;
            for(counter2;counter2<=rows.size()-2;counter2++){
                rows[counter2]=rows[counter2+1];}
           rows[rows.size()-1]="";
        }
    }
   file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text);
    QByteArray r;
    foreach(r,rows)
        file.write(r);
    file.close();
}

QByteArray Password::in_data_base_search(QString service_name){
     QByteArray  password, pswd, name;
     QFile file(Administration::receive_path_to_data_base());
     if(file.open(QIODevice::ReadOnly |QIODevice::Text)){
         while(!file.atEnd()){
             QByteArray line = file.readLine();
             QList<QByteArray> lst = line.split(' ');
             name=lst[0];
             pswd=lst[1];
             if (name==service_name){
                 password=pswd;
             };
         }
     }else{
         QMessageBox::information(0,"Report","Data file doesn't open. You should contact your administrator.\n");
     }
     file.close();
     return password;
}

bool Password:: check_number (QString str, Config cfg)
{
   for(int counter=0;counter<str.size();counter++)
    { int ascii=static_cast<int>(str.data()[counter].toLatin1());
        if (( (ascii-48) >=0 ) && ((ascii-48)  <=9)) {cfg.number=1;};
    }
   return cfg.number;
}

bool Password:: check_small_letter (QString str, Config cfg){
    for(int counter=0;counter<str.size();counter++){
        int ascii=static_cast<int>(str.data()[counter].toLatin1());
        if  ((ascii>=97 ) && (ascii <=122))  {cfg.small_letter=1;};
    }
    return cfg.small_letter;
}

bool Password:: check_big_letter (QString str, Config cfg){
    for(int counter=0;counter<str.size();counter++){
        int ascii=static_cast<int>(str.data()[counter].toLatin1());
        if  (( ascii >=65 ) && (ascii <=90))  {cfg.big_letter=1;};
    }
    return cfg.big_letter;
}

bool Password:: check_spec_char (QString str, Config cfg){
    for(int counter=0;counter<str.size();counter++){
        int ascii=static_cast<int>(str.data()[counter].toLatin1());
        if  ( !((((ascii-48) >=0 ) && ((ascii-48)  <=9)) ||
            (( ascii >=97 ) && (ascii <=122))   ||
            (( ascii>=65 ) && (ascii <=90))))  {cfg.spec_char=1;};
     }
   return cfg.spec_char;
}

bool Password:: check_simple_sequence (QString str, Config cfg){
    int right=0,back=0;
    int previous_ch=static_cast<int>(str.data()[0].toLatin1());
    for(int counter=1;counter<str.size();counter++){
        int ascii=static_cast<int>(str.data()[counter].toLatin1());
        if (  ascii==(previous_ch + 1) ) {right++;};
        if (  ascii==(previous_ch - 1) ) {back++;};
        previous_ch=ascii;
    }
    if ( (right==str.size()-1) || (back==str.size()-1 ) ) { return cfg.simple_sequence=1;}
    return rabbin_carp(str,cfg);
}

bool Password:: check_in_dictionary(QString str, Config cfg){
    QFile file(Administration:: receive_path_to_dictionary());
    if(file.open(QIODevice::ReadOnly |QIODevice::Text)){
        while(!file.atEnd()){
            QString line = file.readLine();
            line=line.mid(0,line.size()-1);
            if (line==str){cfg.in_dictionary=1;};
        }
    }else{
        QMessageBox::information(0,"Report","Dictionary file doesn't open. You should contact your administrator.\n");
    }
    file.close();
    return cfg.in_dictionary;
}

bool Password:: check_policy(Config cfg){
    Config cfg0= Administration::config_read(cfg0);
    QString out_message, control;
    out_message="Your password doesn't satisfy all of the requirements. It should:\n";
    control=out_message;
    cfg.policy=1;
    if (cfg0.number==1){
        if(cfg.number==0){
            out_message=out_message+"contain numbers,\n";
        }
    }
    if (cfg0.spec_char==1){
        if(cfg.spec_char==0){
            out_message=out_message+"contain special char,\n";
        }
    }
    if (cfg0.small_letter==1){
        if(cfg.small_letter==0){
            out_message=out_message+"contain small letter,\n";
        }
    }
    if (cfg0.big_letter==1){
        if(cfg.big_letter==0){
            out_message=out_message+"contain big letter,\n";
        }
    }
    if (cfg0.in_dictionary==1){
        if(cfg.in_dictionary==0){
            out_message=out_message+"be in dictionary,\n";
        }
    }
    if (cfg0.simple_sequence==1){
        if(cfg.simple_sequence==0){
            out_message=out_message+" not be a simple_sequence,\n";
        }
    }

    if(control==out_message){
        QMessageBox::information(0,"Report","Your password satisfies all of the requirements\n");
        return cfg.policy=1;
    }
    else{
        QMessageBox::information(0,"Report", out_message);
        return cfg.policy=0;
    } 
}

Config Password:: check_all(QString str , Config cfg){

    Password pswd;

    cfg.number= pswd.check_number(str, cfg);
    cfg.spec_char= pswd.check_spec_char(str, cfg);
    cfg.small_letter= pswd.check_small_letter(str, cfg);
    cfg.big_letter = pswd.check_big_letter(str, cfg);
    cfg.in_dictionary = pswd.check_in_dictionary(str, cfg);
    cfg.simple_sequence = pswd.check_simple_sequence(str, cfg);
    cfg.policy = pswd.check_policy(cfg);

    return cfg;
}
