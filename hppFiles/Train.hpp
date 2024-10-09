#ifndef TRAIN_HPP
#define TRAIN_HPP

#include "Slot.hpp"
#include <memory>
#include <algorithm>

// Train class represents railroad slots on the board.
// The rent increases based on the number of railroads owned by the same player.
class Train : public Slot {
public:
    int baseRent;  // Base rent for owning a single railroad

    // Constructor initializes the railroad's attributes, including its position and base rent.
    Train(const std::string& name, int price, int baseRent, int position);

    // Action for when a player lands on this railroad slot.
    void action(std::shared_ptr<Player> player) override;

    // Calculates rent based on the number of railroads owned.
    int calculateRent(int trainsOwned) const;
};

#endif // TRAIN_HPP
