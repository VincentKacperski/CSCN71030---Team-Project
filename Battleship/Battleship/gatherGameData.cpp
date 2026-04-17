#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Base.h"
#include "helper.h"
#include "gatherGameData.h"
#include "fileIOSystem.h"

/*******************************************************************
 * File: gatherGameData.cpp
 * Project: CSCN71030 Team Project - Battleship
 * Author: Vincent Kacperski
 * Date: April 2026
 * Description:
 * Implements the gatherGameData module used by the Battleship game.
 *******************************************************************/

//Refrences
//https://www.w3schools.com/cpp/ref_fstream_fstream.asp

//Declaration
namespace gameData {

	int mapSize = 0;
	int shipCount = 0;
	char abilities[5] = {'A', 'B', 'C', 'S', 'D'};
	std::string buffer;

}

//Collects essential game data for the game to work correctly
void gatherGameData(int players, GameData* gamedata, UserData* users) {

	//Get the games map size
	while (gamedata->getMapSize() != 20 && gamedata->getMapSize() != 10) {
		
		//Get the games map size
		std::cout << "What map size do you prefer (10 or 20): ";
		std::cin >> gameData::buffer;

		//Invalidate string and character inputs
		try {
			//Try using stoi
			gameData::mapSize = std::stoi(gameData::buffer);
			//Check for a valid map size
			if (gameData::mapSize != 10 && gameData::mapSize != 20) {
				std::cout << "Invalid map size!\n";
			}
			else {
				gamedata->storeMapSize(gameData::mapSize);
			}

		}
		catch (const std::invalid_argument& e) {
			std::cout << "No strings or characters allowed. Integers only!\n";
		}

	}
	gameSaveGD(gamedata);

	for (int i = 0; i < gamedata->getPlayers(); i++) {

		//Indicate the next player
		std::cout << "Player " << i + 1 << "\n";	 
		gatherShipCount(&users[i]);
		gatherAbilities(&users[i]);
		users[i].storeOwnBoard(createBoard(10));
		users[i].storeTrackingBoard(createBoard(10));
		system("cls");
		//playerSaveGD(players, users);
	}
}

//The two functions bellow gather essential user data
void gatherShipCount(UserData* user) {

	//Number of ships for each player
	std::cout << "How many ships would you like to deploy?\n";
	std::cout << "Enter 0, default, all ships: ";
	std::cin >> gameData::buffer;

	//Invalidate string and character inputs
	try {
		//Try using stoi
		gameData::shipCount = std::stoi(gameData::buffer);
		//Check for a valid map size
		if (gameData::shipCount < 0 || gameData::shipCount > 5) {
			std::cout << "Invalid map size!\n";
		} else if (gameData::shipCount == 0) {
			std::cout << "No ships?! Its going to be tough. Carefull there!\n";
			std::cout << "Lucky for you. I brought in some reinforcments!\n";
		} else {
			user->storeShipCount(gameData::shipCount);
		}

	}
	catch (const std::invalid_argument& e) {
		std::cout << "No strings or characters allowed. Integers only!\n";
	}

	//Check for the defualt ship count
	if (gameData::shipCount == 0) {
		//Defaut to starting with 5 ships
		gameData::shipCount = 5;
		user->storeShipCount(5);
	} else {
		//Store the data
		user->storeShipCount(gameData::shipCount);
		std::cout << "Collected player ship count\n";
	}

}

//This function gathers each players abilities
void gatherAbilities(UserData* user) {

	//Number of ships for each player
	int choice = -1;
	while (choice <= 0 || choice > 5) {
		std::cout << "Would you like to upgrade some ships?\n";
		std::cout << "Ability quantity: ";
		std::cin >> choice;

		if (choice > user->getShipCount()) {
			std::cout << user->getShipCount();
			std::cout << "Ability count must match ship count!\n";
			choice = -1;
			continue;
		}

		if (choice <= 0) {
			std::cout << "You can only select 1-5 abilities!\n";
		}
	}

	for (int i = 1; i <= choice; i++) {
		std::cout << "Ability " << i << " (A B C S D): ";
		std::cin >> gameData::abilities[i];
	}

}