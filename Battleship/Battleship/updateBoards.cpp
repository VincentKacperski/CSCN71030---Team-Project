/******************************************************************************
 * File: updateBoards.cpp
 * Project: CSCN71030 Team Project - Battleship
 * Author: Jacob Stekelenburg
 * Date: March 2026
 * Description:
 *     Implements logic for updating boards after attacks and abilities.
 ******************************************************************************/

#include "updateBoards.h"

 /**
  * Checks whether any remaining cells of a ship symbol still exist
  * on the defender's board.
  *
  * @param board The defender's board.
  * @param shipSymbol The symbol of the ship being checked.
  * @return True if the ship has been fully destroyed, otherwise false.
  */
static bool isShipFullyDestroyed(const std::vector<std::vector<char>>& board, char shipSymbol)
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

/**
 * Replaces all hit cells of a sunk ship with the sunk symbol.
 *
 * @param board The board being updated.
 * @param shipSymbol The original symbol of the sunk ship.
 */
static void replaceSunkShipCells(std::vector<std::vector<char>>& board, char shipSymbol)
{
    for (int row = 0; row < static_cast<int>(board.size()); row++)
    {
        for (int col = 0; col < static_cast<int>(board[row].size()); col++)
        {
            if (board[row][col] == HIT_SYMBOL)
            {
                // Leave existing hit markers unchanged unless the team later
                // decides to track ship identity separately.
            }
        }
    }
}

/**
 * Marks the ship with the given symbol as sunk in the defender's ship list.
 */
void markShipAsSunk(Player& defender, char shipSymbol)
{
    for (int i = 0; i < static_cast<int>(defender.ships.size()); i++)
    {
        if (defender.ships[i].symbol == shipSymbol)
        {
            defender.ships[i].isSunk = true;
            defender.ships[i].health = 0;
        }
    }

    replaceSunkShipCells(defender.ownBoard, shipSymbol);
}

/**
 * Updates the defender's board and the attacker's tracking board after an attack.
 * Returns true if the attack hit a ship and false if it missed or was invalid.
 */
bool updateBoardAfterAttack(Player& defender, Player& attacker, int row, int col)
{
    if (!isValidCoordinate(row, col, defender.boardSize))
    {
        return false;
    }

    char& defenderCell = defender.ownBoard[row][col];
    char& attackerCell = attacker.trackingBoard[row][col];

    if (defenderCell == HIT_SYMBOL || defenderCell == MISS_SYMBOL || defenderCell == SUNK_SYMBOL)
    {
        return false;
    }

    if (isShipSymbol(defenderCell))
    {
        char hitShipSymbol = defenderCell;

        defenderCell = HIT_SYMBOL;
        attackerCell = HIT_SYMBOL;

        for (int i = 0; i < static_cast<int>(defender.ships.size()); i++)
        {
            if (defender.ships[i].symbol == hitShipSymbol)
            {
                defender.ships[i].health--;
            }
        }

        if (isShipFullyDestroyed(defender.ownBoard, hitShipSymbol))
        {
            markShipAsSunk(defender, hitShipSymbol);
        }

        return true;
    }

    defenderCell = MISS_SYMBOL;
    attackerCell = MISS_SYMBOL;
    return false;
}

/**
 * Applies an ability result to both the defender's board and
 * the attacker's tracking board.
 */
void updateBoardsAfterAbility(Player& defender, Player& attacker, int row, int col, char resultSymbol)
{
    if (!isValidCoordinate(row, col, defender.boardSize))
    {
        return;
    }

    defender.ownBoard[row][col] = resultSymbol;
    attacker.trackingBoard[row][col] = resultSymbol;
}