#include "Game.h"


int Game::gameCounter = 0;

Game* Game::gameSingleton = NULL;

Game::Game(string newName) {
	gameName = newName;
}