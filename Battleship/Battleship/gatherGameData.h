#pragma once
class GameData {
private:

	int mapSize;
	int shipCount;
	char abilities[5] = "";

public:

	//Default constructor
	GameData() {}

	//Build Constructor
	GameData(int m, int s) {
		mapSize = m;
		shipCount = s;
	}

	//Default setter functions
	void storeMapSize(int m) { //Store player count
		mapSize = m;
	}
	void storeShipCount(int s) { //Store nickname
		shipCount = s;
	}

	//Default getter functions
	int getMapSize() { //Store player count
		return mapSize;
	}

	int getShipCount() { //Store nickname
		return shipCount;
	}

};

struct User {

	int mapSize = 0;
	int shipCount = 0;
	char abilities[5] = "";

};

//Function Prototypes
int gatherGameData(int);
int testSave(int);