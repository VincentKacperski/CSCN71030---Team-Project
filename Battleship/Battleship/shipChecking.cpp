#include <iostream>
#include <vector>
#include <utility>
#include "shipChecking.h"


//Add your code here



bool shipMap[boardSize][boardSize];
bool shotMap[boardSize][boardSize];


void ShipChecking() {
    // Initialize shipMap and shotMap to false
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            shipMap[i][j] = false;
            shotMap[i][j] = false;
        }
    }
}
void placeShip(int x, int y) {
    if (x >= 0 && x < 10 && y >= 0 && y < 10) {
        shipMap[x][y] = true;
    }
}
void checkHit(int x, int y) {
    if (x >= 0 && x < 10 && y >= 0 && y < 10) {
        shotMap[x][y] = true;
    }
}
    /*  void displayMaps() {

            std::cout << "Shot Map:\n";
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    std::cout << (shotMap[i][j] ? "X " : ". ");
                }
                std::cout << "\n";
            }
        }
    }; */
