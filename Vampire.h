#ifndef VAMPIRE_H
#define VAMPIRE_H
#include "Monster.h"


class Vampire :public Monster {
private:
	static int numVampires;
public:
	Vampire(string, int);
	~Vampire();
	static int getNumVampires();
	string speak();
	string attack();

};





#endif // !VAMPIRE_H

