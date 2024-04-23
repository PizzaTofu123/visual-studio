/*
Assignment 3
Name   : William
ID     : 32210213
Tutor  : Robert Smith
Unit   : MCD 4720
Date Created : 16/12/2020

Extra Functionalities included :
1.Implement an appropriate scoring system based on game parameters (see introduction2.txt for more details)
2.Add a theme to the game which is incorporated into the game play (Need to also find the treasure to beat the game)
3.The player can collect useful items to help them survive, either before the game starts (Players can buy special item or extra items at the start)
4.Create roaming opponents ( Lantern Ghost: steals the player's lantern oil, can travel throughout the entire cavern (makes it pretty rare to meet it) 
  and will move every turn (when the player shoot or move))
*/

#include "Location.h"
#include "Player.h"
#include <iostream>
#include <fstream>


//classes
Location caves;
Player Player1;

bool wumpusAlive;
bool treasureTaken;

void displayIntroAndAskForName(string textFileName, string textFileName2);//show introduction, rules and asks for the player name, has 2 parameters as it will read from 2 different files
void readCaveInformationFromText(string myFileName); //will read information about caves (it's description,exits and adjoining caves) and store it into 2 arrays and 1 vector
void playHuntTheWumpus();
void displayTurnTitle();
void playerTurn();
void waitForPlayer();
void playerMove(); // if player chooses to move
void playerShoot();// if player chooses to shoot
void wumpusMove(); // decides where and if the wumpus will move
void gameOver();

void checkCloseToHazard();//check if the caves adjoining the current player's cave contains a hazard, and if so, will display a warning
void checkForBats();
char askForLetter(string question);
void checkTreasureFound();
void wumpusAndTreasureTurnDetails(); //displays the two objectives status
void checkForGhost();//checks if player is inside the same cave as the Lantern Ghost
void displayShop(); //function for the shop

bool checkGameOver();//check if player is in the same room as hazards that can kill them
int isTheDirectionOfATunnel(char direction);//check if the rooms the player or hazard want to move into are adjacents, will return -1 if not adjacent
string askForString(string question);
int askForNumber(string question);


int main() {
	readCaveInformationFromText("cave.txt");
	displayIntroAndAskForName("introduction.txt", "introduction2.txt");
	playHuntTheWumpus();
	return 0;
}

void displayIntroAndAskForName(string textFileName, string textFileName2) {
	string str;
	fstream readFile;
	readFile.open(textFileName);
	while (!readFile.eof()){
		getline(readFile, str);
		cout << str << endl;
	}
	readFile.close();
	waitForPlayer();
	readFile.open(textFileName2);
	while (!readFile.eof()) {
		getline(readFile, str);
		cout << str << endl;
	}
	readFile.close();
	waitForPlayer();
	Player1.setPlayerName(askForString("What should we call you ? "));
	waitForPlayer();
}

void playHuntTheWumpus() {
	displayShop();
	wumpusAlive = true;
	treasureTaken = false;
	while (checkGameOver() == false) {
		playerTurn();
	}
	gameOver();
}

void displayTurnTitle() {
	cout << "--------------------------------------------------------";
	cout << "\n\tTHE WUMPUS CAVERN";
	cout << "\n--------------------------------------------------------";
}

void playerTurn() {
	displayTurnTitle();
	cout << "\n" << caveDesc[caves.getCurrentPlayerCave()];
	cout << "\n--------------------------------------------------------";
	wumpusAndTreasureTurnDetails();
	cout << "\n--------------------------------------------------------";
	cout << "\nHere are the direction of the exits you can see :";
	for (int i = 0; i < 3; i++) {
		cout << " " << directionOfAdjacentCaves[caves.getCurrentPlayerCave()][i];
	}
	checkCloseToHazard(); 
	cout << Player1.getPlayerTurnDetails();
	string userChoice = askForString("\nPlease enter move, shoot, or cheat\n");
	if (userChoice == "Move" || userChoice == "move") {
		playerMove();
		checkForBats();
	}
	else if (userChoice == "Shoot" || userChoice == "shoot"){
		playerShoot();
	}
	else if (userChoice == "Cheat" || userChoice == "cheat") {
		waitForPlayer();
		cout <<caves.getHazardAndObjectiveLocations();
		waitForPlayer();
		playerTurn();
	}
	else {
		cout << "\nI don't know how to do that\n";
		waitForPlayer();
		playerTurn();
	}
	system("cls");
}

void waitForPlayer() {
	cout << endl;
	system("pause");
	system("cls");
}

