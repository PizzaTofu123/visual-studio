/*Author	   : William
  ID Number	   : 32210213
  Unit		   : MCD 4720
  Date Created : 4 November 2020
  Date Updated : 20 November 2020
  Tutor		   : Robert Smith
  Description  : Assignment 01 The Amazing RPG Character Generator
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>

// declaring global vectors, strings and arrays
std::vector<std::string> charTypes; 
std::vector<std::string> attributes;
std::vector<std::string> minStats;
std::string generatedCharText;


// declaring functions and parameters
void runMenu();
void displayText(std::string fileName);
void createLists(std::string charTypeFileName, std::string charAttFileName, std::string attMinFileName);
std::string generateCharacter();
void saveData(std::string fileName);
void loadData(std::string fileName);
void clsAndOpenMenu();// system("pause") and system("cls")
void titleText();
std::string askForInput(std::string question); //asks if the user wants to save the data


int main() {
	runMenu();
	system("pause");
	return 0;
}


void runMenu() {
	titleText();
	// determining which function/action to take depending on the user's input
	int userChoice;
	std::cin >> userChoice;
	switch (userChoice) {
	case 2:
		system("cls");
		displayText("RPGabout.txt");
		clsAndOpenMenu();
		break;
	case 3:
		createLists("charTypes.txt", "charAttributes.txt", "charAttMins.txt");
		clsAndOpenMenu();
		break;
	case 4:
		// to check if the txt files are read or not 
		if (charTypes.size() == 0) {
			std::cout << "\nFiles are not read nor stored.";
			std::cout << "\nPlease read and store file data to generate character.\n";
			clsAndOpenMenu();
		}
		else {
			generatedCharText = generateCharacter();
			std::cout << generatedCharText;
			clsAndOpenMenu();
		}
		break;
	case 5:
		//check if there is a character to be saved
		if (generatedCharText.length() == 0) {
			std::cout << "\nNo characters have been generated yet.\n";
			clsAndOpenMenu();
		}
		else {
			saveData("savedCharacters.txt");
			clsAndOpenMenu();
		}
		break;
	case 6:
		loadData("savedCharacters.txt");
		clsAndOpenMenu();
		break;
	default:
		std::cout << "\nThank you for opening this programme.\n" << std::endl;
	}
}


void displayText(std::string fileName) {
	//reading the text file line per line and diplaying it
	std::string test;
	std::fstream readAbout(fileName);
	if (readAbout.is_open()) {
		while (!readAbout.eof()) {
			getline(readAbout, test);
			std::cout << test << std::endl;
		}
		readAbout.close();
	}
	else {
		std::cout << "File is not opened";
	}
}


void createLists(std::string charTypeFileName, std::string charAttFileName, std::string attMinFileName){
	// reading from file 1 into charTypes
	std::fstream readCharTypes(charTypeFileName);
	std::string str;
	while (!readCharTypes.eof()) {
		getline(readCharTypes, str);
		charTypes.push_back(str);
	}
	// reading from file 2 into attributes
	std::fstream readCharAttributes(charAttFileName);
	std::string str2;
	while (!readCharAttributes.eof()) {
		getline(readCharAttributes, str2);
		attributes.push_back(str2);
	}
	// reading from file 3 into minStats
	std::fstream readCharAttMins(attMinFileName);
	std::string str3;
	while (!readCharAttMins.eof()) {
		getline(readCharAttMins, str3);
		minStats.push_back(str3);
	}

	readCharTypes.close();
	readCharAttributes.close();
	readCharAttMins.close();

	std::cout << "\n   Data loading from charTypes.exe\n";
	std::cout << "   Data loading from charAttributes.txt\n";
	std::cout << "   Data loading from charAttMins.txt\n";
	std::cout << "\t";
}


std::string generateCharacter() {
	srand(static_cast<unsigned int>(time(NULL)));
	std::string generatedRandCharType;
	int generatedMinStats[6];
	int generatedRandNum[6];
	int stats[6];

	// random line number 
	int randLineFromFile = rand() % 6;
	generatedRandCharType = charTypes[randLineFromFile];
	//inserting minstats taken from file in the form int which was changed from ascii 
	for (int i = 0; i < 6; i++) {
		generatedMinStats[i] = ((int)minStats[i][randLineFromFile] - 48);
	}
	// generated extra random stats
	for (int i = 0; i < 6; i++) {
		generatedRandNum[i] = rand() % 5;
	}
	// stats = min stats + rand stats
	for (int i = 0; i < 6; i++) {
		stats[i] = generatedMinStats[i] + generatedRandNum[i];
	}
	return	"\n\n\t" + generatedRandCharType + "\n\t~~~~~~~~~~~~~~~~~~~~" +
		"\n\t" + attributes[0] + ": " + std::to_string(stats[0]) + "[The minimum " + attributes[0] + " is " + std::to_string(generatedMinStats[0]) + " and the random value is " + std::to_string(generatedRandNum[0]) + " ]" +
		"\n\t" + attributes[1] + ": " + std::to_string(stats[1]) + "[The minimum " + attributes[1] + " is " + std::to_string(generatedMinStats[1]) + " and the random value is " + std::to_string(generatedRandNum[1]) + " ]" +
		"\n\t" + attributes[2] + ": " + std::to_string(stats[2]) + "[The minimum " + attributes[2] + " is " + std::to_string(generatedMinStats[2]) + " and the random value is " + std::to_string(generatedRandNum[2]) + " ]" +
		"\n\t" + attributes[3] + ": " + std::to_string(stats[3]) + "[The minimum " + attributes[3] + " is " + std::to_string(generatedMinStats[3]) + " and the random value is " + std::to_string(generatedRandNum[3]) + " ]" +
		"\n\t" + attributes[4] + ": " + std::to_string(stats[4]) + "[The minimum " + attributes[4] + " is " + std::to_string(generatedMinStats[4]) + " and the random value is " + std::to_string(generatedRandNum[4]) + " ]" +
		"\n\t" + attributes[5] + ": " + std::to_string(stats[5]) + "[The minimum " + attributes[5] + " is " + std::to_string(generatedMinStats[5]) + " and the random value is " + std::to_string(generatedRandNum[5]) + " ]" +
		"\n\n";
}


void saveData(std::string fileName) {
	//display the already generated character again 
	std::cout << generatedCharText;
	std::string userSaveChoice = askForInput("Do you want to save this character ? (y/n) ");
	//saving character into savedCharacters.txt if y is chosen
	if (userSaveChoice == "y" || userSaveChoice=="Y" )
	{
		std::fstream saveChar;
		saveChar.open(fileName, std::ios::app);
		saveChar << generatedCharText;
	}
	std::cout << "\n" << std::endl;
}


void loadData(std::string fileName) {
	//reading from savedCharacters.txt and displaying it line by line to the end of the txt file
	std::string readData;
	std::fstream loadData(fileName);
	while (!loadData.eof()) {
		getline(loadData , readData);
		std::cout << readData << std::endl;
	}

	std::cout << "\n" << std::endl;
}


void clsAndOpenMenu() {
	system("pause");
	system("cls");
	runMenu();
}


void titleText() {
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "	The Amazing RPG Character Generator " << std::endl;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << " [1] End Testing The Program" << std::endl;
	std::cout << " [2] Display \"About\" Information" << std::endl;
	std::cout << " [3] Read and store data from files" << std::endl;
	std::cout << " [4] Generate a random character" << std::endl;
	std::cout << " [5] Save a character to file" << std::endl;
	std::cout << " [6] Load saved characters from file" << std::endl;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "Which option would you like (1-6) : ";
}


std::string askForInput(std::string question) {
	std::cout << "\n" << question;
	std::string userInput;
	std::cin >> userInput;
	return userInput;
}