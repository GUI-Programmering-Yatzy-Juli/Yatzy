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
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_roll_2_clicked()
{

    //startNewGame();
    gameManager createGame;

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

void MainWindow::on_pushButton_2_clicked()
{

}

