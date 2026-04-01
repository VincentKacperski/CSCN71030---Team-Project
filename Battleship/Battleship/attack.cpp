#include <iostream>
#include "attack.h"

//Add your code here

class Attack {
private:
	int x;
	int y;
	bool hit;

public:
	void requestAttack() {
		std::cout << "Enter attack coordinates (x y): ";
		std::cin >> x >> y;
		
	
	}
	void setAttack(int x, int y) {
		this->x = x;
		this->y = y;
	}

	void checkAttack() {
		std::cout << "Do you want to attack at (" << x << ", " << y << ")? (y/n): ";
		char choice;
		std::cin >> choice;
		if (choice == 'y' || choice == 'Y') {
			std::cout << "Attack confirmed at (" << x << ", " << y << ")." << std::endl;
			checkHit(x, y);
		} else {
			std::cout << "Attack cancelled." << std::endl;
		}
	}

	void setResult(bool hit) {
		if (hit) {
			std::cout << "It's a hit!" << std::endl;
		} else {
			std::cout << "It's a miss." << std::endl;
		}
	}
};