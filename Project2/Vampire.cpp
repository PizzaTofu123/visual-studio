#include "Vampire.h"

int Vampire::numVampires = 0;

Vampire::Vampire(string newName, int newHealth) : Monster(newName, newHealth) {
	numVampires++;
}

Vampire::~Vampire() {
	numVampires--;
}

int Vampire::getNumVampires() { return numVampires; }

string Vampire::speak() {
	return "Me is want ur blood plz";
}

string Vampire::attack() {
	return "he do be sucking ur blood";
}
