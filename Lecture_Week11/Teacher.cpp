#include "Teacher.h"

int Teacher::staffIDCounter = 999;

Teacher::Teacher(string newName, int newAge, string newDepartment): Person(newName,newAge){
	staffIDCounter++;
	staffID = staffIDCounter;
	setDepartment(newDepartment);
}

Teacher::~Teacher(){}

void Teacher::setDepartment(string newDepartment) {
	if (newDepartment.size() > 2) {
		department = newDepartment;
	}
}

string Teacher::getInformation() {
	stringstream d;
	d << "\n============================================";
	d << "\nName : " << name;
	d << "\nAge : " << age;
	d << "\nTeacher ID : " << staffID;
	d << "\nTeacher Department : " << department;
	d << "\n============================================";
	return d.str();
}