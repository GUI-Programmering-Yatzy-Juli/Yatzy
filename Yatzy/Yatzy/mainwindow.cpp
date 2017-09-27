#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <qdebug.h>
#include <QTableWidgetItem>
#include <QWidget>
#include <QPushButton>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    g = new Game(ui);
    ui->setupUi(this);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QMainWindow::centralWidget()->layout()->setContentsMargins(0,0,0,0);
    ui->label->setVisible(false);
    ui->btn_roll->setVisible(false);
      ui->btn_save0->setEnabled(false);     // Ska bli kopplat med dice.valueDice så ifall valueDice inte har något värde så är setEnabled(false)
      ui->btn_save1->setEnabled(false);
      ui->btn_save2->setEnabled(false);
      ui->btn_save3->setEnabled(false);
      ui->btn_save4->setEnabled(false);     //
      QPixmap img1(":/new/prefix1/Dices/1.png");
      QPixmap img2(":/new/prefix1/Dices/2.png");
      QPixmap img3(":/new/prefix1/Dices/3.png");
      QPixmap img4(":/new/prefix1/Dices/4.png");
      QPixmap img5(":/new/prefix1/Dices/5.png");
      QPixmap img6(":/new/prefix1/Dices/6.png");
      QIcon ButtonIcon1(img1);
      QIcon ButtonIcon2(img2);
      QIcon ButtonIcon3(img3);
      QIcon ButtonIcon4(img4);
      QIcon ButtonIcon5(img5);
      QIcon ButtonIcon6(img6);

      ui->btn_save0->setIcon(ButtonIcon1);
      ui->btn_save0->setIconSize(QSize(100,100));
      ui->btn_save1->setIcon(ButtonIcon2);
      ui->btn_save1->setIconSize(QSize(100,100));

      ui->btn_save2->setIcon(ButtonIcon3);
      ui->btn_save2->setIconSize(QSize(100,100));

      ui->btn_save3->setIcon(ButtonIcon4);
      ui->btn_save3->setIconSize(QSize(100,100));

      ui->btn_save4->setIcon(ButtonIcon5);
      ui->btn_save4->setIconSize(QSize(100,100));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_roll_clicked()
{
    g->update(ui);
    enableSaveBtn();
}

void MainWindow::on_btn_roll_2_clicked()
{

    ui->label->setVisible(true);
    ui->btn_roll->setVisible(true);
    ui->btn_roll_2->setVisible(false);
}

void MainWindow::on_btn_exit_clicked()
{
    QMessageBox::StandardButton reply;
     reply = QMessageBox::question(this, "Yahtzee", "Do you really wanna exit?",
                                   QMessageBox::Yes|QMessageBox::No);
     if (reply == QMessageBox::Yes) {
       qDebug() << "I did not want you to play eitherway :(";
       QApplication::quit();
     } else {
       qDebug() << "Thank you for staying :)";
     }
   }

void MainWindow::on_btn_rules_clicked()
{
    QMessageBox::information(
            this,
            tr("Yahtzee"),
            tr("Yatzy är ett tärningsspel för en eller flera spelare där det gäller att samla poäng genom att med fem tärningar och tre kast per omgång försöka få in kombinationer enligt följande tabell:\n"
               "Villkor \t\t|Max|\tkommentar \n"
               "Ettor   \t\t|5|\tSå många som möjligt\n"
               "tvåor   \t\t|10|\tSå många som möjligt\n"
               "treor   \t\t|15|\tSå många som möjligt\n"
               "fyror   \t\t|20|\tSå många som möjligt\n"
               "femmor  \t|25|\tSå många som möjligt\n"
               "sexor   \t\t|30|\tSå många som möjligt\n"
               "summa:  \t|105|\ttotalsumma ettor till sexor\n"
               "bonus:  \t|50|\tsnitt med tre av varje\n"
               "1 par   \t\t|12|\tSå högt som möjligt\n"
               "2 par   \t\t|22|\tSå högt som möjligt\n"
               "triss   \t\t|18|\tSå högt som möjligt\n"
               "fyrtal  \t\t|24|\tSå högt som möjligt\n"
               "L.stege \t|15 |\tett till fem\n"
               "S.stege \t|20|\ttvå till sex\n"
               "kåk	    \t|28 |\ttre av en sort, två av en annan\n"
               "chans   \t|30|\tSå högt som möjligt\n"
               "Yatzy   \t\t|50|\tfem lika\n"
               "summa   \t|374|\ttotalt\n"
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

void MainWindow::on_tableWidget_cellClicked(int row, int column)
{
    qDebug() << "Du tryckte:" << row << column;
    if(ui->tableWidget->item(row, column) != 0)
    {
   ui->tableWidget->clearContents();
    }
   ui->tableWidget->setItem(row, column, new QTableWidgetItem(""));
   ui->tableWidget->item(row, column)->setBackgroundColor(Qt::red);

    /*Använd typ denna för att välja skit fast den blir ju implementerad i rounds med str o green
 Sedan för att reseta så kan man använda clearcontents men då måste vi ha kunnat implementerat funktionen för att spara tärningar. eller så gör vi en array med en while loop
 och varje gång vi använder vår click för att markera alternativ så blir det en hardsave typ(Asså vi får på något sätt göra så att row och column får det grund värdet(mystr)
 på det sättet så skulle det kanske inte blir clearat
 kan vara bättre att lägga clearcontents på Roll knappen och kanske kolla ifall man kan göra exceptions på den
   */

    //en funktion kan skicka iväg och köra en annan funktion t.ex.
    //isPossibleChoice(int row, int column
}

void MainWindow::enableSaveBtn()
{
    ui->btn_save0->setEnabled(true);
    ui->btn_save1->setEnabled(true);
    ui->btn_save2->setEnabled(true);
    ui->btn_save3->setEnabled(true);
    ui->btn_save4->setEnabled(true);
}

void MainWindow::on_btn_save0_clicked()
{
    g->saveDice(0);
}

void MainWindow::on_btn_save1_clicked()
{
    g->saveDice(1);
}

void MainWindow::on_btn_save2_clicked()
{
    g->saveDice(2);
}

void MainWindow::on_btn_save3_clicked()
{
    g->saveDice(3);
}

void MainWindow::on_btn_save4_clicked()
{
    g->saveDice(4);
}

