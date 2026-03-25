//C libraries
#include "main.h"
/******************************************************************************
 * File: main.cpp
 * Project: CSCN71030 Team Project - Battleship
 * Author: Team Project Group
 * Date: March 2026
 * Description:
 *     Entry point for the Battleship game.
 *
 * Notes:
 *     This current version includes a temporary test setup for validating
 *     the helper, display, and update board modules.
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

/**
 * Program entry point.
 *
 * @return 0 if the program finishes successfully.
 */
int main()
{
  
    //Jacob's Code
  
    // Temporary integration test added to verify helper, displayBoards,
    // and updateBoards functionality before full game flow is connected.
    Player player1;
    Player player2;

    initializePlayer(player1, "Player 1", 10);
    initializePlayer(player2, "Player 2", 10);

    // Sample ship data added for temporary board-update testing.
    Ship destroyer = { "Destroyer", 'D', 2, 2, false };
    player2.ships.push_back(destroyer);

    // Manual placement used only to simulate attack and display behavior.
    player2.ownBoard[2][3] = 'D';
    player2.ownBoard[2][4] = 'D';

    std::cout << "\nBefore attack:\n";
    displayPlayerBoards(player2);

    // Temporary attack simulation used to confirm hit and miss updates.
    updateBoardAfterAttack(player2, player1, 2, 3);
    updateBoardAfterAttack(player2, player1, 0, 0);

    std::cout << "\nAfter attacks:\n";
    std::cout << "\nPlayer 2 board:\n";
    displaySingleBoard(player2.ownBoard, false);

    std::cout << "\nPlayer 1 tracking board:\n";
    displaySingleBoard(player1.trackingBoard, false);
    displayOpponentBoard(player2);
	  //User Input

    //Vincent's Code
  
	  //Create gamedata and player objects
   	GameData* gamedata = new GameData;
	  UserData userOne;
	  UserData userTwo;
	  UserData userThree;
	  UserData userFour;
  	UserData* users[4] = {&userOne, &userTwo, &userThree, &userFour};
	
  	int players = userInput(gamedata, *users);
	  gatherGameData(players, gamedata, *users);
    // Opponent view added to confirm that hidden ship display works correctly.
    std::cout << "\nOpponent View:\n";
   

    return 0;
}