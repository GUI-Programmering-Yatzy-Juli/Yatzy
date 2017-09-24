#include "gamemanager.h"
#include <qdebug.h>

gameManager::gameManager(Ui::MainWindow *ui)
{
    qDebug() << "game-objektet skapas";
    Player player1;
    Player player2;
    Game game(ui, player1, player2);
    game.numRounds = 0;
}

//scores ska vara en vektor, det är som en 2d array
