#include "Player.h"

Player::Player()
{

}


void Player::checkSavedDice(Dice *dice, Player *currentP)
{



    for (int i = 0; i < 5; i++)
    {
        if (currentP->savedDice[i] != 0)
        {
            dice->valueDice[i] = currentP->savedDice[i];
        }
    }
}




