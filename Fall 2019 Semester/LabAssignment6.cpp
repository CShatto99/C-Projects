#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

class DayOfYear {
	private:
		int day;
		string month;
	public:
		DayOfYear(int newDay) {
			day = newDay;
		}
		void print() {
			if (day > 0 && day <= 31) {
				month = "January";
				cout << "Your entry is " << month << " " << day << endl;
			}
			else if (day > 31 && day <= 59) {
				month = "February";
				day -= 31;
				cout << "Your entry is " << month << " " << day << endl;
			}
			else if (day > 59 && day <= 90) {
				month = "March";
				day -= 59;
				cout << "Your entry is " << month << " " << day << endl;
			}
			else if (day > 90 && day <= 120) {
				month = "April";
				day -= 90;
				cout << "Your entry is " << month << " " << day << endl;
			}
			else if (day > 120 && day <= 151) {
				month = "May";
				day -= 120;
				cout << "Your entry is " << month << " " << day << endl;
			}
			else if (day > 151 && day <= 181) {
				month = "June";
				day -= 151;
				cout << "Your entry is " << month << " " << day << endl;
			}
			else if (day > 181 && day <= 212) {
				month = "July";
				day -= 181;
				cout << "Your entry is " << month << " " << day << endl;
			}
			else if (day > 212 && day <= 243) {
				month = "August";
				day -= 212;
				cout << "Your entry is " << month << " " << day << endl;
			}
			else if (day > 243 && day <= 273) {
				month = "September";
				day -= 243;
				cout << "Your entry is " << month << " " << day << endl;
			}
			else if (day > 273 && day <= 304) {
				month = "October";
				day -= 273;
				cout << "Your entry is " << month << " " << day << endl;
			}
			else if (day > 304 && day <= 334) {
				month = "November";
				day -= 304;
				cout << "Your entry is " << month << " " << day << endl;
			}
			else if (day > 334 && day <= 365) {
				month = "December";
				day -= 334;
				cout << "Your entry is " << month << " " << day << endl;
			}
		}
};

// start of main test function
int main() {
	int inputDay;

	for (int i = 0; i < 3; i++) {
		cout << "Enter a day of the year in integer form (1-365): ";
		cin >> inputDay;
		DayOfYear day = DayOfYear(inputDay);
		day.print();
	}

	system("PAUSE");
	return 0;
}
