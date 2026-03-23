#include <iostream>
#include <string>
#include <fstream>
#include "Base.h"
#include "userInput.h"

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
			playerSaveUI(&users[0], data::players);

		} else if (data::players == 2) {
			gatherNickname(&users[1]);
			gatherUsername(&users[1]);
			gatherAge(&users[1]);
			playerSaveUI(&users[1], data::players);

		} else if (data::players == 3) {
			gatherNickname(&users[2]);
			gatherUsername(&users[2]);
			gatherAge(&users[2]);
			playerSaveUI(&users[2], data::players);

		} else {
			gatherNickname(&users[3]);
			gatherUsername(&users[3]);
			gatherAge(&users[3]);
			playerSaveUI(&users[3], data::players);

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

void gameSaveUI(GameData* game) {

	//Decleration
	std::fstream fileptr;

	//Store game data player count to the game data file
	fileptr.open("Playerone.txt");
	fileptr << game->getPlayers();
	fileptr.close(); //Close the file

}

//Test save file
void playerSaveUI(UserData* user, int players) {

	//Decleration
	std::fstream fileptr;

	//Opening and using files
	if (players == 1) {
		fileptr.open("Playerone.txt"); // Moved open before is_open check so the file stream is actually tested after opening
		if (fileptr.is_open()) {

			//Open player ones file
			fileptr.open("Playerone.txt");
			fileptr << user->getNickname();
			fileptr << user->getUsername();
			fileptr << user->getAge();
			fileptr.close(); //Close the file

		}
		else {
			//Do nothing for now
		}
	}
	else {
		if (players == 2) {
			fileptr.open("Playertwo.txt"); // Moved open before is_open check so the file stream is actually tested after opening
			if (fileptr.is_open()) {

				//Open player twos file
				fileptr.open("Playertwo.txt");
				fileptr << user->getNickname();
				fileptr << user->getUsername();
				fileptr << user->getAge();
				fileptr.close(); //Close the file

			}
			else {
				//Do nothing for now
			}
		}
		else {
			if (players == 3) {
				fileptr.open("Playerthree.txt"); // Moved open before is_open check so the file stream is actually tested after opening
				if (fileptr.is_open()) {

					//Open player twos file
					fileptr.open("Playerthree.txt");
					fileptr << user->getNickname();
					fileptr << user->getUsername();
					fileptr << user->getAge();
					fileptr.close(); //Close the file

				}
				else {
					//Do nothing for now
				}
			}
			else {
				if (players == 4) {
					fileptr.open("Playerthree.txt"); // Moved open before is_open check so the file stream is actually tested after opening
					if (fileptr.is_open()) {

						//Open player twos file
						fileptr.open("Playerfour.txt");
						fileptr << user->getNickname();
						fileptr << user->getUsername();
						fileptr << user->getAge();
						fileptr.close(); //Close the file

					}
					else {
						//Do nothing for now
					}
				}
				else {
					//Do nothing for now
				}
			}
		}
	}

	return 0; // Added return value because the function is declared with int
}