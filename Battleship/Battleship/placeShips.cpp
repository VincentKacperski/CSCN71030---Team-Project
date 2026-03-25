#include <iostream>
#include "placeShips.h"

//Add your code here

class PlaceShips {
	private:
		int x;
		int y;
		char orientation;
		typedef struct {
			char name[30];
			int size;
			char ability[100];
		} Ship;
		Ship fleet[5] = {
			{"Cruiser", 3, "Can move one space after being placed."},
			{"Battleship", 4, "Can attack twice per turn."},
			{"Submarine", 3, "Can submerge to avoid attacks for one turn."},
			{"Destroyer", 2, "Can detect nearby ships within a 1-space radius."},
			{"Aircraft Carrier", 5, "Can launch airstrikes to attack multiple spaces at once."}
		};
		int ships[5];
		int amountselected = 0;


	public:

	
	void displayShips(Ship fleet[], int size) {
		for (int i = 0; i < size; i++) {
			printf("%d. %s (Size: %d) - %s\n",
				i + 1,
				fleet[i].name,
				fleet[i].size,
				fleet[i].ability);
		}
	}
	void placeShip(int x, int y, char orientation) {
		std::cout << "Placing ship at (" << x << ", " << y << ") with orientation " << orientation << "..." << std::endl;
	}

	void selectShipType() {
		std::cout << "Select ship type (1: Cruiser, 2: Battleship, 3: Submarine, 4: Destroyer, 5: Aircraft Carrier): ";
		std::
			cin >> ships;
		std::cout << "You selected ship type " << ships << "." << std::endl;
	}

	void placeShip() {
		std::cout << "Enter ship placement coordinates in numbers ex. 7,2 (x y) and orientation (h for horizontal, v for vertical): ";
		std::cin >> x >> y >> orientation;
		placeShip(x, y, orientation);
		}
};