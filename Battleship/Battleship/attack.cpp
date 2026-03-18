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
	void hit() {
		std::cout << "Attack at (" << x << ", " << y << ") was a " << (hit ? "hit!" : "miss!") << std::endl;
	}
	void setAttack(int x, int y) {
		this->x = x;
		this->y = y;
	}

	void printAttack() {
		std::cout << "Attack at (" << x << ", " << y << ")" << std::endl;
	}

	void setResult(bool hit) {
		this->hit = hit;
	}
};