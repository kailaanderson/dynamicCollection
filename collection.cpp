// Function Definitions
// Kaila Anderson
// November 7, 2022

#include <iostream>
#include "collection.hpp"

using std::cin; using std::cout; using std::endl;

void output(const double* colPtr, const int size) {
	for (int i = 0; i < size; ++i) {
		cout << colPtr[i] << " ";
	}
	cout << endl;
}

double value(const double* colPtr, const int size) {
	double sum = 0;
	for (int i = 0; i < size; ++i) {
		sum += colPtr[i];
	}
	return sum;
}

int check(const double* colPtr, const double number, const int size) {
	for (int i = 0; i < size; ++i) {
		if (colPtr[i] == number) {
			return i;
		}
		else if (i == size - 1) {
			return -1;
		}
		else continue;
	}
}

void addNumber(double*& colPtr, const double number, int& size) {
	int index = check(colPtr, number, size);

	if (index == -1) {

		double* tmpArray = new double[size + 1];
		size++;
		for (int i = 0; i < size - 1; ++i) {
			tmpArray[i] = colPtr[i];
		}

		tmpArray[size - 1] = number;
		delete[] colPtr;
		colPtr = tmpArray;

	}
}

void removeNumber(double*& colPtr, const double number, int& size) {
	if (check(colPtr, number, size) != -1) {
		bool found = false;
		double* tmpArray = new double[size - 1];
		size--;
		for (int i = 0; i < size; ++i) {
			if (colPtr[i] == number) {
				found = true;
			}
			else {
				if (found == false) {
					tmpArray[i] = colPtr[i];
				}
				else
					tmpArray[i - 1] = colPtr[i];

			}
		}
		tmpArray[size - 1] = colPtr[size];
		delete[] colPtr;
		colPtr = tmpArray;
	}
}