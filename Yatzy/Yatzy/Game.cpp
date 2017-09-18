#include "Game.h"
#include <qdebug.h>

Game::Game()
{
    Round round;
    qDebug() << "Första rundan startar";

    /*while (gameIsActive())
    {
        if (currentPlayer == 1)
        {
            for (int r = 0; r < 3; r++)
            {
               //round.startNewRound();
            }
            currentPlayer++;
            //player1turn
        }
        else if (currentPlayer == 2)
        {
            for (int r = 0; r < 3; r++)
            {
               //round.startNewRound();
            }
            currentPlayer++;
            //player2Turn
        }
        else if (currentPlayer == 3)
        {
            numRounds++;
            currentPlayer = 1;
            //roundEnd
        }
    }*/
}

bool Game::gameIsActive()
{
    if (numRounds == 13)
    {
        //utnämn vinnaren
        //avsluta spelet
        return false;
    }
    else
    {
        return true;
    }
}
