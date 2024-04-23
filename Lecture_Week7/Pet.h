#ifndef PET_H
#define PET_H

#include <string>
#include <sstream>
#include "Enums.h"
using namespace std;

class Pet {
private:
	string petName;
	string petColour;
	string petType;
	PetRating rating;

public:
	//constructors 
	Pet();
	Pet(string, string, string);

	//destructors 
	~Pet();

	//getters/get functions/ accessors
	string getPetName();
	string getPetColour();
	string getPetType();
	PetRating getRating();

	//setters/set functions/ mutatos
	void setPetName(string);
	void setPetColour(string);
	void setPetType(string);
	void setRating(PetRating);


	//utility function
	string getAllPetDetails();

	string getNameForRating();

};
#endif
