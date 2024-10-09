#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include "Slot.hpp"

// The Player class handles all player-specific information and actions, such as moving around the board,
// buying properties, paying rent, and managing their money. It also tracks whether the player is in jail
// and handles house building logic on owned properties.
class Player : public std::enable_shared_from_this<Player> {
public:
    std::string name;                 // Player's name
    int money;                        // Amount of money the player has
    int position;                     // Current position on the board (0-39)
    std::vector<std::shared_ptr<Slot>> properties;  // List of properties owned by the player
    bool inJail;                      // Flag to indicate if the player is in jail
    int turnsInJail;                  // Tracks how many turns the player has been in jail

    // Constructor initializes the player with a name and a default money value of 1500.
    Player(const std::string& name, int money = 1500);

    // Moves the player a certain number of steps and updates position.
    void move(int steps);

    // Buys a property if the player has enough money and the slot is not owned.
    void buyProperty(std::shared_ptr<Slot> property);

    // Pays rent, reducing money by the rent amount.
    void payRent(int amount);

    // Builds a house on a street property the player owns.
    void buildHouse(std::shared_ptr<Slot> street);

    // Checks if the player is bankrupt (money <= 0).
    bool isBankrupt() const;

    // Adds or reduces money by a specified amount.
    void reduceMoney(int price);  // Reduce the player's money by a given amount
    void addMoney(int amount);    // Add a given amount to the player's money

    // Returns true if the player owns both utilities (Electric and Water Company).
    bool ownsBothUtilities() const;

    // Roll dice and return a pair of values (for simulating the player's turn).
    static std::pair<int, int> rollDice();

    // Getters
    std::string getName() const;
    int getMoney() const;
    int getPosition() const;
    bool getInJail() const;
    int getTurnsInJail() const;

    // Setters
    void setName(const std::string& name);
    void setMoney(int money);
    void setPosition(int position);
    void setInJail(bool inJail);
    void setTurnsInJail(int turnsInJail);
};

#endif // PLAYER_HPP
