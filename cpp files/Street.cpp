#include "../hpp files/Street.hpp"
#include "../hpp files/Player.hpp"

Street::Street(const std::string& name, int price, const std::string& colorGroup, int rent, int housePrice, int rentWithHouse, int rentWithHotel)
    : Slot(name, price), colorGroup(colorGroup), rent(rent), housePrice(housePrice),
      rentWithHouse(rentWithHouse), rentWithHotel(rentWithHotel), houses(0), hasHotel(false) {}

void Street::buildHouse() {
    if (houses < 4 && !hasHotel) {
        houses++;
        std::cout << name << " now has " << houses << " houses." << std::endl;
    }
}

int Street::calculateRent() const {
    if (hasHotel) {
        return rentWithHotel;
    } else if (houses > 0) {
        return rentWithHouse * houses;
    }
    return rent;
}

void Street::action(std::shared_ptr<Player> player) {
    if (owner != nullptr && owner != player) {
        int rent = calculateRent();
        std::cout << player->name << " pays rent of " << rent << " to " << owner->name << std::endl;
        player->payRent(rent);
        owner->money += rent;
    } else if (owner == nullptr) {
        std::cout << player->name << " landed on " << name << " which is unowned and can be bought for " << price << std::endl;
        player->buyProperty(shared_from_this());
    }
}
