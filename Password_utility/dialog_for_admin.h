#ifndef DIALOG_FOR_ADMIN_H
#define DIALOG_FOR_ADMIN_H

#include <QDialog>

namespace Ui {
class Dialog_for_admin;
}

class Dialog_for_admin : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_for_admin(QWidget *parent = 0);
    ~Dialog_for_admin();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog_for_admin *ui;
};

#endif // DIALOG_FOR_ADMIN_H
