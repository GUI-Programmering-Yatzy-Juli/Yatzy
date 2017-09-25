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

/*-----------------------------------------
 *              TODO
 *
 *  Spar funktion för att spara tärningar (se Player.cpp)
 *  Välja vilket alternativ man vill köra på (se Round.cpp)
 *  Antalet poäng ska skrivas ut i tabellen till rätt plats (QString)
 *  återställa färgerna efter valet är gjort (se Round.cpp)
 *  En runda ska spelas när man trycker på roll (se Round.cpp eller Game.cpp)
 *  Skapa en score vector (Se gamemanager.cpp)
 *  Kanske byta plats på Rules och Exit btn
 *  Kanske ha starttexten Start på Roll och sen byta efter ett klick
 *
 * ---------------------------------------*/
