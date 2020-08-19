#include "stdafx.h"
#include <iostream>
using namespace std;

class Time {
protected:
	int hour, min, sec;
public:
	// Default constructor
	Time() {
		hour = 0; min = 0; sec = 0;
	}
	// Constructor
	Time(int h, int m, int s) {
		hour = h; min = m; sec = s;
	}
	// Accessor functions
	int getHour() const {
		return hour;
	}
	int getMin() const {
		return min;
	}
	int getSec() const {
		return sec;
	}
};

class MilTime : public Time {
private:
	int milHours;
	int milSeconds;

public:
	MilTime() {

	}
	void setTime(int milH, int milS) {
		// converts military time to standard time
		milHours = milH;
		milSeconds = milS;

		if (milHours >= 2359 || milHours <= 0) {
			throw "Invalid hours input.\n";
		}
		else if (milSeconds >= 59 || milSeconds <= 0) {
			throw "Invalid seconds input.\n";
		}
		else {
			hour = milHours / 100;
			min = (milHours % (hour * 100));
			sec = milSeconds;
		}
	}
	void getHour() {
		// returns time in military format
		cout << "Military Time: " << hour << ":" << min << endl;
	}
	void getStandHr() {
		// returns time in standard format
		if (hour > 12)
			cout << "Standard Time: " << hour % 12 << ":" << min << ":" << sec << " PM\n";
		else
			cout << "Standard Time: " << hour << ":" << min << ":" << sec << " AM\n";
	}
};

int main() {
	int hours, seconds;
	MilTime milTime;

	cout << "Enter the time in military format(Ex: 4:30 PM is 1630): \n";
	cout << "Hours: \n";
	cin >> hours;
	cout << "Seconds: \n";
	cin >> seconds;

	try {
		milTime.setTime(hours, seconds);
		milTime.getHour();
		milTime.getStandHr();
	}
	catch (char *error) {
		cout << "Error: " << error;
	}

	system("PAUSE");
	return 0;
}
