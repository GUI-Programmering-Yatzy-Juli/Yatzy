#include "Round.h"
#include <QMediaPlayer>

Round::Round(Ui::MainWindow *ui, Game *g)
{
    table = ui;
    game = g;
}

void Round::newRound(Player *currentP)
{
    current = currentP;
    resetColour();
    currentP->checkSavedDice(&dice, currentP);
    checkResult(dice, currentP->pNum);
    currentP->rollsLeft--;
    showImage();
}

void Round::showImage()
{
    changeImage(table->btn_save0, dice.valueDice[0]);
    changeImage(table->btn_save1, dice.valueDice[1]);
    changeImage(table->btn_save2, dice.valueDice[2]);
    changeImage(table->btn_save3, dice.valueDice[3]);
    changeImage(table->btn_save4, dice.valueDice[4]);
}

void Round::changeImage(QPushButton *btn, int pic)
{
    switch (pic)
    {
    case 1:
        btn->setIcon(QIcon(QPixmap(":/new/prefix1/Dices/1.png")));
        btn->setIconSize(QSize(100, 100));
        break;
    case 2:
        btn->setIcon(QIcon(QPixmap(":/new/prefix1/Dices/2.png")));
        btn->setIconSize(QSize(100, 100));
        break;
    case 3:
        btn->setIcon(QIcon(QPixmap(":/new/prefix1/Dices/3.png")));
        btn->setIconSize(QSize(100, 100));
        break;
    case 4:
        btn->setIcon(QIcon(QPixmap(":/new/prefix1/Dices/4.png")));
        btn->setIconSize(QSize(100, 100));
        break;
    case 5:
        btn->setIcon(QIcon(QPixmap(":/new/prefix1/Dices/5.png")));
        btn->setIconSize(QSize(100, 100));
        break;
    case 6:
        btn->setIcon(QIcon(QPixmap(":/new/prefix1/Dices/6.png")));
        btn->setIconSize(QSize(100, 100));
        break;
    default:
        break;
    }
}

void Round::checkResult(Dice dice, int column)
{
    for (int i = 0; i < 18; i++)        //Sätter 0 som värde på alla platser
    {
        roundScore[i] = 0;
    }
    roundScore[8] = checkPair(dice);
    roundScore[9] = checkTwoPairs(dice);
    roundScore[10] = checkThreeOfAKind(dice);
    roundScore[11] = checkFourOfAKind(dice);
    roundScore[12] = checkSmallLadder(dice);
    roundScore[13] = checkBigLadder(dice);
    roundScore[14] = checkFullHouse(dice);
    roundScore[15] = checkChance(dice);
    roundScore[16] = checkYatzy(dice);

    for (int i = 1; i < 7; i++)
    {
        int sum = checkNum(dice, i);
        if (sum > 0)
        {
            roundScore[i - 1] = sum;
        }
    }

    for (int i = 0; i < 18; i++)
    {
        if (roundScore[i] > 0)
        {
            isPossibleChangeColour(i, column, roundScore[i]);
        }
    }
}

int Round::checkPair(Dice dice)
{
    int firstPairValue = 0;
    int secondPairValue = 0;

    for (int firstDice = 0; firstDice < 5; firstDice++)
    {
       for (int secondDice = firstDice+1; secondDice < 5; secondDice++)
       {
           if (dice.valueDice[firstDice] == dice.valueDice[secondDice] && dice.valueDice[firstDice] != 0)
           {
                if (firstPairValue == 0)
                {
                    firstPairValue = dice.valueDice[firstDice] * 2;
                    dice.valueDice[firstDice] = 0;
                    dice.valueDice[secondDice] = 0;
                }
                else if (secondPairValue == 0 && dice.valueDice[firstDice != 0])
                {
                    secondPairValue = dice.valueDice[firstDice] * 2;
                }
                if (firstPairValue > secondPairValue)
                {
                    return firstPairValue;
                }
                else if (firstPairValue < secondPairValue)
                {
                    return secondPairValue;
                }
           }
       }
    }
    return 0;
}

