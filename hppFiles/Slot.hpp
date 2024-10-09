#ifndef SLOT_HPP
#define SLOT_HPP

#include <iostream>
#include <string>
#include <memory>

// Forward declaration to prevent cyclic dependencies
class Player;

// Base class for all board slots. Each slot (like a property, railroad, or special slot) will inherit from this.
class Slot {
public:
    std::string name;    // Slot name, e.g., "Boardwalk"
    int price;           // Price to buy the slot, 0 if it's not purchasable
    int position;        // Board position from 0 to 39
    std::weak_ptr<Player> owner;  // Owner of the slot, using weak_ptr to avoid cyclic references

    // Constructor initializes basic slot details
    Slot(const std::string& name, int price, int position);
    virtual ~Slot() = default;

    // Every slot has a specific action when a player lands on it
    virtual void action(std::shared_ptr<Player> player) = 0;

    // Utility method to check if the slot is currently owned
    bool isOwned() const;

    // Display the slot details in a readable format
    virtual void displayInfo() const;
};

#endif // SLOT_HPP
