#include "Game.h"
#include <qdebug.h>

Game::Game(Ui::MainWindow *ui)
{
    qDebug() << "Första rundan startar";
    p1.pNum = 0;
    p2.pNum = 1;
}

void Game::update(Ui::MainWindow *ui)
{

    qDebug() << "funktion";

    Round round(ui);

    if (gameIsActive())
    {
        qDebug() << "Runda: " << numRounds;

        if (p1.rollsLeft != 0)
        {
            round.newRound(&p1);
            //qDebug() << "p1";
            qDebug() << "Slag kvar för spelare 1: " << p1.rollsLeft;
        }
        else if (p2.rollsLeft != 0)
        {
            //round.newRound(&p2);
            //qDebug() << "p2";
            qDebug() << "Slag kvar för spelare 2: " << p2.rollsLeft;
        }
        else
        {
            p1.rollsLeft = 3;
            p2.rollsLeft = 3;
            numRounds++;
        }
    }

}

bool Game::gameIsActive()
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

void Game::calcScore(int pCol)
{

    score[6][pCol] = calcPointsTillBonus(pCol);     //Poäng till bonus col 6
    if (score[6][pCol] >= 63)                       //Bonus col 7
    {
        score[7][pCol] = 50;
    }
    score[17][pCol] = calcTotal(pCol);
    qDebug() << score[17][pCol];
}

int Game::calcPointsTillBonus(int pCol)
{
    //points till bonus row 6
    int sum = 0;
    for (int i = 0; i < 6; i++)
    {
        sum = score[i][pCol];
    }
    return sum;
}

int Game::calcTotal(int pCol)
{
    int sum = 0;
    for (int i = 0; i < 17; i++)
    {
        score[i][pCol] += sum;
    }
    return sum;
}

void Game::makeChoice()
{

}
