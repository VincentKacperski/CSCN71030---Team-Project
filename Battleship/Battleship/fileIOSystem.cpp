#include <iostream>
#include <fstream>
#include <string>
#include "fileIOSystem.h"
#include "userInput.h"

//Add your code here

//std::fstream filePtr;

int fileOpen(){
	std::fstream file("gamedata.txt");

	if (!file.is_open()) {
		std::cout << "Error in opening the file!\n";
	}

	std::string pCount, nickname, username, age;
	if (file.is_open()) {
		std::getline(file, nickname);
		std::getline(file, username);
		std::getline(file, age);
		std::getline(file, pCount);
	}

	file.close();
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
}