void playerMove() {
	string question = "In which direction " + Player1.getPlayerName() + " ? (N for North, E for East, S for South, W for West)";
	char direction = askForLetter(question);
	if (isTheDirectionOfATunnel(direction) == -1){
		cout << "There is no tunnel there !\n";
		system("pause");
	}
	else {
		Player1.setOilCount(Player1.getOilCount() - (rand() % 3 + 2));
		caves.setCurrentPlayerCave(AdjacentCaves[caves.getCurrentPlayerCave()][isTheDirectionOfATunnel(direction)]);
		checkForGhost();
		caves.setGhostCave(rand() % 20 + 1);
		checkTreasureFound();
	}
}

void playerShoot() {
	int roomShotInto;
	if (Player1.getArrowCount() != 0) {
		string question = "In which direction " + Player1.getPlayerName() + " ? (N for North, E for East, S for South, W for West)";
		char direction = askForLetter(question);
		if (isTheDirectionOfATunnel(direction) == -1) {
			cout << "There is no tunnel there !\n";
			system("pause");
		}
		else {
			Player1.setOilCount(Player1.getOilCount() - (rand() % 3 + 2));
			Player1.setArrowCount(Player1.getArrowCount() - 1);
			roomShotInto = AdjacentCaves[caves.getCurrentPlayerCave()][isTheDirectionOfATunnel(direction)];
			caves.setGhostCave(rand() % 20 + 1);
			checkForGhost();
			if (roomShotInto == caves.getCurrentWumpusCave()) {
				wumpusAlive = false;
				cout << "\nCongratulations, you killed the Wumpus.\n";
				system("pause");
			}
			else {
				wumpusMove();
			}
		}
	}
	else { 
		cout << "\nYou got no arrows left";
		system("pause"); 
	}
}

void wumpusMove() {
	int move = rand() % 3 + 2;
	if (wumpusAlive == true) {
		caves.setCurrentWumpusCave(AdjacentCaves[caves.getCurrentWumpusCave()][move - 2]);
		cout << "\n*You missed the Wumpus\nI hear rumbling... could it be that the Wumpus just moved..";
		system("pause");
	}
	else {
		cout << "\n*You missed the Wumpus\nHmmm...There's nothing but silence, I guess I missed.";
		system("pause");
	}
}

void gameOver() {
	if (Player1.getPlayerAlive() == true && wumpusAlive == false && treasureTaken == true){
		system("cls");
		cout << "You killed the wumpus and retrieved the kingdom's lost treasures, congratulations!";
		cout << "\n--------------------------------------------------------";
		cout << "\nLantern Oil left : " << Player1.getOilCount();
		cout << "\nArrow Left : " << Player1.getArrowCount();
		wumpusAndTreasureTurnDetails();
		cout << "\nYour final score is : " << (Player1.getArrowCount() * 15) + (Player1.getOilCount() * 1) + 200 + 300 + 350;
	}
	else if ((caves.getCurrentPlayerCave() == caves.getPit1Cave() || caves.getCurrentPlayerCave() == caves.getPit2Cave()) && Player1.getSpecialItem() != "Sucker Boots") {
		system("cls");
		cout << "You fell into a bottomless pit and died";
		cout << "\n--------------------------------------------------------";
		cout << "\nLantern Oil left : " << Player1.getOilCount();
		cout << "\nArrow Left : " << Player1.getArrowCount();
		wumpusAndTreasureTurnDetails();
		if (wumpusAlive == true && treasureTaken == false) {
			cout << "\nYour final score is : " << (Player1.getArrowCount() * 15) + (Player1.getOilCount() * 1);
		}
		else if (wumpusAlive == false && treasureTaken == false) {
			cout << "\nYour final score is : " << (Player1.getArrowCount() * 15) + (Player1.getOilCount() * 1) + 200;
		}
		else if (wumpusAlive == true && treasureTaken == true) {
			cout << "\nYour final score is : " << (Player1.getArrowCount() * 15) + (Player1.getOilCount() * 1) + 300;
		}
		else if (wumpusAlive == false && treasureTaken == true) {
			cout << "\nYour final score is : " << (Player1.getArrowCount() * 15) + (Player1.getOilCount() * 1) + 200 + 300;
		}
	}
	else if (caves.getCurrentPlayerCave() == caves.getCurrentWumpusCave() && wumpusAlive == true) {
		system("cls");
		cout << "The wumpus came into your cave and gobbled you up. You lost";
		cout << "\n--------------------------------------------------------";
		cout << "\nLantern Oil left : " << Player1.getOilCount();
		cout << "\nArrow Left : " << Player1.getArrowCount();
		wumpusAndTreasureTurnDetails();
		if (treasureTaken == false) {
			cout << "\nYour final score is : " << (Player1.getArrowCount() * 15) + (Player1.getOilCount() * 1);
		}
		else if (treasureTaken == true) {
			cout << "\nYour final score is : " << (Player1.getArrowCount() * 15) + (Player1.getOilCount() * 1) + 350;
		}
	}
	else if (Player1.getOilCount() <= 0) {
		system("cls");
		cout << "You ran out of lantern oil and died of starvation in the cavern";
		cout << "\n--------------------------------------------------------";
		cout << "\nLantern Oil left : " << Player1.getOilCount();
		cout << "\nArrow Left : " << Player1.getArrowCount();
		wumpusAndTreasureTurnDetails();
		if (wumpusAlive == true && treasureTaken == false) {
			cout << "\nYour final score is : " << (Player1.getArrowCount() * 15) + (Player1.getOilCount() * 1);
		}
		else if(wumpusAlive == false && treasureTaken == false) {
			cout << "\nYour final score is : " << (Player1.getArrowCount() * 15) + (Player1.getOilCount() * 1) + 200;
		}
		else if (wumpusAlive == true && treasureTaken == true) {
			cout << "\nYour final score is : " << (Player1.getArrowCount() * 15) + (Player1.getOilCount() * 1) + 300;
		}
		else if (wumpusAlive == false && treasureTaken == true) {
			cout << "\nYour final score is : " << (Player1.getArrowCount() * 15) + (Player1.getOilCount() * 1) + 200 + 300;
		}
	}
	char userChoice = askForLetter("Do you want to play again ? (Y/N) ");
	if (userChoice == 'Y') {
		caves.resetHazardsAndObjectiveLocations();
		Player1.resetPlayer();
		system("cls");
		playHuntTheWumpus();
	}
	if (userChoice == 'N') {
		cout << "\nThank you for playing.\n";
	}
}

