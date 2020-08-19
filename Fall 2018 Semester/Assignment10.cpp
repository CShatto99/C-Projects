// Name: Cameron Shatto
// Class: 2018 Fall COSC 1436-S01
// Project 10: Phone Number List
// Date: 12/05/2018
// Description: This program will read a file and allow the user to search the contents of that file.


#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	int counter = 0;
	int results = 0;
	const int numOfStrings = 11;
	string listOfNames[numOfStrings];
	string inputName;

	ifstream contacts;
	contacts.open("contacts.txt");

	while (!contacts.fail()) {
		getline(contacts, listOfNames[counter]);
		counter++;
	}
	contacts.close();

	cout << "Enter a name to be searched and I will display any matches: ";
	cin >> inputName;
	
	for (int i = 0; i < counter; i++) {
		if (listOfNames[i].length() > listOfNames[i].find(inputName.data(), 0)) {
			cout << listOfNames[i] << endl;
			results++;
		}
	}

	if (results == 0)
		cout << "Nothing matches your search: " << endl;;

	system("PAUSE");
    return 0;
}
