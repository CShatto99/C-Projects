#include "stdafx.h"
#include <iostream>
#include <fstream>  
#include <iomanip>
using namespace std;

struct recordDate {
	int M, D, YYYY;
};

struct Inventory {
	char desc[100];
	int quantity;
	float wholesale, retail;
	recordDate date;
};

void addRecord(Inventory);
void displayRecord(Inventory);
void modifyRecord(Inventory);

int main()
{
	int choice;
	int itemID = 1;
	char restart;

	fstream recordFile("inventory.txt", ios::out | ios::binary);
	Inventory newItem = { "", 0, 0.0 };

	for (int i = 1; i < 10; i++) {
		recordFile.write(reinterpret_cast<char *>(&newItem), sizeof(newItem));
	}

	do {
		cout << "Choose option one through four.\n";
		cout << "1.Add a new record to the file.\n";
		cout << "2.Display a record from the file.\n";
		cout << "3.Modify a record in the file.\n";
		cout << "4.Exit\n\n";
		cin >> choice;

		while (choice < 1 || choice > 4) {
			cout << "Enter a number one through four.\n";
			cin >> choice;
		}

		switch (choice) {
			case 1:
				cout << "Record ID number: " << itemID++ << endl;
				addRecord(newItem);
				break;
			case 2:
				displayRecord(newItem);
				break;
			case 3:
				modifyRecord(newItem);
				break;
			default:
				return 0;
		}
		cout << "Want to add, edit, or view another record? 'Y' for yes or 'N' for no.\n";
		cin >> restart;
		restart = toupper(restart);
	} while (restart == 'Y');

	recordFile.close();
	system("PAUSE");
	return 0;
}

void addRecord(Inventory newItem) {
	fstream recordFile("inventory.txt", ios::out | ios::binary);
	recordFile.seekp(sizeof(newItem), ios::end);

	cout << "Enter the description of the item: ";
	cin.ignore();
	cin.getline(newItem.desc, 100);

	cout << "Enter the quantity of the item: ";
	cin >> newItem.quantity;
	while (newItem.quantity < 0) {
		cout << "The quantity must be greater than or equal to zero.\n" << "Enter the quantity of the item: ";
		cin >> newItem.quantity;
	}

	cout << "Enter the wholesale cost: ";
	cin >> newItem.wholesale;
	while (newItem.wholesale < 0) {
		cout << "The wholesale cost must be greater than or equal to zero.\n" << "Enter the wholesale cost of the item: ";
		cin >> newItem.wholesale;
	}

	cout << "Enter the retail cost: ";
	cin >> newItem.retail;
	while (newItem.retail < 0) {
		cout << "The retail cost must be greater than or equal to zero.\n" << "Enter the retail cost of the item: ";
		cin >> newItem.retail;
	}

	cout << "Enter today's date:\n";
	cout << "Month (M): ";
	cin >> newItem.date.M;
	while (newItem.date.M < 1 || newItem.date.M > 12) {
		cout << "Enter a month that is valid: ";
		cin >> newItem.date.M;
	}

	cout << "Day (D): ";
	cin >> newItem.date.D;
	while (newItem.date.D < 1 || newItem.date.D > 31) {
		cout << "Enter a day that is valid: ";
		cin >> newItem.date.D;
	}

	cout << "Year (YYYY): ";
	cin >> newItem.date.YYYY;
	while (newItem.date.YYYY < 2000 || newItem.date.YYYY > 2200) {
		cout << "Enter a year that is valid (2000 to 2200): ";
		cin >> newItem.date.YYYY;
	}

	recordFile.write(reinterpret_cast<char *>(&newItem), sizeof(newItem));
	recordFile.close();
}

void displayRecord(Inventory newItem) {
	fstream recordFile("inventory.txt", ios::in | ios::binary);
	recordFile.seekg (sizeof(newItem), ios::beg);
	recordFile.read(reinterpret_cast<char *>(&newItem), sizeof(newItem));

	while (!recordFile.eof()) {
		cout << "Description: " << newItem.desc << endl;
		cout << "Quantity: " << newItem.quantity << endl;
		cout << "Wholesale cost: " << newItem.wholesale << endl;
		cout << "Retail cost: " << newItem.retail << endl;
		cout << "Date Added: " << newItem.date.M << "/" << newItem.date.D << "/" << newItem.date.YYYY << endl;
		recordFile.read(reinterpret_cast<char *>(&newItem), sizeof(newItem));
	}
	recordFile.close();
}

void modifyRecord(Inventory newItem) {
	int recordID;
	fstream recordFile("inventory.txt", ios::in | ios::out | ios::binary);

	cout << "Which record do you want to edit? ";
	cin >> recordID;
	recordFile.seekg(recordID * sizeof(newItem), ios::beg);
	recordFile.read(reinterpret_cast<char *>(&newItem), sizeof(newItem));

	cout << "Description: " << newItem.desc << endl;
	cout << "Quantity: " << newItem.quantity << endl;
	cout << "Wholesale cost: " << newItem.wholesale << endl;
	cout << "Retail price: " << newItem.retail << endl;
	cout << "Date added to inventory: " << newItem.date.M << "/" << newItem.date.D << "/" << newItem.date.YYYY << endl;

	cout << "Enter the description of the item: ";
	cin.ignore();
	cin.getline(newItem.desc, 100);

	cout << "Enter the quantity of the item: ";
	cin >> newItem.quantity;
	while (newItem.quantity < 0) {
		cout << "The quantity must be greater than or equal to zero.\n" << "Enter the quantity of the item: ";
		cin >> newItem.quantity;
	}

	cout << "Enter the wholesale cost: ";
	cin >> newItem.wholesale;
	while (newItem.wholesale < 0) {
		cout << "The wholesale cost must be greater than or equal to zero.\n" << "Enter the wholesale cost of the item: ";
		cin >> newItem.wholesale;
	}

	cout << "Enter the retail cost: ";
	cin >> newItem.retail;
	while (newItem.retail < 0) {
		cout << "The retail cost must be greater than or equal to zero.\n" << "Enter the retail cost of the item: ";
		cin >> newItem.retail;
	}

	cout << "Enter today's date:\n";
	cout << "Month (M): ";
	cin >> newItem.date.M;
	while (newItem.date.M < 1 || newItem.date.M > 12) {
		cout << "Enter a month that is valid: ";
		cin >> newItem.date.M;
	}

	cout << "Day (D): ";
	cin >> newItem.date.D;
	while (newItem.date.D < 1 || newItem.date.D > 31) {
		cout << "Enter a day that is valid: ";
		cin >> newItem.date.D;
	}

	cout << "Year (YYYY): ";
	cin >> newItem.date.YYYY;
	while (newItem.date.YYYY < 2000 || newItem.date.YYYY > 2200) {
		cout << "Enter a year that is valid (2000 to 2200): ";
		cin >> newItem.date.YYYY;
	}

	recordFile.seekp(recordID * sizeof(newItem), ios::beg);
	recordFile.write(reinterpret_cast<char *>(&newItem), sizeof(newItem));
	recordFile.close();
}