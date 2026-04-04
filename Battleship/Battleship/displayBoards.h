#pragma once

#include "helper.h"

// Prints one board to the console.
// hideShips is used when showing an opponent board.
void displaySingleBoard(const Board& board, bool hideShips);

// Prints the player's own board and tracking board.
void displayPlayerBoards(const Player& player);

// Prints an opponent board without showing ship locations.
void displayOpponentBoard(const Player& player);