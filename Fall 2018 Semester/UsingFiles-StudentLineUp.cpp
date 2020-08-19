// Name: Cameron Shatto
// Class: 2018 Fall - COSC 1436-S01
// Project 5: Using Files-Student Line Up
// 10/24/2018
// Decription: This program will read a file of students and 
// display the first and last student based on their first name

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	string first, last;
	ifstream inputFile;

	inputFile.open("LineUp.txt");

	char word[100];
	inputFile >> word;
	first = last = word;
	cout << "The students are: " << endl;
	cout << endl;

	while (inputFile >> word) {

		if (word > last) {
			last = word;
		}
		else if (word < first) {
			first = word;
		}

		cout << word << endl;
	}

	cout << endl;
	cout << first << " is at the beginning of the line. \n" << endl;
	cout << last << " is at the back of the line. \n" << endl;

	system("PAUSE");
	return 0;
}

