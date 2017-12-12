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


#define FULL_UNROLL
#include <string>
#include <cstdio>
#include <cstring>



typedef unsigned int u32;
typedef unsigned char u8;

#define GETU32(openedText) (((u32)(openedText)[0] << 24) ^ \
        ((u32)(openedText)[1] << 16) ^ \
        ((u32)(openedText)[2] <<  8) ^ \
        ((u32)(openedText)[3]))

#define PUTU32(cipheredText, st) { (cipheredText)[0] = (u8)((st) >> 24); \
        (cipheredText)[1] = (u8)((st) >> 16); \
        (cipheredText)[2] = (u8)((st) >>  8); \
        (cipheredText)[3] = (u8)(st); }


extern const u32 Te0[256];
extern const u32 Te1[256];
extern const u32 Te2[256];
extern const u32 Te3[256];
extern const u32 Te4[256];
extern const u32 Td0[256];
extern const u32 Td1[256];
extern const u32 Td2[256];
extern const u32 Td3[256];
extern const u32 Td4[256];
extern const u32 rcon[];
AES_ROUND_KEYS_128_256 aes_roundkey_256;

int  Cipher:: encryptInitialization(u32 *roundKey, const u8 *key, int keybits) {
    int counter1 = 0;
    u32 addBuffer;

    for (counter1 = 0; counter1 <8; counter1++) {
        roundKey[counter1] = GETU32(key + (4* counter1) );
    }

    counter1 = 0;

    if (keybits == 256)
    {
        while(1)
        {
            addBuffer = roundKey[ 7];
            roundKey[ 8] = roundKey[ 0] ^(Te4[(addBuffer >> 16) & 0xff] & 0xff000000) ^(Te4[(addBuffer >>  8) & 0xff] & 0x00ff0000) ^(Te4[(addBuffer) & 0xff] & 0x0000ff00) ^(Te4[(addBuffer >> 24)] & 0x000000ff) ^rcon[counter1];
            roundKey[ 9] = roundKey[ 1] ^ roundKey[ 8];
            roundKey[10] = roundKey[ 2] ^ roundKey[ 9];
            roundKey[11] = roundKey[ 3] ^ roundKey[10];
            if (++counter1 == 7)
                return 14;
            addBuffer = roundKey[11];
            roundKey[12] = roundKey[ 4] ^(Te4[(addBuffer >> 24)] & 0xff000000) ^(Te4[(addBuffer >> 16) & 0xff] & 0x00ff0000) ^(Te4[(addBuffer >>  8) & 0xff] & 0x0000ff00) ^(Te4[(addBuffer) & 0xff] & 0x000000ff);
            roundKey[13] = roundKey[ 5] ^ roundKey[12];
            roundKey[14] = roundKey[ 6] ^ roundKey[13];
            roundKey[15] = roundKey[ 7] ^ roundKey[14];
            roundKey += 8;
        }
    }
    return 0;
}

