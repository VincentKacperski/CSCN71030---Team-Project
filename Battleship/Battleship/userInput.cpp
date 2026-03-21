#include <iostream>
#include <string>
#include <fstream>
#include "Base.h"
#include "userInput.h"

//Note: The code below is not tested or finished yet.
//Do not run the code below as it needs further testing.
//Testing will begin tomorrow due to delays.

namespace data {

	//Decleration
	int choice = 0;
	int selections = 0;
	int players = 0;
	int age = 0;
	std::string nickname;
	std::string username;

}

int userInput() {

	GameData* gamedata = new GameData;
	while (data::players <= 0 || data::players > 4) {
		std::cout << "Number of players: ";
		std::cin >> data::players;
		gamedata->storePlayers(data::players);
	}

	for (int i = 1; i <= data::players; i++) {

		if (data::players == 1) {

			UserData* userOne = new UserData;
			gatherNickname(userOne);
			gatherUsername(userOne);
			gatherAge(userOne);

		} else if (data::players == 2) {

			UserData* userTwo = new UserData;
			gatherNickname(userTwo);
			gatherUsername(userTwo);
			gatherAge(userTwo);

		} else if (data::players == 3) {

			UserData* userThree = new UserData;
			gatherNickname(userThree);
			gatherUsername(userThree);
			gatherAge(userThree);

		} else {

			UserData* userFour = new UserData;
			gatherNickname(userFour);
			gatherUsername(userFour);
			gatherAge(userFour);

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
//=----------------------=

//Test save file
int testSaveTwo(int players, User users, GameData gamedata) {

	//Decleration
	std::fstream fileptr;

	//Opening and using files
	if (players == 1) {
		if (fileptr.is_open()) {

			//Open player ones file
			fileptr.open("Playerone.txt");
			fileptr << data::users.nickname;
			fileptr << data::users.username;
			fileptr << data::users.age;
			fileptr.close(); //Close the file

		} else {
			//Do nothing for now
		}
	} else {
		if (players == 2) {
			if (fileptr.is_open()) {

				//Open player twos file
				fileptr.open("Playertwo.txt");
				fileptr << data::users.nickname;
				fileptr << data::users.username;
				fileptr << data::users.age;
				fileptr.close(); //Close the file

			} else {
				//Do nothing for now
			}
		} else {
			if (players == 3) {
				if (fileptr.is_open()) {

					//Open player twos file
					fileptr.open("Playerthree.txt");
					fileptr << data::users.nickname;
					fileptr << data::users.username;
					fileptr << data::users.age;
					fileptr.close(); //Close the file

				} else {
					//Do nothing for now
				}
			} else {
				if (players == 4) {
					if (fileptr.is_open()) {

						//Open player twos file
						fileptr.open("Playerthree.txt");
						fileptr << data::users.nickname;
						fileptr << data::users.username;
						fileptr << data::users.age;
						fileptr.close(); //Close the file

					} else {
						//Do nothing for now
					}
				} else {
					//Do nothing for now
				}
			}
		}
	}
	return 0;
}