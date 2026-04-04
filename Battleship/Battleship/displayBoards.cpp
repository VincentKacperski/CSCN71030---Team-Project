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