int  Cipher:: decryptInitialization(u32 *roundKey, const u8 *key, int keybits) {
    int amountOfRounds, counter1, counter2;
    u32 addBuffer;


    amountOfRounds = encryptInitialization(roundKey, key, keybits);

    for (counter1 = 0, counter2 = 4*amountOfRounds; counter1 < counter2; counter1 += 4, counter2 -= 4)
    {
        addBuffer = roundKey[counter1    ]; roundKey[counter1    ] = roundKey[counter2    ]; roundKey[counter2    ] = addBuffer;
        addBuffer = roundKey[counter1 + 1]; roundKey[counter1 + 1] = roundKey[counter2 + 1]; roundKey[counter2 + 1] = addBuffer;
        addBuffer = roundKey[counter1 + 2]; roundKey[counter1 + 2] = roundKey[counter2 + 2]; roundKey[counter2 + 2] = addBuffer;
        addBuffer = roundKey[counter1 + 3]; roundKey[counter1 + 3] = roundKey[counter2 + 3]; roundKey[counter2 + 3] = addBuffer;
    }

    for (counter1 = 1; counter1 < amountOfRounds; counter1++)
    {
        roundKey += 4;
        roundKey[0] =
                Td0[Te4[(roundKey[0] >> 24)       ] & 0xff] ^
                Td1[Te4[(roundKey[0] >> 16) & 0xff] & 0xff] ^
                Td2[Te4[(roundKey[0] >>  8) & 0xff] & 0xff] ^
                Td3[Te4[(roundKey[0]      ) & 0xff] & 0xff];
        roundKey[1] =
                Td0[Te4[(roundKey[1] >> 24)       ] & 0xff] ^
                Td1[Te4[(roundKey[1] >> 16) & 0xff] & 0xff] ^
                Td2[Te4[(roundKey[1] >>  8) & 0xff] & 0xff] ^
                Td3[Te4[(roundKey[1]      ) & 0xff] & 0xff];
        roundKey[2] =
                Td0[Te4[(roundKey[2] >> 24)       ] & 0xff] ^
                Td1[Te4[(roundKey[2] >> 16) & 0xff] & 0xff] ^
                Td2[Te4[(roundKey[2] >>  8) & 0xff] & 0xff] ^
                Td3[Te4[(roundKey[2]      ) & 0xff] & 0xff];
        roundKey[3] =
                Td0[Te4[(roundKey[3] >> 24)       ] & 0xff] ^
                Td1[Te4[(roundKey[3] >> 16) & 0xff] & 0xff] ^
                Td2[Te4[(roundKey[3] >>  8) & 0xff] & 0xff] ^
                Td3[Te4[(roundKey[3]      ) & 0xff] & 0xff];
    }
    return amountOfRounds;
}

u32  Cipher:: makeSJTE(int counterName, u32 t0,  u32 t1, u32 t2, u32 t3, const u32 *roundKey ){
    if  ( (counterName== 8) ||
          (counterName==16) ||
          (counterName==24) ||
          (counterName==32) ||
          (counterName==40) ||
          (counterName==48) ) {
            return Te0[t0 >> 24] ^ Te1[(t1 >> 16) & 0xff] ^ Te2[(t2 >>  8) & 0xff] ^ Te3[t3 & 0xff] ^ roundKey[counterName];
    } else {
        if  ( (counterName== 9) ||
              (counterName==17) ||
              (counterName==25) ||
              (counterName==33) ||
              (counterName==41) ||
              (counterName==49) ) {
            return Te0[t1 >> 24] ^ Te1[(t2 >> 16) & 0xff] ^ Te2[(t3 >>  8) & 0xff] ^ Te3[t0 & 0xff] ^ roundKey[ counterName];
        } else {
            if  ( (counterName==10) ||
                  (counterName==18) ||
                  (counterName==26) ||
                  (counterName==34) ||
                  (counterName==42) ||
                  (counterName==50) ) {
                return Te0[t2 >> 24] ^ Te1[(t3 >> 16) & 0xff] ^ Te2[(t0 >>  8) & 0xff] ^ Te3[t1 & 0xff] ^ roundKey[counterName];
            } else {
                if  ( (counterName==11) ||
                      (counterName==19) ||
                      (counterName==27) ||
                      (counterName==35) ||
                      (counterName==43) ||
                      (counterName==51) ) {
                    return Te0[t3 >> 24] ^ Te1[(t0 >> 16) & 0xff] ^ Te2[(t1 >>  8) & 0xff] ^ Te3[t2 & 0xff] ^ roundKey[counterName];
                }
            }
        }
    }
}

