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

/* ship({{1,1}, {1,2}, {1,3}});

if (ship.shoot(1, 2)) {
    std::cout << "Hit!\n";
}
else {
    std::cout << "Miss!\n";
}

if (ship.isSunk()) {
    std::cout << "Ship sunk!\n";
}
else {
    std::cout << "Ship still afloat.\n";
}

return 0;
} This is the way we will need to implement it into the function that uses this, will work on that later*/