/******************************************************************************
 * File: updateBoards.h
 * Project: CSCN71030 Team Project - Battleship
 * Author: Jacob Stekelenburg
 * Date: March 2026
 * Description:
 *     Declares the functions used to update player boards after attacks
 *     and ability usage.
 *
 * Notes:
 *     This module handles hits, misses, and sunk ship states while
 *     preserving valid board data.
 ******************************************************************************/

#pragma once

#include "helper.h"

 /**
  * Updates both the defender's board and the attacker's tracking board
  * after a standard attack.
  *
  * @param defender The player being attacked.
  * @param attacker The player performing the attack.
  * @param row The target row.
  * @param col The target column.
  * @return True if the attack was a hit, otherwise false.
  */
bool updateBoardAfterAttack(Player& defender, Player& attacker, int row, int col);

/**
 * Marks the matching ship in the defender's ship list as sunk.
 *
 * @param defender The defending player.
 * @param shipSymbol The symbol of the ship that was destroyed.
 */
void markShipAsSunk(Player& defender, char shipSymbol);

/**
 * Updates both boards after an ability affects a specific location.
 *
 * @param defender The affected player.
 * @param attacker The player using the ability.
 * @param row The affected row.
 * @param col The affected column.
 * @param resultSymbol The symbol to apply at that location.
 */
void updateBoardsAfterAbility(Player& defender, Player& attacker, int row, int col, char resultSymbol);