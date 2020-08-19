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
public:
	int milHours, milMinutes, milSeconds;
	MilTime() {

	}

	void getTime() {
		cout << "Hours: " << endl;
		cin >> milHours;
		cout << "Seconds: " << endl;
		cin >> milSeconds;
		while (milHours >= 2359 || milHours <= 0 || milSeconds >= 59 || milSeconds <= 0) {
			cout << "Hours must be less than 2400 and greater than or equal to 0.\n";
			cout << "Seconds must be less than 60 and greater than or equal to 0.\n";
			cout << "Hours: " << endl;
			cin >> milHours;
			cout << "Seconds: " << endl;
			cin >> milSeconds;
		}
	}
	void setTime() {
		// converts military time to standard time
		hour = milHours / 100;
		min = milMinutes;
		sec = milSeconds;
	}
	void getHour() {
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

class TimeClock : public MilTime {
private:
	int startTime, endTime;
public:
	TimeClock() {

	}
	TimeClock(int startT, int endT) {
		startTime = startT, endTime = endT;
	}
	int timeElapsed() {
		milHours = (endTime - startTime) / 100;
		milMinutes = (endTime - startTime) % 100;
		if (milMinutes > 60) {
			milHours++;
			milMinutes = milMinutes % 60;
		}
		return milHours;
	}
};

int main()
{
	int startT, endT, deltaH, deltaM;
	
	cout << "Enter the starting time in military format: " << endl;
	cin >> startT;
	while (startT % 100 > 60 || startT > 2349 || startT < 0) {
		cout << "The time you entered was invalid. Try again." << endl;
		cout << "Starting time: ";
		cin >> startT;
	}
	cout << "Enter the ending time in military format: " << endl;
	cin >> endT;
	while (startT > endT) {
		cout << "The starting time must be smaller than the ending time" << endl;
		cout << "Starting time: ";
		cin >> startT;
		cout << "Ending time: ";
		cin >> endT;
	}
	while (endT % 100 > 60 || startT > 2349 || startT < 0) {
		cout << "The time you entered was invalid. Try again." << endl;
		cout << "Ending time: ";
		cin >> endT;
	}

	TimeClock changeInTime(startT, endT);
	deltaH = changeInTime.timeElapsed();
	deltaM = changeInTime.milMinutes;

	cout << "The time elapsed is: " << deltaH << " hours " << deltaM << " minutes " << endl;

	system("PAUSE");
    return 0;
}
