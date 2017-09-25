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



int main(int argc, char *argv[])
{/*
//qDebug()<<QCoreApplication::applicationDirPath() ;
    QString str = "  lots\t of\nwhitespace\r\n ";
    str = str.simplified();
qDebug()<<str;*/


 //path.indexOf('/',0)

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();

}

