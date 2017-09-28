#include "Game.h"
#include <qdebug.h>
#include <QString>

#include <QMessageBox>
#include <QApplication>
#include <QProcess>
#include <QTextEdit>
#include <QThread>
#include <QMediaPlayer>


Game::Game(Ui::MainWindow *ui)
{
    qDebug() << "Första rundan startar";
    p1.pNum = 0;
    p2.pNum = 1;
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
             //calcScore(p1.pNum);
             showScore(ui);
             ui->btn_save0->setEnabled(true);
             ui->btn_save1->setEnabled(true);
             ui->btn_save2->setEnabled(true);
             ui->btn_save3->setEnabled(true);
             ui->btn_save4->setEnabled(true);

             if(p1.rollsLeft == 0)
             {
                  ui->btn_save0->setEnabled(false);
                  ui->btn_save1->setEnabled(false);
                  ui->btn_save2->setEnabled(false);
                  ui->btn_save3->setEnabled(false);
                  ui->btn_save4->setEnabled(false);
                  ui->btn_save0->setChecked(false);
                  ui->btn_save1->setChecked(false);
                  ui->btn_save2->setChecked(false);
                  ui->btn_save3->setChecked(false);
                  ui->btn_save4->setChecked(false);


             }

        }


        else if (p2.rollsLeft != 0)
        {
            round->newRound(&p2);
            btnAndLabelChange(ui, p2);
            //calcScore(p2.pNum);
            showScore(ui);
            ui->btn_save0->setEnabled(true);
            ui->btn_save1->setEnabled(true);
            ui->btn_save2->setEnabled(true);
            ui->btn_save3->setEnabled(true);
            ui->btn_save4->setEnabled(true);
            if(p2.rollsLeft == 0)
            {
                 ui->btn_save0->setEnabled(false);
                 ui->btn_save1->setEnabled(false);
                 ui->btn_save2->setEnabled(false);
                 ui->btn_save3->setEnabled(false);
                 ui->btn_save4->setEnabled(false);
                 ui->btn_save0->setChecked(false);
                 ui->btn_save1->setChecked(false);
                 ui->btn_save2->setChecked(false);
                 ui->btn_save3->setChecked(false);
                 ui->btn_save4->setChecked(false);
            }

        }

        else
        {
             p1.rollsLeft = 3;
             p2.rollsLeft = 3;
             numRounds++;
             update(ui);
        }


    if(numRounds > 3)
    {
        ui->btn_roll->setEnabled(false);
     }

    }
}

bool Game::gameIsActive()
{

    if (numRounds > 3)
    if (numRounds > 15)
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
            txt->setStyleSheet("font: 19pt; text-shadow: -1px 0 black, 0 1px black, 1px 0 black, 0 -1px black; color: black;  position: relative; bottom: 50; background-image: url(:/new/prefix1/fire/firew.png); background-repeat: no-repeat;");
            txt->show();
            txt->setEnabled(false);

            QMediaPlayer * music = new QMediaPlayer();
            music->setMedia(QUrl("qrc:/new/prefix1/Dices/YOU WIN.mp3"));
            music->play();


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
            txt->setStyleSheet("font: 19pt; text-shadow: -1px 0 black, 0 1px black, 1px 0 black, 0 -1px black; color: black;position: relative; bottom: 50;background-image: url(:/new/prefix1/fire/firew.png); background-repeat: no-repeat;");
            txt->show();
            txt->setEnabled(false);

            QMediaPlayer * music = new QMediaPlayer();
            music->setMedia(QUrl("qrc:/new/prefix1/Dices/YOU WIN.mp3"));
            music->play();

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
            txt->setStyleSheet("font: 19pt;text-border: 12px 12px yellow;  color: black; position: relative; bottom: 50; background-image: url(:/new/prefix1/fire/tie.png); background-repeat: no-repeat;");
            txt->show();
            txt->setEnabled(false);

            QMediaPlayer * music = new QMediaPlayer();
            music->setMedia(QUrl("qrc:/new/prefix1/Dices/Tie.mp3"));
            music->play();

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
    qDebug() << score[0][0] << score[1][0] << score[2][0] << score[3][0] << score[4][0] << score[5][0] << score[6][0] << score[7][0] << score[8][0]
             << score[9][0] << score[10][0] << score[11][0] << score[12][0] << score[13][0] << score[14][0] << score[15][0] << score[16][0] << score[17][0];
    qDebug() << score[0][1] << score[1][1] << score[2][1] << score[3][1] << score[4][1] << score[5][1] << score[6][1] << score[7][1] << score[8][1]
             << score[9][1] << score[10][1] << score[11][1] << score[12][1] << score[13][1] << score[14][1] << score[15][1] << score[16][1] << score[17][0];
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

    for (int pCol = 0; pCol < 2; pCol++)
    {
        for (int r = 0; r < 18; r++)
        {
            score[r][pCol] = 0;
        }
    }
}

void Game::btnAndLabelChange(Ui::MainWindow *ui, Player p)
{
    ui->btn_roll->setText("Rolls left " + QString::number(p.rollsLeft ) + " /3");
    ui->label->setText("Player " + QString::number(p.pNum  + 1) + "    Runda " + QString::number(numRounds));
    ui->btn_roll->setText("Roll " + QString::number(p.rollsLeft) + " /3");
    ui->label->setText("Player " + QString::number(p.pNum + 1) + "    Runda " + QString::number(numRounds));
}


