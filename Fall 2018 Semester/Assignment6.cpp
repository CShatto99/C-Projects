//Name: Cameron Shatto
//Class: 2018 Fall - COSC 1436.S01
//Project 6: Prime Number List
//Revision: 1.0
//Date: 10/31/2018
//Description: This program will write a list of prime numbers to an empty file.

#include "stdafx.h"
#include <iostream>
#include <fstream>
using namespace std;

void input(int);

int main() {
	int interval = 100;
	cout << "The prime numbers 1 to 100 will now be written to an empty file." << endl;
	input(interval);
	system("PAUSE");
}

void input(int interval) {

	ofstream outputFile;
	outputFile.open("OutputFile.txt");
	outputFile << "1" << endl;

	for (int interval = 2; interval <= 100; ++interval)
	{
		int denom = 2;
		for (; denom <= interval - 1; denom++)
		{
			if (interval % denom == 0)
				break;
		}

		if (denom == interval && denom != 2) {
			outputFile << interval << endl;
		}
	}
	outputFile.close();
}

