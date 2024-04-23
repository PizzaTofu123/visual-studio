#ifndef PERSON_H
#define PERSON_H

#include <sstream>
#include <string>
#include <vector>
using namespace std;
#include "Pet.h"

class Person {
private :
	string name;
	std::vector<Pet> petLists;
	float height;
public :
	Person();
	Person(string, float);
	~Person();
	

	string getPersonName();
	float getPersonHeight();

	void setPersonName(string);
	void setPersonHeight(float);

	string getPersonDetails();

	int removeAPet(int);
	void addAPet(Pet);
};

#endif 

