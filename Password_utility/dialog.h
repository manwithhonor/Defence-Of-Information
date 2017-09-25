#ifndef DIALOG_H
#define DIALOG_H


#include <QDialog>
#include <QString>
#include "dialog_if_match.h"
#include "ui_dialog_if_match.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

 private slots:
    void on_pushButton_clicked();
     void onButtonSend();

signals:
    void sendData(QString str,QString str1,QString str2);
    void trigger_my();


private:

 Ui::Dialog *ui;
 Dialog_if_match *dialog_if_match;
};

#endif // DIALOG_H
