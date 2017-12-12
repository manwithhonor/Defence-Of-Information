//#include "stdafx.h"
#include "encryption.h"

#define KEY_SIZE   32
#define NUM_ROUNDS 14

const unsigned char sbox[256] = {
    0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5,
    0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76,
    0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0,
    0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0,
    0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc,
    0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15,
    0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a,
    0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75,
    0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0,
    0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84,
    0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b,
    0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf,
    0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85,
    0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8,
    0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5,
    0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2,
    0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17,
    0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73,
    0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88,
    0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb,
    0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c,
    0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79,
    0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9,
    0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08,
    0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6,
    0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a,
    0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e,
    0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e,
    0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94,
    0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf,
    0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68,
    0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16
};
const unsigned char sboxinv[256] = {
    0x52, 0x09, 0x6a, 0xd5, 0x30, 0x36, 0xa5, 0x38,
    0xbf, 0x40, 0xa3, 0x9e, 0x81, 0xf3, 0xd7, 0xfb,
    0x7c, 0xe3, 0x39, 0x82, 0x9b, 0x2f, 0xff, 0x87,
    0x34, 0x8e, 0x43, 0x44, 0xc4, 0xde, 0xe9, 0xcb,
    0x54, 0x7b, 0x94, 0x32, 0xa6, 0xc2, 0x23, 0x3d,
    0xee, 0x4c, 0x95, 0x0b, 0x42, 0xfa, 0xc3, 0x4e,
    0x08, 0x2e, 0xa1, 0x66, 0x28, 0xd9, 0x24, 0xb2,
    0x76, 0x5b, 0xa2, 0x49, 0x6d, 0x8b, 0xd1, 0x25,
    0x72, 0xf8, 0xf6, 0x64, 0x86, 0x68, 0x98, 0x16,
    0xd4, 0xa4, 0x5c, 0xcc, 0x5d, 0x65, 0xb6, 0x92,
    0x6c, 0x70, 0x48, 0x50, 0xfd, 0xed, 0xb9, 0xda,
    0x5e, 0x15, 0x46, 0x57, 0xa7, 0x8d, 0x9d, 0x84,
    0x90, 0xd8, 0xab, 0x00, 0x8c, 0xbc, 0xd3, 0x0a,
    0xf7, 0xe4, 0x58, 0x05, 0xb8, 0xb3, 0x45, 0x06,
    0xd0, 0x2c, 0x1e, 0x8f, 0xca, 0x3f, 0x0f, 0x02,
    0xc1, 0xaf, 0xbd, 0x03, 0x01, 0x13, 0x8a, 0x6b,
    0x3a, 0x91, 0x11, 0x41, 0x4f, 0x67, 0xdc, 0xea,
    0x97, 0xf2, 0xcf, 0xce, 0xf0, 0xb4, 0xe6, 0x73,
    0x96, 0xac, 0x74, 0x22, 0xe7, 0xad, 0x35, 0x85,
    0xe2, 0xf9, 0x37, 0xe8, 0x1c, 0x75, 0xdf, 0x6e,
    0x47, 0xf1, 0x1a, 0x71, 0x1d, 0x29, 0xc5, 0x89,
    0x6f, 0xb7, 0x62, 0x0e, 0xaa, 0x18, 0xbe, 0x1b,
    0xfc, 0x56, 0x3e, 0x4b, 0xc6, 0xd2, 0x79, 0x20,
    0x9a, 0xdb, 0xc0, 0xfe, 0x78, 0xcd, 0x5a, 0xf4,
    0x1f, 0xdd, 0xa8, 0x33, 0x88, 0x07, 0xc7, 0x31,
    0xb1, 0x12, 0x10, 0x59, 0x27, 0x80, 0xec, 0x5f,
    0x60, 0x51, 0x7f, 0xa9, 0x19, 0xb5, 0x4a, 0x0d,
    0x2d, 0xe5, 0x7a, 0x9f, 0x93, 0xc9, 0x9c, 0xef,
    0xa0, 0xe0, 0x3b, 0x4d, 0xae, 0x2a, 0xf5, 0xb0,
    0xc8, 0xeb, 0xbb, 0x3c, 0x83, 0x53, 0x99, 0x61,
    0x17, 0x2b, 0x04, 0x7e, 0xba, 0x77, 0xd6, 0x26,
    0xe1, 0x69, 0x14, 0x63, 0x55, 0x21, 0x0c, 0x7d
};

#define FE(x)  (((x) << 1) ^ ((((x)>>7) & 1) * 0x1b))
#define FD(x)  (((x) >> 1) ^ (((x) & 1) ? 0x8d : 0))