u32  Cipher:: makeTJTE(int counterName, u32 s0,  u32 s1, u32 s2, u32 s3, const u32 *roundKey ){
    if  ( (counterName== 4) ||
          (counterName==12) ||
          (counterName==20) ||
          (counterName==28) ||
          (counterName==36) ||
          (counterName==44) ||
          (counterName==52) ) {
        return Te0[s0 >> 24] ^ Te1[(s1 >> 16) & 0xff] ^ Te2[(s2 >>  8) & 0xff] ^ Te3[s3 & 0xff] ^ roundKey[counterName];
    } else {
        if   ( (counterName== 5) ||
               (counterName==13) ||
               (counterName==21) ||
               (counterName==29) ||
               (counterName==37) ||
               (counterName==45) ||
               (counterName==53) ) {
            return  Te0[s1 >> 24] ^ Te1[(s2 >> 16) & 0xff] ^ Te2[(s3 >>  8) & 0xff] ^ Te3[s0 & 0xff] ^ roundKey[counterName];
        } else {
            if   ( (counterName== 6) ||
                   (counterName==14) ||
                   (counterName==22) ||
                   (counterName==30) ||
                   (counterName==38) ||
                   (counterName==46) ||
                   (counterName==54) ) {
                return Te0[s2 >> 24] ^ Te1[(s3 >> 16) & 0xff] ^ Te2[(s0 >>  8) & 0xff] ^ Te3[s1 & 0xff] ^ roundKey[ counterName];
            } else {
                if   ( (counterName== 7) ||
                       (counterName==15) ||
                       (counterName==23) ||
                       (counterName==31) ||
                       (counterName==39) ||
                       (counterName==47) ||
                       (counterName==55) ) {
                    return Te0[s3 >> 24] ^ Te1[(s0 >> 16) & 0xff] ^ Te2[(s1 >>  8) & 0xff] ^ Te3[s2 & 0xff] ^ roundKey[ counterName];
                }
            }
        }
    }
}

void  Cipher:: encryption(const u32 *roundKey, int amountOfRounds, u8 openedText[16],u8 cipheredText[16]) {
    u32 s0, s1, s2, s3, t0, t1, t2, t3;
#ifndef FULL_UNROLL
    int r;
#endif /* ?FULL_UNROLL */

#ifdef FULL_UNROLL

    int k=0;
    for (int counter3=0; counter3< amountOfRounds; counter3=counter3+2){
        if (counter3==0) {
            s0 = GETU32(openedText) ^ roundKey[k++];
            s1 = GETU32(openedText + 4) ^ roundKey[k++];
            s2 = GETU32(openedText + 8) ^ roundKey[k++];
            s3 = GETU32(openedText + 12) ^ roundKey[k++];
        } else {
            s0 = makeSJTE(k++, t0, t1, t2, t3, roundKey);
            s1 = makeSJTE(k++, t0, t1, t2, t3, roundKey);
            s2 = makeSJTE(k++, t0, t1, t2, t3, roundKey);
            s3 = makeSJTE(k++, t0, t1, t2, t3, roundKey);
        }
        t0 = makeTJTE(k++, s0, s1, s2, s3, roundKey);
        t1 = makeTJTE(k++, s0, s1, s2, s3, roundKey);
        t2 = makeTJTE(k++, s0, s1, s2, s3, roundKey);
        t3 = makeTJTE(k++, s0, s1, s2, s3, roundKey);
    }
    roundKey += amountOfRounds << 2;
#else  /* !FULL_UNROLL */

    r = amountOfRounds >> 1;
     while(1){
        t0 = makeTJTE(4, s0, s1, s2, s3, roundKey);
        t1 = makeTJTE(5, s0, s1, s2, s3, roundKey);
        t2 = makeTJTE(6, s0, s1, s2, s3, roundKey);
        t3 = makeTJTE(7, s0, s1, s2, s3, roundKey);
        roundKey += 8;
        if (--r == 0)
            break;
        s0 =Te0[(t0 >> 24)] ^Te1[(t1 >> 16) & 0xff] ^Te2[(t2 >>  8) & 0xff] ^Te3[(t3) & 0xff] ^roundKey[0];
        s1 =Te0[(t1 >> 24)] ^Te1[(t2 >> 16) & 0xff] ^Te2[(t3 >>  8) & 0xff] ^Te3[(t0) & 0xff] ^roundKey[1];
        s2 =Te0[(t2 >> 24)] ^Te1[(t3 >> 16) & 0xff] ^Te2[(t0 >>  8) & 0xff] ^Te3[(t1) & 0xff] ^roundKey[2];
        s3 =Te0[(t3 >> 24)] ^Te1[(t0 >> 16) & 0xff] ^Te2[(t1 >>  8) & 0xff] ^Te3[(t2) & 0xff] ^roundKey[3];
    }
#endif /* ?FULL_UNROLL */

    s0 =
            (Te4[(t0 >> 24)       ] & 0xff000000) ^
            (Te4[(t1 >> 16) & 0xff] & 0x00ff0000) ^
            (Te4[(t2 >>  8) & 0xff] & 0x0000ff00) ^
            (Te4[(t3      ) & 0xff] & 0x000000ff) ^
            roundKey[0];
    PUTU32(cipheredText     , s0);
    s1 =
            (Te4[(t1 >> 24)       ] & 0xff000000) ^
            (Te4[(t2 >> 16) & 0xff] & 0x00ff0000) ^
            (Te4[(t3 >>  8) & 0xff] & 0x0000ff00) ^
            (Te4[(t0      ) & 0xff] & 0x000000ff) ^
            roundKey[1];
    PUTU32(cipheredText +  4, s1);
    s2 =
            (Te4[(t2 >> 24)       ] & 0xff000000) ^
            (Te4[(t3 >> 16) & 0xff] & 0x00ff0000) ^
            (Te4[(t0 >>  8) & 0xff] & 0x0000ff00) ^
            (Te4[(t1      ) & 0xff] & 0x000000ff) ^
            roundKey[2];
    PUTU32(cipheredText +  8, s2);
    s3 =
            (Te4[(t3 >> 24)       ] & 0xff000000) ^
            (Te4[(t0 >> 16) & 0xff] & 0x00ff0000) ^
            (Te4[(t1 >>  8) & 0xff] & 0x0000ff00) ^
            (Te4[(t2      ) & 0xff] & 0x000000ff) ^
            roundKey[3];
    PUTU32(cipheredText + 12, s3);
}

