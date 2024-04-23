#include "Food.h"
#include <iostream>

//static data 
int Food::counter = 0;


Food::Food() {
	setColor("");
	setName("");
	setPrice(0);
	setDelishRate(-1);
	counter++;
}

Food::Food(std::string newName, std::string newColor) {
	setName(newName);
	setColor(newColor);
	setPrice(0);
	setDelishRate(-1);
	counter++;
}

Food::Food(float newPrice, std::string newName, std::string newColor, int newDelishRate) {
	setPrice(newPrice);
	setName(newName);
	setColor(newColor);
	setDelishRate(newDelishRate);
	counter++;
}

Food::~Food(){
	counter--;
}

//getters//accessor//get functions

float Food::getPrice(){
	return price;
}

std::string Food::getName(){
	return name;
}

std::string Food::getColor(){
	return color;
}

int Food::getDelishRate(){
	return delishRate;
}

//setter//mutator//set functions

void Food::setPrice( float newPrice) {
	if (newPrice >= 0) {
		price = newPrice;
	}
}

void Food::setName(std::string newName) {
	name = newName;
}

void Food::setColor(std::string newColor) {
	color = newColor;
}

void Food::setDelishRate(int newRate) {
	delishRate = newRate;
}

//static function
int Food::getNoOfFoodObj() {
	return counter;
}