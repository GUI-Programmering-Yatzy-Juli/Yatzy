#include "gamemanager.h"
#include <qdebug.h>

gameManager::gameManager(Ui::MainWindow *ui)
{
    qDebug() << "game-objektet skapas";
    Game game(ui);
    game.numRounds = 0;
}

//scores ska vara en vektor, det är som en 2d array
