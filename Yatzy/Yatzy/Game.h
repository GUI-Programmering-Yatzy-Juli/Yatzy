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

    bool gameIsActive(Ui::MainWindow *ui);

    Round *round;

    Player p1;
    Player p2;

    int score[19][2];

    void calcScore(int pCol);
    int calcPointsTillBonus(int pCol);
    int calcTotal(int pCol);
    void showScore(Ui::MainWindow *ui, int pCol);

    void saveDice(int d);
    void populateArray();


private:

    void btnAndLabelChange(Ui::MainWindow *ui, Player p);

public slots:
     void update(Ui::MainWindow *ui);
};

#endif // GAME_H
