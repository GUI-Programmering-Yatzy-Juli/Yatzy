#include "Dice.h"
#include <random>
#include <qdebug.h>

Dice::Dice()
{
    qDebug() << "Tärningarna har skapats";
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
    qDebug() << valueDice[0] << valueDice[1]<< valueDice[2]<< valueDice[3]<< valueDice[4];


}
