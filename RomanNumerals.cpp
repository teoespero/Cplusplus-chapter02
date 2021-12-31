// RomanNumerals.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

	//	define the vars that we will be using
	int
		year = 0,
		thousands = 0,
		hundreds = 0,
		tens = 0,
		ones = 0;

	string
		romannumeral = "";


	bool
		validyear = false,
		runagain = true;

	char
		convertanotheryear = 'y';

	//	program starts
	do {
		do {

			//	get a year input from the user
			cout << "Numeric Year to Roman Numeral Converter" << endl;
			cout << "----------------------------------------" << endl;
			cout << "Year(yyyy format)....";
			cin >> year;

			//	check if the year is within the range required
			if (year >= 1000 && year <= 3000)
				validyear = true;
			else
				cout << "\t**** Invalid year." << endl;
		} while (!(validyear));

		//	break down the pieces of 
		//		thousands
		//		hundreds
		//		tens
		//		ones
		if (year > 900) {
			thousands = year / 1000;
			year = year - (thousands * 1000);
		}

		if (year > 99) {
			hundreds = year / 100;
			year = year - (hundreds * 100);
		}

		if (year > 9) {
			tens = year / 10;
			year = year - (tens * 10);
		}

		if (year > 0) {
			ones = year / 1;
			year = year - (ones * 1);
		}


		//	show the breakdown
		cout << endl << "Results..." << endl;
		cout << "\t" << "---------------------------------" << endl;
		cout << "\t" << "Thousands....." << thousands << endl;
		cout << "\t" << "Hundreds....." << hundreds << endl;
		cout << "\t" << "Tens....." << tens << endl;
		cout << "\t" << "Ones....." << ones << endl;

		//	perform the conversion
		if (thousands > 0)
			for (int counterforM = 0; counterforM < thousands; counterforM++)
				romannumeral = romannumeral + "M";
		if (hundreds > 8)
			romannumeral = romannumeral + "CM";
		else {
			if (hundreds > 4) {
				romannumeral = romannumeral + "D";
				hundreds = hundreds - 5;
			}
			for (int counterforC = 0; counterforC < hundreds; counterforC++)
				romannumeral = romannumeral + "C";
		}
		if (tens > 4) {
			romannumeral = romannumeral + "L";
			if (tens > 5) {
				tens = tens - 5;
				for (int counterforLX = 0; counterforLX < tens; counterforLX++)
					romannumeral = romannumeral + "X";
			}
		}
		else {
			if (tens > 3)
				romannumeral = romannumeral + "XL";
			if (tens > 1) {
				for (int counterforX = 0; counterforX < tens; counterforX++)
					romannumeral = romannumeral + "X";
			}
			if (tens == 1)
				romannumeral = romannumeral + "X";
		}
		if (ones > 9) {
			romannumeral = romannumeral + "X";
		}
		if (ones == 9) {
			romannumeral = romannumeral + "IX";
		}
		else {
			if (ones > 4) {
				romannumeral = romannumeral + "V";
				ones = ones - 5;
				for (int counterforVI = 0; counterforVI < ones; counterforVI++)
					romannumeral = romannumeral + "I";
			}
			else if (ones > 3)
				romannumeral = romannumeral + "IV";
			else
				for (int counterforI = 0; counterforI < ones; counterforI++)
					romannumeral = romannumeral + "I";
		}

		//	display the converted results
		cout << "\t" << "---------------------------------" << endl;
		cout << "\t" << "Roman numeral..... " << romannumeral << endl;

		do {
			cout << endl << "Would you like to convert another year [y/n]?.....";
			cin >> convertanotheryear;

			convertanotheryear = tolower(convertanotheryear);
		} while (!(convertanotheryear == 'y' || convertanotheryear == 'n'));

		if (convertanotheryear == 'n')
			runagain = false;
		else {
			thousands = 0;
			hundreds = 0;
			tens = 0;
			ones = 0;
			romannumeral = "";
		}
	} while (runagain);

	//	user wants to exit
	cout << endl << "Goodbye." << endl;
}