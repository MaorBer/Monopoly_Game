#include "../hppFiles/GameManager.hpp"
#include <iostream>

GameManager::GameManager() : board() { // Initialize GameBoard
    // Any additional initialization logic for the game can go here
}

void GameManager::playTurn(std::shared_ptr<Player> player) {
    auto diceRoll = player->rollDice();  // Call rollDice on the player instance
    std::cout << player->getName() << " rolled " << diceRoll.first << " and " << diceRoll.second << std::endl;
    int steps = diceRoll.first + diceRoll.second;
    board.movePlayer(player, steps); // Make sure movePlayer handles game logic
}

void GameManager::addPlayer(const std::string& playerName) {
    // Check if the player already exists
    for (const auto& player : players) {
        if (player->getName() == playerName) {
            std::cout << "Player " << playerName << " already exists!" << std::endl;
            return; // Prevent adding duplicate players
        }
    }
    players.push_back(std::make_shared<Player>(playerName));
}

void GameManager::startGame() {
    while (!isGameOver()) {
        for (auto& player : players) {
            if (!player->isBankrupt()) {
                playTurn(player);
            }
        }
    }
}

bool GameManager::isGameOver() {
    int activePlayers = 0;
    for (const auto& player : players) {
        if (!player->isBankrupt()) activePlayers++;
    }
    return activePlayers <= 1; // Game ends when one or no players are left
}
