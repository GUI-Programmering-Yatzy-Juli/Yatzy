#ifndef PLAYER_H
#define PLAYER_H

#include "Dice.h"

class Player
{
public:
    Player();

    int score;

    int rollsLeft = 3;
    int roundsLeft = 13;

    int pNum;

    int savedDice[5] = {0, 0, 0, 0, 0};

    void checkSavedDice(Dice *dice, Player *currentP);
};

#endif // PLAYER_H
