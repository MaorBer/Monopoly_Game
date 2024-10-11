#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "hppFiles/GameManager.hpp"
#include <QLabel>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , gameManager(std::make_shared<GameManager>())  // Initialize gameManager
{
    ui->setupUi(this);

    // Check Init Game button
    if (!ui->button_InitGame) {
        qDebug() << "Error: button_InitGame is nullptr!";
    } else {
        qDebug() << "button_InitGame is correctly initialized.";
    }

    // Load Monopoly board image
    QPixmap boardPixmap(":/Resources/MonopolyBoard.jpg");

    if (boardPixmap.isNull()) {
        qDebug() << "Image failed to load!";
    } else {
        // Set the Monopoly board image to the QLabel
        ui->label_Board->setPixmap(boardPixmap.scaled(ui->label_Board->size(), Qt::KeepAspectRatio));
    }

    // Connect the Init Game button to the new slot
    // connect(ui->button_InitGame, &QPushButton::clicked, this, &MainWindow::onInitGameButtonClicked);
    // qDebug() << "Connection made to onInitGameButtonClicked slot.";
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onInitGameButtonClicked() {
    qDebug() << "Init Game button clicked! Starting a new game.";

    // Reset the game state by creating a new GameManager instance
    qDebug() << "Creating new GameManager...";
    gameManager = std::make_shared<GameManager>();
    if (!gameManager) {
        qDebug() << "Error: GameManager is nullptr!";
        return;  // Exit early if gameManager could not be created
    }

    qDebug() << "Adding Player 1...";
    gameManager->addPlayer("Player 1");

    qDebug() << "Adding Player 2...";
    gameManager->addPlayer("Player 2");

    qDebug() << "Adding Player 3...";
    gameManager->addPlayer("Player 3");

    qDebug() << "Adding Player 4...";
    gameManager->addPlayer("Player 4");

    qDebug() << "Initialized game with 4 players successfully.";

    // Update the UI to reflect the reset game state
    ui->button_InitGame->setText("Game Initialized!");
    qDebug() << "UI updated successfully.";
}

