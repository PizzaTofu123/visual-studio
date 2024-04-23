#ifndef ANIMAL_H
#define ANIMAL_H
#include <string>
#include <sstream>
#include "Enums.h"
using namespace std;


class Animal {
protected :
	string name;
	Species species;
	int noOfLegs;
	Colours colour;
public:
	Animal();
	Animal(string, Species, int, Colours);

	~Animal();

	string getAnimalName();
	Species getAnimalSpecies();
	int getNoOfLegs();
	Colours getAnimalColour();

	void setAnimalName(string);
	void setAnimalSpecies(Species);
	void setNoOfLegs(int);
	void setAnimalColour(Colours);




	string getColourName();
	string getSpeciesName();
	virtual string getAllDetails();//to let cpp know this hit gon get changed soon



};






#endif // !ANIMAL_H

