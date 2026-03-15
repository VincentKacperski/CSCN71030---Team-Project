//C libraries
#include <iostream>
#include <string>
#include <cmath>

//Modules
#include "mainMenu.h"
#include "userInput.h"
#include "gatherGameData.h"
#include "placeShips.h"
#include "displayBoards.h"
#include "fileIOSystem.h"
#include "attack.h"
#include "updateBoards.h"
#include "shipChecking.h"
#include "win.h"
#include "helper.h"

//Ship abilities
#include "cruiser.h"
#include "battleship.h"
#include "submarine.h"
#include "destroyer.h"
#include "aircraftCarrier.h"

//Main function
int main() {

	//User Input
	int players = userInput();
	gatherGameData(players);

	return 0;
}