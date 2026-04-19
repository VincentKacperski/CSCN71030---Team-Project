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
extern "C++" int userInput(GameData*, UserData*);
extern "C++" std::string gatherNickname(UserData* user);
extern "C++" std::string gatherUsername(UserData* user);
extern "C++" int gatherAge(UserData* user);

//Gather Game Data module - Vincent
extern "C++" int gatherGameData(int players, GameData* gamedata, UserData* users);
extern "C++" int gatherShipCount(UserData* user);
extern "C++" int gatherAbilities(UserData* user);

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
extern "C++" static bool isShipCell(char value);
extern "C++" static void printColumnHeaders(int boardSize);
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

namespace UnitInegrationTesting
{
	TEST_CLASS(UserInputTesting)
	{
	public:
		
		TEST_METHOD(UserInputTest_001_NicknameCorrect)
		{
			//Decleration
			UserData user;
			std::string name = gatherNickname(&user);
			
			//Check data
			Assert::AreEqual(std::string("Vince"), name);

		}

		TEST_METHOD(UserInputTest_002_UsernameCorrect)
		{
			//Decleration
			UserData user;
			std::string name = gatherUsername(&user);

			//Check data
			Assert::AreEqual(std::string("uirwuiwriouvwoiwrfkrwkkrfreooi"), name);

		}

		TEST_METHOD(UserInputTest_003_AgeCorrect)
		{
			//Decleration
			UserData user;
			int age = gatherAge(&user);

			//Check data
			Assert::AreEqual(1, age);

		}

		TEST_METHOD(UserInputTest_004_PlayerCountCorrect)
		{
			//Decleration

			GameData* gamedata = new GameData;
			UserData userOne;
			UserData userTwo;
			UserData userThree;
			UserData userFour;
			UserData users[4] = { userOne, userTwo, userThree, userFour };
			int playerCount = userInput(gamedata, users);

			//Check data
			Assert::AreEqual(2, playerCount);

		}

	};

	TEST_CLASS(GatherGameDataTesting)
	{
	public:

		TEST_METHOD(GatherGameDataTest_001_PlayerCountCorrect)
		{
			//Decleration

			GameData* gamedata = new GameData;
			UserData userOne;
			UserData userTwo;
			UserData userThree;
			UserData userFour;
			UserData users[4] = { userOne, userTwo, userThree, userFour };
			int player = 0;
			int mapSize = gatherGameData(2, gamedata, users);

			//Check data
			Assert::AreEqual(20, mapSize);

		}

		TEST_METHOD(GatherGameDataTest_002_ShipCountValid)
		{

			//Decleration
			UserData user;
			int shipCount = gatherShipCount(&user);

			//Check data
			Assert::AreEqual(5, shipCount);

		}

		TEST_METHOD(GatherGameDataTest_003_AbilitiesInvalid)
		{

			//Decleration
			UserData user;
			int choice = gatherAbilities(&user);

			//Check data
			Assert::AreEqual(-3, choice);

		}

	};
}

