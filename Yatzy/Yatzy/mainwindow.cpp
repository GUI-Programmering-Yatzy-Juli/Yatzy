#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "Game.h"
#include <qdebug.h>
#include "gamemanager.h"
#include <QTableWidgetItem>
#include <QWidget>
#include <QPushButton>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    QMainWindow::centralWidget()->layout()->setContentsMargins(0,0,0,0);

}

MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::on_btn_roll_2_clicked()
{

    gameManager createGame(ui);
    //ui->btn_roll_2->setEnabled(false);
}
void MainWindow::on_pushButton_3_clicked()
{
    QCoreApplication::quit();
}

void MainWindow::startNewGame()
{
    //Om game objektet inte finns ska den säga ifrån
    qDebug() << "Test";
    //Round round(ui);
}


void MainWindow::on_btn_roll_clicked()
{
    startNewGame();
    //textChange();
    //diceChange();
}

void MainWindow::diceChange()
{
    if(ui->btn_save0->styleSheet() == "")
    {
    ui->btn_save0->setStyleSheet("background-image: url(:/new/prefix1/G:/green.jpg);"); //Ska ändras till vad dice1 är. t.ex  dice 1 blir en 2a så ska en bild på en 2a komma upp.
    }
    else
    {
         ui->btn_save0->setStyleSheet("");
    }
}
/*void MainWindow::on_pushButton_7_clicked()
{
    saveDice();
}

void MainWindow::saveDice()
{
     if(ui->pushButton_7->styleSheet() != 0)
     {
         ui->pushButton_7->setStyleSheet(ui->pushButton_7->styleSheet());
     }
}
*/

void MainWindow::on_pushButton_2_clicked()
{
    QMessageBox::information(
            this,
            tr("Yahtzee"),
            tr("Yatzy är ett tärningsspel för en eller flera spelare där det gäller att samla poäng genom att med fem tärningar och tre kast per omgång försöka få in kombinationer enligt följande tabell:\n"
               "Villkor |Max|kommentar \n"
               "Ettor   |5	|Så många som möjligt\n"
               "tvåor   |10	|Så många som möjligt\n"
               "treor   |15	|Så många som möjligt\n"
               "fyror   |20	|Så många som möjligt\n"
               "femmor  |25	|Så många som möjligt\n"
               "sexor   |30	|Så många som möjligt\n"
               "summa:  |105|totalsumma ettor till sexor\n"
               "bonus:  |50	|snitt med tre av varje\n"
               "1 par   |12	|Så högt som möjligt\n"
               "2 par   |22	|Så högt som möjligt\n"
               "triss   |18	|Så högt som möjligt\n"
               "fyrtal  |24	|Så högt som möjligt\n"
               "L.stege |15 |ett till fem\n"
               "S.stege |20	|två till sex\n"
               "kåk	    |28 |tre av en sort, två av en annan\n"
               "chans   |30	|Så högt som möjligt\n"
               "Yatzy   |50	|fem lika\n"
               "summa   |374|totalt\n"
               "_______________________________________________________________________________________________________________________________________________________\n"
               "bonus - Bonus på 50 poäng utdelas till de spelare som fått minst 63 poäng sammanlagt på ettor till sexor. Det motsvarar tre av varje på den övre delen.\n"
               "två par - Ett resultat som kan klassificeras som ett fyrtal godkänns inte som ett två par.\n"
               "liten stege - En etta, en tvåa, en trea, en fyra och en femma.\n"
               "stor stege - En tvåa, en trea, en fyra, en femma, och en sexa.\n"
               "kåk - Tre av en sort och två av en annan. En resultat som kan klassificeras som en Yatzy godkänns inte som en kåk.\n"
               "chans - Summan av resultatet.\n"
               "Yatzy - Femtal.\n"
               "summa\n") );
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
