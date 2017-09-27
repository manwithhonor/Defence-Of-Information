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
#include "administration.h"
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

using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::getline;
using std::vector;
using std::numeric_limits;


vector<string>   Cipher:: read_cipher_params( ) {
    vector<string> result;      
    QString iv=Administration:: receive_iv();
    string siv = iv.toLocal8Bit().constData();

    QString key=Administration:: receive_key();
    string skey = key.toLocal8Bit().constData();

    QString fert=str;
    string sstr = fert.toLocal8Bit().constData();

    result.push_back(skey);
    result.push_back(siv);
    result.push_back(sstr);
    return result;
}

QString Cipher::  stringToHex(QString str) {
    QString out;
    QByteArray arr;
    for(int counter=0;counter<str.size();counter++){
        arr.append(str[counter].toLatin1());
    }
    if (arr.length() > 0) {
        out = QString("%1").arg(arr[0], 2, 16, QChar('0'));
    }
    for (int i = 1; i < arr.length(); ++i) {
        out.append(QString("%1").arg(arr[i], 2, 16, QChar('0')));
    }
    return out;
}

string Cipher::  hexToString(QString hexdata) {
    int i=2;
    while (i<hexdata.length()){
        hexdata.insert(i,' ');
        i=i+3;
    }
    string text = hexdata.toLocal8Bit().constData();
    std::vector<char> bindata;
    std::istringstream iss(text);
    std::string v;
    string resa;

    while (iss >> v) {
        char h0 = toupper(v[0]);
        char h1 = toupper(v[1]);
        char r = ((h0 - (h0 > '9' ? 'A'- 10 : '0')) << 4) | (h1 - (h1 > '9' ? 'A' - 10 : '0'));
        bindata.push_back(r);
    }

    for (auto e : bindata){
         resa+=e;
    }
    return resa;
}

vector<string> split(const string & s, char ch) {
    vector<string> v;

    string::size_type i = 0;
    string::size_type j = s.find(ch);
    while(j != string::npos) {
        v.push_back(s.substr(i, j-i));
        i = ++j;
        j = s.find(ch, j);

        if(j == string::npos)
            v.push_back(s.substr(i, s.size()-i));
    }
    return v;
}

ByteBlock Cipher::keyDeriveFunction(QString stra){
   //qDebug()<<1;
   //QString str1 = "Test";
   //QByteArray ba = stra.toLatin1();
    // const char *str = ba.data();


  // char *str = new char;
    //str="my_fucking_password";


     //char *a;
   //  memcpy(str,stra.toLatin1(),stra.size());


qDebug()<<"name="<<stra<<"\n";
  const char * str = ( const char *) stra. toLocal8Bit().data();

  // char *str = new char; //данные

//qDebug()<<2;
   HCRYPTPROV hCryptProv = 0;
   HCRYPTHASH hHash = 0;
   //gets(str);
//stra.length();
   DWORD count=strlen(str);
   CryptAcquireContext(&hCryptProv, NULL, NULL, PROV_RSA_SCHANNEL, 0);
   CryptCreateHash(hCryptProv, CALG_SHA, 0, 0, &hHash);
   CryptHashData(hHash, (BYTE*)str, count, 0);
//qDebug()<<3;
   BYTE result0, hash_value[41];
   DWORD dwDataLen = 40;

   CryptGetHashParam(hHash, HP_HASHVAL,hash_value, &dwDataLen, 0);
   cout<<endl;
   //int f=(sizeof(hash_value)/sizeof(BYTE));
   for(int i=0;i<20;i++) {
       printf("%02x",hash_value[i]);
      // result0[i]=hash_value[i];
   }
   ByteBlock result(hash_value, 32);
   cout<<endl;
   auto cipher_params = read_cipher_params();







   /*int* arr = new int[32];// новый массив нужной тебе длины
       for (int i = 0; i < 32; i++)
       {
           arr[i] = hash_value[i];// копирование
       }*/
     //  QString out;
        // for (int i = 1; i < 32; ++i) {
       //out.append(QString("%02x").arg(hash_value[i]));
         //qDebug()<<QString("%02x").arg(hash_value[i]);
         //}
        // qDebug()<<out;
   //return result;
   return hex_to_bytes(cipher_params[0]);
          // string resup= System::Text::Encoding::UTF8->GetString(hash_value, 0, hash_value->Length);
//QString str2 = QString(QByteArray((const char*) hash_value));
//cout<< typename (str2);
        //QString qstr1 = QString::fromStdString(resup);
       //delete[] Arr;// удаление старого

   /*HCRYPTPROV hCryptProv = NULL;

       if(CryptAcquireContext(&hCryptProv, NULL, NULL, PROV_RSA_FULL, CRYPT_VERIFYCONTEXT))
       {
           std::string strToKeyGen = "HELLO";

               HCRYPTHASH hHash=NULL;

               if(CryptCreateHash(hCryptProv,CALG_MD5,0,0,&hHash))
               {
                   if(CryptHashData(hHash,(const BYTE*)strToKeyGen.data(),strToKeyGen.size(),0))
                   {
                       HCRYPTKEY hCryptKey=NULL;
                       if(CryptDeriveKey(hCryptProv,CALG_RC4,hHash, CRYPT_EXPORTABLE|(0x080<<0x10),&hCryptKey))
                       {
                           std::cout <<  hCryptKey << std::endl;
                       }
                   }
                   CryptDestroyHash(hHash);
               }

       }*/
}


QString Cipher::myEncryption(){
    auto cipher_params = read_cipher_params();

   ByteBlock key =keyDeriveFunction(this->name);
   //  ByteBlock key =hex_to_bytes(cipher_params[0]);

    ByteBlock iv = hex_to_bytes(cipher_params[1]);
    string fe=cipher_params[2];
    QString qstr = QString::fromStdString(fe);
    QString out=  stringToHex(qstr);
    string text = out.toLocal8Bit().constData();
    const string b=text;
    ByteBlock message = hex_to_bytes(b);
    ByteBlock output;
    CFB_Mode<Kuznyechik> encryptor(Kuznyechik(key), iv);
    encryptor.encrypt(message, output);   
    string result =hex_representation(output);
    cout<<"res="<< result<<endl;
    QString rerer = QString::fromStdString(result);
    return rerer;
}

QString Cipher::myDecryption(){
    auto  cipher_params = read_cipher_params();
   // cout<< cipher_params[0]<<endl;
   // cout<< cipher_params[1]<<endl;
   // cout<< cipher_params[2]<<endl;
cout<<"text="<< cipher_params[2]<<endl;
     ByteBlock key =keyDeriveFunction(this->name);
    //ByteBlock key = hex_to_bytes(cipher_params[0]);

    ByteBlock iv = hex_to_bytes(cipher_params[1]);
    ByteBlock message1 = hex_to_bytes(cipher_params[2]);
    ByteBlock output;
    CFB_Mode<Kuznyechik> encryptor(Kuznyechik(key), iv);
    encryptor.decrypt(message1, output);
    string resup =hex_representation(output);
    cout<<"out="<<resup;
    QString qstr1 = QString::fromStdString(resup);
    string realResilt = hexToString(qstr1);
    QString truRes = QString::fromStdString(realResilt);
    return truRes;
}

bool Cipher::  logic_xor3(bool x, bool y, bool z) {
    return (!x && !y && z) || (!x && y && !z) || (x && !y && !z);}

