#ifndef UNIT_H
#define UNIT_H
#include <sstream>
#include <string>
using namespace std;

class Unit {
private:
	static int unitCounter;

	string unitName;
	string unitCode;

public:
	Unit(string, string);
	
	~Unit();

	void setUnitCode(string);

	string getUnitName();
	string getUnitCode();
	

	string getUnitDetails();

	static int getNoOfUnit();

};







#endif UNIT_H

