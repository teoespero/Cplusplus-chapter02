// QuadraticRoot.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Teodulfo Espero
// BS Cloud and Systems Administration
// BS Software Development
// Western Governors University

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <cstdlib>

using namespace std;

int main() {

	//	define the vars we will be using

	double
		valueforA = 0.00,
		valueforB = 0.00,
		valueforC = 0.00,
		root1 = 0.00,
		root2 = 0.00,
		discriminant = 0.00,
		realPart = 0.00,
		imaginaryPart = 0.00;

	bool
		runagain = true;

	char
		computeagain = 'y';

	//	get the values for a,b, and c
	do {
		cout << "Values for:" << endl;
		cout << "A:.....";
		cin >> valueforA;

		cout << "B:.....";
		cin >> valueforB;

		cout << "C:.....";
		cin >> valueforC;

		//	compute the discriminant to determine the natire of roots
		discriminant = (valueforB * valueforB - 4 * valueforA * valueforC);
		cout << setprecision(2);

		if (valueforA > 0) {
			root1 = (-valueforB + sqrt(discriminant)) / (2 * valueforA);
			root2 = (-valueforB - sqrt(discriminant)) / (2 * valueforA);

			cout << "Roots are real and different." << endl;
			cout << "x1 = " << root1 << endl;
			cout << "x2 = " << root2 << endl;
		}

		else if (discriminant == 0) {
			cout << "Roots are real and the same." << endl;
			root1 = -valueforB / (2 * valueforA);
			cout << "x1 = x2 = " << root1 << endl;
		}
		else {
			realPart = -valueforB / (2 * valueforA);
			imaginaryPart = sqrt(-discriminant) / (2 * valueforA);
			cout << "Roots are complex and different." << endl;
			cout << "x1 = " << realPart << "+" << imaginaryPart << "i" << endl;
			cout << "x2 = " << realPart << "-" << imaginaryPart << "i" << endl;
		}

		do {
			cout << "Make another computation [y/n]?.....";
			cin >> computeagain;

			computeagain = tolower(computeagain);
		} while (!(computeagain == 'n' || computeagain == 'y'));

		if (computeagain == 'n')
			runagain = false;
	} while (runagain);
}