/******************************************************************************
 * File: updateBoards.cpp
 * Project: CSCN71030 Team Project - Battleship
 * Author: Jacob Stekelenburg
 * Date: April 2026
 * Description:
 *     Implements the board update functions for the Battleship project.
 *     This file handles standard attacks and applies ability results to both
 *     player boards.
 *
 * References:
 *     "std::vector." cppreference.com,
 *     https://en.cppreference.com/w/cpp/container/vector.html.
 ******************************************************************************/

#include "updateBoards.h"

 /**
  * Handles a standard attack and updates both the defender board and the
  * attacker's tracking board.
  *
  * @param defender The player being attacked.
  * @param attacker The player making the attack.
  * @param row The target row on the board.
  * @param col The target column on the board.
  * @return True if the attack was a hit, otherwise false.
  */
  // Handles a standard attack and updates both the defender board
  // and the attacker's tracking board.
bool updateBoardAfterAttack(UserData& defender, UserData& attacker, int row, int col)
{
    std::vector<std::vector<char>> defenderBoard = defender.getOwnBoard();
    std::vector<std::vector<char>> attackerBoard = attacker.getTrackingBoard();

    if (defenderBoard.empty() || attackerBoard.empty())
    {
        return false;
    }

    int boardSize = static_cast<int>(defenderBoard.size());

    if (row < 0 || row >= boardSize || col < 0 || col >= boardSize)
    {
        return false;
    }

    char& defenderCell = defenderBoard[row][col];
    char& attackerCell = attackerBoard[row][col];

    // Ignore cells that were already attacked before.
    if (defenderCell == 'X' || defenderCell == 'O' || defenderCell == '#')
    {
        return false;
    }

    // Any non-water cell counts as a hit.
    if (defenderCell != '~')
    {
        defenderCell = 'X';
        attackerCell = 'X';

        defender.storeOwnBoard(defenderBoard);
        attacker.storeTrackingBoard(attackerBoard);
        return true;
    }

    defenderCell = 'O';
    attackerCell = 'O';

    defender.storeOwnBoard(defenderBoard);
    attacker.storeTrackingBoard(attackerBoard);
    return false;
}

/**
 * Applies an ability result directly to both boards.
 *
 * @param defender The player affected by the ability.
 * @param attacker The player using the ability.
 * @param row The target row on the board.
 * @param col The target column on the board.
 * @param resultSymbol The symbol to place on both boards.
 */
 // Applies an ability result directly to both boards.
void updateBoardsAfterAbility(UserData& defender, UserData& attacker, int row, int col, char resultSymbol)
{
    std::vector<std::vector<char>> defenderBoard = defender.getOwnBoard();
    std::vector<std::vector<char>> attackerBoard = attacker.getTrackingBoard();

    if (defenderBoard.empty() || attackerBoard.empty())
    {
        return;
    }

    int boardSize = static_cast<int>(defenderBoard.size());

    if (row < 0 || row >= boardSize || col < 0 || col >= boardSize)
    {
        return;
    }

    defenderBoard[row][col] = resultSymbol;
    attackerBoard[row][col] = resultSymbol;

    defender.storeOwnBoard(defenderBoard);
    attacker.storeTrackingBoard(attackerBoard);
}