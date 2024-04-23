#include "ItDoBLiddis.h"

int main() {

	/*vector<Person*> personList;

	cout << "How many people is u want?\n";
	int temp;
	cin >> temp;

	capturePersonData(temp, personList);
	displayData(personList);
	deleteCollection(personList);*/

	/*for (int i = 0; i < temp; i++) {
		string tempName;
		int tempAge;
		int tempType;
		cout << "\n For person " << i+1;
		cout << "\ninput name plz : \n";
		cin >> tempName;
		cout << "\nEnter Type : (0:Person 1:Student 2:Teacher)\n";
		cin >> tempType;
		cout << "\ninput age plz : \n";
		cin >> tempAge;
		if (tempType==0){ personList.push_back(new Person(tempName, tempAge)); }
		else if (tempType==1){ personList.push_back(new Student(tempName, tempAge)); }
		else if (tempType == 2) { 
			string dep;
			cout << "\ninput dep : \n";
			cin >> dep;
			personList.push_back(new Teacher(tempName, tempAge, dep)); }
	}

	for (int i = 0; i < personList.size(); i++) {
		cout<<personList[i]->getInformation();
	}

	for (int i = 0; i < personList.size(); i++) {
		delete personList[i];
		personList[i] = NULL;
	}

	personList.clear();*/

	Person* Pperson = new Person("BlackMale", 50);
	Student* Pstud = new Student("Monke", 69);
	Teacher* Pteach = new Teacher("Bababouille", 420, "UniversalEducation");

	Person* generalP = nullptr;

	generalP = static_cast<Person*>(Pperson);
	cout << endl << (*generalP).getInformation();

	/*Person person1("BlackMale", 50);
	Teacher teach1("Bababouille", 420, "UniversalEducation");
	Student stud1("Monke", 69);

	Person G = static_cast<Person>(teach1); //c this shit this shit needs stat cast like a bitch, pointers aint no bitch tho

	cout << G.getInformation();*/


	cout << endl;
	system("pause");
	return 0;
}

