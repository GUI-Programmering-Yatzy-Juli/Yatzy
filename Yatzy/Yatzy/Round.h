#ifndef ROUND_H
#define ROUND_H


#include "Game.h"
#include <ui_mainwindow.h>
#include "Player.h"

class Game;
class Round
{
public:
    Round(Ui::MainWindow *ui, Game *g);



    void newRound(Player *currentP);

    void isPossibleChangeColour (int r, int pCol, int score);

    Dice dice;

    int player1Turn = 0;
    int player2Turn = 0;

private:
    void showImage();
    void changeImage(QPushButton *btn, int pic);
    int checkNum(Dice dice, int n);

    void checkResult(Dice dice, int column);
    int checkPair(Dice dice);
    int checkThreeOfAKind(Dice dice);
    int checkFourOfAKind(Dice dice);
    int checkTwoPairs(Dice dice);
    int checkYatzy(Dice dice);
    int checkSmallLadder(Dice dice);
    int checkBigLadder(Dice dice);
    int checkFullHouse(Dice dice);
    int checkChance(Dice dice);

    Game *game;
    Ui::MainWindow *table;

public slots:
    void startNewRound(Player *currentP);
};

#endif // ROUND_H
