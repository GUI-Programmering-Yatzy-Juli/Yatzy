#ifndef PLAYER_H
#define PLAYER_H

#include "Dice.h"

class Player
{
public:
    Player();

    int score = 0;

    int rollsLeft = 3;
    int roundsLeft = 13;

    bool isCurrentPlayer = false;

    int savedDice[5] = {0, 0, 0, 0, 0};

    void checkSavedDice(Dice *dice, Player *currentP);
};

#endif // PLAYER_H
