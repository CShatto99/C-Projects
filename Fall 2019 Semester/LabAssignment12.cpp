// Prime Number Generation
#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;

bool isPrime(int);

int main()
{
	int inVal;
	cout << "Enter an integer: ";
	cin >> inVal;
	vector<int> allNums(inVal-1);
	for (int index = 0; index < allNums.size(); index++) {
		allNums[index] = index+2;
	}
	cout << "Prime Numbers: ";
	for (auto element : allNums) {
		if(isPrime(element)) cout << element << " ";
	}
	cout << endl;
	system("PAUSE");
    return 0;
}

bool isPrime(int element) {
	int factors = 0;
	for (int i = 1; i <= element; i++) {
		if (element % i == 0) {
			factors++;
		}
	}
	return factors == 2;
	factors = 0;
}
