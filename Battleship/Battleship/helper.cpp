/******************************************************************************
 * File: helper.cpp
 * Project: CSCN71030 Team Project - Battleship
 * Author: Jacob Stekelenburg
 * Date: April 2026
 * Description:
 *     Implements shared helper functions used by the board-related modules of
 *     the Battleship project.
 *
 * References:
 *     "std::vector." cppreference.com,
 *     https://en.cppreference.com/w/cpp/container/vector.html.
 ******************************************************************************/

#include "helper.h"

 /**
  * Creates a square board and fills it with water symbols.
  *
  * @param boardSize The number of rows and columns in the board.
  * @return A 2D board initialized with WATER_SYMBOL.
  */
Board createBoard(int boardSize)
{
    Board board(boardSize, std::vector<char>(boardSize, WATER_SYMBOL));
    return board;
}

/**
 * Sets up a player with a name, board size, empty boards, and no ships.
 *
 * @param player The player being initialized.
 * @param name The player's display name.
 * @param boardSize The selected board size.
 */
void initializePlayer(Player& player, const std::string& name, int boardSize)
{
    player.name = name;
    player.boardSize = boardSize;
    player.ownBoard = createBoard(boardSize);
    player.trackingBoard = createBoard(boardSize);
    player.ships.clear();
}

/**
 * Checks if a row and column are inside the board limits.
 *
 * @param row The row to check.
 * @param col The column to check.
 * @param boardSize The current size of the board.
 * @return True if the coordinate is valid, otherwise false.
 */
bool isValidCoordinate(int row, int col, int boardSize)
{
    return row >= 0 && row < boardSize && col >= 0 && col < boardSize;
}

/**
 * Checks if the cell contains a ship instead of water or a result marker.
 *
 * @param cell The character stored in the board cell.
 * @return True if the cell is a ship symbol, otherwise false.
 */
bool isShipSymbol(char cell)
{
    return cell != WATER_SYMBOL &&
        cell != HIT_SYMBOL &&
        cell != MISS_SYMBOL &&
        cell != SUNK_SYMBOL;
}