// Name: Cameron Shatto
// Class: 2018 Fall COSC 1436-S01
// Project 9: Reverse Array
// Date: 11/27/2018
// Description: This program will take the contents of an array and reverse it.

#include "stdafx.h"
#include <iostream>

using namespace std;

void reverse(int [], int);

int main() {
	const int size = 6;
	int firstArr[size] = { 5, 10, 15, 20, 25, 30 };

	reverse(firstArr, size);

	system("PAUSE");
    return 0;
}

void reverse(int arr[], int size) {
	int *numPtr = arr;

	cout << "Content of the starting array: ";
	for (int i = 0; i < size; i++) {
		cout << *numPtr << " ";
		numPtr++;
	}
	cout << endl;

	cout << "Contents of the reversed array: ";
	while (numPtr > arr) {
		numPtr--;
		cout << *numPtr << " ";
	}
	cout << endl;
}