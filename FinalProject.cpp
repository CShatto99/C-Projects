// Name: Cameron Shatto
// Class: 2018 Fall COSC 1436-S01
// Final Project
// Date: 12/12/2018
// Description: This program will write a multipurpose payroll to an output file 
// based on information from a input file.

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

struct Hourly {
	int hoursWorked;
	double payrate;
};
struct Salary {
	double salary;
	double bonus;
};
union Worker {
	Hourly hourlyPaid;
	Salary salaryPaid;
};

void inputHourly(Worker[], const int);
void hourlyGross(Worker[], const int, ofstream&);
void inputSalary(Worker[], const int);
void salaryGross(Worker[], const int, ofstream&);

int main() {
	double averageHGP = 0;
	double totalHourlyGP = 0;
	ifstream employees;
	employees.open("employees.txt");
	ofstream payroll;
	payroll.open("payroll.txt");

	if (employees.fail()) {
		cerr << "Error opening file." << endl;
		exit(1);
	}

	string empType;
	int salaryCount = 0;
	int hourlyCount = 0;
	while (!employees.eof()) {
		employees >> empType;
		if (empType == "Hourly-employee") {
			hourlyCount++;
		}
		if (empType == "Salary-employee") {
			salaryCount++;
		}
	}
	employees.close();

	cout << "There are " << hourlyCount << " hourly paid employees." << endl;
	cout << "There are " << salaryCount << " salary paid employees." << endl;
	payroll << "There are " << hourlyCount << " hourly paid employees." << endl;
	payroll << "There are " << salaryCount << " salary paid employees." << endl;

	Worker *hourlyPtr = nullptr;
	hourlyPtr = new Worker[hourlyCount];
	Worker *salaryPtr = nullptr;
	salaryPtr = new Worker[salaryCount];

	inputHourly(hourlyPtr, hourlyCount);
	hourlyGross(hourlyPtr, hourlyCount, payroll);
	inputSalary(salaryPtr, salaryCount);
	salaryGross(salaryPtr, salaryCount, payroll);

	payroll.close();

	delete[] hourlyPtr;
	delete[] salaryPtr;

	system("PAUSE");
	return 0;
}

void inputHourly(Worker newWorker[], const int hourlyCount) {
	int i = 0;
	while (i < hourlyCount) {
		cout << "Enter the hours worked by employee #" << (i + 1) << ": ";
		cin >> newWorker[i].hourlyPaid.hoursWorked;

		while (newWorker[i].hourlyPaid.hoursWorked < 0 || newWorker[i].hourlyPaid.hoursWorked > 80) {
			cout << "Enter the hours worked by employee #" << (i + 1) << ": ";
			cin >> newWorker[i].hourlyPaid.hoursWorked;
		}
		cout << "Enter the payrate of the employee #" << (i + 1) << ": ";
		cin >> newWorker[i].hourlyPaid.payrate;

		while (newWorker[i].hourlyPaid.payrate < 0) {
			cout << "The payrate must be greater that or equal to zero.";
			cin >> newWorker[i].hourlyPaid.payrate;
		}
		i++;
	}
}

void hourlyGross(Worker newWorker[], const int hourlyCount, ofstream& payroll) {
	double grossHourly;
	double totalHourlyGP = 0;
	double averageHGP;
	for (int i = 0; i < hourlyCount; i++) {
		grossHourly = newWorker[i].hourlyPaid.hoursWorked * newWorker[i].hourlyPaid.payrate;
		totalHourlyGP += grossHourly;
	}
	averageHGP = totalHourlyGP / hourlyCount;
	cout << "The average weekly pay for hourly paid workers is: $" << averageHGP << endl;
	cout << "The total weekly pay for the hourly paid employees is: $" << totalHourlyGP << endl;
	payroll << "The average weekly pay for hourly paid workers is: $" << averageHGP << endl;
	payroll << "The total weekly pay for the hourly paid employees is: $" << totalHourlyGP << endl;
}

void inputSalary(Worker newWorker[], const int salaryCount) {
	double bonusConversion;
	for (int i = 0; i < salaryCount; i++) {
		cout << "Enter the salary of employee #" << (i + 1) << ": ";
		cin >> newWorker[i].salaryPaid.salary;

		while (newWorker[i].salaryPaid.salary < 0) {
			cout << "Enter the salary of employee #" << (i + 1) << ": ";
			cin >> newWorker[i].salaryPaid.salary;
		}
		cout << "Enter the bonus precentage (0%-99%): ";
		cin >> newWorker[i].salaryPaid.bonus;
		newWorker[i].salaryPaid.bonus = (newWorker[i].salaryPaid.bonus) / 100;

		while (newWorker[i].salaryPaid.bonus < 0 || newWorker[i].salaryPaid.bonus > 99) {
			cout << "The bonus must be between 0% and 99%. ";
			cin >> newWorker[i].salaryPaid.bonus;
		}
	}
}

void salaryGross(Worker newWorker[], const int salaryCount, ofstream &payroll) {
	double grossSalary;
	double actualBonus;
	double totalSalaryGP = 0;
	double averageSGP;
	for (int i = 0; i < salaryCount; i++) {
		actualBonus = newWorker[i].salaryPaid.salary * newWorker[i].salaryPaid.bonus;
		grossSalary = (newWorker[i].salaryPaid.salary + actualBonus) / 52;
		totalSalaryGP += grossSalary;
	}
	averageSGP = totalSalaryGP / salaryCount;
	cout << "The average weekly pay for salary paid workers is: $" << averageSGP << endl;
	cout << "The total weekly pay for the salary paid employees is: $" << totalSalaryGP << endl;
	payroll << "The average weekly pay for salary paid workers is: $" << averageSGP << endl;
	payroll << "The total weekly pay for the salary paid employees is: $" << totalSalaryGP << endl;
}