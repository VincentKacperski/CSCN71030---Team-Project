#include <iostream>
#include "destroyer.h"
#include "Base.h"

//Add your code here

//void useAbility5(Ship& ship, Board& board) {
//	int newX, newY;
//
//	while (true) {
//		std::cout << "Enter new position (x y) ";
//		std::cin >> newX >> newY;
//
//		if (!board.isValidPosition(newX, newY)) {
//			std::cout << "Invalid location: Out of Bounds\n";
//			continue;
//		}
//
//		if (board.isTargeted(newX, newY)) {
//			std::cout << "Invalid location: This position has already been targeted\n";
//			continue;
//		}
//		break;
//	}
//
//	ship.x = newX;
//	ship.y = newY;
//	ship.abilityUsed = true;
//
//	detectMovement(ship);
//	std::cout << "Ability used and the ship has been moved!\n";
//}