u32 Cipher:: makeSJTD(int counterName, u32 t0,  u32 t1, u32 t2, u32 t3, const u32 *roundKey ){
    if  ( (counterName== 8) ||
          (counterName==16) ||
          (counterName==24) ||
          (counterName==32) ||
          (counterName==40) ||
          (counterName==48) ) {
        return Td0[t0 >> 24] ^ Td1[(t3 >> 16) & 0xff] ^ Td2[(t2 >>  8) & 0xff] ^ Td3[t1 & 0xff] ^ roundKey[ counterName];
    } else {
        if  ( (counterName== 9) ||
              (counterName==17) ||
              (counterName==25) ||
              (counterName==33) ||
              (counterName==41) ||
              (counterName==49) ) {
            return Td0[t1 >> 24] ^ Td1[(t0 >> 16) & 0xff] ^ Td2[(t3 >>  8) & 0xff] ^ Td3[t2 & 0xff] ^ roundKey[ counterName];
        } else {
            if  ( (counterName==10) ||
                  (counterName==18) ||
                  (counterName==26) ||
                  (counterName==34) ||
                  (counterName==42) ||
                  (counterName==50) ) {
                return Td0[t2 >> 24] ^ Td1[(t1 >> 16) & 0xff] ^ Td2[(t0 >>  8) & 0xff] ^ Td3[t3 & 0xff] ^ roundKey[counterName];
            } else {
                if  ( (counterName==11) ||
                      (counterName==19) ||
                      (counterName==27) ||
                      (counterName==35) ||
                      (counterName==43) ||
                      (counterName==51) ) {
                    return Td0[t3 >> 24] ^ Td1[(t2 >> 16) & 0xff] ^ Td2[(t1 >>  8) & 0xff] ^ Td3[t0 & 0xff] ^ roundKey[counterName];
                }
            }
        }
    }
}

u32  Cipher:: makeTJTD(int counterName, u32 s0,  u32 s1, u32 s2, u32 s3, const u32 *roundKey ){
    if  ( (counterName== 4) ||
          (counterName==12) ||
          (counterName==20) ||
          (counterName==28) ||
          (counterName==36) ||
          (counterName==44) ||
          (counterName==52) ) {
        return Td0[s0 >> 24] ^ Td1[(s3 >> 16) & 0xff] ^ Td2[(s2 >>  8) & 0xff] ^ Td3[s1 & 0xff] ^ roundKey[counterName];
    } else {
        if   ( (counterName== 5) ||
               (counterName==13) ||
               (counterName==21) ||
               (counterName==29) ||
               (counterName==37) ||
               (counterName==45) ||
               (counterName==53) ) {
            return  Td0[s1 >> 24] ^ Td1[(s0 >> 16) & 0xff] ^ Td2[(s3 >>  8) & 0xff] ^ Td3[s2 & 0xff] ^ roundKey[ counterName];
        } else {
            if   ( (counterName== 6) ||
                   (counterName==14) ||
                   (counterName==22) ||
                   (counterName==30) ||
                   (counterName==38) ||
                   (counterName==46) ||
                   (counterName==54) ) {
                return Td0[s2 >> 24] ^ Td1[(s1 >> 16) & 0xff] ^ Td2[(s0 >>  8) & 0xff] ^ Td3[s3 & 0xff] ^ roundKey[ counterName];
            } else {
                if   ( (counterName== 7) ||
                       (counterName==15) ||
                       (counterName==23) ||
                       (counterName==31) ||
                       (counterName==39) ||
                       (counterName==47) ||
                       (counterName==55) ) {
                    return Td0[s3 >> 24] ^ Td1[(s2 >> 16) & 0xff] ^ Td2[(s1 >>  8) & 0xff] ^ Td3[s0 & 0xff] ^ roundKey[ counterName];
                }
            }
        }
    }
}

