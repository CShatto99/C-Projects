#include "stdafx.h"
#include <iostream>
using namespace std;

float spent = 0;

struct MonthlyBudget {
	float housing, util, houseExp, trans, food, med, insur, entertain, cloth, misc;
};

MonthlyBudget getInfo(MonthlyBudget[]);
void displayInfo(MonthlyBudget, MonthlyBudget[]);

int main()
{
	MonthlyBudget budget = {500.00, 150.00, 65.00, 50.00, 250.00, 30.00, 100.00, 150.00, 75.00, 50.00};
	MonthlyBudget stu[1];

	getInfo(stu);
	displayInfo(budget, stu);

	system("PAUSE");
    return 0;
}

MonthlyBudget getInfo(MonthlyBudget stu[]) {

	cout << "Enter the monthly expenses of each option.\n";
	cout << "Housing? ";
	cin >> stu[0].housing;
	spent += stu[0].housing;
	cout << "Utilities? ";
	cin >> stu[0].util;
	spent += stu[0].util;
	cout << "Household Expenses? ";
	cin >> stu[0].houseExp;
	spent += stu[0].houseExp;
	cout << "Transportation? ";
	cin >> stu[0].trans;
	spent += stu[0].trans;
	cout << "Food? ";
	cin >> stu[0].food;
	spent += stu[0].food;
	cout << "Medical? ";
	cin >> stu[0].med;
	spent += stu[0].med;
	cout << "Insurance? ";
	cin >> stu[0].insur;
	spent += stu[0].insur;
	cout << "Entertainment? ";
	cin >> stu[0].entertain;
	spent += stu[0].entertain;
	cout << "Clothing? ";
	cin >> stu[0].cloth;
	spent += stu[0].cloth;
	cout << "Miscellaneous? ";
	cin >> stu[0].misc;
	spent += stu[0].misc;
	return stu[0];
}

void displayInfo(MonthlyBudget budget, MonthlyBudget stu[]) {
	float entireMonthly = 1420.00;
	//t = true
	float tHousing = (budget.housing - stu[0].housing),
		tUtil = abs((budget.util - stu[0].util)),
		tHouseExp = abs((budget.houseExp - stu[0].houseExp)),
		tTrans = abs((budget.trans - stu[0].trans)),
		tFood = abs((budget.food - stu[0].food)),
		tMed = abs((budget.med - stu[0].med)),
		tInsur = abs((budget.insur - stu[0].insur)),
		tEntertain = abs((budget.entertain - stu[0].entertain)),
		tCloth = abs((budget.cloth - stu[0].cloth)),
		tMisc = abs((budget.misc - stu[0].misc)),
		tMonthly = abs((entireMonthly - spent));

	if (tHousing > 0)
		cout << "You went " << tHousing << " under your housing budget.\n";
	else if (tHousing <= 0)
		cout << "You went " << tHousing << " over your housing budget.\n";
	if (tUtil > 0)
		cout << "You went " << tUtil << " under your utilities budget.\n";
	else if (tUtil <= 0)
		cout << "You went " << tUtil << " over your utilities budget.\n";
	if (tHouseExp > 0)
		cout << "You went " << tHouseExp << " under your housing expenses budget.\n";
	else if (tHouseExp <= 0)
		cout << "You went " << tHouseExp << " over your housing expenses budget.\n";
	if (tTrans > 0)
		cout << "You went " << tTrans << " under your transportation budget.\n";
	else if (tTrans <= 0)
		cout << "You went " << tTrans << " over your transportation budget.\n";
	if (tFood > 0)
		cout << "You went " << tFood << " under your food budget.\n";
	else if (tFood <= 0)
		cout << "You went " << tFood << " over your food budget.\n";
	if (tMed > 0)
		cout << "You went " << tMed << " under your medical budget.\n";
	else if (tMed <= 0)
		cout << "You went " << tMed << " over your medical budget.\n";
	if (tInsur > 0)
		cout << "You went " << tInsur << " under your insurance budget.\n";
	else if (tInsur <= 0)
		cout << "You went " << tInsur << " over your insurance budget.\n";
	if (tEntertain > 0)
		cout << "You went " << tEntertain << " under your entertainment budget.\n";
	else if (tEntertain <= 0)
		cout << "You went " << tEntertain << " over your entertainment budget.\n";
	if (tCloth > 0)
		cout << "You went " << tCloth << " under your clothing budget.\n";
	else if (tCloth <= 0)
		cout << "You went " << tCloth << " over your clothing budget.\n";
	if (tMisc > 0)
		cout << "You went " << tMisc << " under your miscellaneous budget.\n";
	else if (tMisc <= 0)
		cout << "You went " << tMisc << " over your miscellaneous budget.\n";
	if (tMonthly > 0)
		cout << "You went " << tMonthly << " under your monthly budget.\n";
	else if (tMonthly <= 0)
		cout << "You went " << tMonthly << " over your monthly budget.\n";
}