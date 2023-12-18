// Modifies a number collection
// Kaila Anderson
// 11/09/2022

#include<iostream>
#include "collection.hpp"

using std::cin; using std::cout; using std::endl; 

int main() {
	int size = 1;
	double* dynamic = new double[size];
	double sumOfArray;
	char choice;


	cout << "Hello! Input a number to start your collection!" << endl;
	double start; 
	cin >> start; 
	dynamic[0] = start; 
	sumOfArray = value(dynamic, size);
	cout << "Your collection: ";
	output(dynamic, size);
	cout << "Total Value: " << sumOfArray << endl;

	do {
		cout << "Would You Like To Add(a) or Remove(r) from your collection? (q to Quit): " << endl; 
		cin >> choice;
		if (choice != 'q' || choice != 'Q') {
			switch (choice) {
			case 'a':
				cout << "What number would you like to add?" << endl;
				double add;
				cin >> add; 
				if (check(dynamic, add, size) != -1) 
					cout << "that number is already in your collection." << endl; 
				else addNumber(dynamic, add, size);
				break;
			case 'r': 
				cout << "What number would you like to remove?" << endl;
				double remove;
				cin >> remove; 
				if (check(dynamic, remove, size) == -1)
					cout << "That number is not in your collection." << endl;
				else removeNumber(dynamic, remove, size); 
				break; 	
			}
			sumOfArray = value(dynamic, size);
			cout << "Your collection: "; 
			output(dynamic, size);
			cout << "Total Value: " << sumOfArray << endl;
		}
	} while (choice != 'q'); 

}