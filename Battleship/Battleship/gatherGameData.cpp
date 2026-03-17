#include <iostream>
#include "gatherGameData.h"

//Add your code here

class GameData {
private:

	int mapSize;
	int shipCount;
	char abilities[5] = "";

public:

	//Default constructor
	GameData() {}

	//Build Constructor
	GameData(int m, int s) {
		mapSize = m;
		shipCount = s;
	}

};

struct User {
	
	int mapsize = 0;
	int shipCount = 0;
	char abilities[5] = "";

};

namespace gameData {

	int mapsize = 100;
	int shipCount = 0;
	char abilities[5] = {'A', 'B', 'C', 'S', 'D'};
	User data;

}

int gatherGameData(int players) {

	//Get the games map size
	while (gameData::data.mapsize != 400 && gameData::data.mapsize != 100) {
		std::cout << "What map size do you prefer? (area): ";
		std::cin >> gameData::mapsize;
		gameData::data.mapsize = gameData::mapsize;
	}

	for (int i = 1; i <= players; i++) {

		//Indicate the next player
		std::cout << "Player " << i << "\n";

		//Number of ships for each player
		std::cout << "How many ships would you like to deploy?\n";
		std::cout << "Enter 0, default, all ships: ";
		std::cin >> gameData::shipCount;
		if (gameData::shipCount == 0) {
			//Defaut to starting with 5 ships
			gameData::shipCount = 5;
		} else {
			//Store the data
			gameData::data.shipCount = gameData::shipCount;
		}
		 
		//Number of ships for each player
		int choice = -1;
		while (choice <= 0 || choice > 5) {
			std::cout << "How many abilities would you like?\n";
			std::cout << "Quantity: ";
			std::cin >> choice;
			if (choice <= 0 && choice > 5) {
				std::cout << "You can only select 1-5 abilities!\n";
			}
		}

		for (int i = 1; i <= choice; i++) {
			std::cout << "Ability " << i << " (A B C S D): ";
			std::cin >> gameData::data.abilities[i];
		}

	}

	return 0;

}