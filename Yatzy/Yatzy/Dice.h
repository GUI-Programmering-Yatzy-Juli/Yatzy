#ifndef DICE_H
#define DICE_H

#include <time.h>
#include <random>
#include <qdebug.h>


class Dice
{
public:
    Dice();
    void roll();
    int valueDice[4];
private:

};

#endif // DICE_H
