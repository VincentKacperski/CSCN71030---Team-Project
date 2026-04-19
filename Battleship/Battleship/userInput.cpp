#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>
#include <exception>
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
	int players = 0;
	int age = 0;
	std::string buffer;
	std::string nickname;
	std::string username;
}

//Get essential data from the user
void userInput(GameData* gamedata, UserData* users) {

	system("cls");

	while (data::players < 2 || data::players > 4) {

		//Player # input
		std::cout << "Number of players: ";
		std::cin >> data::buffer;
		//Invalidate character input
		try {

			//Try using stoi
			data::players = std::stoi(data::buffer);
			//Cast string with number to valid inputs
			if (std::stoi(data::buffer) < 2 || std::stoi(data::buffer) > 4) {
				std::cout << "Invalid player count!\n";
			} else {
				gamedata->storePlayers(data::players);
			}

		} catch (const std::invalid_argument& e) {
			std::cout << "No strings or characters allowed. Integers only!\n";
		}
	
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