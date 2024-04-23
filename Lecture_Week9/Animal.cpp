#include "Animal.h"


Animal::Animal() {
	setAnimalName("");
	setNoOfLegs(0);
	setAnimalColour(UnknownColour);
	setAnimalSpecies(Unknown);
}

Animal::Animal(string newName, Species newSpecies,int newNoOfLegs, Colours newColour) {
	setAnimalName(newName);
	setAnimalSpecies(newSpecies);
	setNoOfLegs(newNoOfLegs);
	setAnimalColour(newColour);
}

Animal::~Animal(){}

string Animal::getAnimalName() {
	return name;
}

int Animal::getNoOfLegs() {
	return noOfLegs;
}

Species Animal::getAnimalSpecies() {
	return species;
}

Colours Animal::getAnimalColour() {
	return colour;
}

void Animal::setAnimalColour(Colours newColour) {
	colour = newColour;
}

void Animal::setAnimalName(string newName) {
	name = newName;
}

void Animal::setAnimalSpecies(Species newSpecies) {
	species = newSpecies;
}

void Animal::setNoOfLegs(int newNoOfLegs) {
	noOfLegs = newNoOfLegs;
}

string Animal::getColourName() {
	switch (colour) {
	case UnknownColour:
		return "Unknown";
		break;
	case Red :
		return "Red";
		break;
	case Yellow:
		return "Yellow";
		break;
	case Green:
		return "Green";
		break;
	case Purple:
		return "Purple";
		break;
	default:
		return "Unknown";
		break;
	}
}

string Animal::getSpeciesName() {
	switch (species)
	{
	case Unknown:
		return "Unknown";
		break;
	case Mammals:
		return "Mammals";
		break;
	case Reptiles:
		return "Reptiles";
		break;
	case Amphibians:
		return "Amphibian";
		break;
	case Insects:
		return "Insect";
		break;
	default:
		return "Unknown";
		break;
	}
}

string Animal::getAllDetails() {
	stringstream details;
	details << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	details << "\n\t" << getAnimalName();
	details << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	details << "\n\tColour : " << getColourName();
	details << "\n\tNo of Legs : " << getNoOfLegs();
	details << "\n\tSpecies : " << getSpeciesName();
	details << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";

	return details.str();
}