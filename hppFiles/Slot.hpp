#ifndef SLOT_HPP
#define SLOT_HPP

#include <iostream>
#include <string>
#include <memory>

class Player;

class Slot {
public:
    std::string name;
    int price;
    std::shared_ptr<Player> owner;
    int houses;  // Number of houses built on this slot
    int houseCost;  // Cost to build a house on this slot

    Slot(const std::string& name, int price, int houseCost)
        : name(name), price(price), owner(nullptr), houses(0), houseCost(houseCost) {}

    virtual ~Slot() = default;

    virtual void action(std::shared_ptr<Player> player) = 0; // Pure virtual function
    bool canBuildHouse() const; // Check if a house can be built
    void buildHouse(); // Function to build a hous
};

#endif // SLOT_HPP
