#include <iostream>
#include <memory>
#include <vector>
#include "GameManager.hpp"
#include "Player.hpp"
#include "GameBoard.hpp"

int main() {
    // Create a GameManager instance
    GameManager gameManager;

    // Add players
    gameManager.addPlayer("Alice");
    gameManager.addPlayer("Bob");
    gameManager.addPlayer("Charlie");

    // Start the game
    std::cout << "Starting the Monopoly game!" << std::endl;
    gameManager.startGame();

    // Simulate a few turns
    for (int turn = 1; turn <= 10; ++turn) {
        std::cout << "\nTurn " << turn << ":" << std::endl;
        for (const auto& player : gameManager.players) {
            if (!player->isBankrupt()) {
                gameManager.playTurn(player);
                // Add additional game logic here, such as checking if the player lands on a property, buying it, etc.
                
                // Example: Check if the player is bankrupt after their turn
                if (player->isBankrupt()) {
                    std::cout << player->getName() << " is bankrupt!" << std::endl;
                }
            }
        }
        // Check if the game is over after each turn
        if (gameManager.isGameOver()) {
            std::cout << "Game over! Only one player remains!" << std::endl;
            break; // Exit the turn loop if the game is over
        }
    }

    std::cout << "Thanks for playing!" << std::endl;
    return 0;
}
