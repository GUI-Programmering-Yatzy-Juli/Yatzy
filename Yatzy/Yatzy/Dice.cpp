#include "Dice.h"
#include <cstdlib>
#include <ctime>
using namespace std;

Dice::Dice()
{
    srand(time(NULL));
    roll();
}

void Dice::roll()
{
    for (int i = 0; i < 5; i++)
    {
        valueDice[i] = rand() % 6 + 1;
    }
}
