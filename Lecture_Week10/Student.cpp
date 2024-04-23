#include "Student.h"
//function definition file for student class 

int Student::studentIDCounter = 0;

Student::Student(string newName) {
	studentName = newName;
	studentIDCounter += 1;
	studentID = studentIDCounter;
	noOfUnits = 0;
}

Student::~Student() {

}

int Student::getStudentID() {
	return studentID;
}

int Student::getNoOfUnits() {
	return noOfUnits;
}

string Student::getStudentName() {
	return studentName;
}

void Student::addUnit(Unit* newUnit) {
	if (getNoOfUnits() < 4) {
		studUnits[getNoOfUnits()] = newUnit;
	}

	noOfUnits++;
}

string Student::getStudentDetails() {
	stringstream D;
	D << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	D << "\nName : " << getStudentName();
	D << "\nID : " << getStudentID();
	D << "\n\nList Of Units : ";
	for (int i = 0; i < noOfUnits; i++)
	{
		D<< "\n" << studUnits[i]->getUnitDetails();
	}
	D << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	return D.str();
}