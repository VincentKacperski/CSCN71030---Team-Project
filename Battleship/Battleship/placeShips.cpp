#include <iostream>
#include "placeShips.h"




Ship fleet[5] = {
	{"Cruiser", 3, false},
	{"Battleship", 4, false},
	{"Submarine", 3, false},
	{"Destroyer", 2, false},
	{"Carrier", 5, false}
};
int ships[5];


void displayShips(Ship fleet[]) {
	for (int i = 0; i < 5; i++) {
		std::cout << "" << fleet[i + 1].name << "Size: " << fleet[i + 1].size << "\n";
	}
}

void chooseShips(GameData* data, UserData* user) {
	//Declaration
	int amountSelected = 0;
	int choice;
	int shipCount = 5;
	//std::vector<std::string> selected(shipCount);
	int amount = 0;
	
	while (amountSelected < shipCount) {
		choice = 0;
		// Select Ship
		std::cout << "\nChoose a ship (1-5): ";
		std::cin >> choice;;

		// Adjust for array index
		choice--;

		// 
		if (choice >= 0 && choice < 5) {

			std::cout <<  "You selected: " << fleet[choice].name << "  \n\n";
			// Checks if ship is already chosen
			if (fleet[choice].chosen == true) {
				std::cout << "You already chose that ship!\n\n";
			}
			else {

				placeShip(choice);
				fleet[choice].chosen = true;
				amountSelected++;
			}
		}
		else {
			std::cout << "Invalid choice. Try again.\n\n";
		}
	}
}
void placedShip(int x, int y, char orientation) {
	std::cout << "Placing ship at (" << x << ", " << y << ") with orientation " << orientation << "..." << std::endl;
}
	

void placeShip(int choice) {
	int x;
	int y;
	int orientation;
	std::cout << "Enter ship placement coordinate x: ";
	std::cin >> x; 
	std::cout << "Enter ship placement coordinate y: ";
	std::cin >> y;
	std::cout << "orientation (1 for horizontal, 2 for vertical):";
	std::cin >> orientation;
	placeShips(x, y, orientation, fleet[choice].size);
	placedShip(x, y, orientation);
}
