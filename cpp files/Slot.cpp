#include "Slot.hpp"

Slot::Slot(const std::string& name, int price)
    : name(name), price(price), owner(nullptr) {}
