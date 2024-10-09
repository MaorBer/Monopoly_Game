#include "Player.hpp"
#include "Slot.hpp"
#include "Utility.hpp"
#include "Street.hpp"
#include <iostream>




// Constructor initializes player attributes and sets default position and jail status.
Player::Player(const std::string& name, int money)
    : name(name), money(money), position(0), inJail(false), turnsInJail(0) {}

// Moves the player on the board by the given number of steps.
void Player::move(int steps) {
    int oldPosition = position;
    position = (position + steps) % 40;  // Assuming 40 positions on the board

    // Check if the player passed "Go" and collect $200.
    if (position < oldPosition) {
        std::cout << name << " passed Go! Collect $200." << std::endl;
        addMoney(200);
    }

    std::cout << name << " moves to position " << position << std::endl;
}

// Buys a property if it's unowned and the player has enough money.
void Player::buyProperty(std::shared_ptr<Slot> property) {
    if (!property->isOwned() && money >= property->price) {
        money -= property->price;
        properties.push_back(property);  // Add the property to the player's list of owned properties
        property->owner = shared_from_this();  // Set the player as the owner
        std::cout << name << " bought " << property->name << " for $" << property->price << std::endl;
    } else {
        std::cout << "Cannot buy " << property->name << std::endl;
    }
}

// Reduces the player's money by a given amount for rent or other payments.
void Player::payRent(int amount) {
    money -= amount;
    std::cout << name << " pays $" << amount << " in rent. Remaining money: $" << money << std::endl;
}

// Builds a house on a street if the player owns it and meets building rules.
void Player::buildHouse(std::shared_ptr<Slot> slot) {
    // Check if the slot is a Street using dynamic_cast
    auto street = std::dynamic_pointer_cast<Street>(slot);
    if (!street) {
        std::cout << "Cannot build houses on this slot type. This is not a street!" << std::endl;
        return;
    }

    // Check if the player is the owner of the street
    if (street->owner.lock() != shared_from_this()) {
        std::cout << "You do not own this property." << std::endl;
        return;
    }

    // Check if more houses can be built on this street
    if (!street->canBuildHouse()) {
        std::cout << "Cannot build more houses on " << street->name << "." << std::endl;
        return;
    }

    // Verify if the player has enough money to build the house
    if (money >= street->housePrice) {
        money -= street->housePrice;
        street->buildHouse();
        std::cout << name << " built a house on " << street->name << "." << std::endl;
    } else {
        std::cout << "Not enough money to build a house on " << street->name << "." << std::endl;
    }
}

// Checks if the player has gone bankrupt.
bool Player::isBankrupt() const {
    return money <= 0;
}

// Adds money to the player's total.
void Player::addMoney(int amount) {
    money += amount;
}

// Reduces the player's money.
void Player::reduceMoney(int price) {
    money -= price;  // Assuming price is always positive
}

// Checks if the player owns both utility slots (Electric Company and Water Works).
bool Player::ownsBothUtilities() const {
    int utilityCount = 0;
    for (const auto& property : properties) {
        if (std::dynamic_pointer_cast<Utility>(property)) {
            utilityCount++;
        }
    }
    return utilityCount == 2;
}

// Rolls two dice and returns the values.
std::pair<int, int> Player::rollDice() {
    return {1 + rand() % 6, 1 + rand() % 6};  // Simulate a dice roll between 1 and 6
}

// Getters and Setters
std::string Player::getName() const { return name; }
int Player::getMoney() const { return money; }
int Player::getPosition() const { return position; }
bool Player::getInJail() const { return inJail; }
int Player::getTurnsInJail() const { return turnsInJail; }
void Player::setName(const std::string& name) { this->name = name; }
void Player::setMoney(int money) { this->money = money; }
void Player::setPosition(int position) { this->position = position; }
void Player::setInJail(bool inJail) { this->inJail = inJail; }
void Player::setTurnsInJail(int turnsInJail) { this->turnsInJail = turnsInJail; }
