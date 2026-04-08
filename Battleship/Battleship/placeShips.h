#include "Base.h"
#include "shipChecking.h"

typedef struct {
	std::string name;
	int size;
	bool chosen;
} Ship;

void placeShip();
void placedShip(int x, int y, char orientation);
void chooseShips();
void displayShips(Ship fleet[]);