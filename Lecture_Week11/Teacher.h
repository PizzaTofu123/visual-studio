#ifndef TEACHER_H
#define TEACHER_H

#include "Person.h"


class Teacher:public Person{
private:
	static int staffIDCounter;
	int staffID;
	string department;

public:
	Teacher(string, int, string);
	~Teacher();

	void setDepartment(string);
	
	string getInformation();





};




#endif // !TEACHER_H

