#include "collection.hpp"
#include <iostream>

using std::cout; using std::cin; using std::endl;
void createCollection(double*&, const int&);
bool foundNumber(double*&, const int&, double);
int main() {
	int size = 10;
	
	double* a = new double[size];

	createCollection(a, size);
	bool complete = 0;
	double number;
	int selection;
	do {
		
		cout << " Menu " << endl
			<< " 1. view collection" << endl
			<< "2. add a number to collection" << endl
			<< "3. remove a number from collection"
			<< "4. exit" <<endl;
		
		cin >> selection;

		switch (selection) {
		case 1:
			cout << "Collection:" << endl;
			output(a, size);
			cout << "Value of Collection: " << value(a, size) << endl;
			break;

		case 2:
			//add a number to collection
			cout << "Enter a number to add to the collection" << endl;
			cin >> number;
			while (foundNumber(a, size, number));

			//add the number to the collection
			addNumber(a, number, size);
			cout << "Collection:"; output(a, size);
			break;

		case 3:
			//remove a number
			cout << "Enter a number to add to the collection" << endl;
			cin >> number;
			removeNumber(a, number, size);
			cout << "Collection:"; output(a, size);
			break;

		case 4:
			complete = 1;
			break;
		}
	} while (!complete);
}

bool foundNumber(double*& a, const int& size, double number) {
	bool found;
	if (check(a, number, size) != -1) {
		cout << "That number is already in the collection try again." << endl;
		found = 1;
	}
	else {
		found = 0;
	}

	while (found) {
		cout << "Enter a number to add to the collection" << endl;
		cin >> number;
		if (check(a, number, size) != -1) {
			cout << "That number is already in the collection try again." << endl;
		}
		else {
			found = 0;
		}
	}
	return found;
}
void createCollection(double*& p, const int& size)
{
	double number;
	for (int i = 0; i < size; ++i) {
		number = i + (size % 4) * ((35 + i)/size);
		p[i] = number;
	}
}
