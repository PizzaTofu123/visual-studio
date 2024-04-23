#include <iostream>
#include <string>
#include "Student.h"
#include <vector>
#include "Unit.h"
using namespace std;

int main() {
	int score = 69;
	int* pscore = &score;
	cout << pscore;
	/*cout << score << endl << pscore << endl << (*pscore); //score, addr of score, score
	cout << endl << &pscore; //addr of pscore */
	*pscore = *pscore + 4200;
	cout << endl << pscore << endl << score;
	pscore += 69;
	cout << endl << pscore;//changing the pointer addr


	cout << "\n\n\n";
	Student stud1("Toilet");
	Student stud2("Bathroom");

	Student* Spointer = NULL;
	Unit* Punit = new Unit("C++", "MCD6969");
	delete Punit;

	cout << "You have  :  " << Unit::getNoOfUnit() << " unit to enroll";

	/*cout << endl << stud1.getStudentDetails();
	cout << endl << stud2.getStudentDetails();

	cout << "\nStudent Details using pointer";

	Spointer = &stud2;

	cout << (*Spointer).getStudentDetails();

	Spointer = &stud1;

	cout << (*Spointer).getStudentDetails();*/



	//Student* studentP = new Student("a");

	vector<Student*> studList;

	for (int i = 0; i < 3; i++)
	{
		string tempName;
		cout << "\nPlz Enter the name 4 stud : ";
		cin >> tempName;

		studList.push_back(new Student(tempName));

	}

	for (int i = 0; i < studList.size(); i++)
	{
		studList[i]->addUnit(Punit);
		cout << (*studList[i]).getStudentDetails();  // or studList[i]->getStudentDetails();
	}

	for (int i = 0; i < studList.size(); i++)
	{
		delete studList[i];
		studList[i] = NULL;
	}

	studList.clear();

	cout << endl;
	system("pause");
	return 0;
}