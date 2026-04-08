/*

/******************************************************************************
 * File: display.h
 * Project: CSCN71030 Team Project - Battleship
 * Author: Jacob Stekelenburg
 * Date: April 2026
 * Description:
 *     Contains function declarations for displaying Battleship boards to the
 *     console, including a single board, both player boards, and an opponent
 *     board with hidden ship positions.
 *
 * References:
 *     "std::vector." cppreference.com,
 *     https://en.cppreference.com/w/cpp/container/vector.html.
 ******************************************************************************/

#pragma once

#include "helper.h"

 /**
  * Prints one board to the console.
  *
  * @param board The board to display.
  * @param hideShips True if ship positions should be hidden from view.
  */
void displaySingleBoard(const Board& board, bool hideShips);

/**
 * Prints the player's own board and tracking board.
 *
 * @param player The player whose boards will be displayed.
 */
void displayPlayerBoards(const Player& player);

/**
 * Prints an opponent board without showing ship locations.
 *
 * @param player The player whose opponent-facing board will be displayed.
 */
void displayOpponentBoard(const Player& player);
