#include "Round.h"
#include <qdebug.h>


Round::Round(Ui::MainWindow *ui, Game *g)
{
    table = ui;
    game = g;
}

void Round::newRound(Player *currentP)
{
    current = currentP;
    qDebug() << "Rullar tärningar";
    resetColour();
    currentP->checkSavedDice(&dice, currentP);
    checkResult(dice, currentP->pNum);
    currentP->rollsLeft--;
    showImage();
}

void Round::showImage()
{
    //Något sånt här för bild för tärnings value förmodeligen bättre att göra en for loop på den
    //fast här behöver vi koppla dice.valueDice till denna klass så vi kan hämta ut värdet
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

    //Man ska välja vilken alternativ man vill köra på
    //void makeChoice()

    //alla färger som blev gröna förutom den som man valde
    //ska bli vita igen
    qDebug() << roundScore[0] << roundScore[1] << roundScore[2] << roundScore[3] << roundScore[4] << roundScore[5] << roundScore[6] << roundScore[7] << roundScore[8]
             << roundScore[9] << roundScore[10] << roundScore[11] << roundScore[12] << roundScore[13] << roundScore[14] << roundScore[15] << roundScore[16] << roundScore[17];

}

int Round::checkPair(Dice dice)                        //Klar
{
    //här är par
    //Den kollar bara ifall ett par finns, den måste kolla ifall det finns flera par.

    for (int firstDice = 0; firstDice < 5; firstDice++)
    {
       for (int secondDice = firstDice+1; secondDice < 5; secondDice++)
       {
           if (dice.valueDice[firstDice] == dice.valueDice[secondDice])
           {
                //här blir det par
                //glöm inte att värdet på paret måste sparas
                return dice.valueDice[firstDice] * 2;
           }
       }
    }
    return 0;
}

int Round::checkTwoPairs(Dice dice)                    //Klar
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

int Round::checkThreeOfAKind(Dice dice)                //Klar
{
    //Här är triss
    //Denna fungerar
    for (int firstDice = 0; firstDice < 5; firstDice++)
    {
       for (int secondDice = firstDice + 1; secondDice < 5; secondDice++)
       {
           for(int thirdDice = secondDice + 1; thirdDice < 5; thirdDice++)
           {
               if (dice.valueDice[firstDice] == dice.valueDice[secondDice] && dice.valueDice[secondDice] == dice.valueDice[thirdDice])
               {
                    //här blir det triss
                    //glöm inte att värdet på trissen måste sparas
                    return dice.valueDice[firstDice] * 3;
               }
           }
       }
    }
    return 0;
}

int Round::checkFourOfAKind(Dice dice)                 //Klar
{
    //Denna fungerar
    //Här är fyrtal
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
                        dice.valueDice[firstDice] = 0;
                        //här blir det fyrtal
                        //glöm inte att värdet på fyrtalet måste sparas
                        return dice.valueDice[firstDice] * 4;
                    }
                }
            }
         }
    }
    return 0;
}

int Round::checkYatzy(Dice dice)                       //Klar
{
    //Denna fungerar
    //Här är yahtzee
    if (    dice.valueDice[0] == dice.valueDice[1] &&
            dice.valueDice[0] == dice.valueDice[2] &&
            dice.valueDice[0] == dice.valueDice[3] &&
            dice.valueDice[0] == dice.valueDice[4])
        {
        return 50;
        }
    return 0;
}

int Round::checkSmallLadder(Dice dice)                 //Klar
{
    //Denna fungerar
    //liten stege

    bool one = false;
    bool two = false;
    bool three = false;
    bool four = false;
    bool five = false;

    for (int firstDice = 0; firstDice < 5; firstDice++)     //kollar ifall det finns 1
    {
        if(dice.valueDice[firstDice] == 1)
            one  = true;
    }

    for (int firstDice = 0; firstDice < 5; firstDice++)     //kollar ifall det finns 2
    {
        if(dice.valueDice[firstDice] == 2)
            two  = true;
    }

    for (int firstDice = 0; firstDice < 5; firstDice++)     //kollar ifall det finns 3
    {
        if(dice.valueDice[firstDice] == 3)
            three  = true;
    }

    for (int firstDice = 0; firstDice < 5; firstDice++)     //kollar ifall det finns 4
    {
        if(dice.valueDice[firstDice] == 4)
            four  = true;
    }

    for (int firstDice = 0; firstDice < 5; firstDice++)     //kollar ifall det finns 4
    {
        if(dice.valueDice[firstDice] == 5)
            five  = true;
    }

    if (one && two && three && four && five)
    {
        //här blir det liten stege
        //glöm inte att värdet måste sparas

        return 15;
    }
    return 0;
}

int Round::checkBigLadder(Dice dice)                   //Klar
{
    //Denna fungerar
    //stor stege

    bool two = false;
    bool three = false;
    bool four = false;
    bool five = false;
    bool six = false;



    for (int firstDice = 0; firstDice < 5; firstDice++)     //kollar ifall det finns 2
    {
        if(dice.valueDice[firstDice] == 2)
            two  = true;
    }

    for (int firstDice = 0; firstDice < 5; firstDice++)     //kollar ifall det finns 3
    {
        if(dice.valueDice[firstDice] == 3)
            three  = true;
    }

    for (int firstDice = 0; firstDice < 5; firstDice++)     //kollar ifall det finns 4
    {
        if(dice.valueDice[firstDice] == 4)
            four  = true;
    }

    for (int firstDice = 0; firstDice < 5; firstDice++)     //kollar ifall det finns 5
    {
        if(dice.valueDice[firstDice] == 5)
            five  = true;
    }

    for (int firstDice = 0; firstDice < 5; firstDice++)     //kollar ifall det finns 6
    {
        if(dice.valueDice[firstDice] == 6)
            six  = true;
    }

    if (two && three && four && five && six)
    {
        //här blir det stor stege
        return 20;
    }
    return 0;
}

int Round::checkFullHouse(Dice dice)                   //Klar
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
                    //här blir det triss
                    if (threes)
                        break;
                    threes = true;
                    threesNum = dice.valueDice[firstDice];
                    qDebug() << threesNum;
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
                //här blir det par
               if (pair)
                   break;
               pair = true;
               pairNum = dice.valueDice[firstDice];
               qDebug() << pairNum;
           }
       }
    }

    if (pair && threes && pairNum != threesNum)
    {
        return (threesNum * 3) + (pairNum * 2);
    }
    else
    {
        return 0;
    }
}

int Round::checkChance(Dice dice)                      //Klar
{
    int sum = 0;

    for (int i = 0; i < 5; i++)
    {
        sum +=dice.valueDice[i];
    }
    //ska returna summan av alla tärningar
    // return sum;
    return sum;
}

int Round::checkNum(Dice dice, int n)                  //Klar
{
    //Denna fungerar
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
        table->tableWidget->item(r, pCol)->setBackgroundColor(Qt::green);
    }
}

void Round::makeChoice(int row, int column)
{
    if (column == current->pNum)
    {
        game->score[row][column] = roundScore[row];
        game->calcScore(column);
        current->rollsLeft = 0;
    }
    else
    {
        qDebug() << "inte tillåtet";
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
