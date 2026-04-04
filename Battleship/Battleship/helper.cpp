#include "helper.h"

// Creates a square board and fills it with water symbols.
Board createBoard(int boardSize)
{
    Board board(boardSize, std::vector<char>(boardSize, WATER_SYMBOL));
    return board;
}

// Sets up a player with a name, board size, empty boards, and no ships.
void initializePlayer(Player& player, const std::string& name, int boardSize)
{
    player.name = name;
    player.boardSize = boardSize;
    player.ownBoard = createBoard(boardSize);
    player.trackingBoard = createBoard(boardSize);
    player.ships.clear();
}

// Checks if a row and column are inside the board limits.
bool isValidCoordinate(int row, int col, int boardSize)
{
    return row >= 0 && row < boardSize && col >= 0 && col < boardSize;
}