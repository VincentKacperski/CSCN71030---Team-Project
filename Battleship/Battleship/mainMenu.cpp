#include <iostream>
#include <string>
#include <time.h>
#include "mainMenu.h"
#include "userInput.h"
#include "fileIOSystem.h"
#include "gatherGameData.h"
#include "Base.h"
#include "win.h"
#include "placeShips.h"
#include <Windows.h>

//using namespace std; ?? What do we prefer here?
//Add your code here

int mainMenu(){
	bool runProgram = true;
	int userNum, randUser;

	//Vincent's Code

	//Create gamedata and player objects
	GameData* gamedata = new GameData;
	UserData userOne;
	UserData userTwo;
	UserData userThree;
	UserData userFour;
	UserData users[4] = { userOne, userTwo, userThree, userFour };
	int players = 1;
	bool playerWin = false;
	srand(time(NULL));

	while (runProgram) {
		std::cout << "Welcome to Battleship\n\n";
		std::cout << "1. Play\n";
		std::cout << "2. Help\n";
		std::cout << "3. Saves\n";
		std::cout << "4. End\n";
		std::cin >> userNum;

		switch (userNum) {
		case 1:
			userInput(gamedata, users);
			gatherGameData(players, gamedata, users);
			//placeShip();
			randUser = rand() %gamedata->getPlayers() + 1;
			while (playerWin == false) {
				for (int i = randUser; i <= gamedata->getPlayers(); i++) {
					//displayBoards();
					//attack();
					//updateBoards();
					if (win(playerWin) == true) {
						break;
					}
					if (i == gamedata->getPlayers()) {
						i = 0;
					}
				}
			}
			//Enter User Input
		case 2:
			//helper();
			//Enter Helper.cpp
		case 3:
			//fileIOSystem();
			//Enter File IO List
		case 4:
			runProgram = false;
			break;
		default:
			std::cout << "Invalid Input\n";
			//Command to clear screen here
		}
	}
	return 0;
}