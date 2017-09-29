#include "Game.h"
#include <QString>
#include <QTextEdit>
#include <QMediaPlayer>
#include <QMessageBox>

Game::Game(Ui::MainWindow *ui)
{
    p1.pNum = 0;
    p2.pNum = 1;
}

void Game::update(Ui::MainWindow *ui)
{
    round = new Round(ui, this);

    if (gameIsActive(ui))
    {
        if (p1.rollsLeft != 0)
        {
             round->newRound(&p1);
             btnAndLabelChange(ui, p1);
             showScore(ui, p1.pNum);
        }
        else if (p2.rollsLeft != 0)
        {
            round->newRound(&p2);
            btnAndLabelChange(ui, p2);
            showScore(ui, p2.pNum);
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

bool Game::gameIsActive(Ui::MainWindow *ui)
{

    if (numRounds > 15)
    {



        //utnämn vinnaren
        if (p1.score > p2.score)
        {
            win(p1.pNum + 1);
        }
        else if (p1.score < p2.score)
        {
            win(p2.pNum + 1);
        }
        else if (p1.score == p2.score)
        {
            tie();
        }
ui->btn_roll->setVisible(false);
ui->label->setVisible(false);
ui->pushButton->setVisible(true);
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
    if (score[6][pCol] <= 0)                       //Bonus col 7
    {
        score[7][pCol] = 50;
    }
    score[17][pCol] = calcTotal(pCol);
    if (p1.pNum == pCol)
    {
        p1.score = calcTotal(pCol);
    }
    else if (p2.pNum == pCol)
    {
        p2.score = calcTotal(pCol);
    }
}

int Game::calcPointsTillBonus(int pCol)
{
    //points till bonus row 6
    int sum = 0;
    for (int i = 0; i < 6; i++)
    {
        sum += score[i][pCol];
    }
    return 63 - sum;
}

int Game::calcTotal(int pCol)
{
    int sum = 0;
    for (int i = 0; i < 17; i++)
    {
        if(i != 6)
        {
            sum += score[i][pCol];
        }
    }
    return sum;
}

void Game::showScore(Ui::MainWindow *ui, int pCol)
{
        calcScore(pCol);
        for (int r = 0; r < 18; r++)
        {
            if (score[r][pCol] > 0 || r == 7 || r == 6)
            {
                if (score[6][pCol] < 0)
                {
                    ui->tableWidget->setItem(6, pCol, new QTableWidgetItem("0"));
                    ui->tableWidget->item(6, pCol)->setBackground(Qt::lightGray);
                }
                QString myStr = QString::number(score[r][pCol]);
                ui->tableWidget->setItem(r, pCol, new QTableWidgetItem(myStr));
                if (r != 6 && r != 7 && r != 17)
                {
                    ui->tableWidget->item(r, pCol)->setBackgroundColor(Qt::green);
                }
                else
                {
                    ui->tableWidget->item(r, pCol)->setBackground(Qt::lightGray);
                }
            }
        }
}

void Game::saveDice(int dLoc)
{
    // dLoc är platsen på tärnigen man vill spara
    if (round->current->savedDice[dLoc] == 0)
    {
        round->current->savedDice[dLoc] = round->dice.valueDice[dLoc];
    }
    else if (round->current->savedDice[dLoc] != 0)
    {
        round->current->savedDice[dLoc] = 0;
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
    ui->label->setText("Player " + QString::number(p.pNum  + 1) + "    Runda " + QString::number(numRounds)+ " /15");

    ui->btn_save0->setEnabled(true);
    ui->btn_save1->setEnabled(true);
    ui->btn_save2->setEnabled(true);
    ui->btn_save3->setEnabled(true);
    ui->btn_save4->setEnabled(true);

    if(p.rollsLeft == 0)
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

void Game::tie()
{
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
}

void Game::win(int pNum)
{
    QTextEdit *txt = new QTextEdit();
    txt->setMaximumHeight(400);
    txt->setMaximumWidth(400);
    txt->setMinimumHeight(400);
    txt->setMinimumWidth(400);
    txt->setText("The winner is player " + QString::number(pNum));
    txt->setStyleSheet("font: 19pt; color: black;position: relative; bottom: 50;background-image: url(:/new/prefix1/fire/firew.png); background-repeat: no-repeat;");
    txt->show();
    txt->setEnabled(false);
    QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/new/prefix1/Dices/YOU WIN.mp3"));
    music->play();
}
