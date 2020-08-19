#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

class DayOfYear {
private:
	int day;
	string month;
public:
	bool error;

	DayOfYear(string newMonth, int newDay) {
		month = newMonth;
		day = newDay;
		if (day < 1) {
			error == true;
			cout << "The value entered is not between 1 and 31.\n";
		}
		else
			error = false;
	}

	void print() {
		if (day > 365) {
			day = day % 365;
		}
		if (day > 0 && day <= 31) {
			month = "January";
			cout << month << " " << day << endl;
		}
		else if (day > 31 && day <= 59) {
			month = "February";
			day -= 31;
			cout << month << " " << day << endl;
		}
		else if (day > 59 && day <= 90) {
			month = "March";
			day -= 59;
			cout << month << " " << day << endl;
		}
		else if (day > 90 && day <= 120) {
			month = "April";
			day -= 90;
			cout << month << " " << day << endl;
		}
		else if (day > 120 && day <= 151) {
			month = "May";
			day -= 120;
			cout << month << " " << day << endl;
		}
		else if (day > 151 && day <= 181) {
			month = "June";
			day -= 151;
			cout << month << " " << day << endl;
		}
		else if (day > 181 && day <= 212) {
			month = "July";
			day -= 181;
			cout << month << " " << day << endl;
		}
		else if (day > 212 && day <= 243) {
			month = "August";
			day -= 212;
			cout << month << " " << day << endl;
		}
		else if (day > 243 && day <= 273) {
			month = "September";
			day -= 243;
			cout << month << " " << day << endl;
		}
		else if (day > 273 && day <= 304) {
			month = "October";
			day -= 273;
			cout << month << " " << day << endl;
		}
		else if (day > 304 && day <= 334) {
			month = "November";
			day -= 304;
			cout << month << " " << day << endl;
		}
		else if (day > 334 && day <= 365) {
			month = "December";
			day -= 334;
			cout << month << " " << day << endl;
		}
	}
};

int main() {
	string month;
	int inputDay;

	cout << "Enter a day of the year in integer form (1-365): ";
	cin >> inputDay;
	DayOfYear dayOb = DayOfYear(month, inputDay);
	if (dayOb.error == false) {
		cout << "The date today is: ";
		dayOb.print();

		cout << "The date tomorrow is: ";
		inputDay++;
		dayOb = DayOfYear(month, inputDay);
		dayOb.print();

		cout << "The date two days from now is: ";
		++inputDay;
		dayOb = DayOfYear(month, inputDay);
		dayOb.print();

		cout << "The date yesterday was: ";
		inputDay -= 3;
		dayOb = DayOfYear(month, inputDay);
		dayOb.print();

		cout << "The date two days ago was: ";
		inputDay--;
		dayOb = DayOfYear(month, inputDay);
		dayOb.print();
	}
	system("PAUSE");
	return 0;
}
