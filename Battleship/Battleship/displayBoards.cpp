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

// Checks if the current cell contains a ship symbol.
static bool isShipCell(char value) {
    return value != '~' && value != 'X' && value != 'O' && value != '#';
}

// Prints the numbered column labels at the top of the board.
static void printColumnHeaders(int boardSize) {
    std::cout << "   ";

    for (int col = 0; col < boardSize; col++)
    {
        std::cout << std::setw(3) << col + 1;
    }
    std::cout << std::endl;
}

// Displays a single board with optional hidden ship positions.
void displaySingleBoard(const std::vector<std::vector<char>>& board, bool hideShips) {
    int boardSize = board.size();

    //Print board header including the player nickname
    printColumnHeaders(boardSize);

    for (int row = 0; row < boardSize; row++)
    {
        std::cout << std::setw(3) << row + 1;

        for (int col = 0; col < boardSize; col++)
        {
            char value = board[row][col];

            if (hideShips && isShipCell(value))
            {
                value = '~';
            }
            std::cout << std::setw(3) << value;
        }
        std::cout << std::endl;
    }
}

// Shows both boards for the current player.
void displayPlayerBoards(UserData& player) {
    std::cout << "\n=== Own Board === " << player.getNickname() << "\n";
    displaySingleBoard(player.getOwnBoard(), false);

    std::cout << "\n=== Tracking Board ===\n";
    displaySingleBoard(player.getTrackingBoard(), false);
}

// Shows an opponent board without revealing ship positions.
void displayOpponentBoard(UserData& player) {
    std::cout << "\n=== Opponent Board ===\n";
    displaySingleBoard(player.getTrackingBoard(), true);
}