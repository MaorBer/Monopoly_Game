#ifndef GAMEMANAGER_HPP
#define GAMEMANAGER_HPP

#include <vector>
#include <memory>
#include "GameBoard.hpp"
#include "Player.hpp"
#include "Dice.hpp"

class GameManager {
public:
    std::vector<std::shared_ptr<Player>> players;
    GameBoard board;

    void playTurn(std::shared_ptr<Player> player);
    void addPlayer(const std::string& playerName);
    void startGame();
    bool isGameOver();
};

#endif // GAMEMANAGER_HPP
