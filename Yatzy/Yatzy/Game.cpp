#include "Game.h"
#include <qdebug.h>

Game::Game(Ui::MainWindow *ui)
{
    qDebug() << "Första rundan startar";

    connect(ui->btn_roll, SIGNAL(clicked(bool)), this, SLOT(on_btn_roll_click()));

    /*while (ui->btn_roll->hasFocus())
    {
        update(ui);
    }*/
    update(ui);
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
            system("pause");
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

void Game::on_btn_roll_click()
{
    qDebug() << "Det funkar faktiskt123123123!";
}
