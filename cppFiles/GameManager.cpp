#include "../hppFiles/GameManager.hpp"

void GameManager::playTurn(std::shared_ptr<Player> player) {
    auto diceRoll = Player::rollDice();  
    std::cout << player->name << " rolled " << diceRoll.first << " and " << diceRoll.second << std::endl;
    int steps = diceRoll.first + diceRoll.second;
    board.movePlayer(player, steps);
}

void GameManager::addPlayer(const std::string& playerName) {
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
    return activePlayers <= 1;
}
