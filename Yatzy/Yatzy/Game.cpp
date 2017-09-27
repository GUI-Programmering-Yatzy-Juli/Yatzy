#include "Game.h"
#include <qdebug.h>
#include <QMessageBox>
#include <QApplication>
#include <QProcess>
#include <QTextEdit>
Game::Game(Ui::MainWindow *ui)
{
    qDebug() << "Första rundan startar";
    p1.pNum = 0;
    p2.pNum = 1;

    p1.rollsLeft = 3;
    p2.rollsLeft = 3;
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
            ui->label->setText("Player 1");                                 // Skulle kunna bli en while(p1.rollsLeft >= 1)   ui->label->setText("Player 1"); //
            ui->label->setStyleSheet("font: 75 14pt");
            qDebug() << "Slag kvar för spelare 1: " << p1.rollsLeft;
        }
        else if (p2.rollsLeft != 0)
        {
            round.newRound(&p2);
            //qDebug() << "p2";
            ui->label->setText("Player 2");
            ui->label->setStyleSheet("font: 75 14pt");
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
    if (numRounds > 16)
    {
        //utnämn vinnaren
        if (p1.score > p2.score)
        {
            qDebug() << "The Winner is player one";
            QTextEdit *txt = new QTextEdit();
            txt->setMaximumHeight(400);
            txt->setMaximumWidth(400);
            txt->setMinimumHeight(400);
            txt->setMinimumWidth(400);

                    txt->setText("The winner is player one");
                     txt->setStyleSheet("font: 15pt ; background-image: url(:/new/prefix1/fire/firew.png); background-repeat: no-repeat;");
                    txt->show();

                    txt->setEnabled(false);

        }
        else if (p1.score < p2.score)
        {
            qDebug() << "The Winner is player two";
            QTextEdit *txt = new QTextEdit();
            txt->setMaximumHeight(400);
            txt->setMaximumWidth(400);
            txt->setMinimumHeight(400);
            txt->setMinimumWidth(400);

                    txt->setText("The winner is player two");
                  txt->setStyleSheet("font: 15pt ; background-image: url(:/new/prefix1/fire/firew.png); background-repeat: no-repeat;");
                    txt->show();

                    txt->setEnabled(false);
        }
        else if (p1.score == p2.score)
        {
            qDebug() << "Its a tie";
            QTextEdit *txt = new QTextEdit();
            txt->setMaximumHeight(400);
            txt->setMaximumWidth(400);
            txt->setMinimumHeight(400);
            txt->setMinimumWidth(400);
                    txt->setText("It's a tie stand down, we'll get them another day lads.");
                  txt->setStyleSheet("font: 15pt ; background-image: url(:/new/prefix1/fire/tie.png); background-repeat: no-repeat;");
                    txt->show();

                    txt->setEnabled(false);

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

void Game::saveDice(int d)
{

}