//проверка на x>=128 и xor c 0x1b при истинности, 0x80 = 1000000 в 2-ом представлении
unsigned char rj_xtime(unsigned char x) {
    return (x & 0x80) ? ((x << 1) ^ 0x1b) : (x << 1);
}

encryption::encryption(const ArrayByte &key, unsigned char *buffer)
{
    for (int i = 0; i < 256; i++) {
        m_key.push_back(0);
        m_rkey.push_back(0);
    }

    for (ArrayByte::size_type i = 0; i < key.size(); ++i)
        m_key[i] = key[i];
    Copykey();

    /*enctypt(buffer);
    for (int i = 0; i < 256; i++) {
        printf("%d ", buffer[i]);
        m_rkey[i] = 0;
    }
    printf("\n\n\n");

    decrypt(buffer);
    for (int i = 0; i < 256; i++) {
        printf("%d ", buffer[i]);
    }
    printf("\n");*/
}

encryption::~encryption()
{
}
//+++++++++
void encryption::SubBytes(unsigned char* buffer) {
    unsigned int i = KEY_SIZE / 2;
    for (i; i > 0; i--) {
        buffer[i] = sbox[buffer[i]];
    }
}

void encryption::SubBytesInv(unsigned char* buffer) {
    unsigned int i = KEY_SIZE / 2;
    for (i; i > 0; i--) {
        buffer[i] = sboxinv[buffer[i]];
    }
}
//++++++++
void encryption::ShiftRows(unsigned char* buffer) {
    unsigned char i;

    i = buffer[1];
    buffer[1] = buffer[5];
    buffer[5] = buffer[9];
    buffer[9] = buffer[13];
    buffer[13] = i;

    i = buffer[10];
    buffer[10] = buffer[2];
    buffer[2] = i;

    i = buffer[3];
    buffer[3] = buffer[15];
    buffer[15] = buffer[11];
    buffer[11] = buffer[7];
    buffer[7] = i;

    i = buffer[14];
    buffer[14] = buffer[6];
    buffer[6] = i;
}

void encryption::ShiftRowsInv(unsigned char* buffer) {
    unsigned char i = 0;

    i = buffer[1];
    buffer[1] = buffer[13];
    buffer[13] = buffer[9];
    buffer[9] = buffer[5];
    buffer[5] = i;

    i = buffer[2];
    buffer[2] = buffer[10];
    buffer[10] = i;

    i = buffer[3];
    buffer[3] = buffer[7];
    buffer[7] = buffer[11];
    buffer[11] = buffer[15];
    buffer[15] = i;

    i = buffer[6];
    buffer[6] = buffer[14];
    buffer[14] = i;
}

void encryption::MixColumns(unsigned char* buffer) {
    unsigned char a, b, c, d, e;

    for (int i = 0; i < 16; i += 4)
    {
        a = buffer[i];
        b = buffer[i + 1];
        c = buffer[i + 2];
        d = buffer[i + 3];

        e = a ^ b ^ c ^ d;

        buffer[i] ^= e ^ rj_xtime(a^b);
        buffer[i + 1] ^= e ^ rj_xtime(b^c);
        buffer[i + 2] ^= e ^ rj_xtime(c^d);
        buffer[i + 3] ^= e ^ rj_xtime(d^a);
    }
}

void encryption::MixColumnsInv(unsigned char* buffer) {
    register unsigned char a, b, c, d, e, x, y, z;

    for (int i = 0; i < 16; i += 4)
    {
        a = buffer[i];
        b = buffer[i + 1];
        c = buffer[i + 2];
        d = buffer[i + 3];

        e = a ^ b ^ c ^ d;
        z = rj_xtime(e);
        x = e ^ rj_xtime(rj_xtime(z^a^c));  y = e ^ rj_xtime(rj_xtime(z^b^d));

        buffer[i] ^= x ^ rj_xtime(a^b);
        buffer[i + 1] ^= y ^ rj_xtime(b^c);
        buffer[i + 2] ^= x ^ rj_xtime(c^d);
        buffer[i + 3] ^= y ^ rj_xtime(d^a);
    }
}

void encryption::AddRoundKey(unsigned char* buffer, unsigned char roundkey) {
    unsigned char i = KEY_SIZE / 2;

    while (i--)
        buffer[i] ^= m_rkey[(roundkey & 1) ? i + 16 : i];
}

void encryption::Copykey() {

    for (int i = 0; i < m_key.size(); ++i)
        m_rkey[i] = m_key[i];
}

