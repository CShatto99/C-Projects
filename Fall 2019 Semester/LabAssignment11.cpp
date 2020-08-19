// This project receives a specified number of test scores and outputs the average.
#include "stdafx.h"
#include <iostream>
using namespace std;

class TestScores {
private:
	double total = 0, average;
	int *scores, size;
public:
	TestScores(int *arr, int size_) {
		scores = arr;
		size = size_;
	}

	double avgTestScore() {
		for (int i = 0; i < size; i++) {
			if (scores[i] < 0 || scores[i] > 100) throw "Invalid test score.\n";
			total += scores[i];
		}
		average = total / size;
		return average;
	}

	~TestScores() {
		delete[] scores;
	}
};

int main()
{
	int size;
	int *sizePtr = nullptr;
	cout << "Enter the number of test scores: ";
	cin >> size;
	sizePtr = new int[size];
	cout << "Enter the score for each test (0-100).\n";
	for (int i = 0; i < size; i++) {
		cout << "Test " << (i + 1) << ": ";
		cin >> sizePtr[i];
	}

	TestScores newScores(sizePtr, size);
	try {
		cout << "The average was: " << newScores.avgTestScore() << endl;
	}
	catch (char *error) {
		cout << "Error: " << error;
	}
	
	delete[] sizePtr;
	sizePtr = nullptr;
	system("PAUSE");
    return 0;
}
