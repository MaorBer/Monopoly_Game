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

    Slot(const std::string& name, int price);
    virtual ~Slot() = default;

    virtual void action(std::shared_ptr<Player> player) = 0; // Pure virtual function
};

#endif // SLOT_HPP
