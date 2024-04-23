#include <iostream>
#include "Food.h"

void demoFunction();


int main() {



	Food food1(50, "Boiled Water", "Trans", 6);
	Food food2(400, "Boiled Air", "Trans", 10);
	demoFunction();



	std::cout << std::endl << food1.getName() << " has a " << food1.getColor() << " color" << std::endl;
	std::cout << food2.getName() << " costs " << food2.getPrice() << " and has a rating of " << food2.getDelishRate();
	std::cout << "\nNo of food items after the demo function : " << Food::getNoOfFoodObj();

	std::cout << std::endl;
	system("pause");
	return 0;
}

void demoFunction() {
	Food food1;
	Food food2;
	std::cout << "\nNo of food items in demo function : " << Food::getNoOfFoodObj();
}