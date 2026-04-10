#include <iostream>
#include <vector>
#include "shipChecking.h"

// Initializes the player's own board and tracking board.
void initializeBoards(UserData& user, int boardSize)
{
    std::vector<std::vector<char>> ownBoard(boardSize, std::vector<char>(boardSize, '~'));
    std::vector<std::vector<char>> trackingBoard(boardSize, std::vector<char>(boardSize, '~'));

    user.storeOwnBoard(ownBoard);
    user.storeTrackingBoard(trackingBoard);
}

// Places a ship on the player's own board if the position is valid.
bool placeShips(UserData& user, int x, int y, int orientation, int size, char symbol)
{
    std::vector<std::vector<char>> board = user.getOwnBoard();

    if (board.empty())
    {
        return false;
    }

    int boardSize = static_cast<int>(board.size());

    if (x < 0 || x >= boardSize || y < 0 || y >= boardSize)
    {
        return false;
    }

    if (orientation == 1)
    {
        if (y + size > boardSize)
        {
            return false;
        }

        for (int i = 0; i < size; i++)
        {
            if (board[x][y + i] != '~')
            {
                return false;
            }
        }

        for (int i = 0; i < size; i++)
        {
            board[x][y + i] = symbol;
        }
    }
    else if (orientation == 2)
    {
        if (x + size > boardSize)
        {
            return false;
        }

        for (int i = 0; i < size; i++)
        {
            if (board[x + i][y] != '~')
            {
                return false;
            }
        }

        for (int i = 0; i < size; i++)
        {
            board[x + i][y] = symbol;
        }
    }
    else
    {
        return false;
    }

    user.storeOwnBoard(board);
    return true;
}

// Checks if the selected location is a hit or miss.
bool checkHit(UserData& defender, int x, int y)
{
    std::vector<std::vector<char>> board = defender.getOwnBoard();

    if (board.empty())
    {
        return false;
    }

    int boardSize = static_cast<int>(board.size());

    if (x < 0 || x >= boardSize || y < 0 || y >= boardSize)
    {
        return false;
    }

    char& cell = board[x][y];

    if (cell == 'X' || cell == 'O' || cell == '#')
    {
        return false;
    }

    if (cell != '~')
    {
        cell = 'X';
        defender.storeOwnBoard(board);
        return true;
    }

    cell = 'O';
    defender.storeOwnBoard(board);
    return false;
}