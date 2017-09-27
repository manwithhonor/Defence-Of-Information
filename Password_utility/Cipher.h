#ifndef CIPHER_H
#define CIPHER_H

#include <QString>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
#include <stdexcept>
#include <sstream>
#include <iostream>
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

class Cipher
{
private:
    QString str, name;
    QByteArray key;
    QByteArray KeyGen (unsigned long next);
    QByteArray Combinig( QByteArray key, QByteArray ciphered_text);
    vector<string> read_cipher_params( );
    bool  logic_xor3(bool x, bool y, bool z);
    string  hexToString(QString hexdata);
    QString  stringToHex(QString str);


public:
    QByteArray ciphered_text;
    Cipher (QString str0, QString str1 ) {this->str=str0; this->name=str1;}
    QByteArray Ciphering ();
    QString    myDecryption();
    QString  myEncryption();
    ByteBlock keyDeriveFunction(QString stra);
};

#endif //CIPHER_H
