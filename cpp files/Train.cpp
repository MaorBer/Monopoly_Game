#include "Train.hpp"
#include "Player.hpp"

Train::Train(const std::string& name, int price, int baseRent)
    : Slot(name, price), baseRent(baseRent) {}

int Train::calculateRent(int playerTrainCount) const {
    return playerTrainCount * baseRent;
}

void Train::action(std::shared_ptr<Player> player) {
    if (owner != nullptr && owner != player) {
        int playerTrainCount = std::count_if(owner->properties.begin(), owner->properties.end(),
                                             [](std::shared_ptr<Slot> property) { return dynamic_cast<Train*>(property.get()) != nullptr; });
        int rent = calculateRent(playerTrainCount);
        std::cout << player->name << " pays train rent of " << rent << " to " << owner->name << std::endl;
        player->payRent(rent);
        owner->money += rent;
    }
}
