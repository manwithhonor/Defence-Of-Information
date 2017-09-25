#ifndef KUZNYECHIK_H
#define KUZNYECHIK_H

#include <vector>
#include "mycrypto.h"
#define BLOCK_LENGTH 16

class Kuznyechik {
    std::vector<ByteBlock> keys;
    static bool is_init;
public:
    static const int block_lenght {BLOCK_LENGTH};

    Kuznyechik(const ByteBlock & key);
    Kuznyechik(const Kuznyechik & rhs);
    ~Kuznyechik();
    void encrypt(const ByteBlock & src, ByteBlock & dst) const;
    void decrypt(const ByteBlock & src, ByteBlock & dst) const;
};

#endif // KUZNYECHIK_H
