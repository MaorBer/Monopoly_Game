#ifndef GAMEBOARD_HPP
#define GAMEBOARD_HPP

#include <vector>
#include <memory>
#include "Slot.hpp"
#include "Player.hpp"

class GameBoard {
public:
    std::vector<std::shared_ptr<Slot>> slots;
    void init_board(std::vector<std::shared_ptr<Slot>> &slots);
    std::shared_ptr<Slot> getSlot(int position);
    void movePlayer(std::shared_ptr<Player> player, int steps);
};

#endif // GAMEBOARD_HPP
