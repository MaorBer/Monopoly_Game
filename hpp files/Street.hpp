#ifndef STREET_HPP
#define STREET_HPP

#include "Slot.hpp"

class Street : public Slot,  public std::enable_shared_from_this<Street> {
public:
    std::string colorGroup;
    int rent;
    int housePrice;
    int rentWithHouse;
    int rentWithHotel;
    int houses;
    bool hasHotel;

    Street(const std::string& name, int price, const std::string& colorGroup, int rent, int housePrice, int rentWithHouse, int rentWithHotel);

    void buildHouse();
    int calculateRent() const;

    void action(std::shared_ptr<Player> player) override;
};

#endif // STREET_HPP
