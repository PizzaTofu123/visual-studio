#include <iostream>
#include <string>

#include "Pet.h"
#include "Person.h"
//#include "Person.h"



int main() {

	Pet pet1 ("Baba", "Black", "Rat");
	pet1.setRating(Wild);

	Person person1("Bigmen", 200);
	Person person2("Smolmen", 100);


	person1.addAPet(pet1);
	person1.removeAPet(0);
	cout << person1.getPersonDetails();
	person2.addAPet(pet1);
	cout << person2.getPersonDetails();
	cout << pet1.getAllPetDetails();
	cout << pet1.getRating();


	cout << endl;
	system("pause");
	return 0;
}