#include <iostream>
#include "attack.h"
#include "Base.h"
#include "updateBoards.h"

//Add your code here

bool hit;

void requestAttack(UserData& user, GameData* data) {
	int x;
	int y;
	int selected;
	std::cout << user.getNickname() << "\n";
	std::cout << "Which Player would you like to attack? (1-" << data->getPlayers() << ")\n";
	std::cin >> selected;
	std::cout << "\nEnter attack coordinates (x y): ";
	std::cin >> x >> y;
	checkAttack(&user, x, y, selected);
}

void checkAttack(UserData* user, int x, int y, int selected) {
	std::cout << "Do you want to attack at (" << x << ", " << y << ")? (y/n): ";
	char choice;
	std::cin >> choice;
	if (choice == 'y' || choice == 'Y') {
		std::cout << "Attack confirmed at (" << x << ", " << y << ")." << std::endl;
		//checkHit(*user, x, y);
		updateBoardAfterAttack(user[selected-1], *user, x, y);
	} else {
		std::cout << "Attack cancelled." << std::endl;
		//requestAttack(*user);
	}
}

void setResult(bool hit) {
	if (hit) {
		std::cout << "It's a hit." << std::endl;
	} else {
		std::cout << "It's a miss." << std::endl;
	}
}
