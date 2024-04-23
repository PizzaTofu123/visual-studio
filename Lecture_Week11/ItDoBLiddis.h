#ifndef ITDOBLIDDIS_H //func file
#define ITDOBLIDDIS_H

#include <iostream>
#include "Person.h"
#include "Student.h"
#include "Teacher.h"
#include <vector>
using namespace std;

void capturePersonData(int count, vector<Person*>& collection);
void displayData(vector<Person*>& collection);
void deleteCollection(vector<Person*>& collection);




#endif // !ITDOBLIDDIS_H

