//Libraries
#include <vector>
#include <iostream>
#include <string>
#include <time.h>
#include <fstream>

//Files
extern "C++" {

#include "pch.h"
#include "CppUnitTest.h"
//#include "../Battleship/main.h"
#include "../Battleship/mainMenu.h"
#include "../Battleship/userInput.h"
#include "../Battleship/fileIOSystem.h"
#include "../Battleship/gatherGameData.h"
#include "../Battleship/Base.h"
#include "../Battleship/win.h"
#include "../Battleship/placeShips.h"
#include "../Battleship/displayBoards.h"
#include "../Battleship/attack.h"
#include "../Battleship/helper.h"
}
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
	TEST_CLASS(UnitInegrationTesting)
	{
	public:

		TEST_METHOD(MainMenuTest_001_GameplayLoop) {
			int expected = 1;
			int result = processChoice(1);
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(MainMenuTest_002_FileIO) {
			int expected = 2;
			int result = processChoice(2);
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(MainMenuTest_003_Helper) {
			int expected = 3;
			int result = processChoice(3);
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(MainMenuTest_004_ExitProgram) {
			int expected = 4;
			int result = processChoice(4);
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(MainMenuTest_005_InvalidInput) {
			int expected = -1;
			int result = processChoice(100);
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(FileIOSystemTest_001_OpenFile) {
			GameData data;

			std::ofstream file("gamedata.txt");
			file << "2\n";   // players
			file << "10\n";  // map size
			file.close();

			fileOpen(&data);
			Assert::AreEqual(2, data.getPlayers());
			Assert::AreEqual(10, data.getMapSize());
		}
		TEST_METHOD(FileIOSystemTest_002_MissingFile) {
			GameData data;

			remove("gamedata.txt");

			fileOpen(&data);

			Assert::IsTrue(true);
		}
		TEST_METHOD(FileIOSystemTest_003_gameSaveUI) {
			GameData data;
			data.storePlayers(3);
			data.storeMapSize(8);

			gameSaveUI(&data);

			std::ifstream file("gamedata.txt");
			std::string players, size;

			getline(file, players);
			getline(file, size);

			Assert::AreEqual(std::string("3"), players);
			Assert::AreEqual(std::string("8"), size);
		}
		TEST_METHOD(FileIOSystemTest_004_gameSaveGD) {
			GameData data;
			data.storePlayers(3);

			gameSaveGD(&data);

			std::ifstream file("gamedata.txt");
			std::string players;

			getline(file, players);

			Assert::AreEqual(std::string("3"), players);
		}

	};
}

