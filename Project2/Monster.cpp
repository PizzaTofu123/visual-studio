#include "Monster.h"

int Monster::numMonsters = 0;
Monster::Monster() { numMonsters++; }

Monster::Monster(string newName, int newHealth) {
	monName = newName;
	monHealth = newHealth;
	numMonsters++;
}

Monster::~Monster() { numMonsters--; }

int Monster::getNumMonsters() { return numMonsters; }

string  Monster::getName() { return monName; }

int Monster::getHealth() { return monHealth; }

string Monster::speak() { return "Why hello there"; }

string Monster::attack() { return "Eat this fag!"; }
