#pragma once

struct User {
	std::string nickname;
	std::string username;
	int players = 0;
	int age = 0;
};

int testSave(int, User);
int userInput();

