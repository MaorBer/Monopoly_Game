#include "../hppFiles/Street.hpp"
#include "../hppFiles/Player.hpp"

// Street constructor initializes all relevant street properties, such as rent values and group color.
Street::Street(const std::string& name, int price, const std::string& colorGroup, 
               int baseRent, int housePrice, int rentWithHouse, int rentWithHotel, int position)
    : Slot(name, price, position), 
      colorGroup(colorGroup), 
      baseRent(baseRent), 
      housePrice(housePrice), 
      rentWithHouse(rentWithHouse), 
      rentWithHotel(rentWithHotel), 
      houses(0), 
      hasHotel(false) {}

// Action when a player lands on a street: pay rent or buy property.
void Street::action(std::shared_ptr<Player> player) {
    auto slotOwner = owner.lock();  // Convert weak_ptr to shared_ptr to safely access the owner.
    
    if (slotOwner && slotOwner != player) {
        int rent = calculateRent();
        std::cout << player->name << " pays rent of $" << rent << " to " << slotOwner->name << "." << std::endl;
        player->payRent(rent);
        slotOwner->addMoney(rent);
    } else if (!slotOwner) {
        std::cout << player->name << " landed on an unowned street: " << name 
                  << ". Would you like to buy it for $" << price << "?" << std::endl;
    }
}

// Rent is calculated based on houses/hotel.
int Street::calculateRent() const {
    if (hasHotel) return rentWithHotel;
    if (houses > 0) return rentWithHouse * houses;
    return baseRent;
}

// Builds a house or upgrades to a hotel following the game's rules.
void Street::buildHouse() {
    if (houses < 4) {
        houses++;
        std::cout << "Built house #" << houses << " on " << name << "." << std::endl;
    } else if (!hasHotel) {
        hasHotel = true;
        std::cout << "Upgraded " << name << " to a hotel!" << std::endl;
    } else {
        std::cout << name << " already has a hotel!" << std::endl;
    }
}

// Displays street-specific information like rent, houses, and hotel status.
void Street::displayInfo() const {
    std::cout << "Street: " << name << " (" << colorGroup << "), Rent: " << baseRent 
              << ", Houses: " << houses << ", Hotel: " << (hasHotel ? "Yes" : "No") << std::endl;
}

bool Street::canBuildHouse() const {
    return (houses < 4 && !hasHotel);  // Houses must be less than 4, and no hotel should exist
}

// void Street::buildHouse() {
//     if (houses < 4) {
//         houses++;
//         std::cout << "Built house #" << houses << " on " << name << "." << std::endl;
//     } else if (!hasHotel) {
//         hasHotel = true;
//         std::cout << "Upgraded " << name << " to a hotel!" << std::endl;
//     }
// }
