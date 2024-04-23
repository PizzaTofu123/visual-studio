/*
Cpp file to define all the Location functions that were declared in the Location header file
*/

#include "Location.h"

Location::Location() {
	srand(static_cast<unsigned int>(time(NULL)));
	setCurrentPlayerCave(0);
	setCurrentWumpusCave(20);
	int pit1 = rand() % 20 + 1;
	int pit2 = rand() % 20 + 1;
	//to make the pits not end up in the same room
	while (pit1 == pit2) {
		pit2 = rand() % 20 + 1;
	}
	setPitCave(pit1, pit2);
	int bat1 = rand() % 20 + 1;
	int bat2 = rand() % 20 + 1;
	//to make sure the hazards are placed in different caves 
	while (bat1 == pit1 || bat1 == pit2 || bat1 == bat2) {
		bat1 = rand() % 20 + 1;
	}
	while (bat2 == pit1 || bat2 == pit2 || bat2 == bat1) {
		bat2 = rand() % 20 + 1;
	}
	setBatCave(bat1, bat2);
	int treasure = rand() % 20 + 1;
	//to make sure that the treasure dont get placed in the same room as a hazard
	while (treasure == pit1 || treasure == pit2 || treasure == bat2 || treasure == bat1 || treasure == 20) {
		treasure = rand() % 20 + 1;
	}
	setTreasureCave(treasure);
	int ghost = rand() % 20 + 1;
	setGhostCave(ghost);
}
	

Location::~Location(){}

int Location::getCurrentPlayerCave(){
	return currentPlayerCave;
}

int Location::getCurrentWumpusCave(){
	return currentWumpusCave;
}

int Location::getTreasureCave(){
	return treasureCave;
}

int Location::getBat1Cave(){
	return bat1Cave;
}

int Location::getBat2Cave(){
	return bat2Cave;
}

int Location::getPit1Cave(){
	return pit1Cave;
}

int Location::getPit2Cave()
{
	return pit2Cave;
}

int Location::getGhostCave() {
	return ghostCave;
}

void Location::setCurrentPlayerCave(int newCave){
	currentPlayerCave = newCave;
}

void Location::setCurrentWumpusCave(int newCave){
	currentWumpusCave = newCave;
}

void Location::setTreasureCave(int newCave){
	treasureCave = newCave;
}

void Location::setBatCave(int newCave1, int newCave2){
	bat1Cave = newCave1;
	bat2Cave = newCave2;
}

void Location::setPitCave(int newCave1, int newCave2){
	pit1Cave = newCave1;
	pit2Cave = newCave2;
}

void Location::setGhostCave(int newCave) {
	ghostCave = newCave;
}

string Location::getHazardAndObjectiveLocations() {
	stringstream locations;
	locations << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	locations << "\nShowing all objective and hazard locations";
	locations << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	locations << "\nWumpus is in cave " << getCurrentWumpusCave();
	locations << "\nTreasure is in cave " << getTreasureCave();
	locations << "\nBottomless pits are in caves " << getPit1Cave() << " and " << getPit2Cave();
	locations << "\nSuper bats are in caves " << getBat1Cave() << " and " << getBat2Cave();
	locations << "\nLantern ghost is in cave " << getGhostCave();
	locations << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	
	return locations.str();
}

void Location::resetHazardsAndObjectiveLocations() {
	srand(static_cast<unsigned int>(time(NULL)));
	setCurrentPlayerCave(0);
	setCurrentWumpusCave(20);
	int pit1 = rand() % 20 + 1;
	int pit2 = rand() % 20 + 1;
	//to make the pits not end up in the same room
	while (pit1 == pit2) {
		pit2 = rand() % 20 + 1;
	}
	setPitCave(pit1, pit2);
	int bat1 = rand() % 20 + 1;
	int bat2 = rand() % 20 + 1;
	//to make sure the hazards are placed in different caves 
	while (bat1 == pit1 || bat1 == pit2 || bat1 == bat2) {
		bat1 = rand() % 20 + 1;
	}
	while (bat2 == pit1 || bat2 == pit2 || bat2 == bat1) {
		bat2 = rand() % 20 + 1;
	}
	setBatCave(bat1, bat2);
	int treasure = rand() % 20 + 1;
	//to make sure that the treasure dont get placed in the same room as a hazard
	while (treasure == pit1 || treasure == pit2 || treasure == bat2 || treasure == bat1 || treasure == 20) {
		treasure = rand() % 20 + 1;
	}
	setTreasureCave(treasure);
	int ghost = rand() % 20 + 1;
	setGhostCave(ghost);
}
