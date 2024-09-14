#include "Player.hpp"
#include "Slot.hpp"

Player::Player(const std::string& name, int money)
    : name(name), money(money), position(0), inJail(false), turnsInJail(0) {}

void Player::move(int steps) {
    position = (position + steps) % 40;
    std::cout << name << " moves to position " << position << std::endl;
}

void Player::buyProperty(std::shared_ptr<Slot> property) {
    if (property->owner == nullptr && money >= property->price) {
        money -= property->price;
        properties.push_back(property);
        property->owner = shared_from_this();
        std::cout << name << " bought " << property->name << std::endl;
    }
}

void Player::payRent(int amount) {
    money -= amount;
    std::cout << name << " pays " << amount << " in rent. Remaining money: " << money << std::endl;
}

void Player::buildHouse(std::shared_ptr<Slot> street) {
    // TODO: Add house-building logic
}

bool Player::isBankrupt() const {
    return money <= 0;
}
