/*
Name: Cameron Shatto
Class: 2018 Fall - COSC 1436.S01
Project 3: Box Office
Revision: 1.0
Date: 09/19/2018
Description: This program will calculate a theater's gross and net box office profit for a night
*/

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	//delcare variables
	string movie;
	float adult, child, gross, net, distributor;
	
	//user input
	cout << "Enter the movie name: ";
	getline(cin, movie);
	cout << "Enter the number of adult tickets: ";
	cin >> adult;
	cout << "Enter the number of child tickets: ";
	cin >> child;

	//perform calculations
	gross = child * 6 + adult * 10;
	net = gross * .2;
	distributor = gross - net;

	//display information to user
	cout << endl;
	cout << "Movie Name: " << movie << endl;
	cout << "Adult Tickets Sold: " << adult << endl;
	cout << "Child Tickets Sold: " << child << endl;
	cout << "Gross Box Office Profit: $" << gross << endl;
	cout << "Net Box Offic Profit: $" << net << endl;
	cout << "Amount Paid to Distributor: $" << distributor << endl;

	system("PAUSE");

    return 0;
}

