#include <iostream>
#include <string>
#include "mainMenu.h"
#include "userInput.h"
#include "fileIOSystem.h"
#include "gatherGameData.h"

//using namespace std; ?? What do we prefer here?
//Add your code here

int mainMenu(){
	bool runProgram = true;
	int userNum;
	while (runProgram) {
		std::cout << "Welcome to Battleship\n\n";
		std::cout << "1. Play\n";
		std::cout << "2. Help\n";
		std::cout << "3. Saves\n";
		std::cout << "4. End\n";

		std::cin >> userNum;

		switch (userNum) {
		case 1:
			//userInput();
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
}