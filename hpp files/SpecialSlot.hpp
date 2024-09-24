#ifndef SPECIALSLOT_HPP
#define SPECIALSLOT_HPP

#include "Slot.hpp"

class SpecialSlot : public Slot {
public:
    SpecialSlot(const std::string& name);
    SpecialSlot(const std::string& name, int tax);

    void action(std::shared_ptr<Player> player) override;
};

#endif // SPECIALSLOT_HPP
