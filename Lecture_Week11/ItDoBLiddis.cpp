#include "ItDoBLiddis.h"

void capturePersonData(int temp, vector<Person*>& collection) {

	for (int i = 0; i < temp; i++) {
		string tempName;
		int tempAge;
		int tempType;
		cout << "\n For person " << i + 1;
		cout << "\ninput name plz : \n";
		cin >> tempName;
		cout << "\nEnter Type : (0:Person 1:Student 2:Teacher)\n";
		cin >> tempType;
		cout << "\ninput age plz : \n";
		cin >> tempAge;
		if (tempType == 0) { collection.push_back(new Person(tempName, tempAge)); }
		else if (tempType == 1) { collection.push_back(new Student(tempName, tempAge)); }
		else if (tempType == 2) {
			string dep;
			cout << "\ninput dep : \n";
			cin >> dep;
			collection.push_back(new Teacher(tempName, tempAge, dep));
		}
	}
}

void displayData(vector<Person*>& collection) {
	for (int i = 0; i < collection.size(); i++) {
		cout << collection[i]->getInformation();
	}
}

void deleteCollection(vector<Person*>& collection) {
	for (int i = 0; i < collection.size(); i++) {
		delete collection[i];
		collection[i] = NULL;
	}

	collection.clear();
}