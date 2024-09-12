#include <iostream>
#include <vector>
#include <string>
#include <memory> 


class Player {
public:
    std::string name;
    int money;
    int position; // Player's current position on the board
    std::vector<std::shared_ptr<Slot>> properties;
    bool inJail;
    int turnsInJail;

    Player(const std::string& name, int money = 1500)
        : name(name), money(money), position(0), inJail(false), turnsInJail(0) {}

    void move(int steps); // Moves the player
    void buyProperty(std::shared_ptr<Slot> property);
    void payRent(int amount);
    void buildHouse(std::shared_ptr<Slot> street);
    bool isBankrupt() const { return money <= 0; }
};