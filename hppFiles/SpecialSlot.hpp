#ifndef SPECIALSLOT_HPP
#define SPECIALSLOT_HPP

#include "Slot.hpp"
#include <functional>

// SpecialSlot class represents non-purchasable slots like "Go to Jail", "Free Parking", and "Chance".
// Each slot has a custom action that is defined by the `setSpecialAction` method.
class SpecialSlot : public Slot {
public:
    // Constructors to initialize special slots (e.g., Jail, Chance, Tax, etc.)
    SpecialSlot(const std::string& name, int position);
    SpecialSlot(const std::string& name, int tax, int position);

    // Set a custom action for this slot (like sending a player to jail or drawing a card)
    void setSpecialAction(std::function<void(std::shared_ptr<Player>)> action);

    // Perform the custom action defined for this slot.
    void action(std::shared_ptr<Player> player) override;

private:
    std::function<void(std::shared_ptr<Player>)> specialAction;  // Store the special action
};

#endif // SPECIALSLOT_HPP
