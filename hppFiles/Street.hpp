#ifndef STREET_HPP
#define STREET_HPP

#include "Slot.hpp"

// Street slots represent properties that players can buy, build houses/hotels on, and collect rent from.
class Street : public Slot, public std::enable_shared_from_this<Street> {
public:
    std::string colorGroup;  // Color group (e.g., "Red") for monopoly rules
    int baseRent;            // Rent without any houses/hotel
    int housePrice;          // Price to build a house on this street
    int rentWithHouse;       // Rent with houses
    int rentWithHotel;       // Rent with a hotel
    int houses;              // Number of houses built on this street
    bool hasHotel;           // Whether this street has a hotel built

    // Constructor initializes the street's properties and sets the initial state.
    Street(const std::string& name, int price, const std::string& colorGroup, 
           int baseRent, int housePrice, int rentWithHouse, int rentWithHotel, int position);

    // Handles what happens when a player lands on this street.
    void action(std::shared_ptr<Player> player) override;

    // Calculate rent based on houses/hotel.
    int calculateRent() const;

    // Method to build a house or upgrade to a hotel, following Monopoly rules.
    void buildHouse();

    // Display street-specific details (e.g., rent, houses).
    void displayInfo() const override;

    bool canBuildHouse() const;
};

#endif // STREET_HPP
