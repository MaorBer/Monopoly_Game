#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Connect buttons to the slots
    connect(ui->button_RollDice, &QPushButton::clicked, this, &MainWindow::onRollDiceClicked);
    connect(ui->button_BuyProperty, &QPushButton::clicked, this, &MainWindow::onBuyPropertyClicked);
    connect(ui->button_EndTurn, &QPushButton::clicked, this, &MainWindow::onEndTurnClicked);

    // Load Monopoly board as before
    QPixmap boardPixmap(":/resources/Monopolyboardimg.jpg");

    if (boardPixmap.isNull()) {
        qDebug() << "Image failed to load!";
    } else {
        QPixmap scaledBoard = boardPixmap.scaled(ui->label_Board->size(), Qt::KeepAspectRatio);
        ui->label_Board->setPixmap(scaledBoard);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onRollDiceClicked()
{
    qDebug() << "Roll Dice button clicked!";
    // Call your game manager's roll dice logic here
}

void MainWindow::onBuyPropertyClicked()
{
    qDebug() << "Buy Property button clicked!";
    // Call your game logic for purchasing property here
}

void MainWindow::onEndTurnClicked()
{
    qDebug() << "End Turn button clicked!";
    // Call your logic to end the turn and switch to the next player
}
