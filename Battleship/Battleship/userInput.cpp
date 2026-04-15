#include <iostream>
#include <string>
#include <fstream>
#include "Base.h"
#include "userInput.h"
#include "fileIOSystem.h"

/******************************************************************************
 * File: userInput.cpp
 * Project: CSCN71030 Team Project - Battleship
 * Author: Vincent Kacperski
 * Date: April 2026
 * Description:
 * Implements the userInput module used by the Battleship game.
 ******************************************************************************/

//References
//https://www.w3schools.com/cpp/ref_fstream_fstream.asp

//Declarations
namespace data {
	//Decleration
	int selections = 0;
	int players = -1;
	int age = 0;
	std::string nickname;
	std::string username;
}

//Get essential data from the user
void userInput(GameData* gamedata, UserData* users) {

	system("cls");

	while (data::players < 2 || data::players > 4) {
		std::cout << "Number of players: ";
		std::cin >> data::players;
		if (data::players > 4 || data::players < 2) {
			std::cout << "Player count is invalid! Only 2-4 players allowed.\n";
		}
		gamedata->storePlayers(data::players);
	}
	gameSaveUI(gamedata);

	for (int i = 0; i < gamedata->getPlayers(); i++) {

		std::cout << "Player " << i + 1 << "\n";
		gatherNickname(&users[i]);
		gatherUsername(&users[i]);
		gatherAge(&users[i]);
		savePlayer(i, &users[i], gamedata);

		system("cls");
	}

}

//The three function bellow gather essential user data
void gatherNickname(UserData* user) {
	//Get the users nickname
	std::cout << "Enter a nickname: ";
	std::cin >> data::nickname;
	user->storeNickname(data::nickname);
}

void gatherUsername(UserData* user) {
	//Get the users username
	std::cout << "Enter a username: ";
	std::cin >> data::username;
	user->storeUsername(data::username);
}

void gatherAge(UserData* user) {
	//Get the users username
	std::cout << "Enter your age: ";
	std::cin >> data::age;
	user->storeAge(data::age);
}