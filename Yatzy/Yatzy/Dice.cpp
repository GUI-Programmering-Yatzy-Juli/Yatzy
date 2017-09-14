#include "Dice.h"
#include <random>

Dice::Dice()
{

}

void Dice::roll()
{
    srand(time(NULL));
    for (int i = 0; i < 5; i++)
    {
        valueDice[i] = rand() % 6 + 1;
        if (savedDice[i] != NULL)       //kollar ifall någon tärning är sparad och sätter in den i platsen
        {
            valueDice[i] = savedDice[i];
        }
    }
    return;
}