void  Cipher:: decryption(const u32 *roundKey, int amountOfRounds, const u8 cipheredText[16],u8 openedText[16]){
    u32 s0, s1, s2, s3, t0, t1, t2, t3;
#ifndef FULL_UNROLL
    int r;
#endif /* ?FULL_UNROLL */

#ifdef FULL_UNROLL
    int k=0;
    for (int counter3=0; counter3< amountOfRounds; counter3=counter3+2){
        if (counter3==0) {
            s0 = GETU32(cipheredText) ^ roundKey[k++];
            s1 = GETU32(cipheredText + 4) ^ roundKey[k++];
            s2 = GETU32(cipheredText + 8) ^ roundKey[k++];
            s3 = GETU32(cipheredText + 12) ^ roundKey[k++];
        } else {
            s0 = makeSJTD(k++, t0, t1, t2, t3, roundKey);
            s1 = makeSJTD(k++, t0, t1, t2, t3, roundKey);
            s2 = makeSJTD(k++, t0, t1, t2, t3, roundKey);
            s3 = makeSJTD(k++, t0, t1, t2, t3, roundKey);
        }
        t0 = makeTJTD(k++, s0, s1, s2, s3, roundKey);
        t1 = makeTJTD(k++, s0, s1, s2, s3, roundKey);
        t2 = makeTJTD(k++, s0, s1, s2, s3, roundKey);
        t3 = makeTJTD(k++, s0, s1, s2, s3, roundKey);
    }
    roundKey += amountOfRounds << 2;
#else  /* !FULL_UNROLL */
    /*
     * amountOfRounds - 1 full rounds:
     */
    r = amountOfRounds >> 1;
     while(1)
    {
        t0 = makeTJTD(4, s0, s1, s2, s3, roundKey);
        t1 = makeTJTD(5, s0, s1, s2, s3, roundKey);
        t2 = makeTJTD(6, s0, s1, s2, s3, roundKey);
        t3 = makeTJTD(7, s0, s1, s2, s3, roundKey);
        roundKey += 8;
        if (--r == 0)
            break;
        s0 =Td0[(t0 >> 24)] ^Td1[(t3 >> 16) & 0xff] ^Td2[(t2 >>  8) & 0xff] ^Td3[(t1) & 0xff] ^roundKey[0];
        s1 =Td0[(t1 >> 24)] ^Td1[(t0 >> 16) & 0xff] ^Td2[(t3 >>  8) & 0xff] ^Td3[(t2) & 0xff] ^roundKey[1];
        s2 =Td0[(t2 >> 24)] ^Td1[(t1 >> 16) & 0xff] ^Td2[(t0 >>  8) & 0xff] ^Td3[(t3) & 0xff] ^roundKey[2];
        s3 =Td0[(t3 >> 24)] ^Td1[(t2 >> 16) & 0xff] ^Td2[(t1 >>  8) & 0xff] ^Td3[(t0) & 0xff] ^roundKey[3];
    }
#endif /* ?FULL_UNROLL */
    /*
     * apply last round and
     * map cipher state to byte array block:
     */
    s0 =
            (Td4[(t0 >> 24)       ] & 0xff000000) ^
            (Td4[(t3 >> 16) & 0xff] & 0x00ff0000) ^
            (Td4[(t2 >>  8) & 0xff] & 0x0000ff00) ^
            (Td4[(t1      ) & 0xff] & 0x000000ff) ^
            roundKey[0];
    PUTU32(openedText     , s0);
    s1 =
            (Td4[(t1 >> 24)       ] & 0xff000000) ^
            (Td4[(t0 >> 16) & 0xff] & 0x00ff0000) ^
            (Td4[(t3 >>  8) & 0xff] & 0x0000ff00) ^
            (Td4[(t2      ) & 0xff] & 0x000000ff) ^
            roundKey[1];
    PUTU32(openedText +  4, s1);
    s2 =
            (Td4[(t2 >> 24)       ] & 0xff000000) ^
            (Td4[(t1 >> 16) & 0xff] & 0x00ff0000) ^
            (Td4[(t0 >>  8) & 0xff] & 0x0000ff00) ^
            (Td4[(t3      ) & 0xff] & 0x000000ff) ^
            roundKey[2];
    PUTU32(openedText +  8, s2);
    s3 =
            (Td4[(t3 >> 24)       ] & 0xff000000) ^
            (Td4[(t2 >> 16) & 0xff] & 0x00ff0000) ^
            (Td4[(t1 >>  8) & 0xff] & 0x0000ff00) ^
            (Td4[(t0      ) & 0xff] & 0x000000ff) ^
            roundKey[3];
    PUTU32(openedText + 12, s3);
}

