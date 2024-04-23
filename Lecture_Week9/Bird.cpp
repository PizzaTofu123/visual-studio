#include "Bird.h"

Bird::Bird(string newName, Species newSpecies, int newNoOfLegs, Colours newColour, bool newHasWings, bool newCanFly) : Animal(newName, newSpecies, newNoOfLegs, newColour) {
		hasWings = newHasWings;
		canFLy = newCanFly;
}
string Bird::getAllDetails(){
	stringstream birdDetails;
	//birdDetails << Animal::getAllDetails();
	birdDetails << "\n--------------------------------------------";
	birdDetails << "\n\t" << getAnimalName();
	birdDetails << "\n--------------------------------------------";
	birdDetails << "\n\tColour : " << getColourName();
	birdDetails << "\n\tNo of Legs : " << getNoOfLegs();
	birdDetails << "\n\tSpecies : " << getSpeciesName();
	birdDetails << "\n\tFly Ability : ";
	if (canFLy == true) {
		birdDetails << "YES !";
	}
	else {
		birdDetails << "NO !";
	}
	birdDetails << "\n\tHas Wings : ";
	if (hasWings == true) {
		birdDetails << "YES !";
	}
	else {
		birdDetails << "NO !";
	}
	birdDetails << "\n--------------------------------------------";

	return birdDetails.str();

}