int Round::checkTwoPairs(Dice dice)
{
    int firstPairValue = 0;
    int secondPairValue = 0;
    for (int firstDice = 0; firstDice < 5; firstDice++)
    {
       for (int secondDice = firstDice+1; secondDice < 5; secondDice++)
       {
           if (dice.valueDice[firstDice] == dice.valueDice[secondDice] && dice.valueDice[firstDice] != 0)
           {
                if (firstPairValue != 0)
                    secondPairValue = dice.valueDice[firstDice] * 2;

                if (secondPairValue == 0)
                    firstPairValue = dice.valueDice[firstDice] * 2;

                dice.valueDice[firstDice] = 0;
                dice.valueDice[secondDice] = 0;

                if (firstPairValue != 0 && secondPairValue != 0)
                {
                    return secondPairValue + firstPairValue;
                }
           }
       }
    }
    return 0;
}

int Round::checkThreeOfAKind(Dice dice)
{
    for (int firstDice = 0; firstDice < 5; firstDice++)
    {
       for (int secondDice = firstDice + 1; secondDice < 5; secondDice++)
       {
           for(int thirdDice = secondDice + 1; thirdDice < 5; thirdDice++)
           {
               if (dice.valueDice[firstDice] == dice.valueDice[secondDice] && dice.valueDice[secondDice] == dice.valueDice[thirdDice])
               {
                    return dice.valueDice[firstDice] * 3;
               }
           }
       }
    }
    return 0;
}

int Round::checkFourOfAKind(Dice dice)
{
    for (int firstDice = 0; firstDice < 5; firstDice++)
    {
       for (int secondDice = firstDice + 1; secondDice < 5; secondDice++)
       {
           for(int thirdDice = secondDice + 1; thirdDice < 5; thirdDice++)
           {
                for(int fourthDice= thirdDice + 1; fourthDice < 5; fourthDice++)
                {
                    if (dice.valueDice[firstDice] == dice.valueDice[secondDice] && dice.valueDice[firstDice] != 0&&
                            dice.valueDice[firstDice] == dice.valueDice[thirdDice] &&
                            dice.valueDice[firstDice] == dice.valueDice[fourthDice])
                    {
                        return dice.valueDice[firstDice] * 4;
                    }
                }
            }
         }
    }
    return 0;
}

int Round::checkYatzy(Dice dice)
{
    if (    dice.valueDice[0] == dice.valueDice[1] &&
            dice.valueDice[0] == dice.valueDice[2] &&
            dice.valueDice[0] == dice.valueDice[3] &&
            dice.valueDice[0] == dice.valueDice[4])
        {
        return 50;
        }
    return 0;
}

int Round::checkSmallLadder(Dice dice)
{
    bool one = false;
    bool two = false;
    bool three = false;
    bool four = false;
    bool five = false;
    for (int firstDice = 0; firstDice < 5; firstDice++)
    {
        if(dice.valueDice[firstDice] == 1)
            one  = true;
    }

    for (int firstDice = 0; firstDice < 5; firstDice++)
    {
        if(dice.valueDice[firstDice] == 2)
            two  = true;
    }

    for (int firstDice = 0; firstDice < 5; firstDice++)
    {
        if(dice.valueDice[firstDice] == 3)
            three  = true;
    }

    for (int firstDice = 0; firstDice < 5; firstDice++)
    {
        if(dice.valueDice[firstDice] == 4)
            four  = true;
    }

    for (int firstDice = 0; firstDice < 5; firstDice++)
    {
        if(dice.valueDice[firstDice] == 5)
            five  = true;
    }

    if (one && two && three && four && five)
    {
        return 15;
    }
    return 0;
}

int Round::checkBigLadder(Dice dice)
{
    bool two = false;
    bool three = false;
    bool four = false;
    bool five = false;
    bool six = false;
    for (int firstDice = 0; firstDice < 5; firstDice++)
        if(dice.valueDice[firstDice] == 2)
            two  = true;
    for (int firstDice = 0; firstDice < 5; firstDice++)
        if(dice.valueDice[firstDice] == 3)
            three  = true;
    for (int firstDice = 0; firstDice < 5; firstDice++)
        if(dice.valueDice[firstDice] == 4)
            four  = true;
    for (int firstDice = 0; firstDice < 5; firstDice++)
        if(dice.valueDice[firstDice] == 5)
            five  = true;
    for (int firstDice = 0; firstDice < 5; firstDice++)
        if(dice.valueDice[firstDice] == 6)
            six  = true;
    if (two && three && four && five && six)
        return 20;
    return 0;
}

