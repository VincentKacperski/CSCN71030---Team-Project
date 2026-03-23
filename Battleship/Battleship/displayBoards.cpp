/******************************************************************************
 * File: displayBoards.cpp
 * Project: CSCN71030 Team Project - Battleship
 * Author: Jacob Stekelenburg
 * Date: March 2026
 * Description:
 *     Implements the board display functions used by the Battleship game.
 ******************************************************************************/

#include <iostream>
#include <iomanip>
#include "displayBoards.h"

using namespace std;

/**
 * Prints the numbered column headers for the current board.
 *
 * @param boardSize The size of the board being displayed.
 */
static void printColumnHeaders(int boardSize)
{
    cout << "   ";

    for (int col = 0; col < boardSize; col++)
    {
        cout << setw(3) << col + 1;
    }

    cout << endl;
}

/**
 * Displays a single board using a formatted grid layout.
 * If hideShips is true, ship cells are shown as water instead.
 */
void displaySingleBoard(const std::vector<std::vector<char>>& board, bool hideShips)
{
    int boardSize = static_cast<int>(board.size());

    printColumnHeaders(boardSize);

    for (int row = 0; row < boardSize; row++)
    {
        cout << setw(3) << row + 1;

        for (int col = 0; col < boardSize; col++)
        {
            char displayChar = board[row][col];

            // Hide ship positions when displaying an opponent's board.
            if (hideShips && isShipSymbol(displayChar))
            {
                displayChar = WATER_SYMBOL;
            }

            cout << setw(3) << displayChar;
        }

        cout << endl;
    }
}

/**
 * Displays the player's own board followed by their tracking board.
 */
void displayPlayerBoards(const Player& player)
{
    cout << "\n=== " << player.name << "'s Own Board ===\n";
    displaySingleBoard(player.ownBoard, false);

    cout << "\n=== " << player.name << "'s Tracking Board ===\n";
    displaySingleBoard(player.trackingBoard, false);
}

/**
 * Displays an opponent's board with ship positions hidden.
 */
void displayOpponentBoard(const Player& player)
{
    cout << "\n=== " << player.name << "'s Board (Hidden Ships) ===\n";
    displaySingleBoard(player.ownBoard, true);
}