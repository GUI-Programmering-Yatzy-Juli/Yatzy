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

    bool gameIsActive(Player p1, Player p2);

    void initiateRound(Player *currentP);

public slots:
    //connect(Ui::MainWindow->btn_roll, SIGNAL (click()), this, SLOT (initiateRound(currentP)));

};

#endif // GAME_H
