// HelloWorld.cpp
// Created by gparap

#include <iostream>
#include <time.h>

using namespace std;

int Multiplier(int a, int b) {

	return a * b;
}
void MultiplierCallback() {
	int a = 0, b = 0;
	cout << "Give number: "; cin >> a;
	cout << "Give number: "; cin >> b;
	cout << a << " * " << b << " = " << Multiplier(a, b) << endl;
}
void findOddNumbers() {
	int min = 1, max = 49;

	// user interface
	cout << "Give min and max numbers (1-49)" << endl;
	cout << "min = ? "; cin >> min;
	cout << "max = ? "; cin >> max;

	// prind odd numbers only
	cout << "Odd numbers are: " << endl;
	for (int i = min; i <= max; i++) {
		if (i % 2 == 0) {
			continue;
		}
		cout << i << " ";
	}
	cout << endl;
}
void findEvenNumbers() {
	int min = 1, max = 49;

	// user interface
	cout << "Give min and max numbers (1-49)" << endl;
	cout << "min = ? "; cin >> min;
	cout << "max = ? "; cin >> max;

	// prind odd numbers only
	cout << "Even numbers are: " << endl;
	for (int i = min; i <= max; i++) {
		if (i % 2 != 0) {
			continue;
		}
		cout << i << " ";
	}
	cout << endl;
}

int main()
{
	Init();

	// randomize greeting
	int x = 0;
	srand(time(0));
	x = rand() % 2;
	if (x == 0) {
		cout << "Hello World\n";
	}

	// multiply
	char answerMultiply = 'n';
	for (int i = 0; i < 5; i++) {
		MultiplierCallback();
		cout << "Multiply again? (y/n)";
		cin >> answerMultiply;
		if (answerMultiply == 'n')
			break;
	}

	// remove one from number
	int number;
	cout << "Give a number (2..9)";
	cin >> number;
	do {
		number -= 1;
		cout << "number - 1 = " << number << endl;
	} while (number > 0);

	// print odd and even numbers from a sequence
	findOddNumbers();
	findEvenNumbers();

	// hold the sreen
	cout << endl;
	cout << "Program will now exit...";
	cin.get();
	cin.get();
}
