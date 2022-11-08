#include <iostream>

using std::cout; using std::cin; using std::endl;

void output(const double* colPtr, const int size) {
	for (int i = 0; i < size; ++i) {
		cout << colPtr[i] << " ";
	}
	cout << endl;
}

double value(const double* colPtr, const int size) {
	double total = 0;

	for (int i = 0; i < size; ++i) {
		total = total + (colPtr[i]);

	}

	return total;
}
int check(const double* colPtr, const double number, const int size) {
	int arrayindex = 0;
	for (int i = 0; i < size; i++) {
		if (colPtr[i] == number) {
			arrayindex = i;
			break;
		}
			
		else
			arrayindex = -1;
		}

	return arrayindex;	
}

void addNumber(double*& colPtr, const double number, int& size) {
	

	if (check(colPtr, number, size) == -1){
		double* tmp = new double[size + 1];
		size++;
		for (int i = 0; i < size - 1; ++i) {
			tmp[i] = colPtr[i];
		}
		tmp[size - 1] = number;
		delete[] colPtr;
		colPtr = tmp;
	}		
}
void removeNumber(double*& colPtr, const double number, int& size) {
	bool found = 0;
	if (check(colPtr, number, size) != -1) {
		double* tmp = new double[size - 1];
		size--;
		
		for (int i = 0; i < size; ++i) {
			if (colPtr[i] == number) {
				found = 1;
			
			}
			else {
				if (!found)
					tmp[i] = colPtr[i];
				else
					tmp[i - 1] = colPtr[i];
			}
		}
		tmp[size - 1] = colPtr[size];
		delete[] colPtr;
		colPtr = tmp;
	}

}