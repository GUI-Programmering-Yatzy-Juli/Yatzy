#ifndef GAME_H
#define GAME_H

#include "Dice.h"
#include "Round.h"
#include "gamemanager.h"
#include "Player.h"
#include "mainwindow.h"


class Game
{
public:
    Game(Ui::MainWindow *ui);
    int numRounds = 1;

    void play(Ui::MainWindow *ui);

    bool gameIsActive(Player p1, Player p2);

public slots:


};

#endif // GAME_H
