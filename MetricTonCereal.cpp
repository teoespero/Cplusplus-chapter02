// MetricTonCereal.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Teodulfo Espero
// BS Cloud and Systems Administration
// BS Software Development
// Western Governors University


#include <iostream>

using namespace std;

int main()
{
	// define const
	const float METRICTON = 35273.92;

	float ounces = 0.00,
		howManyOunces = 0.00;

	int	repeatIt = 1;

	char again = 'y';

	do {
		cout << "Enter the number of ounces: ";
		cin >> ounces;

		howManyOunces = METRICTON / ounces;

		cout << "You need " << howManyOunces << " cereal boxes to get 1 Metric Ton. " << endl;

		cout << "Wold you like to try again (y/n)? ";
		cin >> again;

		if (!(again == 'y') || (again == 'Y'))
			repeatIt = 0;
	
	} while (repeatIt == 1);
}

