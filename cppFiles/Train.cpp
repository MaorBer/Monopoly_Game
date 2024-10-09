#include "Train.hpp"
#include "Player.hpp"

// Train constructor initializes name, price, baseRent, and position.
Train::Train(const std::string& name, int price, int baseRent, int position)
    : Slot(name, price, position), baseRent(baseRent) {}

// Calculates rent based on the number of railroads owned by the same player.
int Train::calculateRent(int trainsOwned) const {
    return trainsOwned * baseRent;  // Rent increases with each additional railroad owned
}

// Action performed when a player lands on this railroad.
void Train::action(std::shared_ptr<Player> player) {
    auto slotOwner = owner.lock();  // Get the owner using a shared_ptr from the weak_ptr
    if (slotOwner && slotOwner != player) {
        // Calculate rent based on the number of railroads owned by the same player
        int playerTrainCount = std::count_if(slotOwner->properties.begin(), slotOwner->properties.end(),
                                             [](std::shared_ptr<Slot> property) { 
                                                 return dynamic_cast<Train*>(property.get()) != nullptr; 
                                             });
        int rent = calculateRent(playerTrainCount);
        std::cout << player->name << " pays train rent of $" << rent << " to " << slotOwner->name << "." << std::endl;
        player->payRent(rent);
        slotOwner->addMoney(rent);  // Owner collects the rent
    } else if (!slotOwner) {
        std::cout << player->name << " landed on an unowned railroad: " << name 
                  << ". Would you like to buy it for $" << price << "?" << std::endl;
    }
}
