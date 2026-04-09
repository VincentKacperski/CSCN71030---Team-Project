#include <iostream>
#include "attack.h"

//Add your code here

bool hit;


void requestAttack() {
	int x;
	int y;
	std::cout << "Enter attack coordinates (x y): ";
	std::cin >> x >> y;
	checkAttack(x, y);
		
	
}

void checkAttack(int x, int y) {
	std::cout << "Do you want to attack at (" << x << ", " << y << ")? (y/n): ";
	char choice;
	std::cin >> choice;
	if (choice == 'y' || choice == 'Y') {
		std::cout << "Attack confirmed at (" << x << ", " << y << ")." << std::endl;
		checkHit(x, y);
	} else {
		std::cout << "Attack cancelled." << std::endl;
		requestAttack();
	}
}

void setResult(bool hit) {
	if (hit) {
		std::cout << "It's a hit." << std::endl;
	} else {
		std::cout << "It's a miss." << std::endl;
	}
}
