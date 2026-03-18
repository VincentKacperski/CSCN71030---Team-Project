#pragma once

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

int testSave(int, User);
int userInput();

