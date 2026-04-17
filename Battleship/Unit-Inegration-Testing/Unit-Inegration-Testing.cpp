//Libraries
#include <vector>
#include <iostream>
#include <string>
#include <time.h>

//Files
#include "pch.h"
#include "CppUnitTest.h"
#include "mainMenu.h"
#include "userInput.h"
#include "fileIOSystem.h"
#include "gatherGameData.h"
#include "Base.h"
#include "win.h"
#include "placeShips.h"
#include "displayBoards.h"
#include "attack.h"
#include "helper.h"
#include <Windows.h>

//Main Menu Module  - Owen
extern "C++" int mainMenu();

//User Input Module - Vincent
extern "C++" void userInput(GameData*, UserData*);
extern "C++" void gatherNickname(UserData* user);
extern "C++" void gatherUsername(UserData* user);
extern "C++" void gatherAge(UserData* user);

//Gather Game Data module - Vincent
extern "C++" void gatherGameData(int players, GameData* gamedata, UserData* users);
extern "C++" void gatherShipCount(UserData* user);
extern "C++" void gatherShipCount(UserData* user);
extern "C++" void gatherAbilities(UserData* user);

//Place Ships Module - Alex
extern "C++" void displayShips(Ship fleet[]);
extern "C++" void chooseShips(GameData* data, UserData* user);
extern "C++" void placedShip(int x, int y, char orientation);
extern "C++" void placeShip(UserData* user, int choice);

//Attack Module - Alex
extern "C++" void chooseShips(GameData* data, UserData* user);
extern "C++" void requestAttack(UserData& user, GameData* data);
extern "C++" void checkAttack(UserData* user, int x, int y, int selected);
extern "C++" void setResult(bool hit);
extern "C++" void placeShip(UserData* user, int choice);

//Display Boards - Jacob
extern "C++" void displaySingleBoard(const std::vector<std::vector<char>>& board, bool hideShips);
extern "C++" void displayPlayerBoards(UserData& player);
extern "C++" void displayOpponentBoard(UserData& player);

//Ship Checking - Alex
extern "C++" void initializeBoards(UserData& user, int boardSize);
extern "C++" bool placeShips(UserData& user, int x, int y, int orientation, int size, char symbol);
extern "C++" bool checkHit(UserData& defender, int x, int y);

//Update Boards - Jacob
extern "C++" bool updateBoardAfterAttack(UserData& defender, UserData& attacker, int row, int col);
extern "C++" void updateBoardsAfterAbility(UserData& defender, UserData& attacker, int row, int col, char resultSymbol);

//File Input Output System - Owen
extern "C++" void fileIOSystem(GameData* gamedata);
extern "C++" void gameSaveUI(GameData* game);
extern "C++" void gameSaveGD(GameData* game);
extern "C++" void loadPlayer(int players, UserData* users, GameData* data);
extern "C++" void savePlayer(int players, UserData* users, GameData* data);
extern "C++" int fileOpen(GameData* gamedata);

//Win  - Owen
extern "C++" bool win(bool playerWin);

//Helper
extern "C++" Board createBoard(int boardSize);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitInegrationTesting
{
	TEST_CLASS(UpdateBoardsTests)
	{
	public:

		TEST_METHOD(UpdateBoards_updateBoardAfterAttack_HitReturnsTrue)
		{
			UserData defender;
			UserData attacker;

			defender.storeOwnBoard(createBoard(10));
			attacker.storeTrackingBoard(createBoard(10));

			std::vector<std::vector<char>> board = defender.getOwnBoard();
			board[2][3] = 'S';
			defender.storeOwnBoard(board);

			bool result = updateBoardAfterAttack(defender, attacker, 2, 3);

			Assert::IsTrue(result);
		}

		TEST_METHOD(UpdateBoards_updateBoardAfterAttack_MissReturnsFalse)
		{
			UserData defender;
			UserData attacker;

			defender.storeOwnBoard(createBoard(10));
			attacker.storeTrackingBoard(createBoard(10));

			bool result = updateBoardAfterAttack(defender, attacker, 1, 1);

			Assert::IsFalse(result);
		}
	};
}
