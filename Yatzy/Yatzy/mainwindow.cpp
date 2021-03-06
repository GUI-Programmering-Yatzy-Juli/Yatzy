#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTableWidgetItem>
#include <QWidget>
#include <QPushButton>
#include <QMessageBox>
#include <QProcess>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    g = new Game(ui);
    g->populateArray();
    ui->setupUi(this);
    ui->tableWidget->setSelectionMode(QTableWidget::NoSelection);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QMainWindow::centralWidget()->layout()->setContentsMargins(0,0,0,0);
    ui->tableWidget->horizontalHeader()->setVisible(true);
       ui->tableWidget->verticalHeader()->setVisible(true);
    ui->tableWidget->setEnabled(false);
    ui->label->setVisible(false);
    ui->pushButton->setVisible(false);
    ui->btn_roll->setVisible(false);
    ui->btn_save0->setEnabled(false);
    ui->btn_save1->setEnabled(false);
    ui->btn_save2->setEnabled(false);
    ui->btn_save3->setEnabled(false);
    ui->btn_save4->setEnabled(false);

    ui->btn_save0->setIcon(QIcon(QPixmap(":/new/prefix1/Dices/1.png")));
    ui->btn_save0->setIconSize(QSize(100,100));

    ui->btn_save1->setIcon(QIcon(QPixmap(":/new/prefix1/Dices/2.png")));
    ui->btn_save1->setIconSize(QSize(100,100));

    ui->btn_save2->setIcon(QIcon(QPixmap(":/new/prefix1/Dices/3.png")));
    ui->btn_save2->setIconSize(QSize(100,100));

    ui->btn_save3->setIcon(QIcon(QPixmap(":/new/prefix1/Dices/4.png")));
    ui->btn_save3->setIconSize(QSize(100,100));

    ui->btn_save4->setIcon(QIcon(QPixmap(":/new/prefix1/Dices/5.png")));
    ui->btn_save4->setIconSize(QSize(100,100));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_roll_clicked()
{
    g->update(ui);
    ui->tableWidget->setEnabled(true);
}

void MainWindow::on_btn_roll_2_clicked()
{
    enableSaveBtn();
}

void MainWindow::on_btn_exit_clicked()
{
    QMessageBox::StandardButton reply;
     reply = QMessageBox::question(this, "Yahtzee", "Do you really wanna exit?",
                                   QMessageBox::Yes|QMessageBox::No);
     if (reply == QMessageBox::Yes) {
       QApplication::quit();
     } else {
     }
   }

void MainWindow::on_btn_rules_clicked()
{
    QMessageBox::information(
            this,
            tr("Yahtzee"),
            tr("Yatzy är ett tärningsspel för en eller flera spelare där det gäller att"
               " samla poäng genom att med fem tärningar och tre kast under 15 omgångar, försöka få in kombinationer enligt följande tabell:\n"
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
               "L.stege \t|15|\tett till fem\n"
               "S.stege \t|20|\ttvå till sex\n"
               "kåk	    \t|28|\ttre av en sort, två av en annan\n"
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

void MainWindow::on_pushButton_clicked()
{
    qApp->quit();
    QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
}
void MainWindow::on_tableWidget_cellClicked(int row, int column)
{
    g->round->makeChoice(row, column);
}

void MainWindow::enableSaveBtn()
{
    ui->label->setVisible(true);
    ui->btn_roll->setVisible(true);
    ui->btn_roll_2->setVisible(false);
}

void MainWindow::on_btn_save0_toggled(bool checked)
{
       g->saveDice(0);
}
void MainWindow::on_btn_save1_toggled(bool checked)
{
       g->saveDice(1);
}
void MainWindow::on_btn_save2_toggled(bool checked)
{
       g->saveDice(2);
}
void MainWindow::on_btn_save3_toggled(bool checked)
{
       g->saveDice(3);
}
void MainWindow::on_btn_save4_toggled(bool checked)
{
       g->saveDice(4);
}

