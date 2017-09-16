#include "Round.h"

Round::Round()
{

}

void Round::startNewRound()
{
    newRound(dice);
}

void Round::newRound(Dice dice)
{
    qDebug() << "Rullar tärningar";
    dice.roll();
    checkResult(dice);
}

void Round::checkResult(Dice dice)
{

    //kanske får ändra bool till int och returna antalet poäng man får
    //och ändra if till t.ex              if (checkFunction(dice) > 0)

    //Om funktionen är true ska tillhörande ruta i tabellen bli någon ljusgrön ca #c2ffaf

    if (checkPair(dice))
    {
        qDebug() << "Par";
    }

    if ( checkThreeOfAKind(dice))
    {
        qDebug() << "Triss";
    }

    if ( checkFourOfAKind(dice))
    {
        qDebug() << "Fyrtal";
    }

    if ( checkTwoPairs(dice))
    {
        qDebug() << "Två Par";
    }

    if ( checkYatzy(dice))
    {
        qDebug() << "Yatzy!";
    }

    if ( checkSmallLadder(dice))
    {
        qDebug() << "Liten Stege";
    }

    if ( checkBigLadder(dice))
    {
        qDebug() << "Stor Stege";
    }

    if (checkFullHouse(dice))
    {
        qDebug() << "Kåk";
    }
    if (checkChance(dice))
    {
        qDebug() << "Chans";
    }
}

bool Round::checkPair(Dice dice)                        //Klar
{
    //här är par
    //Denna fungerar
    for (int firstDice = 0; firstDice < 5; firstDice++)
    {
       for (int secondDice = firstDice+1; secondDice < 5; secondDice++)
       {
           if (dice.valueDice[firstDice] == dice.valueDice[secondDice])
           {
                //här blir det par
                //glöm inte att värdet på paret måste sparas
               return true;
           }
       }
    }
    return false;
}

bool Round::checkThreeOfAKind(Dice dice)                //Klar
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
                    return true;
               }
           }
       }
    }
    return false;
}

bool Round::checkFourOfAKind(Dice dice)                 //Klar
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
                        return true;
                    }
                }
            }
         }
    }
    return false;
}

bool Round::checkTwoPairs(Dice dice)                    //Klar
{

    //här är två par
    //Denna fungerar
    for (int firstDice = 0; firstDice < 5; firstDice++)
    {
       for (int secondDice = firstDice + 1; secondDice < 5; secondDice++)
       {
           for(int thirdDice = secondDice + 1; thirdDice < 5; thirdDice++)
           {
                for(int fourthDice= thirdDice + 1; fourthDice < 5; fourthDice++)
                {
                    if(    (dice.valueDice[firstDice] == dice.valueDice[secondDice]   &&
                            dice.valueDice[thirdDice] == dice.valueDice[fourthDice])

                                                        ||

                           (dice.valueDice[firstDice] == dice.valueDice[thirdDice]    &&
                            dice.valueDice[secondDice] == dice.valueDice[fourthDice])

                                                        ||

                           (dice.valueDice[firstDice] == dice.valueDice[fourthDice]   &&
                            dice.valueDice[secondDice] == dice.valueDice[thirdDice]))
                    {
                         //här blir det två par
                         //glöm inte att värdet på två paren måste sparas

                        return true;
                    }
                }
            }
         }
    }
    return false;
}

bool Round::checkYatzy(Dice dice)                       //Klar
{
    //Denna fungerar
    //Här är yahtzee

    if (    dice.valueDice[0] == dice.valueDice[1] &&
            dice.valueDice[0] == dice.valueDice[2] &&
            dice.valueDice[0] == dice.valueDice[3] &&
            dice.valueDice[0] == dice.valueDice[4])
    {
        //här blir det yahtzee
        //glöm inte att värdet på yahtzee måste sparas, typ score + 50
        return true;
    }
    return false;
}

bool Round::checkSmallLadder(Dice dice)                 //Klar
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

        return true;
    }
    return false;
}

bool Round::checkBigLadder(Dice dice)                   //Klar
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
        //glöm inte att värdet måste sparas
        return true;
    }
    return false;
}

bool Round::checkFullHouse(Dice dice)                   //Klar
{

    dice.valueDice[0] = 2;
    dice.valueDice[1] = 3;
    dice.valueDice[2] = 3;

    dice.valueDice[3] = 3;
    dice.valueDice[4] = 2;

    bool pair = false;
    int pairNum;

    bool threes = false;
    int threesNum;

    for (int firstDice = 0; firstDice < 5; firstDice++)
    {
       for (int secondDice = firstDice+1; secondDice < 5; secondDice++)
       {
           if (dice.valueDice[firstDice] == dice.valueDice[secondDice])
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

    if (pair && threes && pairNum != threesNum)
    {
        return true;
    }
    else
    {
        return false;
    }

}

bool Round::checkChance(Dice dice)                      //Klar
{
    int sum;

    for (int i = 0; i < 5; i++)
    {
        sum +=dice.valueDice[i];
    }
    //ska returna summan av alla tärningar
    // return sum;
    return true;
}

int Round::checkOnes(Dice dice)
{
    int sum = 0;
    for (int i = 0; i < 5; i++)
        if (dice.valueDice[i] == 1)
            sum += dice.valueDice[i];
    return sum;
}

int Round::checkTwos(Dice dice)
{
    int sum = 0;
    for (int i = 0; i < 5; i++)
        if (dice.valueDice[i] == 2)
            sum += dice.valueDice[i];
    return sum;
}

int Round::checkThrees(Dice dice)
{
    int sum = 0;
    for (int i = 0; i < 5; i++)
        if (dice.valueDice[i] == 3)
            sum += dice.valueDice[i];
    return sum;
}

int Round::checkFours(Dice dice)
{
    int sum = 0;
    for (int i = 0; i < 5; i++)
        if (dice.valueDice[i] == 4)
            sum += dice.valueDice[i];
    return sum;
}

int Round::checkFives(Dice dice)
{
    int sum = 0;
    for (int i = 0; i < 5; i++)
        if (dice.valueDice[i] == 5)
            sum += dice.valueDice[i];
    return sum;
}

int Round::checkSixes(Dice dice)
{
    int sum = 0;
    for (int i = 0; i < 5; i++)
        if (dice.valueDice[i] == 6)
            sum += dice.valueDice[i];
    return sum;
}
