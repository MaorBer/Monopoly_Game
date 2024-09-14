#include "GameBoard.hpp"

void GameBoard::addSlot(std::shared_ptr<Slot> slot) {
    slots.push_back(slot);
}

std::shared_ptr<Slot> GameBoard::getSlot(int position) {
    return slots[position % slots.size()];
}

void GameBoard::movePlayer(std::shared_ptr<Player> player, int steps) {
    player->position = (player->position + steps) % slots.size();
    slots[player->position]->action(player);
}
