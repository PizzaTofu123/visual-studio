#include <iostream>
#include <string>
#include "Hero.h"
using namespace std;


/*void func(int& z);
void swap(int& a, int& b);

int main() {
	int x = 69;
	int& rx = x;
	int& secrx = x;
	int* y = &secrx;
	int* z = y;
	// & - > ampersand
	func(x); // 1st add
	func(rx); // 2nd add
	func(secrx); // 3rd add
	cout << endl << x << endl << y << endl << z;

	//must use const befor int& and after int& to make const reference, front const to make pointed data unchangeable, 2nd const make it so that the const cant change the addr it is pointing to

	int* pToRand = NULL;
	int* px = &x;

	cout << endl << (*px) << endl << pToRand; // (*pc) and *px is same same 


	int a = 500;
	int b = 1000;
	swap(a, b);
	cout << endl  << a << endl << b;



	cout << endl << endl;
	system("pause");
	return 0;
}

void func(int& z) {
	z = z + 500;
}

void swap(int& a, int& b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}
Lecture 1*/

int main() {
	srand(static_cast<unsigned int>(time(NULL)));
	
	/*Hero hero1("Bababouille", Vegetable);
	Hero* heroPointer = &hero1;

	cout << heroPointer->getDetails(); // or (*heroPointer).getDetails();
	*/

	Hero* heroPointerForHeap = new Hero("skadoosh", Vegetable);
	cout << heroPointerForHeap->getDetails();
	cout << heroPointerForHeap;



	cout << endl;
	system("pause");
	return 0;
}