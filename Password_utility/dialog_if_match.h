#ifndef DIALOG_IF_MATCH_H
#define DIALOG_IF_MATCH_H

#include <QDialog>

namespace Ui {
class Dialog_if_match;
}

class Dialog_if_match : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_if_match(QWidget *parent = 0);
    ~Dialog_if_match();

private slots:
    void on_pushButton_3_clicked();

public slots:
   void recieveData(QString str, QString str1, QString str2);

private:
    Ui::Dialog_if_match *ui;
};

#endif // DIALOG_IF_MATCH_H
