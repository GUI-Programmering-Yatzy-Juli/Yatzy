#include "Game.h"
#include <qdebug.h>

Game::Game(Ui::MainWindow *ui, Player player1, Player player2)
{
    qDebug() << "Första rundan startar";

    p1 = player1;
    p2 = player2;

    connect(ui->btn_roll, SIGNAL(clicked(bool)), this, SLOT(on_btn_roll_click()));
    update(ui);

}

void Game::update(Ui::MainWindow *ui)
{
    Round round(ui);

    if (gameIsActive())
    {
        qDebug() << "Runda: " << numRounds;

        if (p1.rollsLeft != 0)
        {
            //round.newRound(&player1);
            //qDebug() << "p1";
            qDebug() << "Slag kvar för spelare 1: " << p1.rollsLeft;
        }
        else if (p2.rollsLeft != 0)
        {
            //round.newRound(&player1);
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

void Game::on_btn_roll_click()
{
    qDebug() << "Det funkar faktiskt!";
}
