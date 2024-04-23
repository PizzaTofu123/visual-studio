#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <sstream>
using namespace std;

class Person {
protected:
	string name;
	int age;

public:
	Person(string, int);
	~Person();

	void setName(string);
	void setAge(int);


	virtual string getInformation();


};



#endif // !PERSON_H

