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

    // Constructor 
    Slot(const std::string& name, int price, int houseCost);

    Slot(const std::string& name, int price);

    virtual ~Slot() = default;

    virtual void action(std::shared_ptr<Player> player) = 0; // Pure virtual function
    bool canBuildHouse() const; // Check if a house can be built
    void buildHouse(); // Function to build a house
};

#endif // SLOT_HPP
