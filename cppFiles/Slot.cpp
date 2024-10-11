#include "../hppFiles/Slot.hpp"
#include "../hppFiles/Player.hpp"

// Slot constructor initializes the name, price, and position of the slot.
Slot::Slot(const std::string& name, int price, int position)
    : name(name), price(price), position(position) {}

// Checks if the slot has an owner.
bool Slot::isOwned() const {
    return !owner.expired();  // If the weak_ptr is expired, there is no owner.
}

// Displays slot information — basic implementation to be overridden by derived classes.
void Slot::displayInfo() const {
    std::cout << "Slot: " << name << ", Price: " << price << ", Position: " << position << std::endl;
}