inline void  Cipher:: aes_encrypt_b128_k256_one_block( u8 openedText[16], const u32 *roundKey ){
    encryption( roundKey, 14, openedText, openedText);
}


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

 unsigned char*  Cipher::keyDeriveFunction(QString stra){
   //qDebug()<<1;
   //QString str1 = "Test";
   QByteArray ba = stra.toLatin1();
   const char *str = ba.data();
 char *str5 = new char;
   char *a;
    // memcpy(str,stra.toLatin1(),stra.size());
  const char * str6 = ( const char *) stra. toLocal8Bit().data();
   char *str7 = new char;
   HCRYPTPROV hCryptProv = 0;
   HCRYPTHASH hHash = 0; 
   DWORD count=strlen(str);
   CryptAcquireContext(&hCryptProv, NULL, NULL, PROV_RSA_SCHANNEL, 0);
   CryptCreateHash(hCryptProv, CALG_SHA, 0, 0, &hHash);
   CryptHashData(hHash, (BYTE*)str, count, 0);
   BYTE result0, hash_value[41];
   DWORD dwDataLen = 40;
   unsigned char aestestkey[] = { 0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,
         0x08,0x09,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f,
         0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,
         0x18,0x19,0x1a,0x1b,0x1c,0x1d,0x1e,0x1f };
   unsigned char initkey[] = {0x08,0x09,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f,
         0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,
         0x08,0x09,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f,
         0x18,0x08,0x09,0x0a,0x1d,0x1e,0x1f };
   CryptGetHashParam(hHash, HP_HASHVAL,hash_value, &dwDataLen, 0);
  // cout<<endl;
   //int f=(sizeof(hash_value)/sizeof(BYTE));
  /* for(int i=0;i<20;i++) {
       printf("%02x",hash_value[i]);
      // result0[i]=hash_value[i];
   }*/
   ByteBlock result(hash_value, 32);
  // cout<<endl;
   auto cipher_params = read_cipher_params();


          // string resup= System::Text::Encoding::UTF8->GetString(hash_value, 0, hash_value->Length);
//QString str2 = QString(QByteArray((const char*) hash_value));
//cout<< typename (str2);
   return aestestkey;
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



QByteArray Cipher::myEncryption(){
   unsigned char aestestkey[] = { 0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,
                                       0x08,0x09,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f,
                                       0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,
                                       0x18,0x19,0x1a,0x1b,0x1c,0x1d,0x1e,0x1f };

    unsigned char *aestestkeyProduction =   keyDeriveFunction(this->name);

    unsigned char aestest1[] = { 0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,
                                     0x88,0x99,0xaa,0xbb,0xcc,0xdd,0xee,0xff };
    unsigned char aestest[]={};
    unsigned char  result[]={};
    int counter1 = 0;
    u32 *roundKey = (u32 *) aes_roundkey_256;
    char text[100]={};
    char chifer[100] = {};
    char decifer[100] = {};
    QByteArray ba = this->str;
    const char *str = ba.data();
    for (int i=0; i<strlen(str); i++){
        text[i]=str[i];
    };
    int ss= strlen (text) % 16;
    int dd= strlen (text) / 16;
    if (ss!=0) {
        for (counter1=ss; counter1< 16; counter1++){
            text[dd*16+counter1]= ' ';
        }
    }
    dd= strlen (text) / 16;
    for (counter1=0; counter1<dd; counter1++){
        for (int counter2 = 0; counter2<16;counter2++){
            aestest[counter2] = text[counter1*16+counter2];
        }
        encryptInitialization(roundKey, aestestkey, 256);
      // int extraRound= decryptInitialization(roundKey, aestestkeyProduction, 256);
        aes_encrypt_b128_k256_one_block( aestest, roundKey );
                for (int counter2 = 0; counter2<16;counter2++){
                    chifer[counter1*16+counter2] = aestest[counter2];
                   // extraRound++;
                }
    }
    QByteArray ver(chifer) ;
/*
    for (counter1=0; counter1<dd; counter1++){
        for (int counter2 = 0; counter2<16;counter2++){
            aestest[counter2] = text[counter1*16+counter2];
        }
        encryptInitialization(roundKey, aestestkeyProduction, 256);
     int extraRound= decryptInitialization(roundKey, aestestkeyProduction, 256);
        aes_encrypt_b128_k256_one_block( aestest, roundKey );
                for (int counter2 = 0; counter2<16;counter2++){
                    chifer[counter1*16+counter2] = aestest[counter2];
                    extraRound++;
                }
    }*/

    return ver;
}

QString Cipher::myDecryption(){
    unsigned char aestestkey[] = { 0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,
                                       0x08,0x09,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f,
                                       0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,
                                       0x18,0x19,0x1a,0x1b,0x1c,0x1d,0x1e,0x1f };
   unsigned char *aestestkeyProduction =   keyDeriveFunction(this->name);
    unsigned char aestest1[] = { 0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,
                                     0x88,0x99,0xaa,0xbb,0xcc,0xdd,0xee,0xff };
    unsigned char aestest[]={};
    unsigned char  result[]={};
    int counter1 = 0;
    u32 *roundKey = (u32 *) aes_roundkey_256;
    char text[100]={};
    char decifer[100] = {};
    QByteArray ba = this->str;
    const char *str5 = ba.data();
    for (int i=0; i<strlen(str5); i++){
        text[i]=str5[i];
    };
    int   ss= strlen (text) % 16;
    int dd= strlen (text) / 16;
    if (ss!=0) {
        for (counter1=ss; counter1< 16; counter1++){
            text[dd*16+counter1]= ' ';
        }
    }
    dd= strlen (text) / 16;
    for (counter1=0; counter1<dd; counter1++){
        for (int counter2 = 0; counter2<16;counter2++){
            aestest[counter2] = text[counter1*16+counter2];
        }
        int amountOfRounds= decryptInitialization(roundKey, aestestkey, 256);
       // int extraRound= decryptInitialization(roundKey, aestestkeyProduction, 256);
        decryption(roundKey, amountOfRounds, aestest, result );
        for (int counter2 = 0; counter2<16;counter2++){
            decifer[counter1*16+counter2] = aestest[counter2];
           // extraRound++;
        }
    }
    QString resultatik(decifer);
    qDebug()<< resultatik;
    /*for (counter1=0; counter1<dd; counter1++){
        for (int counter2 = 0; counter2<16;counter2++){
            aestest[counter2] = text[counter1*16+counter2];
        }
        //int amountOfRounds= decryptInitialization(roundKey, aestestkey, 256);
         int amountOfRounds= decryptInitialization(roundKey, aestestkey, 256);
       int extraRound= decryptInitialization(roundKey, aestestkeyProduction, 256);
        decryption(roundKey, amountOfRounds, aestest, result );
        for (int counter2 = 0; counter2<16;counter2++){
            decifer[counter1*16+counter2] = aestest[counter2];
           extraRound++;
        }
    }*/
    return resultatik;
}

bool Cipher::  logic_xor3(bool x, bool y, bool z) {
    return (!x && !y && z) || (!x && y && !z) || (x && !y && !z);}

