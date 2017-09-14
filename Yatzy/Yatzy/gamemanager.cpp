#include "gamemanager.h"

gameManager::gameManager()
{
    Game game;
    game.round= 1;
    //numberOfPlayers = någonTextRuta
    game.numberOfPlayers = 2; //Placeholder
    if (game.numberOfPlayers < 2 || game.numberOfPlayers > 6)
    {
        qDebug() << "fel antal spelare";
    }
    else
    {
        qDebug() << "Det fungerar";
    }


}
