//Name: Cameron Shatto
//Class: 2018 Fall - COSC 1436.S01
//Project 4: Speed of Sound in Gases
//Revision: 1.0
//Date: 10/08/18
//Description: This progam will utilize user I/O to determine the speed of sound in gases.

#include "stdafx.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{

	int gas;
	int seconds;
	int minSec = 0;
	int maxSec = 30;

	const double
		carbonDioxide_S = 258.0,
		air_S = 331.5,
		helium_S = 972.0,
		hydrogen_S = 1270.0;

	const int
		carbon = 1,
		air = 2,
		helium = 3,
		hydrogen = 4;

	cout
		<< left << setw(25) << "Medium"
		<< left << setw(25) << "Speed (Meters per Second)" << endl
		<< left << setw(25) << "1. Carbon Dioxide"
		<< left << setw(25) << "258.0" << endl
		<< left << setw(25) << "2. Air"
		<< left << setw(25) << "331.5" << endl
		<< left << setw(25) << "3. Helium"
		<< left << setw(25) << "972.0" << endl
		<< left << setw(25) << "4. Hydrogen"
		<< left << setw(25) << "1270.0" << endl
		<< endl
		<< "Choose the number of a gas that is listed: " << endl;
	cin >> gas;


	if (gas == carbon)
	{

		cout << "Enter the amount of seconds sound traveled through Carbon Dioxide: " << endl;
		cin >> seconds;

		if (seconds < maxSec && seconds > minSec)
		{
			double sourceDistance = seconds * 258.0;
			cout << "The source of the sound was " << sourceDistance << " meters away.";
			cin.get();
		}
		else
		{
			cout << "Invalid response: enter a time between 0 and 30 seconds.";
			cin.get();
		}

	}

	else if (gas == air)
	{
		cout << "Enter the amount of seconds sound traveled through Air: " << endl;
		cin >> seconds;

		if (seconds < maxSec && seconds > minSec)
		{
			double sourceDistance = seconds * 331.5;
			cout << "The source of the sound was " << sourceDistance << " meters away.";
			cin.get();
		}
		else
		{
			cout << "Invalid response: enter a time between 0 and 30 seconds.";
			cin.get();
		}

	}

	else if (gas == helium)
	{
		cout << "Enter the amount of seconds sound traveled through Helium: " << endl;
		cin >> seconds;

		if (seconds < maxSec && seconds > minSec)
		{
			double sourceDistance = seconds * 972.0;
			cout << "The source of the sound was " << sourceDistance << " meters away.";
			cin.get();
		}
		else
		{
			cout << "Invalid response: enter a time between 0 and 30 seconds.";
			cin.get();
		}

	}

	else if (gas == hydrogen)
	{
		cout << "Enter the amount of seconds sound traveled through Hydrogen: " << endl;
		cin >> seconds;

		if (seconds < maxSec && seconds > minSec)
		{
			double sourceDistance = seconds * 1270.0;
			cout << "The source of the sound was " << sourceDistance << " meters away.";
			cin.get();
		}
		else
		{
			cout << "Invalid response: enter a time between 0 and 30 seconds.";
			cin.get();
		}

	}

	else
	{
		cout << "Reboot the program and choose a gas that is listed.";
		cin.get();
	}

	cin.get();
    return 0;
}

 