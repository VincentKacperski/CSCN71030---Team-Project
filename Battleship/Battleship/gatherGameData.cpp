#include <iostream>
#include "gatherGameData.h"

//Add your code here

struct User {
	
	int mapsize = 0;
	int shipCount = 0;
	char* abilities[5];

};

namespace gameData {

	int mapsize = 100;
	int shipCount = 0;
	char abilities[5] = {'A', 'B', 'C', 'S', 'D'};
	User data;

}

int gatherGameData(int players) {

	//Get the games map size
	while (gameData::data.mapsize != 400 && gameData::data.mapsize != 100) {
		std::cout << "What map size do you prefer? (area): ";
		std::cin >> gameData::mapsize;
		gameData::data.mapsize = gameData::mapsize;
	}

	return 0;

}