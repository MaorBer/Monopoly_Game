#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "hppFiles/GameManager.hpp"  // Include your GameManager header


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    gameManager(std::make_shared<GameManager>()), // Initialize the GameManager
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

void MainWindow::onRollDiceClicked() {
    qDebug() << "Roll Dice button clicked!";
    auto [die1, die2] = gameManager->rollDice(); // Call your game manager's roll dice logic
    qDebug() << "Rolled:" << die1 << "and" << die2;

    // You can also update the UI to display the rolled numbers if needed
}

void MainWindow::onBuyPropertyClicked() {
    qDebug() << "Buy Property button clicked!";
    // Implement logic to buy property, assuming currentPlayer and selectedProperty are defined
    // Example:
    // gameManager->buyProperty(currentPlayer, selectedProperty);
}

void MainWindow::onEndTurnClicked() {
    qDebug() << "End Turn button clicked!";
    // Call your logic to end the turn and switch to the next player
    gameManager->endTurn();
}


// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onRollDiceClicked();
    void onBuyPropertyClicked();
    void onEndTurnClicked();

private:
    Ui::MainWindow *ui;
    std::shared_ptr<GameManager> gameManager; // Add this line
};
