#ifndef GAME_H
#define GAME_H

#include "Dice.h"
#include "Round.h"
#include "gamemanager.h"


class Game
{
public:
    Game();
    int numRounds = 0;
    bool gameIsActive();

    int player1 = 0;
    int player2 = 0;
};

#endif // GAME_H
