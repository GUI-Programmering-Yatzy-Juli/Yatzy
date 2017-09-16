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

    int checkOnes(Dice dice);
    int checkTwos(Dice dice);
    int checkThrees(Dice dice);
    int checkFours(Dice dice);
    int checkFives(Dice dice);
    int checkSixes(Dice dice);

    void checkResult(Dice dice);
    bool checkPair(Dice dice);
    bool checkThreeOfAKind(Dice dice);
    bool checkFourOfAKind(Dice dice);
    bool checkTwoPairs(Dice dice);
    bool checkYatzy(Dice dice);
    bool checkSmallLadder(Dice dice);
    bool checkBigLadder(Dice dice);
    bool checkFullHouse(Dice dice);
    bool checkChance(Dice dice);

    Dice dice;

private:

};

#endif // ROUND_H
