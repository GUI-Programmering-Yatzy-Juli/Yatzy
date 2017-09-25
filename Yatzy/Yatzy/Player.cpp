#include "Player.h"

Player::Player()
{

}

void Player::checkSavedDice(Dice *dice, Player *currentP)
{

    qDebug() << "Kollar savedDice";
    qDebug() << dice->valueDice[0] << dice->valueDice[1] << dice->valueDice[2] << dice->valueDice[3] << dice->valueDice[4];
    for (int i = 0; i < 5; i++)
    {
        if (currentP->savedDice[i] != 0)
        {
            dice->valueDice[i] = currentP->savedDice[i];
        }
    }
    qDebug() << dice->valueDice[0] << dice->valueDice[1] << dice->valueDice[2] << dice->valueDice[3] << dice->valueDice[4];
}


