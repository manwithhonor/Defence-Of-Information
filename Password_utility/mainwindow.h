#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionAdd_to_base_triggered();

    void on_actionReceive_from_base_triggered();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_actionAdministration_triggered();

    void on_pushButton_4_clicked();

    void on_actionDelete_from_base_triggered();

    void on_pushButton_5_clicked();

    void on_actionChange_in_base_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
