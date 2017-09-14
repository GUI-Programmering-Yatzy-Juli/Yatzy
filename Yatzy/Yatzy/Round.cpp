#include "Round.h"

Round::Round()
{

}

void Round::newRound()
{
    Dice dice;
    /*
    if (alla spelar spelat en runda)
    {
        game.round++;
    }
    */
}

void Round::checkResult(Dice &dice)
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



}
