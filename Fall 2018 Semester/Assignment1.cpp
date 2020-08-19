// Assignment1.cpp : Defines the entry point for the console application.
// This program calculates available credit

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	double max, used, available;

	// Get customer's maximum credit
	cout << "Enter the customer's maximum credit. ";
	cin >> max;

	// Get  customer's credit used
	cout << "Enter the amount of credit used by the customer. ";
	cin >> used;

	// Calculate available credit
	available = max - used;

	// Display customer's available credit
	cout << "Available Credit: " << available;
	
	int pause;
	pause = 0;
	cin >> pause;

    return 0;
}

