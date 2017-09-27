#include "Dice.h"
#include <cstdlib>
#include <ctime>
using namespace std;

Dice::Dice()
{
    qDebug() << "Nya tärningar har skapats";
    roll();
}

void Dice::roll()
{

    for (int i = 0; i < 5; i++)
    {
        valueDice[i] = rand() % 6 + 1;
    }
    qDebug() << valueDice[0] << valueDice[1]<< valueDice[2]<< valueDice[3]<< valueDice[4];

}


/* while(valueDice[i] == 0)
 * {
 * ui->btn_save0->setEnabled(false);
 * ui->btn_save1->setEnabled(false);
 * ui->btn_save2->setEnabled(false);
 * ui->btn_save3->setEnabled(false);
 * }
 * */
