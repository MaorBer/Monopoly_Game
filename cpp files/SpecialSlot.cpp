#include "SpecialSlot.hpp"
#include "Player.hpp"

SpecialSlot::SpecialSlot(const std::string& name)
    : Slot(name, 0) {}

void SpecialSlot::action(std::shared_ptr<Player> player) {
    std::cout << player->name << " landed on special slot " << name << std::endl;
    // Implement special action based on slot type
}
