#include <iostream>

using namespace std;

/*******************************************************
 gparap: Mathematics
		 - least common multiple
		 - greatest common divisor
		 - sum of custom positive numbers divisible by 2
 *******************************************************/

int main() {

	/*least common multiple*/
	cout << "least common multiple" << endl;
	cout << "***********************" << endl;
	int number1 = 0, number2 = 0;
	int gcd = 1;
	int lcm = 1;

	cout << "Give 1st positive integer: " << endl;
	cin >> number1;
	cout << "Give 2nd positive integer: " << endl;
	cin >> number2;
	gcd = number1 < number2 ? number1 : number2;

	for (int i = gcd; i > 0; i--) {
		if (number1 % i == 0 && number2 % i == 0) {
			gcd = i;
			break;
		}
	}

	if (gcd == 1)
		lcm = number1 * number2;
	else
		lcm = (number1 * number2) / gcd;

	cout << "*******" << endl;
	cout << "gcd = " << gcd << endl;
	cout << "*******" << endl;
	cout << "lcm = " << lcm << endl;
	
	/*greatest common divisor*/
	cout << "greatest common divisor" << endl;
	cout << "***********************" << endl;
	int number1 = 0, number2 = 0;
	int gcd = 1;

	cout << "Give 1st positive integer: " << endl;
	cin >> number1;
	cout << "Give 2nd positive integer: " << endl;
	cin >> number2;
	gcd = number1 < number2 ? number1 : number2;

	for (int i = gcd; i > 0; i--) {
		if (number1 % i == 0 && number2 % i == 0) {
			gcd = i;
			break;
		}
	}
	cout << "------" << endl;
	cout << "gcd = " << gcd << endl;
	cout << "------" << endl;

	/*sum of custom positive numbers divisible by 2*/
	cout << "sum of custom positive numbers divisible by 2" << endl;
	cout << "*********************************************" << endl;
	int number = -1;
	int sum = 0;
	while (number != 0) {
		cout << "Give a positive number divisible by 2: (exit=0)" << endl;
		cin >> number;
		if (number > 0) {
			if (number % 2 == 0) {
				sum += number;
			}
		}
	}
	cout << "------" << endl;
	cout << "sum = " << sum << endl;
	cout << "------" << endl;
	
	return 0;
}