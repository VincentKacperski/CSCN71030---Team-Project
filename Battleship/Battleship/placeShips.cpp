#include <iostream>
#include "placeShips.h"

//Add your code here


int x;
int y;
int orientation;
Ship fleet[5] = {
	{"Cruiser", 3, false},
	{"Battleship", 4, false},
	{"Submarine", 3, false},
	{"Destroyer", 2, false},
	{"Carrier", 5, false}
};
int ships[5];
int amountSelected = 0;

void displayShips(Ship fleet[]) {
	for (int i = 0; i < 5; i++) {
		printf("%d. %s (Size: %d) - %s\n",
			i + 1,
			fleet[i].name,
			fleet[i].size);
	}
}

void chooseShips(GameData* data, UserData* user) {
	
	//Declaration
	int choice;
	int shipCount = user->getShipCount();
	//std::vector<std::string> selected(shipCount);
	int amount = 0;
	
	while (amountSelected < shipCount) {

		// Select Ship
		printf("\nChoose a ship (1-5): ");
		scanf_s("%d", &choice);

		// Adjust for array index
		choice--;

		// 
		if (choice >= 0 && choice < 5) {

			printf("You selected: %s\n\n", fleet[choice].name);
			// Checks if ship is already chosen
			if (fleet[choice].chosen = true) {
				printf("You already chose that ship!\n\n");
			}
			else {

				placeShip(choice);
				fleet[choice].chosen = true;
				amountSelected++;
			}
		}
		else {
			printf("Invalid choice. Try again.\n\n");
		}
	}
}
void placedShip(int x, int y, char orientation) {
	std::cout << "Placing ship at (" << x << ", " << y << ") with orientation " << orientation << "..." << std::endl;
}
	

void placeShip(int choice) {
	std::cout << "Enter ship placement coordinates in numbers ex. 7,2 (x y)";
	std::cin >> x >> y;
	std::cout << "orientation (1 for horizontal, 2 for vertical):";
	std::cin >> orientation;
	placeShips(x, y, orientation, fleet[choice].size);
	placedShip(x, y, orientation);
}
