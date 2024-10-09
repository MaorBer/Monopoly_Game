#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memory> // Include for std::shared_ptr
#include "hppFiles/GameManager.hpp" // Include the GameManager header

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onRollDiceClicked();   // Slot for "Roll Dice" button
    void onBuyPropertyClicked(); // Slot for "Buy Property" button
    void onEndTurnClicked();    // Slot for "End Turn" button

private:
    Ui::MainWindow *ui;
    std::shared_ptr<GameManager> gameManager; // Member variable for GameManager
};

#endif // MAINWINDOW_H
