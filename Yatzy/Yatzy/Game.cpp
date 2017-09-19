#include "Game.h"
#include <qdebug.h>

Game::Game()
{
    Round round;
    qDebug() << "Första rundan startar";

    while (gameIsActive())
    {
        qDebug() << numRounds;
        for (int r = 0; r <4; r++)
        {
            round.startNewRound();
            //player1
            qDebug() << "player1";
        }
        for (int r = 0; r <4; r++)
        {
            round.startNewRound();
            //player2
            qDebug() << "player2";
        }
    }
}

bool Game::gameIsActive()
{
    if (numRounds == 13)
    {
        //utnämn vinnaren
        if (player1 > player2)
        {
            qDebug() << "The Winner is player one";
        }
        else if (player1 < player2)
        {
            qDebug() << "The Winner is player two";
        }
        else if (player1 == player2)
        {
            qDebug() << "Its a tie";
        }
        //avsluta spelet
        return false;
    }
    else
    {

        numRounds++;
        return true;
    }
}




