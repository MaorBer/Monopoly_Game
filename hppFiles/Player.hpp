// Player.hpp
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <vector>
#include <memory>
#include "Slot.hpp"

class Player : public std::enable_shared_from_this<Player> {
public:
    std::string name;
    int money;
    int position;
    std::vector<std::shared_ptr<Slot>> properties;
    bool inJail;
    int turnsInJail;

    Player(const std::string& name, int money = 1500);

    void move(int steps);
    void buyProperty(std::shared_ptr<Slot> property);
    void payRent(int amount);
    void buildHouse(std::shared_ptr<Slot> street);
    bool isBankrupt() const;
    void reduceMoney(int price); 
    void addMoney(int amount);
    bool ownsBothUtilities() const;
    // static std::pair<int, int> rollDice();

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
