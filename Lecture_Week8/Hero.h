#ifndef HERO_H
#define HERO_H
#include <string>
#include <sstream>
#include <time.h>
#include "Enums.h"
using namespace std;



class Hero {
private :
	string name;
	int health;
	int power;
	HeroType hType;
public:
	Hero(string, HeroType);
	string getName();
	int getHealth();
	int getPower();
	HeroType getHType();


	void setName(string);
	void setHealth(int);
	void setPower(int);
	void setHType(HeroType);


	string getNameForHeroType();
	string getDetails();



};




#endif // !HERO_H

