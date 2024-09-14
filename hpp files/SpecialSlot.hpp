#ifndef SPECIALSLOT_HPP
#define SPECIALSLOT_HPP

#include "Slot.hpp"

class SpecialSlot : public Slot {
public:
    SpecialSlot(const std::string& name);

    void action(std::shared_ptr<Player> player) override;
};

#endif // SPECIALSLOT_HPP
