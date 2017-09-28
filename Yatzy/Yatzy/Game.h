#ifndef GAME_H
#define GAME_H

#include "Dice.h"
#include "Round.h"
#include "Player.h"
#include "mainwindow.h"
#include <QPushButton>
#include <QObject>

class Round;
class Game
{

public:
    Game(Ui::MainWindow *ui);
    int numRounds = 1;

    bool gameIsActive();

    Round *round;

    Player p1;
    Player p2;

    int score[19][2];

    void calcScore(int pCol);
    int calcPointsTillBonus(int pCol);
    int calcTotal(int pCol);
    void showScore(Ui::MainWindow *ui);

    void makeChoice(int row, int column);
    void saveDice(int d);
    void populateArray();

private:

public slots:
     void update(Ui::MainWindow *ui);
};

#endif // GAME_H
