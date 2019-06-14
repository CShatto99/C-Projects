// Name: Cameron Shatto
// Class: 2018 Fall COSC 1436-S01
// Project 11: Course Grade
// Date: 12/08/2018
// Description: This program manipulates user input, stores it in a structure, and display the output.
#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Student {
	string name;
	int idNum;
	double tests;
	double average;
	char grade;
};

void getInfo(Student[], const int, int);
void getAverage(Student[], const int);
void displayInfo(Student[], const int);

int main() {
	int numOfTests;
	int numOfStudents;

	cout << "Enter how many students there are: " << endl;
	cin >> numOfStudents;

	Student *stuPtr = nullptr;
	stuPtr = new Student[numOfStudents];

	cout << "Enter how many test scores there are: " << endl;
	cin >> numOfTests;

	getInfo(stuPtr, numOfStudents, numOfTests);

	getAverage(stuPtr, numOfStudents);

	displayInfo(stuPtr, numOfStudents);

	system("PAUSE");
	return 0;
}

void getInfo(Student newStu[], const int students, int numTests) {
	int counter = 0;
	double total = 0.0;
	for (int i = 0; i < students; i++) {
		cout << "Enter the name of student #" << (i + 1) << ":" << endl;
		cin >> newStu[i].name;
		cout << "Enter the ID number for " << newStu[i].name << ":" << endl;
		cin >> newStu[i].idNum;

		while (counter < numTests) {
			cout << "Enter test score #" << (counter + 1) << " for " << newStu[i].name << ": " << endl;
			cin >> newStu[i].tests;
			if (newStu[i].tests < 0) {
				cout << "Please enter a postive test score." << endl;
			}
			else if (newStu[i].tests >= 0) {
				counter++;
				total += newStu[i].tests;
			}
		}
		counter = 0;
		newStu[i].average = total / numTests;
		total = 0;
	}
}

void getAverage(Student newStu[], const int students) {
	for (int i = 0; i < students; i++) {
		if (newStu[i].average >= 90 && newStu[i].average <= 100) {
			newStu[i].grade = 'A';
		}
		if (newStu[i].average >= 80 && newStu[i].average < 90) {
			newStu[i].grade = 'B';
		}
		if (newStu[i].average >= 70 && newStu[i].average < 80) {
			newStu[i].grade = 'C';
		}
		if (newStu[i].average >= 60 && newStu[i].average < 70) {
			newStu[i].grade = 'D';
		}
		if (newStu[i].average < 60 && newStu[i].average >= 0) {
			newStu[i].grade = 'F';
		}
	}
}

void displayInfo(Student newStu[], const int students) {
	cout << "Name\t\tID\t\tAverage\t\tGrade" << endl;
	cout << "------------------------------------------------------" << endl;
	for (int i = 0; i < students; i++) {
		cout << setprecision(2);
		cout << newStu[i].name << "\t\t"
			 << newStu[i].idNum << "\t\t"
			 << newStu[i].average << "\t\t"
			 << newStu[i].grade << endl;
	}
}