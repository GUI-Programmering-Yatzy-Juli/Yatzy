#include "Dice.h"

Dice::Dice()
{
    qDebug() << "Nya tärningar har skapats";
    roll();
}

void Dice::roll()
{
    srand(time(NULL));
    for (int i = 0; i < 5; i++)
    {
        valueDice[i] = rand() % 6 + 1;

    }
    qDebug() << valueDice[0] << valueDice[1]<< valueDice[2]<< valueDice[3]<< valueDice[4];
}
//tanke för en keep
/*
    if(savetoggle1 == true)
    {
        valueDice[0] == valueDice[0]
    }
    else
    {
        valueDice[0] =! valueDice[0]
    }
    */




/* while(valueDice[i] == 0)
 * {
 * ui->btn_save0->setEnabled(false);
 * ui->btn_save1->setEnabled(false);
 * ui->btn_save2->setEnabled(false);
 * ui->btn_save3->setEnabled(false);
 * }
 * */
