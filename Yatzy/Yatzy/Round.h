#ifndef ROUND_H
#define ROUND_H

#include "Dice.h"
#include "Game.h"
#include <qdebug.h>
#include "Player.h"
#include "mainwindow.h"
#include <ui_mainwindow.h>

class Round
{
public:
    Round(Ui::MainWindow *ui);

    void newRound(Player *currentP);
    void isPossibleChangeColour (int y, int x, int score);

    Dice dice;

    int player1Turn = 0;
    int player2Turn = 0;

private:
    int checkNum(Dice dice, int n);

    void checkResult(Dice dice);
    int checkPair(Dice dice);
    int checkThreeOfAKind(Dice dice);
    int checkFourOfAKind(Dice dice);
    int checkTwoPairs(Dice dice);
    int checkYatzy(Dice dice);
    int checkSmallLadder(Dice dice);
    int checkBigLadder(Dice dice);
    int checkFullHouse(Dice dice);
    int checkChance(Dice dice);

     Ui::MainWindow *table;

public slots:
    void startNewRound(Player *currentP);

private slots:
    void on_btn_roll_clicked();
};

#endif // ROUND_H
