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

private:
    std::vector<std::shared_ptr<Player>> players;
    GameBoard board;
};

#endif // GAMEMANAGER_HPP
