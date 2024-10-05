#include "../hppFiles/GameManager.hpp"
#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime> // For time()

GameManager::GameManager() : board(), currentPlayerIndex(0) {
    // Initialize random seed for dice rolls
    std::srand(static_cast<unsigned int>(std::time(nullptr))); 
}

std::pair<int, int> GameManager::rollDice() {
    int die1 = std::rand() % 6 + 1; // Generate a random number between 1 and 6
    int die2 = std::rand() % 6 + 1; // Generate a random number between 1 and 6
    return { die1, die2 }; // Return the rolled values
}

void GameManager::buyProperty(std::shared_ptr<Player> player, std::shared_ptr<Slot> property) {
    if (property->owner) {
        std::cout << "Property already owned!" << std::endl;
        return;
    }
    
    if (player->getMoney() < property->price) {
        std::cout << "Not enough money to buy this property!" << std::endl;
        return;
    }
    
    player->buyProperty(property);
    property->owner = player; // Set the player as the owner of the property
    player->reduceMoney(property->price); // Deduct the cost from the player's money
    std::cout << player->getName() << " bought " << property->name << " for " << property->price << std::endl;
}

void GameManager::playTurn(std::shared_ptr<Player> player) {
    auto diceRoll = rollDice(); // Roll the dice
    std::cout << player->getName() << " rolled " << diceRoll.first << " and " << diceRoll.second << std::endl;
    int steps = diceRoll.first + diceRoll.second;
    board.movePlayer(player, steps); // Move the player

    // Get the slot the player landed on
    auto landedSlot = board.getSlot(player->getPosition());
    if (landedSlot) {
        landedSlot->action(player); // Execute the slot action
    }
}

void GameManager::endTurn() {
    currentPlayerIndex = (currentPlayerIndex + 1) % players.size(); // Move to the next player
    currentPlayer = players[currentPlayerIndex]; // Update the current player
}

void GameManager::startGame() {
    while (!isGameOver()) {
        playTurn(currentPlayer); // Play turn for the current player
    }
}

bool GameManager::isGameOver() {
    int activePlayers = 0;
    for (const auto& player : players) {
        if (!player->isBankrupt()) activePlayers++;
    }
    return activePlayers <= 1; // Game ends when one or no players are left
}
