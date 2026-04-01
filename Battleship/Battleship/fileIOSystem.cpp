#include <iostream>
#include <fstream>
#include <string>
#include "fileIOSystem.h"
#include "userInput.h"
#include "Base.h"

//Add your code here

//std::fstream filePtr;

int fileOpen(){
	std::fstream file("gamedata.txt");

	if (!file.is_open()) {
		std::cout << "Error in opening the file!\n";
	}

	GameData gameData;
	UserData playerData;

	std::string pCount, nickname, username, age, size, map;
	int realSize, realAge, realpCount;
	if (file.is_open()) {
		std::getline(file, nickname);
		std::getline(file, username);
		std::getline(file, age);
		std::getline(file, pCount);
		std::getline(file, size);
		realSize = stoi(size);
		realAge = stoi(age);
		realpCount = stoi(pCount);

		gameData.storeMapSize(realSize);
		gameData.storePlayers(realpCount);

		playerData.storeAge(realAge);
		playerData.storeUsername(username);
		playerData.storeNickname(nickname);

		for (int i = 0;i < realSize; i++) {
			std::getline(file, map);
		}
	}
	file.close();

	int i = 0;
	std::string s[] = {"playerone.txt", "playertwo.txt", "playerthree.txt", "playerfour.txt"};
	for (int i = 0; i < gameData.getPlayers(); i++) {
		std::fstream file(s[i]);
		
		if(!file){

		}


	}
	return 0;
}

int savePlayer(int players) {

	std::fstream filePtr;
	User userdata;

	if (players == 1) {
		if (filePtr.is_open()) {

			filePtr.open("playerone.txt");
			filePtr << userdata.nickname;
			filePtr << userdata.username;
			filePtr << userdata.age;
			filePtr.close();
		}
	}
	else {
		if (players == 2) {
			if (filePtr.is_open()) {

				filePtr.open("playertwo.txt");
				filePtr << userdata.nickname;
				filePtr << userdata.username;
				filePtr << userdata.age;
				filePtr.close();
			}
		}
		else {
			if (players == 3) {
				if (filePtr.is_open()) {

					filePtr.open("playerthree.txt");
					filePtr << userdata.nickname;
					filePtr << userdata.username;
					filePtr << userdata.age;
					filePtr.close();
				}
			}
			else {
				if (players == 4) {
					if (filePtr.is_open()) {

						filePtr.open("playerfour.txt");
						filePtr << userdata.nickname;
						filePtr << userdata.username;
						filePtr << userdata.age;
						filePtr.close();
					}
				}
				else {
					//std::cout << "Error";
				}
			}
		}
	}
	return 0;
}

//class Ship {
//
//};
//class Board {
//
//};

//void useAbility5(Ship& ship, Board& board) {
//	int newX, newY;
//	
//	while (true) {
//		std::cout << "Enter new position (x y) ";
//		std::cin >> newX >> newY;
//
//		if (!board.isValidPosition(newX, newY)) {
//			std::cout << "Invalid location: Out of Bounds\n";
//			continue;
//		}
//
//		if (board.isTargeted(newX, newY)) {
//			std::cout << "Invalid location: This position has already been targeted\n";
//			continue;
//		}
//		break;
//	}
//
//	ship.x = newX;
//	ship.y = newY;
//	ship.abilityUsed = true;
//
//	detectMovement(ship);
//	std::cout << "Ability used and the ship has been moved!\n";
//}