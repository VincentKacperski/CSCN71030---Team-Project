/******************************************************************************
 * File: displayBoards.cpp
 * Project: CSCN71030 Team Project - Battleship
 * Author: Jacob Stekelenburg
 * Date: April 2026
 * Description:
 *     Implements the board display functions for the Battleship project.
 *     This file prints numbered column headers, displays a single board,
 *     and shows the current player's own board and tracking board.
 *
 * References:
 *     "std::vector." cppreference.com,
 *     https://en.cppreference.com/w/cpp/container/vector.html.
 *
 *     "std::setw." cppreference.com,
 *     https://en.cppreference.com/w/cpp/io/manip/setw.html.
 *
 *     "Header <iomanip>." cppreference.com,
 *     https://en.cppreference.com/w/cpp/header/iomanip.html.
 ******************************************************************************/

#include <iostream>
#include <iomanip>
#include "displayBoards.h"

using namespace std;

// Prints the numbered column labels at the top of the board.
static void printColumnHeaders(int boardSize)
{
    cout << "   ";

    for (int col = 0; col < boardSize; col++)
    {
        cout << setw(3) << col + 1;
    }

    cout << endl;
}

// Displays a single board with optional hidden ship positions.
void displaySingleBoard(const Board& board, bool hideShips)
{
    int boardSize = static_cast<int>(board.size());

    printColumnHeaders(boardSize);

    for (int row = 0; row < boardSize; row++)
    {
        cout << setw(3) << row + 1;

        for (int col = 0; col < boardSize; col++)
        {
            char value = board[row][col];

            // If we are hiding ships, replace ship cells with water.
            if (hideShips && isShipSymbol(value))
            {
                value = WATER_SYMBOL;
            }

            cout << setw(3) << value;
        }

        cout << endl;
    }
}

// Shows both boards for the current player.
void displayPlayerBoards(const Player& player)
{
    cout << "\n=== " << player.name << "'s Own Board ===\n";
    displaySingleBoard(player.ownBoard, false);

    cout << "\n=== " << player.name << "'s Tracking Board ===\n";
    displaySingleBoard(player.trackingBoard, false);
}