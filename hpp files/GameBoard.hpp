#ifndef GAMEBOARD_HPP
#define GAMEBOARD_HPP

#include <vector>
#include <memory>
#include "Slot.hpp"
#include "Player.hpp"

class GameBoard {
public:
    std::vector<std::shared_ptr<Slot>> slots;

    void addSlot(std::shared_ptr<Slot> slot);
    std::shared_ptr<Slot> getSlot(int position);
    void movePlayer(std::shared_ptr<Player> player, int steps);
};

#endif // GAMEBOARD_HPP
