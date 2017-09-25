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
    QString str;
    QByteArray key;
    QByteArray KeyGen (unsigned long next);
    QByteArray Combinig( QByteArray key, QByteArray ciphered_text);
    vector<string> read_cipher_params( );
    bool  logic_xor3(bool x, bool y, bool z);
    string  hexToString(QString hexdata);
    QString  stringToHex(QString str);

public:
    QByteArray ciphered_text;
    Cipher (QString  str0) {this->str=str0;}
    QByteArray Ciphering ();
    QString    myDecryption();
    QString  myEncryption();
};

#endif //CIPHER_H
