#include "gamemanager.h"
#include <qdebug.h>

gameManager::gameManager()
{
    qDebug() << "game-objektet skapas";
    Game game;
    game.numRounds = 0;
}

//scores ska vara en vektor, det är som en 2d array