void encryption::ExpandEncKey(unsigned char *buffer){
    unsigned char i;

    m_rkey[0] = m_rkey[0] ^ sbox[m_rkey[29]] ^ (*buffer);
    m_rkey[1] = m_rkey[1] ^ sbox[m_rkey[30]];
    m_rkey[2] = m_rkey[2] ^ sbox[m_rkey[31]];
    m_rkey[3] = m_rkey[3] ^ sbox[m_rkey[28]];
    *buffer = FE(*buffer);

    for (i = 4; i < 16; i += 4) {
        m_rkey[i] = m_rkey[i] ^ m_rkey[i - 4];
        m_rkey[i + 1] = m_rkey[i + 1] ^ m_rkey[i - 3];
        m_rkey[i + 2] = m_rkey[i + 2] ^ m_rkey[i - 2];
        m_rkey[i + 3] = m_rkey[i + 3] ^ m_rkey[i - 1];
    }
    m_rkey[16] = m_rkey[16] ^ sbox[m_rkey[12]];
    m_rkey[17] = m_rkey[17] ^ sbox[m_rkey[13]];
    m_rkey[18] = m_rkey[18] ^ sbox[m_rkey[14]];
    m_rkey[19] = m_rkey[19] ^ sbox[m_rkey[15]];

    for (i = 20; i < 32; i += 4) {
        m_rkey[i] = m_rkey[i] ^ m_rkey[i - 4];
        m_rkey[i + 1] = m_rkey[i + 1] ^ m_rkey[i - 3];
        m_rkey[i + 2] = m_rkey[i + 2] ^ m_rkey[i - 2];
        m_rkey[i + 3] = m_rkey[i + 3] ^ m_rkey[i - 1];
    }
}

void encryption::ExpandDecKey(unsigned char *buffer) {
    unsigned char i;

    for (i = 28; i > 16; i -= 4) {
        m_rkey[i + 0] = m_rkey[i + 0] ^ m_rkey[i - 4];
        m_rkey[i + 1] = m_rkey[i + 1] ^ m_rkey[i - 3];
        m_rkey[i + 2] = m_rkey[i + 2] ^ m_rkey[i - 2];
        m_rkey[i + 3] = m_rkey[i + 3] ^ m_rkey[i - 1];
    }

    m_rkey[16] = m_rkey[16] ^ sbox[m_rkey[12]];
    m_rkey[17] = m_rkey[17] ^ sbox[m_rkey[13]];
    m_rkey[18] = m_rkey[18] ^ sbox[m_rkey[14]];
    m_rkey[19] = m_rkey[19] ^ sbox[m_rkey[15]];

    for (i = 12; i > 0; i -= 4) {
        m_rkey[i + 0] = m_rkey[i + 0] ^ m_rkey[i - 4];
        m_rkey[i + 1] = m_rkey[i + 1] ^ m_rkey[i - 3];
        m_rkey[i + 2] = m_rkey[i + 2] ^ m_rkey[i - 2];
        m_rkey[i + 3] = m_rkey[i + 3] ^ m_rkey[i - 1];
    }

    *buffer = FD(*buffer);
    m_rkey[0] = m_rkey[0] ^ sbox[m_rkey[29]] ^ (*buffer);
    m_rkey[1] = m_rkey[1] ^ sbox[m_rkey[30]];
    m_rkey[2] = m_rkey[2] ^ sbox[m_rkey[31]];
    m_rkey[3] = m_rkey[3] ^ sbox[m_rkey[28]];
}

void encryption::enctypt(unsigned char *buffer) {
    unsigned char i, rcon;
    Copykey();
    AddRoundKey(buffer, 0);
    for (i = 1, rcon = 1; i < NUM_ROUNDS; ++i)
    {
        SubBytes(buffer);
        ShiftRows(buffer);
        MixColumns(buffer);
        if (!(i & 1))
            ExpandEncKey(&rcon);
        AddRoundKey(buffer, i);
    }
    SubBytes(buffer);
    ShiftRows(buffer);
    ExpandEncKey(&rcon);
    AddRoundKey(buffer, i);
}

void encryption::decrypt(unsigned char *buffer) {
    unsigned char i, rcon = 1;

    Copykey();
    for (i = NUM_ROUNDS / 2; i > 0; --i)
        ExpandDecKey(&rcon);

    AddRoundKey(buffer, NUM_ROUNDS);
    ShiftRows(buffer);
    SubBytes(buffer);

    for (i = NUM_ROUNDS, rcon = 0x80; --i;)
    {
        if ((i & 1))
            ExpandDecKey(&rcon);
        AddRoundKey(buffer, i);
        MixColumnsInv(buffer);
        ShiftRowsInv(buffer);
        SubBytesInv(buffer);
    }
    AddRoundKey(buffer, i);
}