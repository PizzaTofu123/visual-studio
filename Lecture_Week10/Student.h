#ifndef STUDENT_H
#define STUDENT_H
using namespace std;
#include <string>
#include <sstream>

#include "Unit.h"



class Student 
{
private:
	static int studentIDCounter;
	string studentName;
	int studentID;
	int noOfUnits;
	
	Unit* studUnits[4];
public:
	Student(string);
	~Student();

	string getStudentName();
	int getStudentID();
	int getNoOfUnits();

	void addUnit(Unit*);

	string getStudentDetails();

};


#endif // !STUDENT_H

