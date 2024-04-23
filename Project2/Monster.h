#ifndef MONSTER_H
#define MONSTER_H
#include <iostream>
#include <string>
using namespace std;

class Monster {
protected:
	static int numMonsters;
	string monName;
	int monHealth;

public:
	Monster();
	Monster(string, int);
	~Monster();

	static int getNumMonsters();
	string getName();
	int getHealth();

	virtual string speak();
	virtual string attack();

};

#endif
