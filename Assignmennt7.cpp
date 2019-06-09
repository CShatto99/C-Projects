// Name: Cameron Shatto
// Class: 2018 Fall COSC 1436-S01
// Project 7: Driver's License Exam
// Date: 10/24/2018
// Description: This program will prompt the user to enter 20 answers and will then grade those inputs.

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	const int questions = 20;
	char correct[questions] = { 'A','D','B','B','C','B','A','B','C','D','A','C','D','B','D','C','C','A','D','B' };
	char input[questions];
	char grading[questions];
	int sum = 0;
	int finalGrade = questions - sum;

	cout << "This program will grade your Driver's License Exam." << endl;
	cout << "Please enter your answers in capital form. \n" << endl;
	for (int i = 0; i < questions; i++) {
		cout << "Enter your answer for question #" << (i + 1) << endl;
		cin >> input[i];
	
		if (input[i] == correct[i]) {
			grading[i] = 'T';
		}
		else {
			grading[i] = 'F';
		}
	}

	for (int j = 0; j < questions; j++) {
		if (grading[j] == 'F') {
			cout << "#" << (j + 1) << ", ";
		}
		else {
			sum += 1;
		}
		if (sum == 20) {
			cout << "None of your answers ";
		}
	}
	cout << "are(is) incorrect." << endl;

	if (sum >= 15) {
		cout << "You have successfully passed the exam. \n" << endl;
	}
	else {
		cout << "You have failed the exam. \n" << endl;
	}

	cout << "You answered " << sum << " questions correctly." << endl;
	cout << "You answered " << (questions - sum) << " questions incorrectly." << endl;

	system("PAUSE");
    return 0;
}
