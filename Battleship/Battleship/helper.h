/******************************************************************************
 * File: helper.h
 * Project: CSCN71030 Team Project - Battleship
 * Author: Jacob Stekelenburg
 * Date: April 2026
 * Description:
 *     Contains shared board constants, data structures, and helper function
 *     declarations used by the board-related modules of the Battleship project.
 *
 * References:
 *     "std::vector." cppreference.com,
 *     https://en.cppreference.com/w/cpp/container/vector.html.
 ******************************************************************************/

 //This Module has been flagged for plagerism

#pragma once

#include <string>
#include <vector>

 // Shared board type used across the board-related modules.
using Board = std::vector<std::vector<char>>;

// Supported board sizes.
const int MIN_BOARD_SIZE = 10;
const int MID_BOARD_SIZE = 15;
const int MAX_BOARD_SIZE = 20;

// Symbols used on the game boards.
const char WATER_SYMBOL = '~';
const char HIT_SYMBOL = 'X';
const char MISS_SYMBOL = 'O';
const char SUNK_SYMBOL = '#';

/**
 * Stores information about one ship on the board.
 */
struct BoardShip
{
    std::string name;
    char symbol;
    int size;
    int health;
    bool isSunk = false;
};

/**
 * Stores the board data and ship list for one player.
 */
struct Player
{
    std::string name;
    int boardSize = MIN_BOARD_SIZE;
    Board ownBoard;
    Board trackingBoard;
    std::vector<BoardShip> ships;
};

/**
 * Creates a square board filled with water symbols.
 *
 * @param boardSize The number of rows and columns in the board.
 * @return A 2D board initialized with WATER_SYMBOL.
 */
Board createBoard(int boardSize);

/**
 * Sets up a player with a name, board size, empty boards, and no ships.
 *
 * @param player The player being initialized.
 * @param name The player's display name.
 * @param boardSize The selected board size.
 */
//void initializePlayer(Player& player, const std::string& name, int boardSize);

/**
 * Checks if a row and column are inside the board limits.
 *
 * @param row The row to check.
 * @param col The column to check.
 * @param boardSize The current size of the board.
 * @return True if the coordinate is valid, otherwise false.
 */
bool isValidCoordinate(int row, int col, int boardSize);

/**
 * Checks if the cell contains a ship instead of water or a result marker.
 *
 * @param cell The character stored in the board cell.
 * @return True if the cell is a ship symbol, otherwise false.
 */
bool isShipSymbol(char cell);