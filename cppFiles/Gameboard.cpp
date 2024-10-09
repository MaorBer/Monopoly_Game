#include "GameBoard.hpp"
#include "Street.hpp"
#include "Train.hpp"
#include "Utility.hpp"
#include "SpecialSlot.hpp"

// Initializes the board with all 40 slots in their fixed positions.
void GameBoard::initBoard() {
    slots.reserve(40);  // Reserve space for 40 slots

    // Bottom side of the board
    slots.push_back(std::make_shared<SpecialSlot>("Go", 0));  // Position 0
    slots.push_back(std::make_shared<Street>("Mediterranean Avenue", 60, "Brown", 2, 50, 10, 250, 1));
    slots.push_back(std::make_shared<SpecialSlot>("Community Chest", 2));
    slots.push_back(std::make_shared<Street>("Baltic Avenue", 60, "Brown", 4, 50, 20, 450, 3));
    slots.push_back(std::make_shared<SpecialSlot>("Income Tax", 200, 4));  // Pay $200
    slots.push_back(std::make_shared<Train>("Reading Railroad", 200, 50, 5));
    slots.push_back(std::make_shared<Street>("Oriental Avenue", 100, "Light Blue", 6, 50, 30, 550, 6));
    slots.push_back(std::make_shared<SpecialSlot>("Chance", 7));  // Chance slot
    slots.push_back(std::make_shared<Street>("Vermont Avenue", 100, "Light Blue", 6, 50, 30, 550, 8));
    slots.push_back(std::make_shared<Street>("Connecticut Avenue", 120, "Light Blue", 8, 50, 40, 600, 9));
    slots.push_back(std::make_shared<SpecialSlot>("Jail", 10));  // Jail slot

    // Left side of the board
    slots.push_back(std::make_shared<Street>("St. Charles Place", 140, "Pink", 10, 100, 50, 750, 11));
    slots.push_back(std::make_shared<Utility>("Electric Company", 150, 12));
    slots.push_back(std::make_shared<Street>("States Avenue", 140, "Pink", 10, 100, 50, 750, 13));
    slots.push_back(std::make_shared<Street>("Virginia Avenue", 160, "Pink", 12, 100, 60, 900, 14));
    slots.push_back(std::make_shared<Train>("Pennsylvania Railroad", 200, 50, 15));
    slots.push_back(std::make_shared<Street>("St. James Place", 180, "Orange", 14, 100, 70, 950, 16));
    slots.push_back(std::make_shared<SpecialSlot>("Community Chest", 17));
    slots.push_back(std::make_shared<Street>("Tennessee Avenue", 180, "Orange", 14, 100, 70, 950, 18));
    slots.push_back(std::make_shared<Street>("New York Avenue", 200, "Orange", 16, 100, 80, 1000, 19));
    slots.push_back(std::make_shared<SpecialSlot>("Free Parking", 20));  // Free Parking slot

    // Top side of the board
    slots.push_back(std::make_shared<Street>("Kentucky Avenue", 220, "Red", 18, 150, 90, 1050, 21));
    slots.push_back(std::make_shared<SpecialSlot>("Chance", 22));  // Chance slot
    slots.push_back(std::make_shared<Street>("Indiana Avenue", 220, "Red", 18, 150, 90, 1050, 23));
    slots.push_back(std::make_shared<Street>("Illinois Avenue", 240, "Red", 20, 150, 100, 1100, 24));
    slots.push_back(std::make_shared<Train>("B&O Railroad", 200, 50, 25));
    slots.push_back(std::make_shared<Street>("Atlantic Avenue", 260, "Yellow", 22, 150, 110, 1150, 26));
    slots.push_back(std::make_shared<Street>("Ventnor Avenue", 260, "Yellow", 22, 150, 110, 1150, 27));
    slots.push_back(std::make_shared<Utility>("Water Works", 150, 28));
    slots.push_back(std::make_shared<Street>("Marvin Gardens", 280, "Yellow", 24, 150, 120, 1200, 29));
    slots.push_back(std::make_shared<SpecialSlot>("Go to Jail", 30));  // Go to Jail slot

    // Right side of the board
    slots.push_back(std::make_shared<Street>("Pacific Avenue", 300, "Green", 26, 200, 130, 1275, 31));
    slots.push_back(std::make_shared<Street>("North Carolina Avenue", 300, "Green", 26, 200, 130, 1275, 32));
    slots.push_back(std::make_shared<SpecialSlot>("Community Chest", 33));
    slots.push_back(std::make_shared<Street>("Pennsylvania Avenue", 320, "Green", 28, 200, 150, 1400, 34));
    slots.push_back(std::make_shared<Train>("Short Line", 200, 50, 35));
    slots.push_back(std::make_shared<SpecialSlot>("Chance", 36));  // Chance slot
    slots.push_back(std::make_shared<Street>("Park Place", 350, "Blue", 35, 200, 175, 1500, 37));
    slots.push_back(std::make_shared<SpecialSlot>("Luxury Tax", 100, 38));  // Pay $100 luxury tax
    slots.push_back(std::make_shared<Street>("Boardwalk", 400, "Blue", 50, 200, 200, 2000, 39));
}


// Returns the slot at the specified position.
std::shared_ptr<Slot> GameBoard::getSlot(int position) {
    if (position < 0 || position >= static_cast<int>(slots.size())) {
        throw std::out_of_range("Invalid slot index");
    }
    return slots[position];
}

// Moves a player a specified number of steps and triggers slot-specific actions.
void GameBoard::movePlayer(std::shared_ptr<Player> player, int steps) {
    player->move(steps);  // Update player position
    auto landedSlot = getSlot(player->getPosition());
    if (landedSlot) {
        landedSlot->action(player);  // Execute the action for the slot
    }
}
