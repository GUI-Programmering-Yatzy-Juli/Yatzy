/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QPushButton *btn_rules;
    QPushButton *btn_roll_2;
    QPushButton *btn_roll;
    QTableWidget *tableWidget;
    QPushButton *btn_exit;
    QLabel *label;
    QSplitter *splitter;
    QPushButton *btn_save0;
    QPushButton *btn_save1;
    QPushButton *btn_save2;
    QPushButton *btn_save3;
    QPushButton *btn_save4;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1161, 781);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMaximumSize(QSize(1920, 1280));
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QStringLiteral(""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy1);
        centralWidget->setMaximumSize(QSize(1920, 1280));
        centralWidget->setAutoFillBackground(false);
        centralWidget->setStyleSheet(QStringLiteral("background-color: rgb(106, 200, 62);"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        btn_rules = new QPushButton(centralWidget);
        btn_rules->setObjectName(QStringLiteral("btn_rules"));
        sizePolicy1.setHeightForWidth(btn_rules->sizePolicy().hasHeightForWidth());
        btn_rules->setSizePolicy(sizePolicy1);
        btn_rules->setMinimumSize(QSize(298, 44));
        btn_rules->setMaximumSize(QSize(820, 100));
#ifndef QT_NO_TOOLTIP
        btn_rules->setToolTip(QString::fromUtf8("<html><head/><body><p><span style=\" font-size:14pt;\">Yahtzee spel, spela och besegra dina v\303\244nner</span></p></body></html>"));
#endif // QT_NO_TOOLTIP
        btn_rules->setToolTipDuration(10);
        btn_rules->setStyleSheet(QLatin1String("border-color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));
        btn_rules->setCheckable(false);
        btn_rules->setChecked(false);
        btn_rules->setAutoDefault(false);
        btn_rules->setFlat(false);

        gridLayout->addWidget(btn_rules, 1, 0, 1, 1);

        btn_roll_2 = new QPushButton(centralWidget);
        btn_roll_2->setObjectName(QStringLiteral("btn_roll_2"));
        sizePolicy1.setHeightForWidth(btn_roll_2->sizePolicy().hasHeightForWidth());
        btn_roll_2->setSizePolicy(sizePolicy1);
        btn_roll_2->setMinimumSize(QSize(300, 44));
        btn_roll_2->setMaximumSize(QSize(820, 100));
        btn_roll_2->setStyleSheet(QLatin1String("font: 22pt \"Adobe Fangsong Std R\";\n"
"border-color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));
        btn_roll_2->setCheckable(false);

        gridLayout->addWidget(btn_roll_2, 1, 3, 1, 1);

        btn_roll = new QPushButton(centralWidget);
        btn_roll->setObjectName(QStringLiteral("btn_roll"));
        sizePolicy1.setHeightForWidth(btn_roll->sizePolicy().hasHeightForWidth());
        btn_roll->setSizePolicy(sizePolicy1);
        btn_roll->setMinimumSize(QSize(300, 44));
        btn_roll->setMaximumSize(QSize(820, 100));
        btn_roll->setLayoutDirection(Qt::RightToLeft);
        btn_roll->setStyleSheet(QLatin1String("font: 22pt \"Adobe Fangsong Std R\";\n"
"border-color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));

        gridLayout->addWidget(btn_roll, 1, 2, 1, 1);

        tableWidget = new QTableWidget(centralWidget);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QFont font;
        font.setUnderline(true);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font);
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font);
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        if (tableWidget->rowCount() < 18)
            tableWidget->setRowCount(18);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(5, __qtablewidgetitem7);
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setFont(font1);
        __qtablewidgetitem8->setBackground(QColor(226, 226, 226));
        tableWidget->setVerticalHeaderItem(6, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        __qtablewidgetitem9->setFont(font1);
        __qtablewidgetitem9->setBackground(QColor(226, 226, 226));
        tableWidget->setVerticalHeaderItem(7, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(8, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(9, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(10, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(11, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(12, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(13, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(14, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(15, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(16, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        __qtablewidgetitem19->setFont(font1);
        __qtablewidgetitem19->setBackground(QColor(226, 226, 226));
        tableWidget->setVerticalHeaderItem(17, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget->setItem(1, 0, __qtablewidgetitem20);
        QBrush brush(QColor(195, 195, 195, 255));
        brush.setStyle(Qt::SolidPattern);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        __qtablewidgetitem21->setBackground(brush);
        __qtablewidgetitem21->setForeground(brush);
        tableWidget->setItem(6, 0, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        __qtablewidgetitem22->setBackground(brush);
        tableWidget->setItem(6, 1, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        __qtablewidgetitem23->setBackground(brush);
        tableWidget->setItem(7, 0, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        __qtablewidgetitem24->setBackground(brush);
        tableWidget->setItem(7, 1, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        __qtablewidgetitem25->setBackground(brush);
        __qtablewidgetitem25->setForeground(brush);
        tableWidget->setItem(17, 0, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        __qtablewidgetitem26->setBackground(brush);
        tableWidget->setItem(17, 1, __qtablewidgetitem26);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setEnabled(true);
        sizePolicy1.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy1);
        tableWidget->setMinimumSize(QSize(298, 595));
        tableWidget->setMaximumSize(QSize(820, 1280));
        tableWidget->setSizeIncrement(QSize(0, 0));
        QFont font2;
        font2.setItalic(false);
        font2.setUnderline(false);
        font2.setStrikeOut(false);
        tableWidget->setFont(font2);
        tableWidget->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CrossCursor)));
        tableWidget->setMouseTracking(false);
        tableWidget->setTabletTracking(false);
        tableWidget->setContextMenuPolicy(Qt::DefaultContextMenu);
        tableWidget->setAcceptDrops(false);
        tableWidget->setLayoutDirection(Qt::LeftToRight);
        tableWidget->setAutoFillBackground(false);
        tableWidget->setStyleSheet(QLatin1String("gridline-color: qconicalgradient(cx:0.5, cy:0.5, angle:0, stop:0 rgba(255, 255, 255, 255), stop:0.373979 rgba(255, 255, 255, 255), stop:0.373991 rgba(33, 30, 255, 255), stop:0.624018 rgba(33, 30, 255, 255), stop:0.624043 rgba(255, 0, 0, 255), stop:1 rgba(255, 0, 0, 255));\n"
"background-color: rgb(255, 255, 255);"));
        tableWidget->setInputMethodHints(Qt::ImhNone);
        tableWidget->setFrameShape(QFrame::StyledPanel);
        tableWidget->setFrameShadow(QFrame::Sunken);
        tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        tableWidget->setAutoScroll(true);
        tableWidget->setTabKeyNavigation(true);
        tableWidget->setProperty("showDropIndicator", QVariant(true));
        tableWidget->setAlternatingRowColors(false);
        tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectItems);
        tableWidget->setTextElideMode(Qt::ElideRight);
        tableWidget->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);
        tableWidget->setHorizontalScrollMode(QAbstractItemView::ScrollPerItem);
        tableWidget->setShowGrid(true);
        tableWidget->setSortingEnabled(false);
        tableWidget->setWordWrap(true);
        tableWidget->setCornerButtonEnabled(true);
        tableWidget->setColumnCount(2);
        tableWidget->horizontalHeader()->setVisible(true);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget->horizontalHeader()->setDefaultSectionSize(100);
        tableWidget->horizontalHeader()->setHighlightSections(true);
        tableWidget->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget->horizontalHeader()->setStretchLastSection(true);
        tableWidget->verticalHeader()->setVisible(true);
        tableWidget->verticalHeader()->setCascadingSectionResizes(true);
        tableWidget->verticalHeader()->setHighlightSections(true);
        tableWidget->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget->verticalHeader()->setStretchLastSection(false);

        gridLayout->addWidget(tableWidget, 0, 0, 1, 1);

        btn_exit = new QPushButton(centralWidget);
        btn_exit->setObjectName(QStringLiteral("btn_exit"));
        sizePolicy1.setHeightForWidth(btn_exit->sizePolicy().hasHeightForWidth());
        btn_exit->setSizePolicy(sizePolicy1);
        btn_exit->setMinimumSize(QSize(100, 44));
        btn_exit->setMaximumSize(QSize(200, 100));
        btn_exit->setStyleSheet(QLatin1String("background-color: rgb(255, 0, 0);\n"
"font: 75 28pt \"MS Shell Dlg 2\";"));

        gridLayout->addWidget(btn_exit, 1, 4, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);
        label->setStyleSheet(QStringLiteral("font: 75 14pt \"MS Shell Dlg 2\";"));

        gridLayout->addWidget(label, 0, 2, 1, 1, Qt::AlignHCenter|Qt::AlignTop);

        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        sizePolicy1.setHeightForWidth(splitter->sizePolicy().hasHeightForWidth());
        splitter->setSizePolicy(sizePolicy1);
        splitter->setMinimumSize(QSize(100, 100));
        splitter->setMaximumSize(QSize(200, 1020));
        splitter->setAutoFillBackground(false);
        splitter->setStyleSheet(QStringLiteral(""));
        splitter->setOrientation(Qt::Vertical);
        btn_save0 = new QPushButton(splitter);
        btn_save0->setObjectName(QStringLiteral("btn_save0"));
        sizePolicy1.setHeightForWidth(btn_save0->sizePolicy().hasHeightForWidth());
        btn_save0->setSizePolicy(sizePolicy1);
        btn_save0->setMinimumSize(QSize(100, 100));
        btn_save0->setMaximumSize(QSize(200, 200));
        btn_save0->setStyleSheet(QStringLiteral("border-color: rgb(0, 0, 0);"));
        btn_save0->setCheckable(true);
        splitter->addWidget(btn_save0);
        btn_save1 = new QPushButton(splitter);
        btn_save1->setObjectName(QStringLiteral("btn_save1"));
        sizePolicy1.setHeightForWidth(btn_save1->sizePolicy().hasHeightForWidth());
        btn_save1->setSizePolicy(sizePolicy1);
        btn_save1->setMinimumSize(QSize(100, 100));
        btn_save1->setMaximumSize(QSize(200, 200));
        btn_save1->setStyleSheet(QStringLiteral("border-color: rgb(0, 0, 0);"));
        btn_save1->setCheckable(true);
        splitter->addWidget(btn_save1);
        btn_save2 = new QPushButton(splitter);
        btn_save2->setObjectName(QStringLiteral("btn_save2"));
        sizePolicy1.setHeightForWidth(btn_save2->sizePolicy().hasHeightForWidth());
        btn_save2->setSizePolicy(sizePolicy1);
        btn_save2->setMinimumSize(QSize(100, 100));
        btn_save2->setMaximumSize(QSize(200, 200));
        btn_save2->setStyleSheet(QStringLiteral("border-color: rgb(0, 0, 0);"));
        btn_save2->setCheckable(true);
        splitter->addWidget(btn_save2);
        btn_save3 = new QPushButton(splitter);
        btn_save3->setObjectName(QStringLiteral("btn_save3"));
        sizePolicy1.setHeightForWidth(btn_save3->sizePolicy().hasHeightForWidth());
        btn_save3->setSizePolicy(sizePolicy1);
        btn_save3->setMinimumSize(QSize(100, 100));
        btn_save3->setMaximumSize(QSize(200, 200));
        QFont font3;
        font3.setPointSize(30);
        btn_save3->setFont(font3);
        btn_save3->setStyleSheet(QStringLiteral("border-color: rgb(0, 0, 0);"));
        btn_save3->setCheckable(true);
        splitter->addWidget(btn_save3);
        btn_save4 = new QPushButton(splitter);
        btn_save4->setObjectName(QStringLiteral("btn_save4"));
        sizePolicy1.setHeightForWidth(btn_save4->sizePolicy().hasHeightForWidth());
        btn_save4->setSizePolicy(sizePolicy1);
        btn_save4->setMinimumSize(QSize(100, 100));
        btn_save4->setMaximumSize(QSize(200, 200));
        btn_save4->setStyleSheet(QStringLiteral("border-color: rgb(0, 0, 0);"));
        btn_save4->setCheckable(true);
        splitter->addWidget(btn_save4);

        gridLayout->addWidget(splitter, 0, 4, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1161, 21));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(btn_save4, btn_save0);
        QWidget::setTabOrder(btn_save0, btn_save3);
        QWidget::setTabOrder(btn_save3, btn_save2);
        QWidget::setTabOrder(btn_save2, btn_roll);
        QWidget::setTabOrder(btn_roll, btn_save1);

        retranslateUi(MainWindow);

        btn_rules->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        btn_rules->setWhatsThis(QApplication::translate("MainWindow", "<html><head/><body><p>Yahtzee spel, spela och besegra dina v\303\244nner</p></body></html>", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        btn_rules->setText(QApplication::translate("MainWindow", "Rules", Q_NULLPTR));
        btn_roll_2->setText(QApplication::translate("MainWindow", "Start", Q_NULLPTR));
        btn_roll->setText(QApplication::translate("MainWindow", "Roll", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Spelare 1", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Spelare 2", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Ettor", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Tv\303\245or", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "Treor", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "Fyror", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->verticalHeaderItem(4);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "Femmor", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->verticalHeaderItem(5);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "Sexor", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->verticalHeaderItem(6);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "Po\303\244ng till bonus", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->verticalHeaderItem(7);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindow", "Bonus", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->verticalHeaderItem(8);
        ___qtablewidgetitem10->setText(QApplication::translate("MainWindow", "Ett par", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->verticalHeaderItem(9);
        ___qtablewidgetitem11->setText(QApplication::translate("MainWindow", "Tv\303\245 par", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->verticalHeaderItem(10);
        ___qtablewidgetitem12->setText(QApplication::translate("MainWindow", "Triss", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->verticalHeaderItem(11);
        ___qtablewidgetitem13->setText(QApplication::translate("MainWindow", "Fyrtal", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->verticalHeaderItem(12);
        ___qtablewidgetitem14->setText(QApplication::translate("MainWindow", "Liten stege", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget->verticalHeaderItem(13);
        ___qtablewidgetitem15->setText(QApplication::translate("MainWindow", "Stor stege", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget->verticalHeaderItem(14);
        ___qtablewidgetitem16->setText(QApplication::translate("MainWindow", "K\303\245k", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget->verticalHeaderItem(15);
        ___qtablewidgetitem17->setText(QApplication::translate("MainWindow", "Chans", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget->verticalHeaderItem(16);
        ___qtablewidgetitem18->setText(QApplication::translate("MainWindow", "Yatzy", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget->verticalHeaderItem(17);
        ___qtablewidgetitem19->setText(QApplication::translate("MainWindow", "Totalt", Q_NULLPTR));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        tableWidget->setSortingEnabled(__sortingEnabled);

        btn_exit->setText(QApplication::translate("MainWindow", "EXIT", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Player 1", Q_NULLPTR));
        btn_save0->setText(QString());
        btn_save1->setText(QString());
        btn_save2->setText(QString());
        btn_save3->setText(QString());
        btn_save4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
