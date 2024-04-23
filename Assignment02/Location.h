/*
Header file for Location class 
*/

#ifndef LOCATION_H
#define LOCATION_H
#include <string>
#include <iostream>
#include <time.h>
#include <sstream>
#include <vector>
#include <fstream>
using namespace std;

//information of cave exits, adjoining caves and description of each caves
static int AdjacentCaves[21][3];
static char directionOfAdjacentCaves[21][3];
static vector<string> caveDesc;

class Location {
private :
	int currentPlayerCave;
	int currentWumpusCave;
	int treasureCave;
	int bat1Cave;
	int bat2Cave;
	int pit1Cave;
	int pit2Cave;
	int ghostCave;

public :
	//constructor for location class
	Location();
	//destructor for location class
	~Location();

	//getter for location class
	int getCurrentPlayerCave();
	int getCurrentWumpusCave();
	int getTreasureCave();
	int getBat1Cave();
	int getBat2Cave();
	int getPit1Cave();
	int getPit2Cave();
	int getGhostCave();

	//setter for location class
	void setCurrentPlayerCave(int);
	void setCurrentWumpusCave(int);
	void setTreasureCave(int);
	void setBatCave(int, int);
	void setPitCave(int, int);
	void setGhostCave(int);

	//utility functions for location class
	string getHazardAndObjectiveLocations();//get treasure and hazard locations for when the player uses the cheat
	void resetHazardsAndObjectiveLocations();//reshuffle the location of the hazards and treasure and reset the location of the player and the wumpus
};


#endif // !LOCATION_H

