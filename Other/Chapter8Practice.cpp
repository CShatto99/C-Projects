
#include "stdafx.h"
#include <iostream>
#include <iomanip>

using namespace std;

void calcSales(const int[], const double[], double[], int);
void dualSort(int[], double[], int);
void swap(int&, int&);
void swap(double&, double&);
void showOrder(const double[], const int[], int);
void showTotal(const double[], const int[], int);

int main() {
	const int prods = 9;
	int id[prods] = { 914, 915, 916, 917, 918, 919, 920, 921, 922 };

	int units[prods] = { 842, 416, 127, 514, 437, 269, 97, 492, 212 };

	double prices[prods] = { 12.95, 14.95, 18.95, 16.95, 21.95, 31.95, 14.94, 14.95, 16.95 };

	double sales[prods];

	calcSales(units, prices, sales, prods);
	dualSort(id, sales, prods);
	cout << setprecision(2) << fixed << showpoint;
	showOrder(sales, id, prods);
	showTotal(sales, units, prods);

	system("PAUSE");
    return 0;
}

void calcSales(const int units[], const double prices[], double sales[], int prods) {
	for (int i = 0; i < prods; i++) {
		sales[i] = units[i] * prices[i];
	}
}

void dualSort(int id[], double sales[], int prods) {
	int start, maxIndex, tempId;
	double maxValue;
	for (start = 0; start < (prods - 1); start++) {
		maxIndex = start;
		maxValue = sales[start];
		tempId = id[start];
		for (int index = start + 1; index < prods; index++) {
			if (sales[index] > maxValue) {
				maxIndex = index;
				maxValue = sales[index];
				tempId = id[index];
			}
		}
		swap(sales[maxIndex], sales[start]);
		swap(id[maxIndex], id[start]);
	}
}

void swap(double &a, double &b) {
	double temp = a;
	a = b;
	b = temp;
}

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

void showOrder(const double sales[], const int id[], int prods) {
	cout << "Product #\tSales\n";
	cout << "----------------------------------" << endl;
	for (int i = 0; i < prods; i++) {
		cout << id[i] << "\t\t$";
		cout << setw(6) << sales[i] << endl;
	}
	cout << endl;
}

void showTotal(const double sales[], const int units[], int prods) {
	int totalUnits = 0;
	double totalSales = 0.0;
	for (int i = 0; i < prods; i++) {
		totalUnits += units[i];
		totalSales += sales[i];
	}
	cout << "Total Units Sold: " << totalUnits << endl;
	cout << "Total Sales: $" << totalSales << endl;
}