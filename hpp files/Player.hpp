#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <vector>
#include <memory>
#include "Slot.hpp"

class Player {
public:
    std::string name;
    int money;
    int position;
    std::vector<std::shared_ptr<Slot>> properties;
    bool inJail;
    int turnsInJail;

    Player(const std::string& name, int money = 1500);

    void move(int steps);
    void buyProperty(std::shared_ptr<Slot> property);
    void payRent(int amount);
    void buildHouse(std::shared_ptr<Slot> street);
    bool isBankrupt() const;
};

#endif // PLAYER_HPP
