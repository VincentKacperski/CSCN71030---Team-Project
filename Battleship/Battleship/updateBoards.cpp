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