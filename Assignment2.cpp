//Name: Cameron Shatto
//Class 2018 Fall - COSC 1436.S01
//Project 2: Stock Commission
//Revision 1.0
//Date: 10/13/18
//Description: This program will calculate the total stock commission paid.

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	//declare variables
	double totalShares = 750, sharePrice = 35.00, commission = .02;
	double totalStocks, totalComm, totalPaid;

	//calculate cost of all shares
	totalStocks = totalShares * sharePrice;

	//calculate commission
	totalComm = totalStocks * commission;

	//calculate total amount paid
	totalPaid = totalStocks + totalComm;

	//display inforamtion to console
	cout << "The amount paid for the stock alone is $" << totalStocks << endl;
	cout << "The amount of the commission is " << commission << endl;
	cout << "The total amount paid is $" << totalPaid << endl;

	system("PAUSE");

    return 0;
}

