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
    void checkResult(Dice dice);

    Dice dice;

private:

};

#endif // ROUND_H
