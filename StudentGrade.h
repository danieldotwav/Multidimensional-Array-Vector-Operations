#ifndef STUGRADE_H
#define STUGRADE_H

#include <array>
#include <vector>
#include <algorithm>

class stuGrade {
public:
	static const size_t colSize{ 11 };
	static const size_t rowSize{ 5 };
	//	  std::srand(std::static_cast<unsigned int>(time(0)));   //Don't need this here.
	stuGrade() {};

	//Assign elements of array proj1[][] to pointer *arrR.
	void initArr(int *ptrA[rowSize], std::array<std::array<int, colSize>, rowSize>& arr){
		for (int i{ 0 }; i < rowSize; i++) {
				ptrA[i] = &arr[i][0];
		}
	}

//Complete this function.
	void initVec( std::vector<std::vector<int>>& vec, std::array<std::array<int, colSize>, rowSize> arr) {
		// Copy elements from array into vector
		for (int i = 0; i < rowSize; i++) {
			for (int j = 0; j < colSize; j++) {
				vec[i][j] = arr[i][j];
			}
		}
	}

	//Sort the multidimensional array proj1[][].
	void sortArray(std::array<std::array<int, colSize>, rowSize>& arr) {
		for (int i{ 0 }; i < rowSize; i++) {
			sort(arr[i].begin(), arr[i].end());
		}
	}

	//Get the average of each row of the multidimensional array.
	void avgRow(int *ptr[rowSize], std::array<double, rowSize>& aRow) {
		double sum{ 0 };

		for (int i{ 0 }; i < rowSize ; i++) {
			for (int j{ 0 }; j < colSize - 1; j++) {
				sum += ptr[i][j];
			}
			aRow[i] = round(100*(sum / colSize))/100;
			sum = 0;
		}
	}

private:
	std::array<std::array<int, colSize>, rowSize> arr1;
	std::array<std::array<int, colSize>, rowSize> arr2;
	int *ptr[rowSize];
};


#endif