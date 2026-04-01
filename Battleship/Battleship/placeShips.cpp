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
		int amountSelected = 0;


	public:

	
	void displayShips(Ship fleet[]) {
		for (int i = 0; i < 5; i++) {
			printf("%d. %s (Size: %d) - %s\n",
				i + 1,
				fleet[i].name,
				fleet[i].size,
				fleet[i].ability);
		}
	}

	void chooseShips() {
		int choice;
		int selected[shipCount];
		while (amountSelected < 5) {
			displayShips(fleet);

			printf("\nChoose a ship (1-5): ");
			scanf_s("%d", &choice);

			// Adjust for array index
			choice--;

			if (choice >= 0 && choice < shipCount) {
				selected[amountSelected] = fleet[choice];
				amountSelected++;

				printf("You selected: %s\n\n", fleet[choice].name);
			}
			else {
				printf("Invalid choice. Try again.\n\n");
			}
		}
		int alreadyChosen = 0;

		for (int i = 0; i < amountSelected; i++) {
			if (strcmp(selected[i].name, fleet[choice].name) == 0) {
				alreadyChosen = 1;
				break;
			}
		}

		if (alreadyChosen) {
			printf("You already chose that ship!\n\n");
		}
		else {
			selected[amountSelected] = fleet[choice];
			amountSelected++;
		}
	}
	void placedShip(int x, int y, char orientation) {
		std::cout << "Placing ship at (" << x << ", " << y << ") with orientation " << orientation << "..." << std::endl;
	}
	

	void placeShip() {
		std::cout << "Enter ship placement coordinates in numbers ex. 7,2 (x y) and orientation (h for horizontal, v for vertical): ";
		std::cin >> x >> y >> orientation;
		placedShip(x, y, orientation);
		}
};