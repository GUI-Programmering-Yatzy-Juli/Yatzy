#include "Game.h"
#include <qdebug.h>
#include <QString>

#include <QMessageBox>
#include <QApplication>
#include <QProcess>
#include <QTextEdit>
Game::Game(Ui::MainWindow *ui)
{
    qDebug() << "Första rundan startar";
    p1.pNum = 0;
    p2.pNum = 1;

    populateArray();
}

void Game::update(Ui::MainWindow *ui)
{
    qDebug() << "funktion";

    round = new Round(ui, this);

    if (gameIsActive())
    {
        qDebug() << "Runda: " << numRounds;

        if (p1.rollsLeft != 0)
        {
             round->newRound(&p1);
             btnAndLabelChange(ui, p1);
             calcScore(p1.pNum);
             showScore(ui);
        }
        else if (p2.rollsLeft != 0)
        {
            round->newRound(&p2);
            btnAndLabelChange(ui, p2);
            calcScore(p2.pNum);
            showScore(ui);
        }
        else
        {
             p1.rollsLeft = 3;
             p2.rollsLeft = 3;
             numRounds++;
             update(ui);
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

void Game::showScore(Ui::MainWindow *ui)
{
    for (int pCol = 0; pCol < 2; pCol++)
    {
        for (int r = 0; r < 17; r++)
        {
            if (score[r][pCol] > 0)
            {
                QString myStr = QString::number(score[r][pCol]);
                ui->tableWidget->setItem(r, pCol, new QTableWidgetItem(myStr));
                ui->tableWidget->item(r, pCol)->setBackgroundColor(Qt::yellow);
            }
        }
    }
}

void Game::makeChoice(int row, int column)
{

}

void Game::saveDice(int dLoc)
{
    // dLoc är platsen på tärnigen man vill spara
    if (round->current->savedDice[dLoc] == 0)
    {
        round->current->savedDice[dLoc] = round->dice.valueDice[dLoc];
        qDebug() << "tärning sparad";
    }
    else if (round->current->savedDice[dLoc] != 0)
    {
        round->current->savedDice[dLoc] = 0;
        qDebug() << "tärning osparad";
    }

}

void Game::populateArray()
{
    for (int p = 0; p > 2; p++)
    {
        for (int r = 0; r > 19; r++)
        {
            score[r][p] = 0;
        }
    }
}

void Game::btnAndLabelChange(Ui::MainWindow *ui, Player p)
{
    ui->btn_roll->setText("Roll " + QString::number(p.rollsLeft + 1) + " /3");
    ui->label->setText("Player " + QString::number(p.pNum + 1) + "    Runda " + QString::number(numRounds));
}

