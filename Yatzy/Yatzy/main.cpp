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
 *              TODO
 *
 *  Välja vilket alternativ man vill köra på (se Round.cpp)
 *  återställa färgerna efter valet är gjort (se Round.cpp)
 *  En runda ska spelas när man trycker på roll (se Round.cpp eller Game.cpp)
 *  Göra användning av score arrayen i Game.cpp
 *  checkTwoPairs måste returna värdet på båda paren
 *  Skriv ut vems tur det är någonstans
 *
 * --------------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------------
 *             Kanske Todo
 *
 *  Kanske byta plats på Rules och Exit btn
 *  Kanske ha starttexten Start på Roll och sen byta efter ett klick
 *
 * --------------------------------------------------------------------------------*/
