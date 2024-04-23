#include "Student.h"

int Student::idCounter = 9999;

Student::Student(string newName, int newAge) : Person(newName, newAge) {
	idCounter++;
	setID(idCounter);
}

Student::~Student(){}

void Student::setID(int newID) {
	if (idCounter > 9999){ studentID = newID; }
}

string Student::getInformation() {
	stringstream d;
	d << Person::getInformation();
	d << "\nType : Student";
	d << "\nStudent id : " << studentID;
	d << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	return d.str();
}