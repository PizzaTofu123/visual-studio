#include "Person.h"


Person::Person() {
	setPersonHeight(0.0);
	setPersonName("");
}

Person::Person(string newName, float newHeight) {
	setPersonName(newName);
	setPersonHeight(newHeight);
}

Person::~Person(){}

string Person::getPersonName() {
	return name;
}

float Person::getPersonHeight() {
	return height;
}

void Person::setPersonHeight(float newHeight) {
	height = newHeight;
}

void Person::setPersonName(string newName) {
	name = newName;
}

void Person::addAPet(Pet aNewPet) {
	petLists.push_back(aNewPet);
}

int Person::removeAPet(int petIndex) {
	vector<Pet>::iterator iter1 = petLists.begin();
	petLists.erase(iter1 + petIndex);
	return 0;
}



string Person::getPersonDetails(){
	stringstream personDetails;
	int vecSize = petLists.size();

	personDetails << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	personDetails << "\n\t Name: " << getPersonName();
	personDetails << "\n\t Height: " << getPersonHeight() << " cm";
	personDetails << "\n\t Pet: ";

	for (int i = 0; i < vecSize; i++) {
		personDetails << "\n\t Pet : " << i + 1;
		personDetails << petLists[i].getAllPetDetails();
	}

	personDetails << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	return personDetails.str();
}