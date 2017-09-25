#ifndef CONFIG_H
#define CONFIG_H

#include "Mem_cleaning.h"
#include <QString>

class Config : public Mem_cleaning
{
private:


public:

    bool number,
    spec_char,
    small_letter,
    big_letter,
    in_dictionary,
    simple_sequence,
    policy;



};

#endif // CONFIG_H
