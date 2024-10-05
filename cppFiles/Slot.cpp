#include "Slot.hpp"


Slot::Slot(const std::string& name, int price)
    : name(name), price(price), owner(nullptr), houses(0), houseCost(0) {
}

Slot::Slot(const std::string& name, int price, int houseCost)
    : name(name), price(price), owner(nullptr), houses(0), houseCost(houseCost) {
}

bool Slot::canBuildHouse() const {
    // Check if the slot has an owner and if the maximum number of houses is not exceeded
    return owner != nullptr && houses < 4; // Assuming 4 is the max number of houses
}

void Slot::buildHouse() {
    if (canBuildHouse()) {
        houses++;
        std::cout << "House built on " << name << ". Total houses: " << houses << std::endl;
    } else {
        std::cout << "Cannot build house on " << name << "." << std::endl;
    }
}
