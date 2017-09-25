#ifndef GAME_H
#define GAME_H

#include "Dice.h"
#include "Round.h"
#include "gamemanager.h"
#include "Player.h"
#include "mainwindow.h"
#include <QPushButton>
#include <QObject>


class Game : public QObject
{

    Q_OBJECT

public:
    Game(Ui::MainWindow *ui, Player player1, Player player2);
    int numRounds = 1;



    bool gameIsActive();

    Player p1;
    Player p2;

public slots:
     void update(Ui::MainWindow *ui);

private slots:
    void on_btn_roll_click();


};

#endif // GAME_H
