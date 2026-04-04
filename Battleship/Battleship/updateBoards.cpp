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