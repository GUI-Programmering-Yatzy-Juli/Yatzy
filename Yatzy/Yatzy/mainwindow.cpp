#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "Game.h"
#include <qdebug.h>
#include "gamemanager.h"
#include <QTableWidgetItem>
#include <QWidget>

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

    if(ui->tableWidget->item(1,0) == 0)
    {
    ui->tableWidget->setItem(1, 0, new QTableWidgetItem("Summa"));          //Detta skriver på raden 1, kolumnen 2, "Summa"
    ui->tableWidget->item(1,0)->setBackgroundColor(Qt::green);                //Detta skriver gör raden1, kolumnen 2 green
    }
    else
    {
        ui->tableWidget->setItem(1, 0, new QTableWidgetItem("Icke Tillgänglig"));          //Detta skriver på raden 1, kolumnen 2, "Icke tillgänglig"
        ui->tableWidget->item(1,0)->setBackgroundColor(Qt::red);                //Detta skriver gör raden1, kolumnen 2 red
    }
}
/*
if ui->tableWidget->item(x,x) == 0)
{
ui->tableWidget->setItem(x, x, new QTableWidgetItem("Summa"));          //Detta skriver på raden 1, kolumnen 2, "Summa"
ui->tableWidget->item(x,x)->setBackgroundColor(Qt::green);                //Detta skriver gör raden1, kolumnen 2 green
}
else
{
    ui->tableWidget->setItem(x, x, new QTableWidgetItem("Icke Tillgänglig"));          //Detta skriver på raden 1, kolumnen 2, "Icke tillgänglig"
    ui->tableWidget->item(x,x)->setBackgroundColor(Qt::red);                //Detta skriver gör raden1, kolumnen 2 red
}
*/
