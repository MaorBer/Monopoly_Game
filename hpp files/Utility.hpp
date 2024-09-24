#ifndef UTILITY_HPP
#define UTILITY_HPP

#include "Slot.hpp"

class Utility : public Slot,  public std::enable_shared_from_this<Utility> {
public:
    std::string name;
    int price;

    Utility(std::string name, int price);
};

#endif // UTILITY_HPP