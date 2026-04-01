#include "Base.h"

typedef struct {
	char name[30];
	int size;
	char ability[100];
} Ship;

void placeShip();
void placedShip(int x, int y, char orientation);
void chooseShips();
void displayShips(Ship fleet[]);