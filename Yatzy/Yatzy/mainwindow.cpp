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

    //startNewGame();
    gameManager test;

}

void MainWindow::startNewGame()
{

}

void MainWindow::on_btn_roll_clicked()
{
    //Om game objektet inte finns ska den säga ifrån
    Round round;
    round.startNewRound();
}
