/******************************************************************************
 * File: helper.cpp
 * Project: CSCN71030 Team Project - Battleship
 * Author: Jacob Stekelenburg
 * Date: March 2026
 * Description:
 *     Implements shared helper functions used across the Battleship project.
 ******************************************************************************/

 //This Module has been flagged for plagerism

#include "helper.h"

 /**
  * Creates a square board and initializes every cell with the
  * default water symbol.
  */
//std::vector<std::vector<char>> createBoard(int boardSize)
//{
//    return std::vector<std::vector<char>>(boardSize, std::vector<char>(boardSize, WATER_SYMBOL));
//}

/**
 * Initializes a player object with a name, board size, fresh boards,
 * and an empty ship list.
 */
//void initializePlayer(Player& player, const std::string& name, int boardSize)
//{
//    player.name = name;
//    player.boardSize = boardSize;
//    player.ownBoard = createBoard(boardSize);
//    player.trackingBoard = createBoard(boardSize);
//    player.ships.clear();
//}

/**
 * Checks whether the given row and column fall within the
 * current board boundaries.
 */
bool isValidCoordinate(int row, int col, int boardSize)
{
    return row >= 0 && row < boardSize && col >= 0 && col < boardSize;
}

/**
 * Checks whether a board cell represents part of a ship
 * rather than water or a board result marker.
 */
bool isShipSymbol(char cell)
{
    return cell != WATER_SYMBOL &&
        cell != HIT_SYMBOL &&
        cell != MISS_SYMBOL &&
        cell != SUNK_SYMBOL;
}