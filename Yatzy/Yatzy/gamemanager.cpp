#include "gamemanager.h"
#include <qdebug.h>

gameManager::gameManager(Ui::MainWindow *ui)
{
    qDebug() << "game-objektet skapas";

    Game game(ui, player1 , player2);
    game.numRounds = 0;
}

void gameManager::test()
{

}


//scores ska vara en vektor, det är som en 2d array
