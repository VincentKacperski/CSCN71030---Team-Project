/******************************************************************************
 * File: displayBoards.h
 * Project: CSCN71030 Team Project - Battleship
 * Author: Jacob Stekelenburg
 * Date: March 2026
 * Description:
 *     Declares the functions used to display player boards during gameplay.
 *
 * Notes:
 *     This module supports different board sizes and can hide ship positions
 *     when displaying an opponent's board.
 ******************************************************************************/

#pragma once

#include "helper.h"

 /**
  * Displays a single board to the console.
  *
  * @param board The board to display.
  * @param hideShips If true, ship positions are hidden from view.
  */
void displaySingleBoard(const std::vector<std::vector<char>>& board, bool hideShips);

/**
 * Displays both the player's own board and their tracking board.
 *
 * @param player The player whose boards are being displayed.
 */
void displayPlayerBoards(const Player& player);

/**
 * Displays a player's board with ship positions hidden.
 * This is mainly used when showing an opponent's board during gameplay.
 *
 * @param player The player whose board is being displayed.
 */
void displayOpponentBoard(const Player& player);