#include <iostream>
#include <string>
#include <time.h>
#include "mainMenu.h"
#include "userInput.h"
#include "fileIOSystem.h"
#include "gatherGameData.h"
#include "Base.h"
#include "win.h"
//#include "placeShips.h"
#include "displayBoards.h"
#include "attack.h"
#include <Windows.h>

//using namespace std; ?? What do we prefer here?
//Add your code here
void chooseShips(GameData* data, UserData* user);

int mainMenu() {
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
		userNum = processChoice(userNum);

		switch (userNum) {
		case 1:
			userInput(gamedata, users);
			gatherGameData(players, gamedata, users);
			gameSaveUI(gamedata);
			chooseShips(gamedata, users);
			randUser = rand() % gamedata->getPlayers();// +1;
			while (playerWin == false) {
				for (int i = 0/*randUser */ ; i < gamedata->getPlayers(); i++) {
					displayPlayerBoards(users[i]);
					for (int j = 0/*randUser */; j < gamedata->getPlayers(); j++) {
						if (j != i) {
							displayOpponentBoard(users[j]);
						}
					}
					requestAttack(users[i], gamedata);
					/*if (win(playerWin) == true) {
						break;
					}*/
					/*if (i == gamedata->getPlayers()) {
						i = 0;
					}*/
					/*if (i == 2) {
						break;
					}*/
				}
			}
			break;
			//Enter User Input
		case 2:
			//helper();
			//Enter Helper.cpp
			break;
		case 3:
			fileIOSystem(gamedata);
			break;
			//Enter File IO List
		case 4:
			runProgram = false;
			break;
		default:
			std::cout << "Invalid Input\n";
			Sleep(1000);
			system("cls");
			//Command to clear screen here
		}

	}
	return 0;
}

int processChoice(int userNum) {
	switch (userNum) {
		case 1: return 1;
		case 2: return 2;
		case 3: return 3;
		case 4: return 4;
		default: return -1;
	}
	//return userNum;
}