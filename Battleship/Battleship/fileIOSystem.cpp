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

void savePlayer(int players, UserData* users, GameData* data) {

	//std::fstream filePtr;
	//User userdata;
	std::string s[] = { "playerone.txt", "playertwo.txt", "playerthree.txt", "playerfour.txt" };

	for (int i = 0; i < data->getPlayers(); i++) {
		std::fstream filePtr(s[i]);

		if (filePtr.is_open()) {
			filePtr << users[0].getNickname();
			filePtr << users[0].getUsername();
			filePtr << users[0].getAge();
			for (const auto& row : users->getOwnBoard()) {
				std::copy(row.begin(), row.end(), std::ostream_iterator<char>(filePtr, " "));
				//filePtr << users->getOwnBoard();
			}
			for (const auto& row : users->getTrackingBoard()) {
				std::copy(row.begin(), row.end(), std::ostream_iterator<char>(filePtr, " "));
				//filePtr << users->getTrackingBoard();
			}
			filePtr.close();
		}
	}
}

void loadPlayer(int players, UserData* users, GameData* data) {
	std::string s[] = { "playerone.txt", "playertwo.txt", "playerthree.txt", "playerfour.txt" };

	for (int i = 0; i < data->getPlayers(); i++) {
		std::fstream filePtr(s[i]);
		std::vector<std::vector<char>> tempBoard;
		std::string tempString;
		int tempInt;
		int count = 0;

		if (filePtr.is_open()) {
			std::getline(filePtr, tempString);
			users[i].storeNickname(tempString);
			std::getline(filePtr, tempString);
			users[i].storeUsername(tempString);
			std::getline(filePtr, tempString);
			tempInt = stoi(tempString);
			users[i].storeAge(tempInt);
			while (count++ < data->getMapSize() && std::getline(filePtr, tempString)) {
				tempBoard.push_back(std::vector<char>(tempString.begin(), tempString.end()));
			}
			users->storeOwnBoard(tempBoard);
			count = 0;
			while (count++ < data->getMapSize() && std::getline(filePtr, tempString)) {
				tempBoard.push_back(std::vector<char>(tempString.begin(), tempString.end()));
			}
			users->storeTrackingBoard(tempBoard);
			filePtr.close();
		}
	}
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



