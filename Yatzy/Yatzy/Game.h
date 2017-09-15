#ifndef GAME_H
#define GAME_H

#include "Dice.h"
#include "Round.h"
#include "gamemanager.h"


class Game
{
public:
    Game();
    int numRounds;
    bool gameIsActive();
};

#endif // GAME_H
