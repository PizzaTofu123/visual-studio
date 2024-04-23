
#include "Animal.h"
#include <iostream>
#include "Bird.h"

int main() {
	Animal animal1("Bababouille", Reptiles, 20, Purple);
	Bird bird1("Birb", Mammals, 21, Green, true, true);
	// Animal animal2 = bird 1 , Bird bird 2 = static_cast<bird>	
	cout << animal1.getAllDetails();
	cout << bird1.getAllDetails();
	
	Animal* animal2 = new Bird("HomelessTurtle", Unknown, 500, Red, true, true);
	cout << endl << animal2->getAllDetails();
	
	delete animal2;
	animal2 = NULL;

	animal2 = new Animal("LaLion", Mammals, 4, Yellow);
	cout << endl << animal2->getAllDetails();


	cout << endl << endl;
	system("pause");
	return 0;
}