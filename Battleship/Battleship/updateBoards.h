/******************************************************************************
 * File: updateBoards.h
 * Project: CSCN71030 Team Project - Battleship
 * Author: Jacob Stekelenburg
 * Date: April 2026
 * Description:
 *     Contains function declarations for handling attacks and board updates
 *     in the Battleship project, including normal attacks, sunk ship handling,
 *     and ability-based board updates.
 *
 * References:
 *     "std::vector." cppreference.com,
 *     https://en.cppreference.com/w/cpp/container/vector.html.
 ******************************************************************************/

#pragma once

#include "helper.h"

 // Handles a normal attack and updates both boards.
bool updateBoardAfterAttack(Player& defender, Player& attacker, int row, int col);

// Marks a ship as sunk using its symbol.
void markShipAsSunk(Player& defender, char shipSymbol);

// Applies an ability result to both boards.
void updateBoardsAfterAbility(Player& defender, Player& attacker, int row, int col, char resultSymbol);