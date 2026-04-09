/******************************************************************************
 * File: updateBoards.h
 * Project: CSCN71030 Team Project - Battleship
 * Author: Jacob Stekelenburg
 * Date: April 2026
 * Description:
 *     Contains function declarations for handling attacks and board updates
 *     in the Battleship project, including normal attacks and ability-based
 *     board updates.
 *
 * References:
 *     "std::vector." cppreference.com,
 *     https://en.cppreference.com/w/cpp/container/vector.html.
 ******************************************************************************/

#pragma once

#include "Base.h"

 // Handles a normal attack and updates both boards.
bool updateBoardAfterAttack(UserData& defender, UserData& attacker, int row, int col);

// Applies an ability result to both boards.
void updateBoardsAfterAbility(UserData& defender, UserData& attacker, int row, int col, char resultSymbol);