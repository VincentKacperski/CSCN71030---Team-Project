#pragma once

#include <string>
#include <vector>

// Shared board type used across the board-related modules.
using Board = std::vector<std::vector<char>>;

// Supported board sizes.
const int MIN_BOARD_SIZE = 10;
const int MID_BOARD_SIZE = 15;
const int MAX_BOARD_SIZE = 20;

// Symbols used on the game boards.
const char WATER_SYMBOL = '~';
const char HIT_SYMBOL = 'X';
const char MISS_SYMBOL = 'O';
const char SUNK_SYMBOL = '#';

struct Ship
{
    std::string name;
    char symbol;
    int size;
    int health;
    bool isSunk = false;
};

struct Player
{
    std::string name;
    int boardSize = MIN_BOARD_SIZE;
    Board ownBoard;
    Board trackingBoard;
    std::vector<Ship> ships;
};

Board createBoard(int boardSize);

void initializePlayer(Player& player, const std::string& name, int boardSize);

bool isValidCoordinate(int row, int col, int boardSize);

bool isShipSymbol(char cell);