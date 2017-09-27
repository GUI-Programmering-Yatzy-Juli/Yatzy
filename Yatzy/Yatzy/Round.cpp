#include "Round.h"
#include <qdebug.h>


Round::Round(Ui::MainWindow *ui)
{
    table = ui;
}

void Round::newRound(Player *currentP)
{
    qDebug() << "Rullar tärningar";
    currentP->checkSavedDice(&dice, currentP);
    checkResult(dice, currentP->pNum);
    currentP->rollsLeft--;
    Image();

}
void Round::Image()
{
    QPixmap img1(":/new/prefix1/Dices/1.png");
    QPixmap img2(":/new/prefix1/Dices/2.png");
    QPixmap img3(":/new/prefix1/Dices/3.png");
    QPixmap img4(":/new/prefix1/Dices/4.png");
    QPixmap img5(":/new/prefix1/Dices/5.png");
    QPixmap img6(":/new/prefix1/Dices/6.png");
    QIcon ButtonIcon1(img1);
    QIcon ButtonIcon2(img2);
    QIcon ButtonIcon3(img3);
    QIcon ButtonIcon4(img4);
    QIcon ButtonIcon5(img5);
    QIcon ButtonIcon6(img6);
        if(dice.valueDice[0] == 1)
     {
      table->btn_save0->setIcon(ButtonIcon1);
      table->btn_save0->setIconSize(QSize(100,100));
     }                                                //Något sånt här för bild för tärnings value förmodeligen bättre att göra en for loop på den
        else if(dice.valueDice[0] == 2)               //fast här behöver vi koppla dice.valueDice till denna klass så vi kan hämta ut värdet
     {
            table->btn_save0->setIcon(ButtonIcon2);
            table->btn_save0->setIconSize(QSize(100,100));
     }
        else if(dice.valueDice[0] == 3)
     {
            table->btn_save0->setIcon(ButtonIcon3);
            table->btn_save0->setIconSize(QSize(100,100));
     }
        else if(dice.valueDice[0] == 4)
     {
            table->btn_save0->setIcon(ButtonIcon4);
            table->btn_save0->setIconSize(QSize(100,100));
     }
        else if(dice.valueDice[0] == 5)
     {
            table->btn_save0->setIcon(ButtonIcon5);
            table->btn_save0->setIconSize(QSize(100,100));
     }
        else if(dice.valueDice[0] == 6)
     {
            table->btn_save0->setIcon(ButtonIcon6);
            table->btn_save0->setIconSize(QSize(100,100));
     }
        if(dice.valueDice[1] == 1)
     {
      table->btn_save1->setIcon(ButtonIcon1);
      table->btn_save1->setIconSize(QSize(100,100));
     }
        else if(dice.valueDice[1] == 2)
     {
            table->btn_save1->setIcon(ButtonIcon2);
            table->btn_save1->setIconSize(QSize(100,100));
     }
        else if(dice.valueDice[1] == 3)
     {
            table->btn_save1->setIcon(ButtonIcon3);
            table->btn_save1->setIconSize(QSize(100,100));
     }
        else if(dice.valueDice[1] == 4)
     {
            table->btn_save1->setIcon(ButtonIcon4);
            table->btn_save1->setIconSize(QSize(100,100));
     }
        else if(dice.valueDice[1] == 5)
     {
            table->btn_save1->setIcon(ButtonIcon5);
            table->btn_save1->setIconSize(QSize(100,100));
     }
        else if(dice.valueDice[1] == 6)
     {
            table->btn_save1->setIcon(ButtonIcon6);
            table->btn_save1->setIconSize(QSize(100,100));
     }
        if(dice.valueDice[2] == 1)
     {
      table->btn_save2->setIcon(ButtonIcon1);
      table->btn_save2->setIconSize(QSize(100,100));
     }
        else if(dice.valueDice[2] == 2)
     {
            table->btn_save2->setIcon(ButtonIcon2);
            table->btn_save2->setIconSize(QSize(100,100));
     }
        else if(dice.valueDice[2] == 3)
     {
            table->btn_save2->setIcon(ButtonIcon3);
            table->btn_save2->setIconSize(QSize(100,100));
     }
        else if(dice.valueDice[2] == 4)
     {
            table->btn_save2->setIcon(ButtonIcon4);
            table->btn_save2->setIconSize(QSize(100,100));
     }
        else if(dice.valueDice[2] == 5)
     {
            table->btn_save2->setIcon(ButtonIcon5);
            table->btn_save2->setIconSize(QSize(100,100));
     }
        else if(dice.valueDice[2] == 6)
     {
            table->btn_save2->setIcon(ButtonIcon6);
            table->btn_save2->setIconSize(QSize(100,100));
     }
        if(dice.valueDice[3] == 1)
     {
      table->btn_save3->setIcon(ButtonIcon1);
      table->btn_save3->setIconSize(QSize(100,100));
     }
        else if(dice.valueDice[3] == 2)
     {
            table->btn_save3->setIcon(ButtonIcon2);
            table->btn_save3->setIconSize(QSize(100,100));
     }
        else if(dice.valueDice[3] == 3)
     {
            table->btn_save3->setIcon(ButtonIcon3);
            table->btn_save3->setIconSize(QSize(100,100));
     }
        else if(dice.valueDice[3] == 4)
     {
            table->btn_save3->setIcon(ButtonIcon4);
            table->btn_save3->setIconSize(QSize(100,100));
     }
        else if(dice.valueDice[3] == 5)
     {
            table->btn_save3->setIcon(ButtonIcon5);
            table->btn_save3->setIconSize(QSize(100,100));
     }
        else if(dice.valueDice[3] == 6)
     {
            table->btn_save3->setIcon(ButtonIcon6);
            table->btn_save3->setIconSize(QSize(100,100));
     }
        if(dice.valueDice[4] == 1)
     {
      table->btn_save4->setIcon(ButtonIcon1);
      table->btn_save4->setIconSize(QSize(100,100));
     }
        else if(dice.valueDice[4] == 2)
     {
            table->btn_save4->setIcon(ButtonIcon2);
            table->btn_save4->setIconSize(QSize(100,100));
     }
        else if(dice.valueDice[4] == 3)
     {
            table->btn_save4->setIcon(ButtonIcon3);
            table->btn_save4->setIconSize(QSize(100,100));
     }
        else if(dice.valueDice[4] == 4)
     {
            table->btn_save4->setIcon(ButtonIcon4);
            table->btn_save4->setIconSize(QSize(100,100));
     }
        else if(dice.valueDice[4] == 5)
     {
            table->btn_save4->setIcon(ButtonIcon5);
            table->btn_save4->setIconSize(QSize(100,100));
     }
        else if(dice.valueDice[4] == 6)
     {
            table->btn_save4->setIcon(ButtonIcon6);
            table->btn_save4->setIconSize(QSize(100,100));
     }
}

void Round::checkResult(Dice dice, int column)
{
    int roundScore[18];
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

void Round::isPossibleChangeColour (int y, int x, int score)
{
    /*
     *  y är beroende på villkoret dvs t.ex. par eller triss eller yatzy
     *  x är beroende på vilken spelare det är. spelare 1 = 0 spelare 2 = 1
     *  score är antalet poäng villkoret är värt
     */
    QString myStr = QString::number(score);

    table->tableWidget->setItem(y, x, new QTableWidgetItem(myStr));
    table->tableWidget->item(y, x)->setBackgroundColor(Qt::green);
}

