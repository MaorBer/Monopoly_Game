#include "../hppFiles/Player.hpp"
#include "../hppFiles/Slot.hpp"
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
    // TODO: Add house-building logic
}

bool Player::isBankrupt() const {
    return money <= 0;
}

void Player::reduceMoney(int price) {
    if (price > 0) {
        this->money -= price;
    }
    else{
        exit(1);
    }
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