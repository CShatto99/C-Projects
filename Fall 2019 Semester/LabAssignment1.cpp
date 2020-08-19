//header files
#include "stdafx.h"
#include <iostream>
using namespace std;

int getMode(int *, const int);
int mode;

int main()
{
	const int size = 15;
	int values[size] = { 1, 8, 2, 8, 8, 5, 8, 4, 4, 3, 6, 6, 7, 3, 9 }, *valPtr;
	//assigning the array values to a pointer
	valPtr = values;
	getMode(valPtr, size);
	cout << "The mode is: " << mode << endl;
	system("PAUSE");
    return 0;
}

int getMode(int *valPtr, const int size) {
	bool noMode = false;
	int index = 1;
	int max = 0;
	mode = *valPtr;
	//looping through the values to find mode
	for (int i = 0; i < size - 1; i++) {
		if (valPtr[i] == valPtr[i + 1]) {
			index++;
			noMode = false;
			if (index > max) {
				max = index;
				mode = valPtr[i];
			}
		}
		else if (noMode == true) {
			mode == -1;
		}
		else 
			index = 1;
	}
	return mode;
}