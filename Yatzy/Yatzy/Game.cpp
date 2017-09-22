#include "Game.h"
#include <qdebug.h>

Game::Game(Ui::MainWindow *ui)
{
    qDebug() << "Första rundan startar";
    play(ui);
}

void Game::play(Ui::MainWindow *ui)
{
    Round round(ui);

    Player player1;
    Player player2;

    if (gameIsActive(player1, player2))
    {
        qDebug() << numRounds;

        if (player1.rollsLeft != 0)
        {
            round.newRound(&player1);
            /*qDebug() << "player1";*/
        }
        else if (player2.rollsLeft != 0)
        {
            round.newRound(&player1);
            /*qDebug() << "player2";*/
        }
        else
        {
            player1.rollsLeft = 3;
            player2.rollsLeft = 3;
            numRounds++;
        }
    }
}

bool Game::gameIsActive(Player p1, Player p2)
{
    if (numRounds > 13)
    {
        //utnämn vinnaren
        if (p1.score > p2.score)
        {
            qDebug() << "The Winner is player one";
        }
        else if (p1.score < p2.score)
        {
            qDebug() << "The Winner is player two";
        }
        else if (p1.score == p2.score)
        {
            qDebug() << "Its a tie";
        }
        //avsluta spelet
        return false;
    }
    else
    {
        return true;
    }
}

