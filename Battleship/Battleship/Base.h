#include <string>
#pragma once

class GameData {
private:

	int mapSize;
	int players;

public:

	//Default constructor
	GameData() {
		mapSize = 0;
		players = 0;
	}

	//Build Constructor
	GameData(int m, int p) {
		mapSize = m;
		players = p;
	}

	//Default Destructor
	~GameData() {}

	void storePlayers(int p) { //Store player count
		players = p;
	}

	void storeMapSize(int m) { //Store player count
		mapSize = m;
	}

	int getPlayers() { //Store player count
		return players;
	}

	int getMapSize() { //Get the games map size
		return mapSize;
	}

};

class UserData {
private:

	int age = 0;
	int shipCount = 0;
	char abilities[5] = "";
	std::string nickname;
	std::string username;

public:

	//Default constructor
	UserData() {
		username = "";
		nickname = "";
		age = 0;
	}

	//Build Constructor
	UserData(std::string n, std::string u, int a) {
		username = u;
		nickname = n;
		age = a;
	}

	//Default Destructor
	~UserData() {}

	//Setter functions
	void storeAge(int a) { //Store ship count
		age = a;
	}

	void storeShipCount(int s) { //Store ship count
		shipCount = s;
	}

	char* storeAbilities(char ab[5]) { //Get the games map size
		abilities[0] = ab[0];
		abilities[1] = ab[1];
		abilities[2] = ab[2];
		abilities[3] = ab[3];
		abilities[4] = ab[4];
	}

	void storeUsername(std::string u) { //Store ship count
		username = u;
	}

	void storeNickname(std::string n) { //Store ship count
		nickname = n;
	}

	//Getter functions
	int getAge() { //Get ship count
		return age;
	}

	int getShipCount() { //Get ship count
		return shipCount;
	}

	char* getAbilities() { //Get the players abilities
		return abilities;
	}

	std::string getUsername() { //Store ship count
		return username;
	}

	std::string getNickname() { //Store ship count
		return nickname;
	}

};

struct User {

	std::string nickname;
	std::string username;
	int players = 0;
	int age = 0; 
	int shipCount = 0;

};

struct Game {

	int mapSize = 0;
	char abilities[5] = "";

};

//Save functions
void gameSaveUI(GameData* game);
void gameSaveGD(GameData* game);
int savePlayer(int players, UserData* users);
int fileOpen();

//Helper functions for gather game data
void gatherShipCount(UserData* user);
void gatherAbilities(UserData* user);

//Help functions for user input
void gatherNickname(UserData* user);
void gatherUsername(UserData* user);
void gatherAge(UserData* user);

//Main module functions
void gatherGameData(int players, GameData* gamedata, UserData* users);
void userInput(GameData* gamedata, UserData* users);
