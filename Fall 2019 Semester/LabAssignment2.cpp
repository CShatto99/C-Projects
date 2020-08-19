#include "stdafx.h"
#include <iostream>
using namespace std;

int vowels(char*);
int consonants(char*);

int main() {
	char input[100];
	char choice[4];
	int consAndVowel;
	//user menu
	cout << "Enter a string that is no more than 100 characters, replace spaces with (_) or (-).\n";
	cin >> input;
	cout << "Enter one of the options below.\n";
	cout << "1.Count the number of vowels in the string.\n";
	cout << "2.Count the number of consonants in the string.\n";
	cout << "3.Counter both the vowels and consonants in the string.\n";
	cout << "4.Enter another string.\n";
	cout << "5.Exit the program.\n";
	while (1) {
		cin >> choice;
		if (choice[0] == '1') {
			vowels(input);
			cout << "Your entry contains " << vowels(input) << " vowel(s).\n\n";
		}
		else if (choice[0] == '2') {
			consonants(input);
			cout << "Your entry contains " << consonants(input) << " consonant(s).\n\n";
		}
		else if (choice[0] == '3') {
			vowels(input);
			consonants(input);
			consAndVowel = vowels(input) + consonants(input);
			cout << "Your entry contains " << consAndVowel << " vowels and consonants.\n";
		}
		else if (choice[0] == '4') {
				cout << "Enter a string that is no more than 100 characters, replace spaces with (_) or (-):\n";
				cin >> input;
				cout << "Enter one of the original options.\n";
		}
		else if (choice[0] >= '5' || choice[0] < '0') {
			return 0;
		}
	}
	system("pause");
}

int vowels(char* input) {
	int vowelCount = 0;
	for (int i = 0; *(input + i) != '\0'; i++) {
		*(input + i) = toupper(*(input + i));
		switch (*(input + i)) {
		//if char is one of the cases, increment the counter.
		case 'A': case 'E': case 'I': case 'O': case 'U':
			vowelCount++;
			break;
		default:
			break;
		}
	}
	return vowelCount;
}

int consonants(char* input) {
	int consCount = 0;
	for (int i = 0; *(input + i) != '\0'; i++) {
		*(input + i) = toupper(*(input + i));
		//checking if each char is a letter
		if (isalpha(*(input + i))) {
			switch (*(input + i)) {
			case 'A': case 'E': case 'I': case 'O': case 'U':
				break;
			default:
				consCount++;
				break;
			}
		}
	}
	return consCount;
}