int Round::checkFullHouse(Dice dice)
{
    bool pair = false;
    int pairNum;

    bool threes = false;
    int threesNum;

    for (int firstDice = 0; firstDice < 5; firstDice++)
    {
       for (int secondDice = firstDice + 1; secondDice < 5; secondDice++)
       {
           for(int thirdDice = secondDice + 1; thirdDice < 5; thirdDice++)
           {
               if (dice.valueDice[firstDice] == dice.valueDice[secondDice] && dice.valueDice[secondDice] == dice.valueDice[thirdDice])
               {
                    if (threes)
                        break;
                    threes = true;
                    threesNum = dice.valueDice[firstDice];
               }
           }
       }
    }
    for (int firstDice = 0; firstDice < 5; firstDice++)
    {
       for (int secondDice = firstDice+1; secondDice < 5; secondDice++)
       {
           if (dice.valueDice[firstDice] == dice.valueDice[secondDice] and dice.valueDice[firstDice] != threesNum)
           {
               if (pair)
                   break;
               pair = true;
               pairNum = dice.valueDice[firstDice];
           }
       }
    }
    if (pair && threes && pairNum != threesNum)
        return (threesNum * 3) + (pairNum * 2);
    else
        return 0;
}

int Round::checkChance(Dice dice)
{
    int sum = 0;
    for (int i = 0; i < 5; i++)
        sum +=dice.valueDice[i];
    return sum;
}

int Round::checkNum(Dice dice, int n)
{
    int sum = 0;
    for (int i = 0; i < 6; i++)
        if (dice.valueDice[i] == n)
            sum += dice.valueDice[i];
    return sum - n;
}

void Round::isPossibleChangeColour (int r, int pCol, int score)
{
    /*
     *  y är beroende på villkoret dvs t.ex. par eller triss eller yatzy
     *  x är beroende på vilken spelare det är. spelare 1 = 0 spelare 2 = 1
     *  score är antalet poäng villkoret är värt
     */
    QString myStr = QString::number(score);
    if (game->score[r][pCol] == 0 && r != 6 && r != 7 && r != 17)
    {
        table->tableWidget->setItem(r, pCol, new QTableWidgetItem(myStr));
        table->tableWidget->item(r, pCol)->setBackgroundColor(Qt::yellow);
    }
}

void Round::makeChoice(int row, int column)
{
    if (column == current->pNum && game->score[row][column] == 0)
    {
        game->score[row][column] = roundScore[row];
        if(roundScore[row] != 0)
        {
            outOfRolls();
        }
        game->showScore(table, current->pNum);
        current->rollsLeft = 0;
    }
}

void Round::resetColour()
{
    for (int r = 0; r < 18; r++)
    {
        for (int pCol = 0; pCol < 2; pCol++)
        {
            if (game->score[r][pCol] == 0 && r != 6 && r != 7 && r != 17)
            {
                table->tableWidget->setItem(r, pCol, new QTableWidgetItem(""));
                table->tableWidget->item(r, pCol)->setBackground(Qt::white);
            }
        }
    }
}

void Round::outOfRolls()
{
    QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/new/prefix1/Dices/choice.mp3"));
    music->play();
table->tableWidget->setEnabled(false);
table->btn_save0->setChecked(false);
table->btn_save1->setChecked(false);
table->btn_save2->setChecked(false);
table->btn_save3->setChecked(false);
table->btn_save4->setChecked(false);
table->btn_save0->setEnabled(false);
table->btn_save1->setEnabled(false);
table->btn_save2->setEnabled(false);
table->btn_save3->setEnabled(false);
table->btn_save4->setEnabled(false);
table->btn_roll->setText("Roll 0/3");
}
