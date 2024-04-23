#ifndef GAME_H
#define GAME_H

#include <string>
using namespace std;

class Game {


private:
	static Game* gameSingleton;
	string gameName;

	static int gameCounter;

	Game(string newName);

public:
	~Game();
	void setGameName(string);
	string getGameName();

	Game* getGameSingleton();
	int getGameCounter();

	
};





#endif // !GAME_H