void checkCloseToHazard(){
	for (int i = 0; i < 3; i++) {
		if (AdjacentCaves[caves.getCurrentPlayerCave()][i] == caves.getBat1Cave() || AdjacentCaves[caves.getCurrentPlayerCave()][i] == caves.getBat2Cave()) {
			cout << "\nI hear Bats";
		}
		if (AdjacentCaves[caves.getCurrentPlayerCave()][i] == caves.getPit1Cave() || AdjacentCaves[caves.getCurrentPlayerCave()][i] == caves.getPit2Cave()) {
			cout << "\nI feel a draft";
		}
		if (AdjacentCaves[caves.getCurrentPlayerCave()][i] == caves.getCurrentWumpusCave()) {
			cout << "\nThis awful smell....it's definitely the smell of a Wumpus!";
		}
	}
}

void checkForBats() {
	if (caves.getCurrentPlayerCave() == caves.getBat1Cave() || caves.getCurrentPlayerCave() == caves.getBat2Cave()) {
		if (Player1.getSpecialItem() == "Magical Whistle") {
			system("cls");
			displayTurnTitle();
			cout << "\nYou have been spotted by the super bats at their lair.";
			cout << "\nYou pull out your whistle and blow into it.";
			cout << "\nThe Bats are now asleep.";
			cout << "\n\"Guess I'm a prodigy\"";
			waitForPlayer();
		}
		else {
			system("cls");
			displayTurnTitle();
			cout << "\nYou have been spotted by the super bats at their lair.\nYou have now been relocated to a random cave.";
			caves.setCurrentPlayerCave(rand() % 20 + 1);
			waitForPlayer();
		}
	}

}

char askForLetter(string question) {
	cout << "\n" << question << endl;
	char reply;
	cin >> reply;
	return toupper(reply);
}

void readCaveInformationFromText(string myFileName) {
	fstream readFile;
	readFile.open(myFileName);
	while (!readFile.eof()) {
		for (int i = 0; i < 21; i++) {
			string temp1;
			getline(readFile, temp1);
			caveDesc.push_back(temp1);
			string temp2;
			for (int j = 0; j < 3; j++) {
				getline(readFile, temp2);
				AdjacentCaves[i][j] = stoi(temp2);
			}
			string temp3;
			getline(readFile, temp3);
			for (int j = 0; j < 3; j++) {
				directionOfAdjacentCaves[i][j] = temp3[j];
			}
		}
	}
	readFile.close();
}


void checkTreasureFound() {
	if (caves.getCurrentPlayerCave() == caves.getTreasureCave() && treasureTaken == false) {
		treasureTaken = true;
		system("cls");
		cout << "Whats this shiny chestbox here?";
		cout << "\nIt's the stolen treasure!";
		cout << endl;
		waitForPlayer();
	}
}

