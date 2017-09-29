#ifndef GAME_H
#define GAME_H

#include "Dice.h"
#include "Round.h"
#include "Player.h"
#include "mainwindow.h"

class Round;
class Game
{
public:
    Game(Ui::MainWindow *ui);
    int numRounds = 1;
    Round *round;
    Player p1;
    Player p2;
    int score[19][2];
    void saveDice(int d);
    void populateArray();
    void update(Ui::MainWindow *ui);
    void showScore(Ui::MainWindow *ui, int pCol);
private:
    bool gameIsActive(Ui::MainWindow *ui);
    void calcScore(int pCol);
    int calcPointsTillBonus(int pCol);
    int calcTotal(int pCol);
    void tie();
    void win(int pNum);
    void btnAndLabelChange(Ui::MainWindow *ui, Player p);
};

#endif // GAME_H
