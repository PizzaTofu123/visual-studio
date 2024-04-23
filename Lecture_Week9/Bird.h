#ifndef BIRD_H
#define BIRD_H
#include "Animal.h"

class Bird : public Animal {
private : 
	bool hasWings;
	bool canFLy;


public : 
	Bird(string, Species, int , Colours, bool, bool);



	string getAllDetails();

};



#endif BIRD_H
