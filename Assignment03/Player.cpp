/*
Cpp file to define all the Player functions that were declared in the Player header file
*/

#include "Player.h"


Player::Player() {
	setPlayerName("");
	setArrowCount(5);
	setOilCount(100);
	setPlayerAlive(true);
	setSilverCount(20);
	setSpecialItem("None");
}

Player::~Player(){}

string Player::getPlayerName() {
	return playerName;
}

int Player::getArrowCount() {
	return arrowCount;
}

int Player::getOilCount() {
	return oilCount;
}

bool Player::getPlayerAlive() {
	return playerAlive;
}

int Player::getSilverCount() {
	return silverCount;
}

string Player::getSpecialItem() {
	return specialItem;
}

void Player::setPlayerName(string newPlayerName) {
	playerName = newPlayerName;
}

void Player::setArrowCount(int newArrowCount) {
	arrowCount = newArrowCount;
}

void Player::setOilCount(int newOilCount) {
	oilCount = newOilCount;
}

void Player::setPlayerAlive(bool newPlayerAlive) {

	playerAlive = newPlayerAlive;
}

void Player::setSilverCount(int newSilverCount) {
	silverCount = newSilverCount;
}

void Player::setSpecialItem(string newSpecialItem) {
	specialItem = newSpecialItem;
}

string Player::getPlayerTurnDetails() {
	stringstream playerDetails;
	playerDetails << "\nNo.of arrows left : " << getArrowCount();
	playerDetails << "\nNo.of lantern oil left : " << getOilCount();
	playerDetails << "\nSpecial Item : " << getSpecialItem();
	return playerDetails.str();
}

void Player::resetPlayer() {
	setArrowCount(5);
	setOilCount(100);
	setPlayerAlive(true);
	setSilverCount(20);
	setSpecialItem("None");
}



