#include "Game.h"

#include <qdebug.h>

Game::Game()
{
    Round round1;
    qDebug() << "Första rundan startar";
    while (gameIsActive())
    {
        //player1Turn

        //player2Turn
    }
}


bool Game::gameIsActive()
{
    if (this->numRounds = 13)
    {
        //utnämn vinnaren
        //avsluta spelet
        return 0;
    }
    else
    {
        return 1;
    }
}
