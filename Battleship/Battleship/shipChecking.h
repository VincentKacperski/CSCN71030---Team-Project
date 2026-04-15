#pragma once

#include "Base.h"

// Initializes the player's own board and tracking board.
void initializeBoards(UserData& user, int boardSize);

// Places a ship on the player's own board.
bool placeShips(UserData* user, int x, int y, int orientation, int size, char symbol);

// Checks whether an attack hits a ship on the defender's board.
bool checkHit(UserData& defender, int x, int y);