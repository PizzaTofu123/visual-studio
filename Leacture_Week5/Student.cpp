/*
Description :
	This is the matching cpp file for student class
	It will contain the functionality definitions
	For student objects
*/

#include "Student.h"
/*
student constructor function 
*/

Student::Student() {
	getFirstName();
	getLastName();
}

Student::Student(std::string newFirstName, std::string newLastName) {
	firstName = newFirstName;
	lastName = newLastName;
}


Student::~Student() {
	//to b used later 
}


//get or accessor functions
std::string Student::getFirstName() {
	return firstName;
}
std::string Student::getLastName() {
	return lastName;
}

std::string Student::getFullName() {
	std::string fullName = getFirstName() + " " + getLastName();
	return fullName;
}

void Student::setFirstName(std::string newName) {
	firstName = newName;
}
void Student::setLastName(std::string newName) {
	lastName = newName;
}