#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "Game.h"
#include <qdebug.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_roll_clicked()
{
    //Om game objektet inte finns ska den säga ifrån
    Round round;
    round.newRound();

}

void MainWindow::on_btn_start_clicked()
{

    startNewGame();
}

void MainWindow::startNewGame()
{
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
