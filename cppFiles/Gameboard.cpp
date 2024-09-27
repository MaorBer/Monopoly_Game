#include "GameBoard.hpp"
#include "SpecialSlot.hpp"
#include "Street.hpp"
#include "Train.hpp"
#include "Utility.hpp"

void init_board(std::vector<std::shared_ptr<Slot>> &slots)
{
   // Board is hardcoded as per the layout from the image.
    
    // Starting from "Go" and going clockwise
    slots.push_back(std::make_shared<SpecialSlot>("Go"));

    // First side of the board (bottom part)
    slots.push_back(std::make_shared<Street>("Mediterranean Avenue", 60, "Brown", 2, 50, 10, 250));
    slots.push_back(std::make_shared<SpecialSlot>("Community Chest"));
    slots.push_back(std::make_shared<Street>("Baltic Avenue", 60, "Brown", 4, 50, 20, 450));
    slots.push_back(std::make_shared<SpecialSlot>("Income Tax", 200)); // Fixed tax
    slots.push_back(std::make_shared<Train>("Reading Railroad", 200, 50));

    // Left side of the board
    slots.push_back(std::make_shared<Street>("Oriental Avenue", 100, "Light Blue", 6, 50, 30, 550));
    slots.push_back(std::make_shared<SpecialSlot>("Chance", 0));
    slots.push_back(std::make_shared<Street>("Vermont Avenue", 100, "Light Blue", 6, 50, 30, 550));
    slots.push_back(std::make_shared<Street>("Connecticut Avenue", 120, "Light Blue", 8, 50, 40, 600));

    slots.push_back(std::make_shared<SpecialSlot>("Jail", 0)); // Corner

    // Top part of the board
    slots.push_back(std::make_shared<Street>("St. Charles Place", 140, "Pink", 10, 100, 50, 750));
    slots.push_back(std::make_shared<Utility>("Electric Company", 150));
    slots.push_back(std::make_shared<Street>("States Avenue", 140, "Pink", 10, 100, 50, 750));
    slots.push_back(std::make_shared<Street>("Virginia Avenue", 160, "Pink", 12, 100, 60, 900));
    slots.push_back(std::make_shared<Train>("Pennsylvania Railroad", 200, 50));

    // Right side of the board
    slots.push_back(std::make_shared<Street>("St. James Place", 180, "Orange", 14, 100, 70, 950));
    slots.push_back(std::make_shared<SpecialSlot>("Community Chest", 0));
    slots.push_back(std::make_shared<Street>("Tennessee Avenue", 180, "Orange", 14, 100, 70, 950));
    slots.push_back(std::make_shared<Street>("New York Avenue", 200, "Orange", 16, 100, 80, 1000));

    slots.push_back(std::make_shared<SpecialSlot>("Free Parking", 0)); // Corner

    // Top part of the board
    slots.push_back(std::make_shared<Street>("Kentucky Avenue", 220, "Red", 18, 150, 90, 1050));
    slots.push_back(std::make_shared<SpecialSlot>("Chance", 0));
    slots.push_back(std::make_shared<Street>("Indiana Avenue", 220, "Red", 18, 150, 90, 1050));
    slots.push_back(std::make_shared<Street>("Illinois Avenue", 240, "Red", 20, 150, 100, 1100));
    slots.push_back(std::make_shared<Train>("B&O Railroad", 200, 50));

    // Left side of the board
    slots.push_back(std::make_shared<Street>("Atlantic Avenue", 260, "Yellow", 22, 150, 110, 1150));
    slots.push_back(std::make_shared<Street>("Ventnor Avenue", 260, "Yellow", 22, 150, 110, 1150));
    slots.push_back(std::make_shared<Utility>("Water Works", 150));
    slots.push_back(std::make_shared<Street>("Marvin Gardens", 280, "Yellow", 24, 150, 120, 1200));

    slots.push_back(std::make_shared<SpecialSlot>("Go to Jail", 0)); // Corner

    // Final side of the board
    slots.push_back(std::make_shared<Street>("Pacific Avenue", 300, "Green", 26, 200, 130, 1275));
    slots.push_back(std::make_shared<Street>("North Carolina Avenue", 300, "Green", 26, 200, 130, 1275));
    slots.push_back(std::make_shared<SpecialSlot>("Community Chest", 0));
    slots.push_back(std::make_shared<Street>("Pennsylvania Avenue", 320, "Green", 28, 200, 150, 1400));
    slots.push_back(std::make_shared<Train>("Short Line", 200, 50));

    // Last stretch (leading to Go)
    slots.push_back(std::make_shared<SpecialSlot>("Chance", 0));
    slots.push_back(std::make_shared<Street>("Park Place", 350, "Blue", 35, 200, 175, 1500));
    slots.push_back(std::make_shared<SpecialSlot>("Luxury Tax", 100));
    slots.push_back(std::make_shared<Street>("Boardwalk", 400, "Blue", 50, 200, 200, 2000));
}


std::shared_ptr<Slot> GameBoard::getSlot(int index) {
    if (index < 0 || index >= slots.size()) {
        throw std::out_of_range("Invalid slot index");
    }
    return slots[index];
}

// std::shared_ptr<Slot> GameBoard::getSlot(int position)
// {
//     return slots[position % slots.size()];
// }

void GameBoard::movePlayer(std::shared_ptr<Player> player, int steps)
{
    player->position = (player->position + steps) % slots.size();
    slots[player->position]->action(player);
}
