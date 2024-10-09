#ifndef GAMEMANAGER_HPP
#define GAMEMANAGER_HPP

#include <vector>
#include <memory>
#include <string>
#include "GameBoard.hpp"
#include "Player.hpp"

// The GameManager class is responsible for controlling the overall game flow.
// It handles player turns, dice rolls, buying properties, and detecting the game-over state.
class GameManager {
public:
    GameManager();  // Constructor initializes the game board and sets up players

    // Adds a new player to the game by name.
    void addPlayer(const std::string& playerName);

    // Start the main game loop.
    void startGame();

    // Executes a single turn for the current player.
    void playTurn(std::shared_ptr<Player> player);

    // Ends the current player's turn and moves to the next player.
    void endTurn();

    // Rolls two dice and returns the result as a pair.
    std::pair<int, int> rollDice();

    // Allows a player to buy a property if it's available.
    void buyProperty(std::shared_ptr<Player> player, std::shared_ptr<Slot> property);

    // Checks if the game is over (only one player left not bankrupt).
    bool isGameOver();

private:
    GameBoard board;  // The game board containing all the slots
    std::vector<std::shared_ptr<Player>> players;  // List of players
    std::shared_ptr<Player> currentPlayer;  // Pointer to the player currently taking their turn
    int currentPlayerIndex;  // Index of the current player in the players vector
};

#endif // GAMEMANAGER_HPP
