#ifndef GAMEMANAGER_HPP
#define GAMEMANAGER_HPP

#include <vector>
#include <memory>
#include "GameBoard.hpp"
#include "Player.hpp"

class GameManager {
public:
    GameManager(); // Constructor to initialize GameBoard

    void playTurn(std::shared_ptr<Player> player);
    void addPlayer(const std::string& playerName);
    void startGame();
    bool isGameOver();
    std::pair<int, int> rollDice(); // Roll the dice
    void buyProperty(std::shared_ptr<Player> player, std::shared_ptr<Slot> property); // Buy property
    void endTurn(); // End the current turn

    std::vector<std::shared_ptr<Player>> players;
    std::shared_ptr<Player> currentPlayer; // Track the current player

private:
    GameBoard board;
    int currentPlayerIndex; // Track the index of the current player
};

#endif // GAMEMANAGER_HPP
