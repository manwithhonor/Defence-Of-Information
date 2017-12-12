#ifndef ENCRYPTION_H
#define ENCRYPTION_H
#pragma once
#include <vector>

typedef std::vector<unsigned char> ArrayByte;

#define BLOCK_SIZE 16

class encryption
{
public:
    encryption(const ArrayByte &key, unsigned char *buffer);
    ~encryption();

//private:

    ArrayByte m_key;
    ArrayByte m_rkey;

    //SubBytes() обрабатывает каждый байт состо¤ни¤,
    //независимо производ¤ нелинейную замену байтов использу¤ таблицу замен (S-box)
    void SubBytes(unsigned char* buffrer);
    void SubBytesInv(unsigned char* buffrer);

    //строки состо¤ни¤ циклически сдвигаютс¤ на i байт по горизонтали, в зависимости от номера строки
    void ShiftRows(unsigned char* buffer);
    void ShiftRowsInv(unsigned char* buffer);

    //четыре байта каждой колонки смешиваютс¤, использу¤ дл¤ этого обратимую линейную трансфорамцию
    void MixColumns(unsigned char* buffer);
    void MixColumnsInv(unsigned char* buffer);

    //RoundKey объедин¤етс¤ с промежуточным результатом шифровани¤
    void AddRoundKey(unsigned char* buffer, unsigned char roundkey);

    void Copykey();

    //расширение ключа шифровани¤ и расшифровани¤
    void ExpandEncKey(unsigned char *buffer);
    void ExpandDecKey(unsigned char *buffer);

    //функции шифровани¤ и расшифровани¤
    void enctypt(unsigned char *buffer);
    void decrypt(unsigned char *buffef);
};
#endif // ENCRYPTION_H
