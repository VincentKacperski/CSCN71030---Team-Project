//C libraries
#include "main.h"
/******************************************************************************
 * File: main.cpp
 * Project: CSCN71030 Team Project - Battleship
 * Author: Team Project Group
 * Date: March 2026
 * Description:
 *     Entry point for the Battleship game.
 ******************************************************************************/

 // C++ libraries
#include <iostream>
#include <string>
#include <cmath>

// Modules
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
#include "Base.h"

// Ship abilities
#include "cruiser.h"
#include "battleship.h"
#include "submarine.h"
#include "destroyer.h"
#include "aircraftCarrier.h"

int main()
{
    // Start the program from the main menu.
    mainMenu();
    return 0;
}