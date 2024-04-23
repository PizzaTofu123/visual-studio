#include "Hero.h"


Hero::Hero(string newName, HeroType newHType) {
	setName(newName);
	setHType(newHType);
	setHealth(100);


	int randomPower = rand() % 100 + 1;
	setPower(randomPower);
	
}


string Hero::getName() {
	return name;
}

int Hero::getHealth() {
	return health;
}

int Hero::getPower() {
	return power;
}

HeroType Hero::getHType() {
	return hType;
}

void Hero::setName(string newName) {
	name = newName;
}

void Hero::setHealth(int newHealth) {
	health = newHealth;
}

void Hero::setPower(int newPower) {
	power = newPower;
}

void Hero::setHType(HeroType newHTYpe) {
	hType = newHTYpe;
}

string Hero::getNameForHeroType() {
	switch (getHType())
	{
	case Dragon:
		return "Dragon";
		break;
	case Vegetable:
		return "Vegetable";
		break;
	case LazyPerson:
		return "LazyPerson";
		break;
	case Hunter:
		return "Hunter";
		break;
	default:
		return "Dafuq?";
		break;
	}
}

string Hero::getDetails() {
	stringstream ssDetails;

	ssDetails << endl << "~~~~~~~~~~~~~~~~~~~";
	ssDetails << "\nHero's name : " << getName();
	ssDetails << "\n\tHero's Health : " << getHealth();
	ssDetails << "\n\tHero's Power : " << getPower();
	ssDetails << "\n\tHero's Type : " << getNameForHeroType();
	ssDetails << endl << "~~~~~~~~~~~~~~~~~~~";

	return ssDetails.str();
}