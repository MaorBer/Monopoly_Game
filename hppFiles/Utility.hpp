#ifndef UTILITY_HPP
#define UTILITY_HPP

#include "Slot.hpp"
#include <memory>
#include <string>
#include <iostream>  // For std::cout (if you're using it for output)

class Utility : public Slot, public std::enable_shared_from_this<Utility> {
public:
    std::string name;
    int price;

    Utility(const std::string& name, int price);
    virtual void action(std::shared_ptr<Player> player) override;
};

#endif // UTILITY_HPP
