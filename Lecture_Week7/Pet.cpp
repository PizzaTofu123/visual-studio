#include "Pet.h"

Pet::Pet() {
	setPetColour("");
	setPetName("");
	setPetType("");
}

Pet::Pet(string newName,string newType,string newColour) {
	setPetColour(newColour);
	setPetName(newName);
	setPetType(newType);
}

Pet::~Pet(){}

string Pet::getPetColour() {
	return petColour;
}

string Pet::getPetName() {
	return petName;
}

string Pet::getPetType() {
	return petType;
}

PetRating Pet::getRating() {
	return rating;
}

void Pet::setPetColour(string newColour) {
	petColour = newColour;
}

void Pet::setPetName(string newName) {
	petName = newName;
}

void Pet::setPetType(string newType) {
	petType = newType;
}

void Pet::setRating(PetRating newRating) {
	rating = newRating;
}

string Pet::getAllPetDetails() {
	stringstream ssPetDetails;
	ssPetDetails << "\nName :" << getPetName();
	ssPetDetails << "\nColour :" << getPetColour();
	ssPetDetails << "\nType :" << getPetType();
	ssPetDetails << "\nRating :" << getNameForRating();
	return ssPetDetails.str();
}

string Pet::getNameForRating() {
	switch (rating)
	{
	case Wild:
		return "Wild";
		break;
	case Normal:
		return "Normal";
		break;
	case Tame:
		return "Tame";
		break;
	default:
		break;
	}
}