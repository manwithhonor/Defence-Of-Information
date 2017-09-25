#ifndef DIALOG_FOR_ADMIN_1_H
#define DIALOG_FOR_ADMIN_1_H

#include <QDialog>
#include "Config.h"

namespace Ui {
class Dialog_for_admin_1;
}

class Dialog_for_admin_1 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_for_admin_1(QWidget *parent = 0);
    ~Dialog_for_admin_1();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog_for_admin_1 *ui;

    Config  set_value();
    void receive_value();
};

#endif // DIALOG_FOR_ADMIN_1_H
