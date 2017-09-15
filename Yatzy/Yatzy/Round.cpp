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
}

void Round::checkResult(Dice dice)
{

    //här är par
    for (int firstDice = 0; firstDice < 5; firstDice++)
    {
       for (int secondDice = 0; secondDice < 5; secondDice++)
       {
           if (dice.valueDice[firstDice] == dice.valueDice[secondDice])
           {
                //här blir det par
                //glöm inte att värdet på paret måste sparas
           }
       }
    }

    //Här är triss
    for (int firstDice = 0; firstDice < 5; firstDice++)
    {
       for (int secondDice = 0; secondDice < 5; secondDice++)
       {
           for(int thirdDice = 0; thirdDice < 5; thirdDice++)
           {
               if (dice.valueDice[firstDice] == dice.valueDice[secondDice] ==dice.valueDice[thirdDice])
               {
                    //här blir det triss
                    //glöm inte att värdet på trissen måste sparas
               }
           }
       }
    }

    //Här är två par

    for (int firstDice = 0; firstDice < 5; firstDice++)
    {
       for (int secondDice = 0; secondDice < 5; secondDice++)
       {
           for(int thirdDice = 0; thirdDice < 5; thirdDice++)
           {
                for(int fourthDice= 0; fourthDice < 5; fourthDice++)
                {
                    if(dice.valueDice[firstDice] == dice.valueDice[secondDice] && dice.valueDice[thirdDice] == dice.valueDice[fourthDice] || dice.valueDice[firstDice] == dice.valueDice[thirdDice] && dice.valueDice[secondDice] == dice.valueDice[fourthDice] || dice.valueDice[firstDice] == dice.valueDice[fourthDice] && dice.valueDice[secondDice] == dice.valueDice[thirdDice])
                    {
                         //här blir det två par
                         //glöm inte att värdet på två paren måste sparas
                    }
                }
            }
         }
    }
    //Här är fyrtal
    for (int firstDice = 0; firstDice < 5; firstDice++)
    {
       for (int secondDice = 0; secondDice < 5; secondDice++)
       {
           for(int thirdDice = 0; thirdDice < 5; thirdDice++)
           {
                for(int fourthDice= 0; fourthDice < 5; fourthDice++)
                {
                    if (dice.valueDice[firstDice] == dice.valueDice[secondDice] == dice.valueDice[thirdDice] == dice.valueDice[fourthDice])
                    {
                        //här blir det fyrtal
                        //glöm inte att värdet på fyrtalet måste sparas
                    }
                }
            }
         }
    }
    //Här är yahtzee
    for (int firstDice = 0; firstDice < 5; firstDice++)
    {
       for (int secondDice = 0; secondDice < 5; secondDice++)
       {
           for(int thirdDice = 0; thirdDice < 5; thirdDice++)
           {
                for(int fourthDice= 0; fourthDice < 5; fourthDice++)
                {
                    for(int fifthDice= 0; fifthDice < 5; fifthDice++)
                       {
                        if (dice.valueDice[firstDice] == dice.valueDice[secondDice] == dice.valueDice[thirdDice] == dice.valueDice[fourthDice] == dice.valueDice[fifthDice])
                        {
                            //här blir det yahtzee
                            //glöm inte att värdet på yahtzee måste sparas, typ score + 50
                        }
                    }
                }
            }
         }
    }
//Här är liten stege

    for (int firstDice = 0; firstDice < 5; firstDice++)
    {
       for (int secondDice = 0; secondDice < 5; secondDice++)
       {
           for(int thirdDice = 0; thirdDice < 5; thirdDice++)
           {
                for(int fourthDice= 0; fourthDice < 5; fourthDice++)
                {
                    for(int fifthDice= 0; fifthDice < 5; fifthDice++)
                       {
                        if (dice.valueDice[firstDice] == 1 && dice.valueDice[secondDice] == 2 && dice.valueDice[thirdDice] == 3 && dice.valueDice[fourthDice] == 4 && dice.valueDice[fifthDice] == 5)
                        {
                            //här blir det en liten stege
                            //glöm inte att värdet på stegen måste sparas
                        }
                    }
                }
            }
         }
    }


}

