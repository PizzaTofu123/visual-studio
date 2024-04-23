#ifndef FOOD_H
#define FOOD_H
#include <string>

class Food {
private :
	//data members
	float price;
	std::string color;
	std::string name;
	int delishRate;
	//static data/members, 1 for the entire class
	static int counter;

public :
	//constructor 
	Food();
	Food(std::string, std::string);
	Food(float, std::string, std::string, int);

	//destructor
	~Food();

	//getter/accessors/get functions
	float getPrice();
	std::string getColor();
	std::string getName();
	int getDelishRate();

	//setters/mutators/set functions
	void setPrice(float);
	void setColor(std::string);
	void setName(std::string);
	void setDelishRate(int);

	//static function
	static int getNoOfFoodObj();


};



#endif // !FOOD_H



