#include <iostream>
#include <vector>
#include <string>
#include <memory> 


class Slot {
public:
    std::string name;
    int price;
    std::shared_ptr<Player> owner;

    Slot(const std::string& name, int price)
        : name(name), price(price), owner(nullptr) {}

    virtual void action(std::shared_ptr<Player> player) = 0; // Pure virtual method
    virtual ~Slot() = default; // Ensure proper cleanup for derived classes
};