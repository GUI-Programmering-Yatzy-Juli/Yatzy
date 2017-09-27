#ifndef GAME_H
#define GAME_H

#include "Dice.h"
#include "Round.h"
#include "Player.h"
#include "mainwindow.h"
#include <QPushButton>
#include <QObject>


class Game
{

public:
    Game(Ui::MainWindow *ui);
    int numRounds = 1;

    bool gameIsActive();

    Player p1;
    Player p2;

    int score[2][19];

    void calcScore(int pCol);
    int calcPointsTillBonus(int pCol);
    int calcTotal(int pCol);
    void makeChoice();

public slots:
     void update(Ui::MainWindow *ui);
};

#endif // GAME_H
