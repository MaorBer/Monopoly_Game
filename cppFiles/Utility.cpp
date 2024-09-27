#include "Utility.hpp"
#include "Player.hpp"  // Include the Player class

Utility::Utility(const std::string& name, int price)
    : name(name), price(price) {}

void Utility::action(std::shared_ptr<Player> player) {
    // Implement the logic here (same as the previous response)
    if (!owner) {
        if (player->getMoney() >= price) {
            std::cout << player->getName() << " can buy " << name << " for " << price << " dollars." << std::endl;
            player->reduceMoney(price);
            owner = player;
            std::cout << player->getName() << " bought " << name << "." << std::endl;
        } else {
            std::cout << player->getName() << " doesn't have enough money to buy " << name << "." << std::endl;
        }
    } else if (owner == player) {
        std::cout << player->getName() << " owns this utility. No rent needed." << std::endl;
    } else {
        int diceRoll = player->rollDice();
        int rentMultiplier = owner->ownsBothUtilities() ? 10 : 4;
        int rent = diceRoll * rentMultiplier;

        std::cout << player->getName() << " landed on " << name << " owned by " << owner->getName()
                  << ". They must pay " << rent << " dollars." << std::endl;
        player->reduceMoney(rent);
        owner->addMoney(rent);
    }
}
