#include "pch.h"

//Libraries
#include <vector>
#include <iostream>
#include <string>
#include <time.h>
#include <sstream>
#include <streambuf>

//Files
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
	// Unit tests for the Update Boards module.
	TEST_CLASS(UpdateBoardsTests)
	{
	public:

		// Checks that a hit returns true.
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

		// Checks that a miss returns false.
		TEST_METHOD(UpdateBoards_updateBoardAfterAttack_MissReturnsFalse)
		{
			UserData defender;
			UserData attacker;

			defender.storeOwnBoard(createBoard(10));
			attacker.storeTrackingBoard(createBoard(10));

			bool result = updateBoardAfterAttack(defender, attacker, 1, 1);

			Assert::IsFalse(result);
		}

		// Checks that a hit updates the defender's board.
		TEST_METHOD(UpdateBoards_updateBoardAfterAttack_HitMarksDefenderBoard)
		{
			UserData defender;
			UserData attacker;

			defender.storeOwnBoard(createBoard(10));
			attacker.storeTrackingBoard(createBoard(10));

			std::vector<std::vector<char>> board = defender.getOwnBoard();
			board[4][5] = 'B';
			defender.storeOwnBoard(board);

			updateBoardAfterAttack(defender, attacker, 4, 5);

			std::vector<std::vector<char>> updatedBoard = defender.getOwnBoard();
			Assert::AreEqual('X', updatedBoard[4][5]);
		}

		// Checks that a hit updates the attacker's tracking board.
		TEST_METHOD(UpdateBoards_updateBoardAfterAttack_HitMarksAttackerTrackingBoard)
		{
			UserData defender;
			UserData attacker;

			defender.storeOwnBoard(createBoard(10));
			attacker.storeTrackingBoard(createBoard(10));

			std::vector<std::vector<char>> board = defender.getOwnBoard();
			board[3][2] = 'C';
			defender.storeOwnBoard(board);

			updateBoardAfterAttack(defender, attacker, 3, 2);

			std::vector<std::vector<char>> trackingBoard = attacker.getTrackingBoard();
			Assert::AreEqual('X', trackingBoard[3][2]);
		}

		// Checks that a miss updates the attacker's tracking board.
		TEST_METHOD(UpdateBoards_updateBoardAfterAttack_MissMarksAttackerTrackingBoard)
		{
			UserData defender;
			UserData attacker;

			defender.storeOwnBoard(createBoard(10));
			attacker.storeTrackingBoard(createBoard(10));

			updateBoardAfterAttack(defender, attacker, 0, 0);

			std::vector<std::vector<char>> trackingBoard = attacker.getTrackingBoard();
			Assert::AreEqual('O', trackingBoard[0][0]);
		}

		// Checks that invalid coordinates return false.
		TEST_METHOD(UpdateBoards_updateBoardAfterAttack_InvalidCoordinatesReturnFalse)
		{
			UserData defender;
			UserData attacker;

			defender.storeOwnBoard(createBoard(10));
			attacker.storeTrackingBoard(createBoard(10));

			bool result = updateBoardAfterAttack(defender, attacker, -1, 15);

			Assert::IsFalse(result);
		}

		// Checks that attacking the same cell again returns false.
		TEST_METHOD(UpdateBoards_updateBoardAfterAttack_RepeatedAttackReturnsFalse)
		{
			UserData defender;
			UserData attacker;

			defender.storeOwnBoard(createBoard(10));
			attacker.storeTrackingBoard(createBoard(10));

			updateBoardAfterAttack(defender, attacker, 0, 0);
			bool result = updateBoardAfterAttack(defender, attacker, 0, 0);

			Assert::IsFalse(result);
		}

		// Checks that ability results update the defender's board.
		TEST_METHOD(UpdateBoards_updateBoardsAfterAbility_UpdatesDefenderBoard)
		{
			UserData defender;
			UserData attacker;

			defender.storeOwnBoard(createBoard(10));
			attacker.storeTrackingBoard(createBoard(10));

			updateBoardsAfterAbility(defender, attacker, 2, 2, 'X');

			std::vector<std::vector<char>> updatedBoard = defender.getOwnBoard();
			Assert::AreEqual('X', updatedBoard[2][2]);
		}

		// Checks that ability results update the attacker's tracking board.
		TEST_METHOD(UpdateBoards_updateBoardsAfterAbility_UpdatesAttackerTrackingBoard)
		{
			UserData defender;
			UserData attacker;

			defender.storeOwnBoard(createBoard(10));
			attacker.storeTrackingBoard(createBoard(10));

			updateBoardsAfterAbility(defender, attacker, 3, 3, 'O');

			std::vector<std::vector<char>> trackingBoard = attacker.getTrackingBoard();
			Assert::AreEqual('O', trackingBoard[3][3]);
		}

		// Checks that ability updates do nothing when coordinates are invalid.
		TEST_METHOD(UpdateBoards_updateBoardsAfterAbility_InvalidCoordinatesDoNothing)
		{
			UserData defender;
			UserData attacker;

			defender.storeOwnBoard(createBoard(10));
			attacker.storeTrackingBoard(createBoard(10));

			updateBoardsAfterAbility(defender, attacker, -1, 15, 'X');

			std::vector<std::vector<char>> defenderBoard = defender.getOwnBoard();
			std::vector<std::vector<char>> trackingBoard = attacker.getTrackingBoard();

			Assert::AreEqual('~', defenderBoard[0][0]);
			Assert::AreEqual('~', trackingBoard[0][0]);
		}
	};

	// Unit tests for the Display Boards module.
	TEST_CLASS(DisplayBoardsTests)
	{
	public:

		// Checks that a board shows ship symbols when hideShips is false.
		TEST_METHOD(DisplayBoards_displaySingleBoard_ShowsVisibleShips)
		{
			std::vector<std::vector<char>> board = createBoard(10);
			board[0][0] = 'Q';

			std::ostringstream output;
			std::basic_streambuf<char>* oldBuffer = std::cout.rdbuf(output.rdbuf());

			displaySingleBoard(board, false);

			std::cout.rdbuf(oldBuffer);

			Assert::IsTrue(output.str().find('Q') != std::string::npos);
		}

		// Checks that ship symbols are hidden when hideShips is true.
		TEST_METHOD(DisplayBoards_displaySingleBoard_HidesShipsWhenRequested)
		{
			std::vector<std::vector<char>> board = createBoard(10);
			board[0][0] = 'Q';

			std::ostringstream output;
			std::basic_streambuf<char>* oldBuffer = std::cout.rdbuf(output.rdbuf());

			displaySingleBoard(board, true);

			std::cout.rdbuf(oldBuffer);

			Assert::IsTrue(output.str().find('Q') == std::string::npos);
		}

		// Checks that the board output includes column headers.
		TEST_METHOD(DisplayBoards_displaySingleBoard_ShowsColumnHeaders)
		{
			std::vector<std::vector<char>> board = createBoard(10);

			std::ostringstream output;
			std::basic_streambuf<char>* oldBuffer = std::cout.rdbuf(output.rdbuf());

			displaySingleBoard(board, false);

			std::cout.rdbuf(oldBuffer);

			Assert::IsTrue(output.str().find("10") != std::string::npos);
		}

		// Checks that the board output includes row numbers.
		TEST_METHOD(DisplayBoards_displaySingleBoard_ShowsRowNumbers)
		{
			std::vector<std::vector<char>> board = createBoard(10);

			std::ostringstream output;
			std::basic_streambuf<char>* oldBuffer = std::cout.rdbuf(output.rdbuf());

			displaySingleBoard(board, false);

			std::cout.rdbuf(oldBuffer);

			Assert::IsTrue(output.str().find("1") != std::string::npos);
		}

		// Checks that player boards show the own board and tracking board labels.
		TEST_METHOD(DisplayBoards_displayPlayerBoards_ShowsBoardLabels)
		{
			UserData player;
			player.storeNickname("Jacob");
			player.storeOwnBoard(createBoard(10));
			player.storeTrackingBoard(createBoard(10));

			std::ostringstream output;
			std::basic_streambuf<char>* oldBuffer = std::cout.rdbuf(output.rdbuf());

			displayPlayerBoards(player);

			std::cout.rdbuf(oldBuffer);

			Assert::IsTrue(output.str().find("=== Own Board ===") != std::string::npos);
			Assert::IsTrue(output.str().find("=== Tracking Board ===") != std::string::npos);
		}

		// Checks that player board output includes the player's nickname.
		TEST_METHOD(DisplayBoards_displayPlayerBoards_ShowsNickname)
		{
			UserData player;
			player.storeNickname("Jacob");
			player.storeOwnBoard(createBoard(10));
			player.storeTrackingBoard(createBoard(10));

			std::ostringstream output;
			std::basic_streambuf<char>* oldBuffer = std::cout.rdbuf(output.rdbuf());

			displayPlayerBoards(player);

			std::cout.rdbuf(oldBuffer);

			Assert::IsTrue(output.str().find("Jacob") != std::string::npos);
		}
	};

	// Integration tests for the Update Boards module.
	TEST_CLASS(UpdateBoardsIntegrationTests)
	{
	public:

		// Checks that a hit updates both the defender's own board and the attacker's tracking board.
		TEST_METHOD(Integration_UpdateBoards_HitUpdatesBothBoards)
		{
			UserData defender;
			UserData attacker;

			defender.storeOwnBoard(createBoard(10));
			attacker.storeTrackingBoard(createBoard(10));

			std::vector<std::vector<char>> defenderBoard = defender.getOwnBoard();
			defenderBoard[2][3] = 'S';
			defender.storeOwnBoard(defenderBoard);

			bool result = updateBoardAfterAttack(defender, attacker, 2, 3);

			std::vector<std::vector<char>> updatedDefenderBoard = defender.getOwnBoard();
			std::vector<std::vector<char>> updatedTrackingBoard = attacker.getTrackingBoard();

			Assert::IsTrue(result);
			Assert::AreEqual('X', updatedDefenderBoard[2][3]);
			Assert::AreEqual('X', updatedTrackingBoard[2][3]);
		}

		// Checks that a miss updates both the defender's own board and the attacker's tracking board.
		TEST_METHOD(Integration_UpdateBoards_MissUpdatesBothBoards)
		{
			UserData defender;
			UserData attacker;

			defender.storeOwnBoard(createBoard(10));
			attacker.storeTrackingBoard(createBoard(10));

			bool result = updateBoardAfterAttack(defender, attacker, 0, 0);

			std::vector<std::vector<char>> updatedDefenderBoard = defender.getOwnBoard();
			std::vector<std::vector<char>> updatedTrackingBoard = attacker.getTrackingBoard();

			Assert::IsFalse(result);
			Assert::AreEqual('O', updatedDefenderBoard[0][0]);
			Assert::AreEqual('O', updatedTrackingBoard[0][0]);
		}
	};

	// Integration tests for the Display Boards module.
	TEST_CLASS(DisplayBoardsIntegrationTests)
	{
	public:

		// Checks that displayPlayerBoards shows an updated hit on the tracking board.
		TEST_METHOD(Integration_DisplayBoards_DisplayPlayerBoardsShowsUpdatedHit)
		{
			UserData defender;
			UserData attacker;

			defender.storeNickname("Defender");
			attacker.storeNickname("Attacker");

			defender.storeOwnBoard(createBoard(10));
			attacker.storeOwnBoard(createBoard(10));
			attacker.storeTrackingBoard(createBoard(10));

			std::vector<std::vector<char>> defenderBoard = defender.getOwnBoard();
			defenderBoard[2][3] = 'S';
			defender.storeOwnBoard(defenderBoard);

			updateBoardAfterAttack(defender, attacker, 2, 3);

			// First confirm the tracking board was actually updated.
			std::vector<std::vector<char>> trackingBoard = attacker.getTrackingBoard();
			Assert::AreEqual('X', trackingBoard[2][3]);

			std::ostringstream output;
			std::basic_streambuf<char>* oldBuffer = std::cout.rdbuf(output.rdbuf());

			displayPlayerBoards(attacker);

			std::cout.rdbuf(oldBuffer);

			Assert::IsTrue(output.str().find("=== Own Board ===") != std::string::npos);
			Assert::IsTrue(output.str().find("=== Tracking Board ===") != std::string::npos);
			Assert::IsTrue(output.str().find("Attacker") != std::string::npos);
		}

		// Checks that displayOpponentBoard shows ability result markers but still hides untouched ships.
		TEST_METHOD(Integration_DisplayBoards_DisplayOpponentBoardShowsAbilityResultAndHidesShips)
		{
			UserData defender;
			UserData attacker;

			defender.storeOwnBoard(createBoard(10));
			attacker.storeTrackingBoard(createBoard(10));

			std::vector<std::vector<char>> defenderBoard = defender.getOwnBoard();
			defenderBoard[4][4] = 'Q';
			defender.storeOwnBoard(defenderBoard);

			updateBoardsAfterAbility(defender, attacker, 2, 2, 'O');

			std::ostringstream output;
			std::basic_streambuf<char>* oldBuffer = std::cout.rdbuf(output.rdbuf());

			displayOpponentBoard(defender);

			std::cout.rdbuf(oldBuffer);

			Assert::IsTrue(output.str().find("=== Opponent Board ===") != std::string::npos);
			Assert::IsTrue(output.str().find("O") != std::string::npos);
			Assert::IsTrue(output.str().find("Q") == std::string::npos);
		}
		// Checks that displaySingleBoard handles unexpected board characters safely.
		TEST_METHOD(DisplayBoards_displaySingleBoard_InvalidBoardCharacterDoesNotCrash)
		{
			std::vector<std::vector<char>> board = createBoard(10);
			board[2][2] = '@'; // invalid/unexpected symbol

			std::ostringstream output;
			std::basic_streambuf<char>* oldBuffer = std::cout.rdbuf(output.rdbuf());

			displaySingleBoard(board, false);

			std::cout.rdbuf(oldBuffer);

			// The board should still print, including row/column formatting.
			Assert::IsTrue(output.str().length() > 0);
			Assert::IsTrue(output.str().find("1") != std::string::npos);
		}

	};

	using namespace Microsoft::VisualStudio::CppUnitTestFramework;

	namespace AlexsUnitTesting
	{
		TEST_CLASS(AttackUnitTesting)
		{
		public:

			TEST_METHOD(TestrequestAttack)
			{
				UserData user;
				GameData data;
				data.Players(2);

				std::istringstream input("1\n3 4\nn\n");
				std::streambuf* cinBackup = std::cin.rdbuf(input.rdbuf());

				std::ostringstream output;
				std::streambuf* coutBackup = std::cout.rdbuf(output.rdbuf());

				requestAttack(user, &data);

				std::cin.rdbuf(cinBackup);
				std::cout.rdbuf(coutBackup);

				std::string outStr = output.str();

				Assert::IsTrue(outStr.find("Which Player would you like to attack?") != std::string::npos);
				Assert::IsTrue(outStr.find("Enter attack coordinates") != std::string::npos);
			}

			TEST_METHOD(TestcheckAttack)
			{
				UserData user;

				std::istringstream input("y\n");
				std::streambuf* cinBackup = std::cin.rdbuf(input.rdbuf());

				std::ostringstream output;
				std::streambuf* coutBackup = std::cout.rdbuf(output.rdbuf());

				checkAttack(&user, 2, 5, 1);

				std::cin.rdbuf(cinBackup);
				std::cout.rdbuf(coutBackup);

				std::string outStr = output.str();

				Assert::IsTrue(outStr.find("Attack confirmed at (2, 5)") != std::string::npos);
			}

			TEST_METHOD(TestsetResult)
			{
				std::ostringstream output;
				std::streambuf* coutBackup = std::cout.rdbuf(output.rdbuf());

				setResult(true);
				setResult(false);

				std::cout.rdbuf(coutBackup);

				std::string outStr = output.str();

				Assert::IsTrue(outStr.find("It's a hit.") != std::string::npos);
				Assert::IsTrue(outStr.find("It's a miss.") != std::string::npos);
			}
		};
		TEST_CLASS(DisplayShipsUnitTesting)
		{

			TEST_METHOD(TestdisplayShipsShowingNames)
			{
				std::ostringstream output;
				std::streambuf* coutBackup = std::cout.rdbuf(output.rdbuf());

				displayShips(fleet);

				std::cout.rdbuf(coutBackup);

				std::string out = output.str();

				Assert::IsTrue(out.find("Cruiser") != std::string::npos);
				Assert::IsTrue(out.find("Battleship") != std::string::npos);
			}

			TEST_METHOD(TestdisplayShipsShowsSizes)
			{
				std::ostringstream output;
				std::streambuf* coutBackup = std::cout.rdbuf(output.rdbuf());

				displayShips(fleet);

				std::cout.rdbuf(coutBackup);

				std::string out = output.str();

				Assert::IsTrue(out.find("Size") != std::string::npos);
			}

			TEST_METHOD(TestchooseShipsInvalid)
			{
				GameData data;
				UserData user;

				std::istringstream input("999\n1\n1\n1\n1\n1\n1\n");
				std::streambuf* cinBackup = std::cin.rdbuf(input.rdbuf());

				std::ostringstream output;
				std::streambuf* coutBackup = std::cout.rdbuf(output.rdbuf());

				chooseShips(&data, &user);

				std::cin.rdbuf(cinBackup);
				std::cout.rdbuf(coutBackup);

				std::string out = output.str();

				Assert::IsTrue(out.find("Invalid choice") != std::string::npos);
			}

			TEST_METHOD(TestchooseShipsSucceed)
			{
				GameData data;
				UserData user;



				std::istringstream input("1\n1\n1\n1\n1\n1\n");
				std::streambuf* cinBackup = std::cin.rdbuf(input.rdbuf());

				std::ostringstream output;
				std::streambuf* coutBackup = std::cout.rdbuf(output.rdbuf());

				chooseShips(&data, &user);

				std::cin.rdbuf(cinBackup);
				std::cout.rdbuf(coutBackup);

				std::string out = output.str();

				Assert::IsTrue(out.find("Choose a ship") != std::string::npos);
			}

			TEST_METHOD(TestplacedShipOutput)
			{
				std::ostringstream output;
				std::streambuf* coutBackup = std::cout.rdbuf(output.rdbuf());

				placedShip(2, 3, 'H');

				std::cout.rdbuf(coutBackup);

				std::string out = output.str();

				Assert::IsTrue(out.find("(2, 3)") != std::string::npos);
				Assert::IsTrue(out.find("H") != std::string::npos);
			}

			TEST_METHOD(TestplacedShipNoCrash)
			{
				placedShip(0, 0, 'V');
				Assert::IsTrue(true);
			}

			TEST_METHOD(TestplaceShipError)
			{
				UserData user;

				std::istringstream input("0\n0\n1\n");
				std::streambuf* cinBackup = std::cin.rdbuf(input.rdbuf());

				std::ostringstream output;
				std::streambuf* coutBackup = std::cout.rdbuf(output.rdbuf());

				placeShip(&user, 0);

				std::cin.rdbuf(cinBackup);
				std::cout.rdbuf(coutBackup);

				std::string out = output.str();

				Assert::IsTrue(out.find("Error in Placement") != std::string::npos);
			}

			TEST_METHOD(TestplaceShipSucceed)
			{
				UserData user;

				std::istringstream input("1\n1\n1\n");
				std::streambuf* cinBackup = std::cin.rdbuf(input.rdbuf());

				std::ostringstream output;
				std::streambuf* coutBackup = std::cout.rdbuf(output.rdbuf());

				placeShip(&user, 0);

				std::cin.rdbuf(cinBackup);
				std::cout.rdbuf(coutBackup);

				std::string out = output.str();

				Assert::IsTrue(out.find("Enter ship placement coordinate") != std::string::npos);
			}
		};
	}

}