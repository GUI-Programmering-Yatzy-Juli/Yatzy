#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Game.h"
#include "Round.h"
#include "Dice.h"
#include "QTableWidget"

class Game;
namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    Game *g;
public:

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    Ui::MainWindow *ui;



public slots:


private slots:
    void on_btn_roll_clicked();

    void on_btn_roll_2_clicked();

    void on_btn_exit_clicked();

    void on_btn_rules_clicked();

    void on_tableWidget_cellClicked(int row, int column);



    void on_btn_save0_clicked();

    void on_btn_save1_clicked();

    void on_btn_save2_clicked();

    void on_btn_save3_clicked();

    void on_btn_save4_clicked();

private:
    void enableSaveBtn();


};

#endif // MAINWINDOW_H
