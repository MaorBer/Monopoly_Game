#ifndef TRAIN_HPP
#define TRAIN_HPP

#include "Slot.hpp"
#include <algorithm>

class Train : public Slot {
public:
    int baseRent;

    Train(const std::string& name, int price, int baseRent);

    int calculateRent(int playerTrainCount) const;
    void action(std::shared_ptr<Player> player) override;
};

#endif // TRAIN_HPP
