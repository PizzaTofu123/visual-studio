#include "Monster.h"
#include"Vampire.h"
void addMon();
void makemonsterWork();

int main() {
	addMon();
	makemonsterWork();
	
	cout << endl;
	system("pause");
	return 0;
}

void addMon() {
	Monster m1 = Monster("Frankenstein", 50);
	Vampire v1 = Vampire("Vlad", 69);
	cout << "The monster count is: " << m1.getNumMonsters() <<endl;
	cout << m1.getName() << " says " << m1.speak() << endl;
	cout << m1.getName() << " attack " << m1.attack() << endl;

	cout << endl;
	cout << "The vampire count is: " << v1.getNumVampires() << endl;
	cout << v1.getName() << " says " << v1.speak() << endl;
	cout << v1.getName() << " attack " << v1.attack() << endl;
}

void makemonsterWork() {
	/*Monster m1 = Monster("Frankenstein", 50);
	Monster m2 = Vampire("Vlad", 80);
	cout << endl;
	cout << "\n " << m1.getName() << " says " << m1.speak();
	cout << "\n " << m2.getName() << " says " << m2.speak();*/ //c this shit, this shit will bring out speak of monster pretty geh

	Monster* m2 = new Vampire("Vlad", 80);
	cout << endl;
	cout << "\n" << m2->getName() << " says " << m2->speak(); //c this shit now it works normal
}