#ifndef UTILITY_HPP
#define UTILITY_HPP

#include "Slot.hpp"
#include <memory>
#include <string>
#include <iostream> 
#include "Player.hpp"

class Utility : public Slot, public std::enable_shared_from_this<Utility> {
public:
    Utility(const std::string& name, int price);
    void action(std::shared_ptr<Player> player) override;

    // Getters
    const std::string& getName() const { return name; }
    int getPrice() const { return price; }

private:
    std::string name;
    int price;
    std::shared_ptr<Player> owner;
};

#endif // UTILITY_HPP
