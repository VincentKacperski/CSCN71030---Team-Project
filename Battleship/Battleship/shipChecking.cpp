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
void placeShips(int x, int y, int orientation, int size) {
    if (x >= 0 && x < 10 && y >= 0 && y < 10) {
        for (int length = 0; length < size; length++) {
            if (orientation == 2) {
                shipMap[x + length][y] = true;
            }
            if (orientation == 1) {
                shipMap[x][y + length] = true;
            }
		}
        
    }
}
void checkHit(int x, int y) {
    if (x >= 0 && x < 10 && y >= 0 && y < 10) {
        shotMap[x][y] = true;
    if (shipMap[x][y] == true) {
            setResult(true);
        } else {
		    setResult(false);
	}
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
