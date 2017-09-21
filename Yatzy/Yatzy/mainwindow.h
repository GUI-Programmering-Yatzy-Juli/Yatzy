#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Game.h"
#include "Round.h"
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
    void startNewGame();
    void textChange();
    void diceChange();
    void saveDice();

    Ui::MainWindow *ui;
public slots:


private slots:
    void on_btn_roll_clicked();

    void on_btn_roll_2_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_7_clicked();




private:


};

#endif // MAINWINDOW_H
