#ifndef DIALOG_FOR_DELETE_H
#define DIALOG_FOR_DELETE_H

#include <QDialog>

namespace Ui {
class Dialog_for_delete;
}

class Dialog_for_delete : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_for_delete(QWidget *parent = 0);
    ~Dialog_for_delete();

private slots:
    void on_pushButton_3_clicked();

private:
    Ui::Dialog_for_delete *ui;
};

#endif // DIALOG_FOR_DELETE_H
