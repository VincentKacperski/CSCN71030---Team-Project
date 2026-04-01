#include <iostream>
#include <fstream>
#include <string>
#include "fileIOSystem.h"
#include "userInput.h"
#include "Base.h"

//Add your code here

//std::fstream filePtr;

int fileOpen() {
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

int savePlayer(int players, UserData* users) {

	std::fstream filePtr;
	//User userdata;

	if (players == 1) {
		if (filePtr.is_open()) {

			filePtr.open("playerone.txt");
			filePtr << users[0].getNickname();
			filePtr << users[0].getUsername();
			filePtr << users[0].getAge();
			filePtr.close();
		}
	}
	else {
		if (players == 2) {
			if (filePtr.is_open()) {

				filePtr.open("playertwo.txt");
				filePtr << users[1].getNickname();
				filePtr << users[1].getUsername();
				filePtr << users[1].getAge();
				filePtr.close();
			}
		}
		else {
			if (players == 3) {
				if (filePtr.is_open()) {

					filePtr.open("playerthree.txt");
					filePtr << users[2].getNickname();
					filePtr << users[2].getUsername();
					filePtr << users[2].getAge();
					filePtr.close();
				}
			}
			else {
				if (players == 4) {
					if (filePtr.is_open()) {

						filePtr.open("playerfour.txt");
						filePtr << users[3].getNickname();
						filePtr << users[3].getUsername();
						filePtr << users[3].getAge();
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

//Save game data from the userInput module
void gameSaveUI(GameData* game) {

	//Decleration
	std::fstream fileptr;

	//Store game data player count to the game data file
	fileptr.open("gamedata.txt");
	fileptr << game->getPlayers();
	fileptr.close(); //Close the file

}

//Save game data from gatherGameData module
void gameSaveGD(GameData* game) {

	//Decleration
	std::fstream fileptr;

	//Store game data player count to the game data file
	fileptr.open("Playerone.txt");
	fileptr << game->getPlayers();
	fileptr.close(); //Close the file

}



