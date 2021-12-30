// budgetforecast.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

int main()
{
	//	define the const
	const int CURRENTYEAR = 2021;

	//	define the vars we will be using
	string 
		itemname = "";

	double
		itemcost = 0.00,
		projectedcost = 0.00,
		inflationrate = 0.00,
		decimaledinflationrate = 0.00,
		growth = 0.01,
		annualcost = 0.00;

	int
		yearstoproject = 0,
		howmanydoyouneed = 0.00;

	bool
		validitemname = false,
		validitemcost = false,
		inflationratevalid = false,
		validprojectionyear = false,
		validquantity = false,
		repeattheapp = true;

	char
		again = 'y';
	
	do {
		//	get inputs from our user
		//	validate the inputs at each step


		//	item name
		do {
			cout << "Item name: ";
			cin >> itemname;
			if (itemname.length() < 3)
				cout << "\t***Invalid item name." << endl;
			else
				validitemname = true;
		} while (!(validitemname));

		//	item cost
		do {
			cout << "Item cost: ";
			cin >> itemcost;

			if (itemcost <= 0)
				cout << "\t***Invalid item cost." << endl;
			else
				validitemcost = true;
		} while (!(validitemcost));

		//	how many do you need
		do {
			cout << "Item quantity: ";
			cin >> howmanydoyouneed;

			if (howmanydoyouneed < 1)
				cout << "\t***Invalid quantity." << endl;
			else
				validquantity = true;
		} while (!(validquantity));

		//	inflation rate
		do {
			cout << "Inflation rate (%): ";
			cin >> inflationrate;

			if (inflationrate <= 0)
				cout << "\t***Invalid inflation rate." << endl;
			else
				inflationratevalid = true;
		} while (!(inflationratevalid));

		//	years to project
		do {
			cout << "Years to project: ";
			cin >> yearstoproject;

			if (yearstoproject < 1)
				cout << "\t***Invalid projection year." << endl;
			else
				validprojectionyear = true;
		} while (!(validprojectionyear));

		//	all data is valid
		//	perform computations

		cout << endl << endl << "Projected cost of a " << itemname << endl;
		cout << "\t\tYear\t\t\tItemcost\t\tQuantity\t\tAnnual Cost" << endl;
		cout << setprecision(2);
		for (int yearbeingprojected = CURRENTYEAR; yearbeingprojected <= (CURRENTYEAR + yearstoproject); yearbeingprojected++) {
			if (yearbeingprojected > CURRENTYEAR) {
				decimaledinflationrate = (inflationrate / 100.00);
				growth = growth + 0.01;
				howmanydoyouneed = howmanydoyouneed + (howmanydoyouneed * growth);
			}
			itemcost = itemcost + (itemcost * decimaledinflationrate);
			annualcost = itemcost * howmanydoyouneed;
			cout << "\t\t" << fixed << yearbeingprojected << "\t\t\t " << fixed << itemcost << "\t\t\t" << fixed << howmanydoyouneed << "\t\t\t" << fixed << annualcost << endl;
		}

		do {
			cout << endl << endl << "Run the forecast on other items [y/n]? ";
			cin >> again;
		} while (!(again == 'y' || again == 'Y' || again == 'n' || again == 'N'));

		if (again == 'n' || again == 'N')
			repeattheapp = false;
		else
			cout << endl << endl;
	} while (repeattheapp);
}
