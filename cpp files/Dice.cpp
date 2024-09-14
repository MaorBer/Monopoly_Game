#include "Dice.hpp"

std::pair<int, int> Dice::roll() {
    return {1 + rand() % 6, 1 + rand() % 6};
}
