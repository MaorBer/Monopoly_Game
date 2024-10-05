#include "SpecialSlot.hpp"
#include "Player.hpp"

SpecialSlot::SpecialSlot(const std::string &name)
    : Slot(name, 0, 0) {} // Pass 0 for price and houseCost

void SpecialSlot::action(std::shared_ptr<Player> player)
{
    std::cout << player->name << " landed on special slot " << name << std::endl;
    // Implement special action based on slot type
}

SpecialSlot::SpecialSlot(const std::string &name, int tax)
    : Slot(name, tax, 0) {} // Pass tax as price and 0 for houseCost
