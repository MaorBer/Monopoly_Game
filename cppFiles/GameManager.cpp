#include "../hppFiles/GameManager.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

// Constructor initializes the game board and sets up an empty player list.
GameManager::GameManager() : currentPlayerIndex(0) {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));  // Seed random number generator
    board.initBoard();  // Initialize the game board with slots
}

// Adds a new player by name.
void GameManager::addPlayer(const std::string &playerName) {
    auto newPlayer = std::make_shared<Player>(playerName);
    players.push_back(newPlayer);  // Add the new player to the players list
    if (players.size() == 1) {
        currentPlayer = newPlayer;  // Set the first player as the current player
    }
}


// Starts the main game loop, rotating through players until the game ends.
void GameManager::startGame() {
    while (!isGameOver()) {
        playTurn(players[currentPlayerIndex]);  // Play turn for the current player
        endTurn();  // Move to the next player
    }
}

// Executes a single turn for the specified player.
void GameManager::playTurn(std::shared_ptr<Player> player) {
    auto diceRoll = rollDice();
    std::cout << player->getName() << " rolled " << diceRoll.first << " and " << diceRoll.second << std::endl;
    int steps = diceRoll.first + diceRoll.second;
    board.movePlayer(player, steps);  // Move the player and trigger slot actions
}

// Ends the current player's turn and moves to the next player.
void GameManager::endTurn() {
    currentPlayerIndex = (currentPlayerIndex + 1) % players.size();  // Go to the next player
    currentPlayer = players[currentPlayerIndex];
}

// Rolls two six-sided dice and returns the values.
std::pair<int, int> GameManager::rollDice() {
    return { std::rand() % 6 + 1, std::rand() % 6 + 1 };
}

// Handles property purchase for the current player.
void GameManager::buyProperty(std::shared_ptr<Player> player, std::shared_ptr<Slot> property) {
    if (property->isOwned()) {
        std::cout << "This property is already owned!" << std::endl;
        return;
    }
    player->buyProperty(property);
}

// Checks if the game is over (only one player left).
bool GameManager::isGameOver() {
    int activePlayers = 0;
    for (const auto& player : players) {
        if (!player->isBankrupt()) activePlayers++;
    }
    return activePlayers <= 1;
}
