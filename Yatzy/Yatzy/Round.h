#ifndef ROUND_H
#define ROUND_H

#include "Dice.h"
#include "Game.h"
#include <qdebug.h>

class Round
{
public:
    Round();
    void startNewRound();
    void newRound(Dice dice);

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

    Dice dice;

private:

};

#endif // ROUND_H
