#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "Game.h"
#include <qdebug.h>
#include "gamemanager.h"


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

void MainWindow::on_btn_start_clicked()
{
<<<<<<< HEAD
    //startNewGame();
    gameManager test;
=======

>>>>>>> 9e9b31475be6e6686854713d84ccf34d8d5f52e1
}

void MainWindow::startNewGame()
{

}

void MainWindow::on_btn_roll_clicked()
{
    //Om game objektet inte finns ska den säga ifrån
    Round round;
    round.newRound();
}
