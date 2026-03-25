#include <iostream>
#include <string>
#include <fstream>
#include "Base.h"
#include "gatherGameData.h"
#include "fileIOSystem.h"

/******************************************************************************
 * File: gatherGameData.cpp
 * Project: CSCN71030 Team Project - Battleship
 * Author: Vincent Kacperski
 * Date: March 2026
 * Description:
 * Implements the board display functions used by the Battleship game.
 ******************************************************************************/

//Refrences
//

//Add your code here

namespace gameData {

	int mapSize = 0;
	int shipCount = 0;
	char abilities[5] = {'A', 'B', 'C', 'S', 'D'};
	User userdata;
	Game gamedata;

}

int gatherGameData(int players, GameData* gamedata, UserData* users) {

	//Get the games map size
	while (gameData::gamedata.mapSize != 400 && gameData::gamedata.mapSize != 100) {
		std::cout << "What map size do you prefer? (area): ";
		std::cin >> gameData::mapSize;
		gameData::gamedata.mapSize = gameData::mapSize;
	}
	gameSaveGD(gamedata);

	for (int i = 1; i <= players; i++) {

		//Indicate the next player
		std::cout << "Player " << i << "\n";
		 
		if (players == 1) {
			gatherShipCount(&users[players]);
			gatherAbilities(&users[players]);
			//playerSaveGD(players, users);

		}
		else if (players == 2) {
			gatherShipCount(&users[players]);
			gatherAbilities(&users[players]);
			//playerSaveGD(players, users);

		}
		else if (players == 3) {
			gatherShipCount(&users[players]);
			gatherAbilities(&users[players]);
			//playerSaveGD(players, users);

		}
		else {
			gatherShipCount(&users[players]);
			gatherAbilities(&users[players]);
			//playerSaveGD(players, users);

		}
	}
	return 0;
}

//The two functions bellow gather essential user data
void gatherShipCount(UserData* user) {

	//Number of ships for each player
	std::cout << "How many ships would you like to deploy?\n";
	std::cout << "Enter 0, default, all ships: ";
	std::cin >> gameData::shipCount;
	if (gameData::shipCount == 0) {
		//Defaut to starting with 5 ships
		gameData::shipCount = 5;
	} else {
		//Store the data
		gameData::userdata.shipCount = gameData::shipCount;
		std::cout << "Collected player ship count\n";
	}
}

void gatherAbilities(UserData* user) {

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
		std::cin >> gameData::gamedata.abilities[i];
	}

}