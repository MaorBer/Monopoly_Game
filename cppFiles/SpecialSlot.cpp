#include "SpecialSlot.hpp"
#include "Player.hpp"

// Constructor for special slots without a specific action.
SpecialSlot::SpecialSlot(const std::string& name, int position)
    : Slot(name, 0, position), specialAction(nullptr) {}  // Default constructor, no action

// Constructor for tax slots that deduct a fixed amount from the player.
SpecialSlot::SpecialSlot(const std::string& name, int tax, int position)
    : Slot(name, tax, position), specialAction([tax](std::shared_ptr<Player> player) {
        std::cout << player->name << " pays $" << tax << " as tax." << std::endl;
        player->reduceMoney(tax);
    }) {}

// Assign a special action to this slot.
void SpecialSlot::setSpecialAction(std::function<void(std::shared_ptr<Player>)> action) {
    specialAction = action;
}

// Perform the action when a player lands on this slot.
void SpecialSlot::action(std::shared_ptr<Player> player) {
    if (specialAction) {
        specialAction(player);  // Execute the custom action
    } else {
        std::cout << player->name << " landed on a special slot: " << name << std::endl;
    }
}
