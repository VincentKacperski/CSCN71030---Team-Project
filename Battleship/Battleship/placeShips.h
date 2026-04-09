#pragma once
#include "Base.h"
#include "shipChecking.h"

typedef struct {
	std::string name;
	int size;
	bool chosen;
} Ship;

void placeShip(int choice);
void placedShip(int x, int y, char orientation);
void chooseShips(GameData* data, UserData* user);
void displayShips(Ship fleet[]);