/*
Header file for Player class
*/
#include <string>
#include <iostream>
#include <time.h>
#include <sstream>
using namespace std;

#ifndef PLYER_H
#define PLAYER_H
class Player{
private :
	string playerName;
	int arrowCount;
	int oilCount;
	bool playerAlive; //status if the player is still alive or not
	int silverCount; //silver count to buy items from shop
	string specialItem; //special item that will help the player

public :
	//constructor for player class 
	Player();
	//destructor for player class 
	~Player();

	//getters for player class 
	string getPlayerName();
	int getArrowCount();
	int getOilCount();
	bool getPlayerAlive();
	int getSilverCount();
	string getSpecialItem();
	
	//setters for player class 
	void setPlayerName(string);
	void setArrowCount(int);
	void setOilCount(int);
	void setPlayerAlive(bool);
	void setSilverCount(int);
	void setSpecialItem(string);

	//utility function for player class 
	string getPlayerTurnDetails(); // collects information that is needed when the turn is being displayed
	void resetPlayer(); // resets players items 

};



#endif // !PLAYER_H

