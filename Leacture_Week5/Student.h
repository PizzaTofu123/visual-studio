/*
Desc : class header for file class 
*/



#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {

	//class attributes/ data members
	//represent data about objects
private:
	std::string firstName;
	std::string lastName;

public:
	//member function,representing functionality for objects
	//constructor has same name as class, it is to create an object of the student class
	//default cons
	Student();
	//overload cons
	Student(std::string, std::string);
	//destructor use tilda, take series of action that you deifne when the object is going to be destroyed
	~Student();

	//get or accessor functions
	std::string getFirstName();
	std::string getLastName();

	//helper function // utility
	std::string getFullName();

	//mutator/set/setter function
	void setFirstName(std::string);
	void setLastName(std::string);


};

#endif
