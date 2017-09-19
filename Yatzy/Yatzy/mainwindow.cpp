#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "Game.h"
#include <qdebug.h>
#include "gamemanager.h"
#include <QTableWidgetItem>


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

void MainWindow::on_btn_roll_2_clicked()
{
    //startNewGame();
    gameManager createGame;
}

void MainWindow::startNewGame()
{
    //Om game objektet inte finns ska den säga ifrån
    Round round;
}

void MainWindow::on_btn_roll_clicked()
{

}

void MainWindow::on_pushButton_2_clicked()
{
    textChange();
}

void MainWindow::textChange()
{
    ui->tableWidget->setItem(1, 0, new QTableWidgetItem("Hello"));          //Detta skriver på raden 1, kolumnen 2, "Hello"
    ui->tableWidget->item(1,0)->setBackgroundColor(Qt::red);                //Detta skriver gör raden1, kolumnen 2 röd
}

