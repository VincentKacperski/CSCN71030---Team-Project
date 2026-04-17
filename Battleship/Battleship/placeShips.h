#pragma once
#include "Base.h"
#include "shipChecking.h"

//Structure definition
typedef struct {
	std::string name;
	int size;
	bool chosen;
} Ship;

//Function prototypes
void placeShip(UserData* user, int choice);
void placedShip(int x, int y, char orientation);
void chooseShips(GameData* data, UserData* user);
void displayShips(Ship fleet[]);