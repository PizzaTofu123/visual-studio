#ifndef STUDENT_H
#define STUDENT_H
#include "Person.h"


class Student:public Person {
private:
	static int idCounter;
	int studentID;

	void setID(int);
public:
	Student(string, int );
	~Student();


	string getInformation();
};




#endif // !STUDENT_H

