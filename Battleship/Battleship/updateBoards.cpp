/******************************************************************************
 * File: updateBoards.cpp
 * Project: CSCN71030 Team Project - Battleship
 * Author: Jacob Stekelenburg
 * Date: April 2026
 * Description:
 *     Implements the board update functions for the Battleship project.
 *     This file handles standard attacks, marks ships as sunk, checks whether
 *     a ship has been fully destroyed, and applies ability results to both
 *     player boards.
 *
 * References:
 *     "std::vector." cppreference.com,
 *     https://en.cppreference.com/w/cpp/container/vector.html.
 ******************************************************************************/

#include "updateBoards.h"

 // Checks if a ship symbol still exists anywhere on the board.
static bool isShipFullyDestroyed(const Board& board, char shipSymbol)
{
    for (int row = 0; row < static_cast<int>(board.size()); row++)
    {
        for (int col = 0; col < static_cast<int>(board[row].size()); col++)
        {
            if (board[row][col] == shipSymbol)
            {
                return false;
            }
        }
    }

    return true;
}

// Updates the matching ship in the defender's ship list to sunk.
void markShipAsSunk(Player& defender, char shipSymbol)
{
    for (int i = 0; i < static_cast<int>(defender.ships.size()); i++)
    {
        if (defender.ships[i].symbol == shipSymbol)
        {
            defender.ships[i].isSunk = true;
            defender.ships[i].health = 0;
            break;
        }
    }
}

// Handles a standard attack and updates both the defender board
// and the attacker's tracking board.
bool updateBoardAfterAttack(Player& defender, Player& attacker, int row, int col)
{
    if (!isValidCoordinate(row, col, defender.boardSize))
    {
        return false;
    }

    char& defenderCell = defender.ownBoard[row][col];
    char& attackerCell = attacker.trackingBoard[row][col];

    // Ignore cells that were already attacked before.
    if (defenderCell == HIT_SYMBOL || defenderCell == MISS_SYMBOL || defenderCell == SUNK_SYMBOL)
    {
        return false;
    }

    if (isShipSymbol(defenderCell))
    {
        char shipSymbol = defenderCell;

        defenderCell = HIT_SYMBOL;
        attackerCell = HIT_SYMBOL;

        for (int i = 0; i < static_cast<int>(defender.ships.size()); i++)
        {
            if (defender.ships[i].symbol == shipSymbol)
            {
                defender.ships[i].health--;
                break;
            }
        }

        if (isShipFullyDestroyed(defender.ownBoard, shipSymbol))
        {
            markShipAsSunk(defender, shipSymbol);
        }

        return true;
    }

    defenderCell = MISS_SYMBOL;
    attackerCell = MISS_SYMBOL;
    return false;
}

// Applies an ability result directly to both boards.
void updateBoardsAfterAbility(Player& defender, Player& attacker, int row, int col, char resultSymbol)
{
    if (!isValidCoordinate(row, col, defender.boardSize))
    {
        return;
    }

    defender.ownBoard[row][col] = resultSymbol;
    attacker.trackingBoard[row][col] = resultSymbol;
}