#include <iostream>
#include <string>
#include <fstream>
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

	//Default setter functions
	void storeMapSize(int m) { //Store player count
		mapSize = m;
	}
	void storeShipCount(int s) { //Store nickname
		shipCount = s;
	}

	//Default getter functions
	int getMapSize() { //Store player count
		return mapSize;
	}

	int getShipCount() { //Store nickname
		return shipCount;
	}

};

struct User {
	
	int mapSize = 0;
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
	while (gameData::data.mapSize != 400 && gameData::data.mapSize != 100) {
		std::cout << "What map size do you prefer? (area): ";
		std::cin >> gameData::mapsize;
		gameData::data.mapSize = gameData::mapsize;
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
			testSave(players);
		} else {
			//Store the data
			gameData::data.shipCount = gameData::shipCount;
			testSave(players);
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
			testSave(players);
		}

	}

	return 0;

}

int testSave(int players) {

	//Decleration
	std::fstream fileptr;

	//Opening and using files
	if (players == 1) {
		if (fileptr.is_open()) {

			//Open player ones file and save game data
			fileptr.open("Playerone.txt");
			fileptr << gameData::data.shipCount;
			fileptr << gameData::data.abilities;
			fileptr.close(); //Close the file

		}
		else {
			//Do nothing for now
		}
	} else {
		if (players == 2) {

			if (fileptr.is_open()) {

				//Open player ones file and save game data
				fileptr.open("Playertwo.txt");
				fileptr << gameData::data.shipCount;
				fileptr << gameData::data.abilities;
				fileptr.close(); //Close the file

			} else {
				//Do nothing for now
			}
		}
		else {
			if (players == 3) {
				if (fileptr.is_open()) {

					//Open player ones file and save game data
					fileptr.open("Playerthree.txt");
					fileptr << gameData::data.shipCount;
					fileptr << gameData::data.abilities;
					fileptr.close(); //Close the file

				} else {
					//Do nothing for now
				}
			}
			else {
				if (players == 4) {
					if (fileptr.is_open()) {

						//Open player ones file and save game data
						fileptr.open("Playerfour.txt");
						fileptr << gameData::data.shipCount;
						fileptr << gameData::data.abilities;
						fileptr.close(); //Close the file

					} else {
						//Do nothing for now
					}
				}
				else {
					//Do nothing for now
				}
			}
		}
	}
	return 0;
}