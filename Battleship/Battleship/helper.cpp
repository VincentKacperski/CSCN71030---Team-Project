#include "helper.h"

// Creates a square board and fills it with water symbols.
Board createBoard(int boardSize)
{
    Board board(boardSize, std::vector<char>(boardSize, WATER_SYMBOL));
    return board;
}