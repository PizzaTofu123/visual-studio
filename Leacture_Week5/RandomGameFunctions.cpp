/*
Details
Desc:
Randomizer
*/
#include "RandomGameFunctions.h"
/*
The related function header for random number generator
*/
int randomizer(int top, int bot) {
	srand(static_cast<unsigned int>(time(NULL)));
	return rand() % (top - bot) + bot;
}
