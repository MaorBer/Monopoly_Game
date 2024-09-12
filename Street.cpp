#include "slot.cpp"



class Street : public Slot {
public:
    std::string colorGroup;
    int rent;
    int housePrice;
    int rentWithHouse;
    int rentWithHotel;
    int houses;
    bool hasHotel;

    Street(const std::string& name, int price, const std::string& colorGroup, int rent, int housePrice, int rentWithHouse, int rentWithHotel)
        : Slot(name, price), colorGroup(colorGroup), rent(rent), housePrice(housePrice),
          rentWithHouse(rentWithHouse), rentWithHotel(rentWithHotel), houses(0), hasHotel(false) {}

    void buildHouse(); // Adds a house
    int calculateRent() const; // Calculates rent based on the number of houses/hotel

    void action(std::shared_ptr<Player> player) override; // Implement player action on this slot
};