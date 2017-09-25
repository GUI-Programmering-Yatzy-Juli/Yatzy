#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include "Game.h"
#include "mainwindow.h"
#include <ui_mainwindow.h>

class gameManager
{
public:
    gameManager(Ui::MainWindow *ui);

    Player player1;
    Player player2;

    void test();

    void startRound(Ui::MainWindow *ui);

private:

};

#endif // GAMEMANAGER_H
