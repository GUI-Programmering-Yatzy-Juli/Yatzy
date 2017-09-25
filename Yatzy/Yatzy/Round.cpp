#include "Round.h"

Round::Round(Ui::MainWindow *ui)
{
    table = ui;
}

void Round::newRound(Player *currentP)
{
    qDebug() << "Rullar tärningar";
    currentP->checkSavedDice(&dice, currentP);
    checkResult();
    currentP->rollsLeft--;
}

void Round::checkResult()
{
    //Om funktionen är true ska tillhörande ruta i tabellen bli någon ljusgrön ca #c2ffaf
    for (int i = 1; i < 7; i++)
    {
        int sum = checkNum(dice, i);
        if (sum > 0)
        {
            qDebug() << i << " = " << sum;
        }
    }
    if (checkPair(dice) > 0)
    {
        isPossibleChangeColour(9, 0, checkPair(dice));
        qDebug() << "Par";
    }

    if ( checkThreeOfAKind(dice) > 0)
    {
        isPossibleChangeColour(10, 0, checkThreeOfAKind(dice));
        qDebug() << "Triss";
    }

    if ( checkFourOfAKind(dice) > 0)
    {
        isPossibleChangeColour(11, 0, checkFourOfAKind(dice));
        qDebug() << "Fyrtal";
    }

    if ( checkTwoPairs(dice) > 0)
    {
        isPossibleChangeColour(12, 0, checkTwoPairs(dice));
        qDebug() << "Två Par";
    }

    if ( checkYatzy(dice) > 0)
    {
        isPossibleChangeColour(13, 0, checkYatzy(dice));
        qDebug() << "Yatzy!";
    }

    if ( checkSmallLadder(dice) > 0)
    {
        isPossibleChangeColour(14, 0, checkSmallLadder(dice));
        qDebug() << "Liten Stege";
    }

    if ( checkBigLadder(dice) > 0)
    {
        isPossibleChangeColour(15, 0, checkBigLadder(dice));
        qDebug() << "Stor Stege";
    }

    if (checkFullHouse(dice) > 0)
    {
        isPossibleChangeColour(16, 0, checkFullHouse(dice));
        qDebug() << "Kåk";
    }
    if (checkChance(dice) > 0)
    {
        isPossibleChangeColour(17, 0, checkChance(dice));
        qDebug() << "Chans";
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

int Round::checkTwoPairs(Dice dice)                    //Nästan Klar
{

    //här är två par
    //Den ska returna antalet poäng det ger
    for (int firstDice = 0; firstDice < 5; firstDice++)
    {
       for (int secondDice = firstDice + 1; secondDice < 5; secondDice++)
       {
           for(int thirdDice = secondDice + 1; thirdDice < 5; thirdDice++)
           {
                for(int fourthDice= thirdDice + 1; fourthDice < 5; fourthDice++)
                {
                    if(    (dice.valueDice[firstDice] == dice.valueDice[secondDice]   && //1+2 och 3+4
                            dice.valueDice[thirdDice] == dice.valueDice[fourthDice])

                                                        ||

                           (dice.valueDice[firstDice] == dice.valueDice[thirdDice]    && //1+3 och 2+4
                            dice.valueDice[secondDice] == dice.valueDice[fourthDice])

                                                        ||

                           (dice.valueDice[firstDice] == dice.valueDice[fourthDice]   && //1+4 och 2+3
                            dice.valueDice[secondDice] == dice.valueDice[thirdDice]))

                    {
                         //här blir det två par
                         //glöm inte att värdet på två paren måste sparas

                        return (dice.valueDice[firstDice] * 2) + (dice.valueDice[secondDice] * 2);
                    }
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
                    if (dice.valueDice[firstDice] == dice.valueDice[secondDice] &&
                            dice.valueDice[firstDice] == dice.valueDice[thirdDice] &&
                            dice.valueDice[firstDice] == dice.valueDice[fourthDice])
                    {
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
        //här blir det yahtzee
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
    int sum;

    for (int i = 0; i < 5; i++)
    {
        sum +=dice.valueDice[i];
    }
    //ska returna summan av alla tärningar
    // return sum;
    return sum;
}

int Round::checkNum(Dice dice, int n)                   //Klar
{
    //Denna fungerar
    int sum = 0;
    for (int i = 0; i < 6; i++)
        if (dice.valueDice[i] == n)
            sum += dice.valueDice[i];
    return sum;
}

void Round::isPossibleChangeColour (int y, int x, int score)
{
    x = 0; //temporärt
    QString myStr;
    myStr.number(score);
    /*
     *  y är beroende på villkoret dvs t.ex. par eller triss eller yatzy
     *  x är beroende på vilken spelare det är. spelare 1 = 0 spelare 2 = 1
     *  score är antalet poäng villkoret är värt
     */
    table->tableWidget->setItem(y, x, new QTableWidgetItem(score));
    table->tableWidget->item(y, x)->setBackgroundColor(Qt::green);
}

