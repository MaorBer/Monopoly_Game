#ifndef GAMEBOARD_HPP
#define GAMEBOARD_HPP

#include <vector>
#include <memory>
#include "Slot.hpp"
#include "Player.hpp"

// The GameBoard class is responsible for managing the board layout, tracking slots, and player movements.
// It contains a collection of slots and provides methods to initialize the board and move players around.
class GameBoard {
public:
    std::vector<std::shared_ptr<Slot>> slots;  // Vector holding all the slots on the board

    // Initializes the board with predefined slots in a fixed order.
    void initBoard();

    // Get a slot by its board position.
    std::shared_ptr<Slot> getSlot(int position);

    // Moves a player by a certain number of steps and triggers slot actions.
    void movePlayer(std::shared_ptr<Player> player, int steps);
};

#endif // GAMEBOARD_HPP
