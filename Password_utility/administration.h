#ifndef ADMINISTRATION_H
#define ADMINISTRATION_H

#include <QString>
#include "Config.h"


class Administration
{
private:
   static char to_char(bool parametr);
   static bool to_bool(char symbol);

public:
    static Config config_read(Config cfg);
    static void config_output(Config cfg, QString dic ,QString base);
    static QString receive_path_to_dictionary();
    static QString receive_path_to_data_base();
    static QString receive_admin_pswd();
    static QString receive_key();
    static QString receive_iv();
    static void change_admin_pswd(QString pswd);
    static QString  get_path_to_adm_file();
};


#endif // ADMINISTRATION_H
