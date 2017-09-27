#include "mainwindow.h"
#include <QApplication>

#include "game.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.show();

    return a.exec();
}

/*----------------------------------------------------------------------------------
 *              TODO                                                               |
 *                                                                                 |
 *  Välja vilket alternativ man vill köra på (se Round.cpp)                        |
 *  återställa färgerna efter valet är gjort (se Round.cpp)                        |
 *  om man väljer att lägga in ett t.ex. par på första draget sätt roundsLeft = 0  |
 *----------------------------------------------------------------------------------
 * Har börjat på dessa men är ej klar                                              |
 *----------------------------------------------------------------------------------
 *  Göra användning av score arrayen i Game.cpp                                    |
 *  Spara tärningar                                                                |
 *                                                                                 |
 * --------------------------------------------------------------------------------*/
