#include"Person.h"

Person::Person(string newName, int newAge) {
	setName(newName);
	setAge(newAge);
}

Person::~Person(){}

void Person::setName(string newName) {
	if (newName.size() > 1) {
		name = newName;
	}
}

void Person::setAge(int newAge) {
	if (newAge> 0) {
		age = newAge;
	}
}

string Person::getInformation() {
	stringstream d;
	d << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	d << "\nName : " << name;
	d << "\nAge : " << age;
	d << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	return d.str();
}