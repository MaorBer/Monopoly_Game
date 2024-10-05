#include "../hppFiles/Player.hpp"
#include "../hppFiles/Slot.hpp"
#include "../hppFiles/Utility.hpp"
#include <iostream>
#include <algorithm>

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
    if (street->owner != shared_from_this()) {
        std::cout << "You do not own this property." << std::endl;
        return;
    }

    if (!street->canBuildHouse()) {
        std::cout << "Cannot build more houses on " << street->name << "." << std::endl;
        return;
    }

    if (money >= street->houseCost) {
        money -= street->houseCost;
        street->buildHouse();
    } else {
        std::cout << "Not enough money to build a house on " << street->name << "." << std::endl;
    }
}

bool Player::isBankrupt() const {
    return money <= 0;
}

void Player::reduceMoney(int price) {
    if (price > 0) {
        this->money -= price;
    } else {
        exit(1);
    }
}

void Player::addMoney(int amount) {
    if (amount > 0) {
        money += amount;
    }
}

bool Player::ownsBothUtilities() const {
    int utilityCount = 0;
    for (const auto& property : properties) {
        if (std::dynamic_pointer_cast<Utility>(property)) {
            utilityCount++;
        }
    }
    return utilityCount == 2;
}

std::pair<int, int> Player::rollDice() {
    return {1 + rand() % 6, 1 + rand() % 6};
}

// Getters
std::string Player::getName() const {
    return name;
}

int Player::getMoney() const {
    return money;
}

int Player::getPosition() const {
    return position;
}

bool Player::getInJail() const {
    return inJail;
}

int Player::getTurnsInJail() const {
    return turnsInJail;
}

// Setters
void Player::setName(const std::string& name) {
    this->name = name;
}

void Player::setMoney(int money) {
    this->money = money;
}

void Player::setPosition(int position) {
    this->position = position;
}

void Player::setInJail(bool inJail) {
    this->inJail = inJail;
}

void Player::setTurnsInJail(int turnsInJail) {
    this->turnsInJail = turnsInJail;
}
