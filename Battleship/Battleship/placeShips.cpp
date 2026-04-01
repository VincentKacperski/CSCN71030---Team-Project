#include <iostream>
#include "placeShips.h"

//Add your code here

class PlaceShips {
	private:
		int x;
		int y;
		char orientation;
		int shipType;

	public:
	
	void placeShip(int x, int y, char orientation) {
		std::cout << "Placing ship at (" << x << ", " << y << ") with orientation " << orientation << "..." << std::endl;
	}

	void selectShipType() {
		std::cout << "Select ship type (1: Cruiser, 2: Battleship, 3: Submarine, 4: Destroyer, 5: Aircraft Carrier): ";
		//std::
	}
	void placeShip() {
		std::cout << "Enter ship placement coordinates in numbers ex. 7,2 (x y) and orientation (h for horizontal, v for vertical): ";
		std::cin >> x >> y >> orientation;
		placeShip(x, y, orientation);
	}
};