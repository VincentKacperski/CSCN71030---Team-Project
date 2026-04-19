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
int gatherGameData(int players, GameData* gamedata, UserData* users) {

	//Test Code =----------------------------=
	try {
		//Try using stoi
		gameData::mapSize = std::stoi("20");
	}
	catch (const std::invalid_argument& e) {
		std::cout << "No strings or characters allowed. Integers only!\n";
	}
	gamedata->storeMapSize(gameData::mapSize);
	return gamedata->getMapSize();
	//=--------------------------------------=

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
int gatherShipCount(UserData* user) {

	//Test Code =----------------------------=
	try {
		//Try using stoi
		gameData::shipCount = std::stoi("0uuiewv");
	
	}
	catch (const std::invalid_argument& e) {
		std::cout << "No strings or characters allowed. Integers only!\n";
		return -1;
	}
	if (gameData::shipCount == 0) {
		gameData::shipCount = 5;
		user->storeShipCount(gameData::shipCount);
		return user->getShipCount();
	}
	user->storeShipCount(gameData::mapSize);
	return 0;
	//=--------------------------------------=

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
		}
		else if (gameData::shipCount == 0) {
			std::cout << "No ships?! Its going to be tough. Carefull there!\n";
			std::cout << "Lucky for you. I brought in some reinforcments!\n"; \
				gameData::shipCount = 5;

		} else {
			user->storeShipCount(gameData::shipCount);
		}

	} catch (const std::invalid_argument& e) {
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
int gatherAbilities(UserData* user) {

	//Number of ships for each player

	//Test Code =------------------------=
	int choice = -2;
	try {
		//Try using stoi
		choice = std::stoi("%-2390^GV)@");
		//Check for a valid map size
		if (choice > gameData::shipCount) {
			std::cout << "To many abilities selected! Greater than maximum ship deployment!\n";
			return -1;
		} else if (choice <= 0) {
			std::cout << "You cannot have negative abilities since they don't exist!\n";
			return -2;
		}
	}
	catch (const std::invalid_argument& e) {
		std::cout << "No strings or characters allowed. Integers only!\n";
		return -3;
	}
	//=----------------------------------=

	while (choice <= 0 || choice > 5) {

		//User input for ability count
		std::cout << "Would you like to upgrade some ships?\n";
		std::cout << "Ability quantity: ";
		std::cin >> gameData::buffer;

		//Invalidate string and character inputs
		try {
			//Try using stoi
			choice = std::stoi(gameData::buffer);
			//Check for a valid map size
			if (choice > gameData::shipCount) {
				std::cout << "To many abilities selected! Greater than maximum ship deployment!\n";
			} else if (choice <= 0) {
				std::cout << "You cannot have negative abilities since they don't exist!\n";
			} else {
				user->storeShipCount(gameData::shipCount);
			}

		}
		catch (const std::invalid_argument& e) {
			std::cout << "No strings or characters allowed. Integers only!\n";
		}

	}

	//Loop for reading in abilities
	for (int i = 1; i <= choice; i++) {

		//Decleration
		int holder = 0;

		//Clear all abilities for next input
		gameData::abilities[0] = '0'; gameData::abilities[1] = '0'; 
		gameData::abilities[2] = '0'; gameData::abilities[3] = '0';  
		gameData::abilities[4] = '0';

		//Game data ability selection
		std::cout << "Select an ability " << i << " (1:A, 2:B, 3:C, 4:S, 5:D)\n";
		std::cout << "Enter a choice from (1-5): ";
		std::cin >> gameData::buffer;

		//Invalidate string and character inputs
		try {
			//Try using stoi
			holder = std::stoi(gameData::buffer);
			//Check for a valid map size
			if (holder == 1) {
				gameData::abilities[i] = (char)holder + 100; //Converts from ASCII
				std::cout << "Aircraft Carrier modification made!\n";
			} else if (holder == 2) {
				gameData::abilities[i] = (char)holder + 100; //Converts from ASCII	
				std::cout << "Battleship modification made!\n";
			} else if (holder == 3) {
				gameData::abilities[i] = (char)holder + 100; //Converts from ASCII	
				std::cout << "Curiser modification made!\n";
			} else if (holder == 4) {
				gameData::abilities[i] = (char)holder + 119; //Converts from ASCII	
				std::cout << "Submarine modification made!\n";
			} else if (holder == 5) {
				gameData::abilities[i] = (char)holder + 100; //Converts from ASCII	
				std::cout << "Destroyer modification made!\n";
			} else {
				//Continue
			}

		} catch (const std::invalid_argument& e) {
			std::cout << "No strings or characters allowed. Integers only!\n";
		}

	}
	user->storeAbilities(gameData::abilities);
}