#include<string>
#include <sstream>
#include<ctime>
#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;



void add(int& num);
void addP(int* num);
int check(string, char);
void dispStar(int);

string gay(int, int, int);

int main() {
	/*arrasy size*/

	/*
	int arr[] = {1,2,3,4,5,6,7};
	cout << sizeof(arr) / sizeof(arr[0]) << endl;*/
	


	/*srand(static_cast<unsigned int>(time(NULL)));*/

	/*string str = "01234~5678~9";
	stringstream test; // is for endline when see ~
	string substr;
	int a = 0;
	int b = 0;
	while (b != -1) {
		b = str.find("~");
		substr = str.substr(a, b);
		str.erase(a, b + 1);
		test << substr << endl;
	}
	cout << test.str();*/

	/*string str;
	fstream read;
	read.open("Text1.txt");
	while (!read.eof()) {
		for (int i = 0; i < 21; i++) {
			getline(read, str);
			cout << str << endl;
			getline(read, str);
			cout << stoi(str) << endl;
			getline(read, str);
			cout << stoi(str) << endl;
			getline(read, str);
			cout << stoi(str) << endl;
			getline(read, str);
			cout << str[0] << endl;
		}
	}*/

	//substr
	/*string s = "1234567890";

	cout << endl << s.length();
	cout << endl << s.size();
	cout << endl << s.substr(0, 4);
	cout << endl;*/ 

	//static cast and normal cast
	/*float oddNum = 1.9; 
	cout << static_cast<int>(oddNum);
	(float)oddNum;
	cout << endl;	cout << endl;*/

	//table and shit
	/*
	int myArr[11][11];
	for (int row = 0; row < 11; row++) {
		for (int col = 0; col < 11; col++) {
			myArr[row][col] = row * col;
		}
	}


	for (int row = 0; row < 11; row++) {
		for (int col = 0; col < 11-row; col++) {
			cout << myArr[row][col] << "\t";
		}
		cout << endl;
	}
	cout << endl;
	for (int row = 0; row < 11; row++) {
		for (int col = 0; col < row; col++) {
			cout << myArr[row][col] << "\t";
		}
		cout << endl;
	}
	cout << endl;
	*/

	//prime number checker
	
	/*
	int n, i, m = 0, flag = 0;
	cout << "Enter the Number to check Prime: ";
	cin >> n;
	m = n / 2;
	for (i = 2; i <= m; i++)
	{
		if (n % i == 0)
		{
			cout << "Number is not Prime." << endl;
			flag = 1;
			break;
		}
	}
	if (flag == 0)
		cout << "Number is Prime." << endl;
		*/
	

	//num to binary
	/*int binAdder = 1;
	int number = 0;
	int remainder;
	long binaryFromNum = 0;
	cin >> number;
	while (number != 0) {
		remainder = number % 2;
		number /= 2;

		if (remainder != 0) {
			binaryFromNum += binAdder;
		}

		binAdder *= 10;

	}

	cout << binaryFromNum; */
	
	/*int Arr[5] = { 1,2,3,4,5 };

	int x = 69;
	const int& y = x;
	int* pnum = &x;
	(*pnum) = (*pnum)+1;
	


	addP(pnum);

	cout << x;
	cout << y;
	cout << endl;
	cout << endl;
	cout << endl;


	*/

//dispStar(5);

cout << gay(7,1,21) << endl;

system("pause");
return 0;

}




int check(string sentence, char letter) {
	int result = 0;
	for (int i = 0; i < sentence.length(); i++) {
		if (sentence[i] == letter) {
			result++;
		}
	}
	return result;
}


void add(int& num) {
	num = num + 1;
}

void addP(int* num) {
	(*num) += 1;
}

string gay(int k, int s, int n) {
	if (k * s == n) {
		return "yes";
	}

	if (k * s < n){
		if (s == 1) {
			if ((n - k) < (k - 2)) {
				return "no";
			}
			else {
				return "yes";
			}
		}
		else {
			return "yes";
		}
	}
	else {
		return "no";
	}
}