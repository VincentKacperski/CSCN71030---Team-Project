#include <iostream>
#include <vector>
#include <utility>
#include "shipChecking.h"


//Add your code here


#include <vector>
#include <utility>

class ShipChecking {
private:
    std::vector<std::pair<int, int>> positions; // ship coordinates
    std::vector<bool> hits; // tracks which positions are hit

public:
    // Constructor
    ShipChecking(const std::vector<std::pair<int, int>>& pos) {
        positions = pos;
        hits.resize(pos.size(), false);
    }

    // Check if shot hits the ship
    bool shoot(int row, int col) {
        for (size_t i = 0; i < positions.size(); i++) {
            if (positions[i].first == row && positions[i].second == col) {
                hits[i] = true;
                return true; // HIT
            }
        }
        return false; // MISS
    }

    // Check if ship is sunk
    bool isSunk() const {
        for (bool hit : hits) {
            if (!hit) return false;
        }
        return true;
    }
};