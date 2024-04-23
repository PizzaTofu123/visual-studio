/*Name,ID,Date created, Date Updated, Tutor Name, Description
Advanced Functions
~multiple function files
~organising functions files
~inclusion guards
~fuinction best practices
~function header and definition files
*/
#include <iostream>
#include "Calculator.h"
#include "RandomGameFunctions.h"
#include "Student.h"



int main() {
	
	/*float answer = addTwoNumbers(20, 69);
	cout << answer;
	cout << endl << multiplyTwoNumbers(69, 69);
	cout << endl << randomizer(100, 50);*/


	Student student1("Baba", "Bouille");
	Student student2("Rata", "Touille");

	student1.setFirstName("Bob");


	std::cout << student1.getFirstName() << student1.getLastName();
	std::cout << std::endl << student2.getFirstName() << student2.getLastName();
	std::cout << std::endl << student1.getFullName();


	std::cout << std::endl;
	system("pause");
	return 0;
}