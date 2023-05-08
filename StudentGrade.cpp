#include <iostream>
#include <ctime>
#include "StudentGrade.h"

using namespace std;

const size_t colSize{ 11 };	 // Number of columns.
const size_t rowSize{ 5 };   // Number of rows.

// Function Prototypes
void printMultiArr(array<array<int, colSize>, rowSize> arr);
void printMultiVec(vector<vector<int>> vec);
void replace(vector<vector<int>>& vec, int rowNum, int colNum);

int main()
{
	srand(static_cast<unsigned int>(time(0)));  //Generate a random number based on the computer timer.

	array<array<int, colSize>, rowSize> proj1{
		59, 78, 89, 93, 91, 62, 45, 55, 85, 81, 0,  //The 11th column is the row sum. It will be populated later.
		89, 75, 72, 96, 98, 90, 56, 67, 45, 82, 0,
		96, 63, 87, 96, 95, 83, 62, 84, 56, 78, 0,
		85, 79, 57, 51, 63, 90, 78, 72, 92, 83, 0,
		73, 70, 71, 93, 88, 66, 87, 74, 55, 68, 0
	};
	array<double, rowSize> avgR{};   //an array for row average.
	array<double, rowSize> highRo{};   //an array for column average.

	//Create an object of the class stuGrade.
	stuGrade stu;

	//Create a 2-dimensional vector vec.
	vector<vector<int>> vec(rowSize, vector<int>(colSize));

	//Initialize the vecvotr vec by calling the function initVec() from the class stuGrade.
	stu.initVec(vec, proj1);

	cout << "\n\nContents of array proj1[][]:\n";

	//Display the elements of the array proj1[][] using a looping control.
	printMultiArr(proj1);

	cout << "\nContents of vector vec[][] after initialization:\n";

	//Display the contents of the 2-dimensional vector vec using a looping control.
	printMultiVec(vec);

	//Display the contents of the vector vec using a looping control.
	replace(vec, 3, 8);

	cout << "Updated Vector: " << endl;
	printMultiVec(vec);

	cout << "\n";

	return 0;
}
// Function Definitions
void printMultiArr(array<array<int, colSize>, rowSize> arr) {
	for (int i = 0; i < rowSize; i++) {
		for (int j = 0; j < colSize; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

void printMultiVec(vector<vector<int>> vec) {
	for (int i = 0; i < rowSize; i++) {
		for (int j = 0; j < colSize; j++) {
			cout << vec[i][j] << " ";
		}
		cout << endl;
	}
}

void replace(vector<vector<int>>& vec, int rowNum, int colNum) {

	// Convert row/column argument to vector index
	int rowIndex = rowNum - 1;
	int colIndex = colNum - 1;
	int originalVal = vec[rowIndex][colIndex];

	// Create a 1-dimensional vector vecTmp;
	vector<int> vecTmp;

	// Copy elements of row 3 from vec to vecTmp using iterator
	for (vector<int>::iterator it = vec[rowIndex].begin(); it != vec[rowIndex].end(); ++it) {
		vecTmp.push_back(*it);
	}
	cout << endl;

	cout << "Values Stored In Temporary Vector:\n\n";
	cout << "Before replacing " << originalVal << " (Row: " << rowNum << ", Column: " << colNum << ")" << endl;

	// Create an iterator called itTmp and set it equal to the beginning of vecTmp
	// Use a looping control to display the elements of the vector vecTmp;
	for (vector<int>::iterator itTmp = vecTmp.begin(); itTmp != vecTmp.end(); ++itTmp) {
		cout << *itTmp << " ";
	}
	cout << "\nCount: " << vecTmp.size() << "\n\n";

	// Remove row values from original vec
	for (int i = 0; i < colSize; i++) {
		vec[rowIndex].pop_back();
	}

	// Insert updated values back into original vector
	for (int i = 0; i < colSize; i++) {
		if (i != colIndex) {
			vec[rowIndex].push_back(vecTmp[i]);
		}
		else {
			vec[rowIndex].push_back(100);
		}
	}
	cout << "After replacing " << originalVal << " (Row: " << rowNum << ", Column: " << colNum << ")" << endl;

	for (vector<int>::iterator itTmp = vec[rowIndex].begin(); itTmp != vec[rowIndex].end(); ++itTmp) {
		cout << *itTmp << " ";
	}
	cout << "\nCount: " << vecTmp.size() << "\n\n";
}