void wumpusAndTreasureTurnDetails() {
	if (treasureTaken == false && wumpusAlive == true) {
		cout << "\nWumpus : " << " Alive";
		cout << "\nTreasure : " << " Not Found";
	}
	else if (treasureTaken == true && wumpusAlive == true) {
		cout << "\nWumpus : " << " Alive";
		cout << "\nTreasure : " << " Found";
	}
	else if (treasureTaken == false && wumpusAlive == false) {
		cout << "\nWumpus : " << " Killed";
		cout << "\nTreasure : " << " Not Found";
	}
	else if (treasureTaken == true && wumpusAlive == false) {
		cout << "\nWumpus : " << " Killed";
		cout << "\nTreasure : " << " Found";
	}
}

void checkForGhost() {
	if (caves.getCurrentPlayerCave() == caves.getGhostCave()) {
		system("cls");
		cout << "You have been spotted by the Lantern Ghost!";
		cout << "\nThe ghost has stolen some of your lantern oil!";
		Player1.setOilCount(Player1.getOilCount() - (rand() % 9 + 10));
		cout << "\nRemaining oil count : " << Player1.getOilCount();
		cout << endl;
		system("pause");
	}
}

void displayShop() {
	bool exitShop = false;
	while (exitShop == false) {
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		cout << "\n\tSHOP";
		cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		cout << "\n[1] 1 extra Arrow, 3 Silvers";
		cout << "\n[2] 5 extra Lantern Oil, 1 Silver";
		cout << "\n[3] Magical whistle, 11 Silvers (Put bats to sleep)";
		cout << "\n[4] Sucker Boots, 12 Silvers (Helps you climb out of a pit)";
		cout << "\n[9] Exit shop";
		cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		cout << "\nSilver Left : " << Player1.getSilverCount();
		cout << "\nCurrent Arrows : " << Player1.getArrowCount();
		cout << "\nCurrent Lantern Oil : " << Player1.getOilCount();
		cout << "\nSpecial Item : " << Player1.getSpecialItem();
		cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		int userInput = askForNumber("What do you want to buy " + Player1.getPlayerName() +  " ?\n");
		switch (userInput) {
		case 1:
			if (Player1.getSilverCount() >= 3) {
				Player1.setArrowCount(Player1.getArrowCount() + 1);
				Player1.setSilverCount(Player1.getSilverCount() - 3);
			}
			else {
				cout << "\nNot Enough Silver\n";
				system("pause");
			}
			break;
		case 2:
			if (Player1.getSilverCount() >= 1) {
				Player1.setOilCount(Player1.getOilCount() + 5);
				Player1.setSilverCount(Player1.getSilverCount() - 1);
			}
			else {
				cout << "\nNot Enough Silver\n";
				system("pause");
			}
			break;
		case 3:
			if (Player1.getSilverCount() >= 11) {
				Player1.setSpecialItem("Magical Whistle");
				Player1.setSilverCount(Player1.getSilverCount() - 11);
			}
			else {
				cout << "\nNot Enough Silver\n";
				system("pause");
			}
			break;
		case 4:
			if (Player1.getSilverCount() >= 12) {
				Player1.setSpecialItem("Sucker Boots");
				Player1.setSilverCount(Player1.getSilverCount() - 12);
			}
			else {
				cout << "\nNot Enough Silver\n";
				system("pause");
			}
			break;
		case 9:
			exitShop = true;
			break;
		default:
			cout << "\nI don't know what that is.\n";
			system("pause");
			break;

		}
		system("cls");
	}
}

bool checkGameOver() {
	if (wumpusAlive == false && treasureTaken == true) {
		return true;
	}
	else if (caves.getCurrentPlayerCave() == caves.getPit1Cave() || caves.getCurrentPlayerCave() == caves.getPit2Cave()) {
		if (Player1.getSpecialItem() == "Sucker Boots") {
			system("cls");
			displayTurnTitle();
			cout << "\nYou fell into a pit.";
			cout << "\nYou use your Sucker Boots to cling onto the slippery walls and climb up.";
			cout << "\n\"Whew, that was close.\"";
			waitForPlayer();
			return false;
		}
		else {
			Player1.setPlayerAlive(false);
			return true;
		}
	}
	else if (caves.getCurrentPlayerCave() == caves.getCurrentWumpusCave() && wumpusAlive == true) {
		return true;
	}
	else if (Player1.getOilCount() <= 0) {
		return true;
	}
	else {
		return false;
	}
}

int isTheDirectionOfATunnel(char direction) {
	int areAdjRooms = -1;
	for (int i = 0; i < 3; i++) {
		if (directionOfAdjacentCaves[caves.getCurrentPlayerCave()][i] == direction) {
			areAdjRooms = i;
		}
	}
	return areAdjRooms;
}

string askForString(string question) {
	cout << "\n" << question;
	string reply;
	cin >> reply;
	return reply;
}

int askForNumber(string question) {
	cout << endl << question;
	int reply;
	cin >> reply;
	return reply;
}