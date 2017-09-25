#ifndef PASSWORD_H
#define PASSWORD_H

#include <QString>
#include "Mem_cleaning.h"
#include "Config.h"

class Password : public Mem_cleaning
{ private:
    int my_hash(QString str);
    bool rabbin_carp(QString str,Config cfg);
    bool check_policy(Config cfg);
    bool check_number ( QString str , Config cfg) ;
    bool check_small_letter ( QString str , Config cfg) ;
    bool check_big_letter ( QString str , Config cfg) ;
    bool check_spec_char ( QString str , Config cfg) ;
    bool check_simple_sequence ( QString str , Config cfg) ;
    bool check_in_dictionary ( QString str , Config cfg) ;

public:
    QByteArray in_data_base_search(QString service_name);
    Config check_all(QString str , Config cfg);
    void from_data_base_delete(QString service_name);
    void replace_in_data_base(QString service_name, QByteArray password);
};


#endif // PASSWORD_H
