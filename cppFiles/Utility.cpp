#include "../hppFiles/Utility.hpp"
#include "../hppFiles/Player.hpp"

// Constructor initializes the utility's name, price, and board position.
Utility::Utility(const std::string& name, int price, int position)
    : Slot(name, price, position) {}

// Calculates the rent based on the dice roll and whether the owner has both utilities.
int Utility::calculateRent(int diceRoll, bool ownsBoth) const {
    return diceRoll * (ownsBoth ? 10 : 4);  // 10x if both utilities are owned, 4x otherwise
}

// Action performed when a player lands on this utility slot.
void Utility::action(std::shared_ptr<Player> player) {
    auto slotOwner = owner.lock();
    if (slotOwner && slotOwner != player) {
        // Owner exists and it's not the player landing here
        auto diceRoll = player->rollDice();
        int diceSum = diceRoll.first + diceRoll.second;  // Sum of the dice rolls
        int rent = calculateRent(diceSum, slotOwner->ownsBothUtilities());

        std::cout << player->name << " landed on " << name << " owned by " << slotOwner->name
                  << ". They must pay $" << rent << " in rent." << std::endl;
        player->payRent(rent);
        slotOwner->addMoney(rent);
    } else if (!slotOwner) {
        std::cout << player->name << " landed on an unowned utility: " << name 
                  << ". Would you like to buy it for $" << price << "?" << std::endl;
    }
}
