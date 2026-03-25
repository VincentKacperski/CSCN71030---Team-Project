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
 * Date: March 2026
 * Description:
 * Implements the board display functions used by the Battleship game.
 ******************************************************************************/

 //Refrences
 //

namespace data {
	//Decleration
	int selections = 0;
	int players = 0;
	int age = 0;
	std::string nickname;
	std::string username;
}

int userInput(GameData* gamedata, UserData* users) {

	for (int i = 1; i <= data::players; i++) {

		while (data::players <= 0 || data::players > 4) {
			std::cout << "Number of players: ";
			std::cin >> data::players;
			gamedata->storePlayers(data::players);
		}
		gameSaveUI(gamedata);

		if (data::players == 1) {
			gatherNickname(&users[0]);
			gatherUsername(&users[0]);
			gatherAge(&users[0]);
			savePlayer(data::players, &users[0]);

		} else if (data::players == 2) {
			gatherNickname(&users[1]);
			gatherUsername(&users[1]);
			gatherAge(&users[1]);
			savePlayer(data::players, &users[1]);

		} else if (data::players == 3) {
			gatherNickname(&users[2]);
			gatherUsername(&users[2]);
			gatherAge(&users[2]);
			savePlayer(data::players, &users[2]);

		} else {
			gatherNickname(&users[3]);
			gatherUsername(&users[3]);
			gatherAge(&users[3]);
			savePlayer(data::players, &users[3]);

		}
	}

	//Procced to the next input module
	int players = data::players;
	return players;

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