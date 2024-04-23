#include "Unit.h"

int Unit::unitCounter = 0;


Unit::Unit(string newName, string newCode) {
	unitCounter++;
	unitName = newName;
	setUnitCode(newCode);
}

Unit::~Unit(){
	unitCounter--;
}

void Unit::setUnitCode(string newCode) {
	if (newCode.size() == 7) {
		unitCode = newCode;
	}
}

string Unit::getUnitCode() { return unitCode; }

string Unit::getUnitName() { return unitName; }

string Unit::getUnitDetails() {
	stringstream D;
	D << "\n---------------------------------------------";
	D << "\nUnit Details";
	D << "\n---------------------------------------------";
	D << "\nUnit Name : " << getUnitName();
	D << "\nUnit Code : " << getUnitCode();
	D << "\n---------------------------------------------";

	return D.str();
}

int Unit::getNoOfUnit() {
	return unitCounter;
}