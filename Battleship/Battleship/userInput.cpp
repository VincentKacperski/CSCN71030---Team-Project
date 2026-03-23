#include <iostream>
#include <string>
#include "userInput.h"
#include <fstream>

class UserData {
private:

	std::string nickname;
	std::string username;
	int players = 0;
	int age = 0;

public:

	//Default constructor
	UserData() {}

	//Build Constructor
	UserData(std::string n, std::string u, int a, int p) {
		username = u;
		nickname = n;
		players = p;
		age = a;
	}

	//Setter functions

	void storePlayers(int p) { //Store player count
		players = p;
	}
	void storeNickname(std::string n) { //Store nickname
		nickname = n;
	}
	void storeUsername(std::string n) { //Store username
		username = n;
	}
	void storeAge(int a) { //Store age
		age = a;
	}

	//Getter functions

	int getPlayers() { //Get player count
		return players;
	}
	std::string getNickname() { //Store nickname
		return nickname;
	}
	std::string getUsername() { //Store username
		return username;
	}
	int getAge() { //Store age
		return age;
	}

};

struct User {
	std::string nickname;
	std::string username;
	int players = 0;
	int age = 0;
};

namespace data {

	//Decleration
	int choice = 0;
	int selections = 0;
	int players = 0;
	int age = 0;
	std::string nickname;
	std::string username;
	User users;

}

int testSave(std::string nickname, int players); // Added forward declaration so testSave can be called before its full definition

void userInput() {

	while (data::players <= 0) {
		std::cout << "Number of players: ";
		std::cin >> data::players; // Changed to data::players so this loop updates the same variable it validates
	}

	for (int i = 1; i <= data::players; i++) { // Changed loop to start at 1 so player numbers match the save cases below

		//Get the users nickname
		std::cout << "Enter a nickname: ";
		std::cin >> data::users.nickname;
		data::selections++; //Increement selections
		testSave(data::users.nickname, i); // Changed arguments so the current nickname and current player number are passed correctly

		//Get the users nickname
		std::cout << "Enter your username";
		std::cin >> data::users.username;
		data::selections++; //Increment selections

		//Get the users nickname
		while (data::age < 5 && data::age > 100) {
			std::cout << "Enter your age (integers only):";
			std::cin >> data::users.age;
			if (data::age < 5 && data::age > 100) {
				std::cout << "Error: Invalid age (Valid: 5-100): ";
				std::cin >> data::users.age;
			}
		}
		data::selections++; //Increment selections

	}

}

int testSave(std::string nickname, int players) {

	//Decleration
	std::fstream fileptr;
	User userdata;

	//Opening and using files
	if (players == 1) {
		fileptr.open("Playerone.txt"); // Moved open before is_open check so the file stream is actually tested after opening
		if (fileptr.is_open()) {

			//Open player ones file
			fileptr << userdata.nickname;
			fileptr << userdata.username;
			fileptr << userdata.age;
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
				fileptr << userdata.nickname;
				fileptr << userdata.username;
				fileptr << userdata.age;
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
					fileptr << userdata.nickname;
					fileptr << userdata.username;
					fileptr << userdata.age;
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
						fileptr << userdata.nickname;
						fileptr << userdata.username;
						fileptr << userdata.age;
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