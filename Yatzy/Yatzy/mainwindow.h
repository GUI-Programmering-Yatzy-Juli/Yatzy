#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Game.h"
#include "round.h"

extern Game game;

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

private slots:
    void on_btn_roll_clicked();

    void on_btn_start_clicked();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
