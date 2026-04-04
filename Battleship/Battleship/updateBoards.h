#pragma once

#include "helper.h"

// Handles a normal attack and updates both boards.
bool updateBoardAfterAttack(Player& defender, Player& attacker, int row, int col);

// Marks a ship as sunk using its symbol.
void markShipAsSunk(Player& defender, char shipSymbol);

// Applies an ability result to both boards.
void updateBoardsAfterAbility(Player& defender, Player& attacker, int row, int col, char resultSymbol);