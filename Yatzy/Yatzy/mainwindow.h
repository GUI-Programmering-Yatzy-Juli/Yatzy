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
    void enableSaveBtn();
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Ui::MainWindow *ui;
private slots:
    void on_btn_roll_clicked();
    void on_btn_roll_2_clicked();
    void on_btn_exit_clicked();
    void on_btn_rules_clicked();
    void on_pushButton_clicked();
    void on_tableWidget_cellClicked(int row, int column);

    void on_btn_save0_toggled(bool checked);
    void on_btn_save1_toggled(bool checked);
    void on_btn_save2_toggled(bool checked);
    void on_btn_save3_toggled(bool checked);
    void on_btn_save4_toggled(bool checked);
};

#endif // MAINWINDOW_H
