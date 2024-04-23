#include<iostream>
#include<string>
#include<vector>
#include<ctime>
#include<algorithm>
/*About :Functions array and vector*/




/*Function Name : Randomizer
* Desc = produces rand num
* return = random int
* arg = short top and bot range
*/


//int randomizer(int, int);
//int answer;

int main() {

	srand(static_cast<unsigned int>(time(NULL)));

	//std::cout << randomizer(20,30) << std::endl;
	//std::cout << addingNumbers(21.5, 22.5);

	/*int numberArray[3];
	numberArray[0] = 69;
	numberArray[1] = 68;
	numberArray[2] = 67;

	for (int i = 0; i < 3; i++) {
		std::cout << numberArray[i] << "\n";
	}*/

	/*int studentMarks[10][10];
	studentMarks[0][0] = 80;
	studentMarks[0][1] = 85;
	studentMarks[1][0] = 90;
	studentMarks[1][1] = 95;
	for (int i = 0; i < 2; i++) {
		std::cout << "\nAssignment : " << i + 1 << std::endl;
		std::cout << "\n\t Student 1 : " << studentMarks[i][0] << "\t Student 2 : " << studentMarks[i][1];
	}
	int student1Marks = 0;
	int student2Marks = 0;
	int totalMarks = 0;
	for (int i = 0; i < 2; i++) {
		student1Marks += studentMarks[i][0];
		student2Marks += studentMarks[i][1];
	}
	totalMarks = student2Marks + student1Marks;

	std::cout << "\n\nThe average is : " << totalMarks/ 4;
	*/


	/*std::vector<int> vector1;
	vector1.push_back(100);
	vector1.push_back(101);
	std::cout << vector1[0];
	for (int i = 0; i < vector1.size(); i++) {
		std::cout << std::endl << vector1[i];
	}
	vector1.pop_back(); // deletes the shit 
	for (int i = 0; i < vector1.size(); i++) {
		std::cout << std::endl << vector1[i];
	}
	// vector.empty is to check empty or not , .clear to clear the whole thing , .capacity the size */

	std::vector<int> vector2;
	vector2.push_back(500);
	vector2.push_back(750);
	vector2.push_back(1000);
	std::vector<int>::iterator vector2Iterator;
	/*vector2Iterator = vector2.begin();
	std::cout << (*vector2Iterator) << std::endl;
	vector2Iterator = vector2.end();
	vector2.insert(vector2Iterator-1, 1500);
	for (int i = 0; i < vector2.size(); i++) {
		std::cout << "\n\t" << vector2[i];
	}*/
	//iterator.end() is end + 1 , vector.erase() erases the shit 
	std::cout << vector2[0] << vector2[1] << vector2[2];
	vector2Iterator = vector2.begin();
	int num = 750;
	vector2Iterator = find(vector2.begin(), vector2.end(), num);
	if (vector2Iterator != vector2.end()) {
		std::cout << "\nfound it\n";
	}
	
	std::cout << std::endl;
	system("pause");
	return 0;
}


/*float addingNumbers(float no1, float no2) {
	float results = no1 + no2;

	return results;
}*/

/*int randomizer(int bottomRange, int topRange) {
	int answer = rand() % bottomRange + topRange;

	return answer;
}*/