#pragma once
#include "shipChecking.h"

void requestAttack(UserData& user, GameData* data);
void hitPrint();
void setAttack(int x, int y);
void checkAttack(UserData* user, int x, int y, int selected);
void setResult(bool hit);