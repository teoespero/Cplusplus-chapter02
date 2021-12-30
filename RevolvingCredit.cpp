// RevolvingCredit.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
	//----------------------------------------------------------------------------
	//	define the vars and constants that we will be using in our app
	const double
		CREDITLINEAMOUNT = 1000.00;

	double
		minimumamountdue = 0.00,
		itemcost = 0.00,
		interestrate1000 = 0.00,
		interestrateexcess1000 = 0.00,
		excessof1000 = 0.00,
		totalamountdue = 0.00;

	bool
		validitemcost = false,
		runagain = true;

	char
		doanotheritem = 'y';

	do {

		//----------------------------------------------------------------------------
		//	get item cost from the user
		//	a valid item cost should be more than $0.00
		//	and should be less than their credit line amount
		do {
			cout << "Enter item cost: ";
			cin >> itemcost;

			if (itemcost > 0 && itemcost <= CREDITLINEAMOUNT)
					validitemcost = true;
				else
					cout << "\t*** Invalid item cost." << endl << endl;
		} while (!(validitemcost));


		//----------------------------------------------------------------------------
		//	perform the computations
		interestrate1000 = 0.015;
		interestrateexcess1000 = 0.01;

		//----------------------------------------------------------------------------
		//	if the item cost is >= 1000
		//	compute for the interest for excess of 1000
		if (itemcost >= 1000) {
			excessof1000 = itemcost - 1000.00;
			totalamountdue = (1000 + (1000 * interestrate1000)) + (excessof1000 + (excessof1000 * interestrateexcess1000));
		}

		//----------------------------------------------------------------------------
		//	if the item cost is < 1000. do a straight computation
		else {
			totalamountdue = itemcost + (itemcost * interestrate1000);
		}

		//----------------------------------------------------------------------------
		//	if the minimum amount due computed is less than $10
		//	we will enforce the $10 rule
		minimumamountdue = totalamountdue * 0.1;
		if (minimumamountdue < 10.00)
			minimumamountdue = 10.00;

		//----------------------------------------------------------------------------
		//	display the results
		cout << setprecision(2);
		cout << "Item cost: " << fixed << itemcost << endl;
		cout << "Cost with interest: " << fixed << totalamountdue << endl;
		cout << "Minimum payment due: " << fixed << minimumamountdue << endl;


		//----------------------------------------------------------------------------
		//	ask if the user wants to compute for another item
		do {
			cout << endl << "Do another computation [y/n]?.....";
			cin >> doanotheritem;

			doanotheritem = tolower(doanotheritem);
		} while (!(doanotheritem == 'y' || doanotheritem == 'n'));
		if (doanotheritem == 'n')
			runagain = false;
		else
			cout << endl << endl;

	} while ((runagain));
	//----------------------------------------------------------------------------
	//	stop running
	cout << "Goodbye." << endl;
}
