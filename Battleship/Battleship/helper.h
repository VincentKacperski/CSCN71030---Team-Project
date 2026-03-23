/******************************************************************************
 * File: helper.h
 * Project: CSCN71030 Team Project - Battleship
 * Author: Jacob Stekelenburg
 * Date: March 2026
 * Description:
 *     Contains shared constants, data structures, and helper functions used
 *     across the Battleship project.
 *
 * Notes:
 *     This file acts as the foundation for multiple modules, including board
 *     display, updates, attack handling, and ship placement.
 ******************************************************************************/

#pragma once

#include <vector>
#include <string>

 /*----------------------------------------------------------
     Board Configuration Constants
     Defines supported board sizes and the symbols used to
     represent different board states.
 ----------------------------------------------------------*/
const int MIN_BOARD_SIZE = 10;
const int MID_BOARD_SIZE = 15;
const int MAX_BOARD_SIZE = 20;

const char WATER_SYMBOL = '~';
const char HIT_SYMBOL = 'X';
const char MISS_SYMBOL = 'O';
const char SUNK_SYMBOL = '#';

/*----------------------------------------------------------
    Ship Structure
    Represents a single ship, including its identity,
    size, remaining health, and sunk status.
----------------------------------------------------------*/
struct Ship
{
    std::string name;
    char symbol;
    int size;
    int health;
    bool isSunk = false;
};

/*----------------------------------------------------------
    Player Structure
    Stores all relevant game data for a player, including
    their own board, tracking board, and ship list.
----------------------------------------------------------*/
struct Player
{
    std::string name;
    int boardSize = MIN_BOARD_SIZE;
    std::vector<std::vector<char>> ownBoard;
    std::vector<std::vector<char>> trackingBoard;
    std::vector<Ship> ships;
};

/*----------------------------------------------------------
    Function Prototypes
----------------------------------------------------------*/

/**
 * Creates a square game board and initializes all cells
 * with the default water symbol.
 *
 * @param boardSize The number of rows and columns.
 * @return A fully initialized 2D board.
 */
std::vector<std::vector<char>> createBoard(int boardSize);

/**
 * Initializes a player's name, board size, and both boards.
 * Also clears any existing ship data.
 *
 * @param player Reference to the player being initialized.
 * @param name The player's name.
 * @param boardSize The selected board size.
 */
void initializePlayer(Player& player, const std::string& name, int boardSize);

/**
 * Validates whether a given coordinate is within the board bounds.
 *
 * @param row The row index.
 * @param col The column index.
 * @param boardSize The current board size.
 * @return True if valid, otherwise false.
 */
bool isValidCoordinate(int row, int col, int boardSize);

/**
 * Checks if a board cell represents part of a ship.
 *
 * @param cell The character stored in the board.
 * @return True if the cell contains a ship segment.
 */
bool isShipSymbol(char cell);