#ifndef UTILITY_HPP
#define UTILITY_HPP

#include "Slot.hpp"

// Utility class represents the Electric Company and Water Works.
// Rent is calculated differently based on dice rolls and whether the player owns both utilities.
class Utility : public Slot, public std::enable_shared_from_this<Utility> {
public:
    // Constructor initializes utility name, price, and position.
    Utility(const std::string& name, int price, int position);

    // Action for when a player lands on this utility.
    void action(std::shared_ptr<Player> player) override;

    // Calculate rent based on dice rolls and ownership of both utilities.
    int calculateRent(int diceRoll, bool ownsBoth) const;
};

#endif // UTILITY_HPP
