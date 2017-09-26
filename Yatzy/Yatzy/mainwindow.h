#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Game.h"
#include "Round.h"
#include "Dice.h"
#include "QTableWidget"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void start();

    Ui::MainWindow *ui;
public slots:


private slots:
    void on_btn_roll_clicked();

    void on_btn_roll_2_clicked();

    void on_btn_exit_clicked();

    void on_btn_rules_clicked();

   // void on_pushButton_7_clicked();

    void on_tableWidget_cellClicked(int row, int column);

private:
    void enableSaveBtn();
};

#endif // MAINWINDOW_H
