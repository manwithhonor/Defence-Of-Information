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

QString Cipher::myEncryption(){
    auto cipher_params = read_cipher_params();
    ByteBlock key = hex_to_bytes(cipher_params[0]);
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
    cout<< result<<endl;
    QString rerer = QString::fromStdString(result);
    return rerer;
}

QString Cipher::myDecryption(){
    auto  cipher_params = read_cipher_params();
    cout<< cipher_params[0]<<endl;
    cout<< cipher_params[1]<<endl;
    cout<< cipher_params[2]<<endl;
    ByteBlock key = hex_to_bytes(cipher_params[0]);
    ByteBlock iv = hex_to_bytes(cipher_params[1]);
    ByteBlock message1 = hex_to_bytes(cipher_params[2]);
    ByteBlock output;
    CFB_Mode<Kuznyechik> encryptor(Kuznyechik(key), iv);
    encryptor.decrypt(message1, output);
    string resup =hex_representation(output);
    QString qstr1 = QString::fromStdString(resup);
    string realResilt = hexToString(qstr1);
    QString truRes = QString::fromStdString(realResilt);
    return truRes;
}

bool Cipher::  logic_xor3(bool x, bool y, bool z) {
    return (!x && !y && z) || (!x && y && !z) || (x && !y && !z);}

