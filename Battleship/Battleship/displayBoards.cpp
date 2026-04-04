#include <iostream>
#include <iomanip>
#include "displayBoards.h"

using namespace std;

// Prints the numbered column labels at the top of the board.
static void printColumnHeaders(int boardSize)
{
    cout << "   ";

    for (int col = 0; col < boardSize; col++)
    {
        cout << setw(3) << col + 1;
    }

    cout << endl;
}

// Displays a single board with optional hidden ship positions.
void displaySingleBoard(const Board& board, bool hideShips)
{
    int boardSize = static_cast<int>(board.size());

    printColumnHeaders(boardSize);

    for (int row = 0; row < boardSize; row++)
    {
        cout << setw(3) << row + 1;

        for (int col = 0; col < boardSize; col++)
        {
            char value = board[row][col];

            // If we are hiding ships, replace ship cells with water.
            if (hideShips && isShipSymbol(value))
            {
                value = WATER_SYMBOL;
            }

            cout << setw(3) << value;
        }

        cout << endl;
    }
}