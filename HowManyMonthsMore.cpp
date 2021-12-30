// HowManyMonthsMore.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
	//------------------------------------------------------------------------
	//	define the variables that we will be needing
	string
		itemyoupurchased = "";

	double
		costofitem = 0.00,
		interestrateperyear = 0.00,
		interestratepermonth = 0.00,
		decimaledinterestrate = 0.00,
		monthlypayment = 0.00,
		runningbalance = 0.00,
		runninginterest = 0.00,
		principal = 0.00;

	int
		monthnumber = 0;

	//------------------------------------------------------------------------
	//	get the item, interest, and cost information

	cout << "Item purchased: ";
	cin >> itemyoupurchased;

	cout << "Item cost: ";
	cin >> costofitem;

	cout << "Interest rate per year: ";
	cin >> interestrateperyear;

	//------------------------------------------------------------------------
	//	compute
	decimaledinterestrate = (interestrateperyear / 100);
	interestratepermonth = (decimaledinterestrate / 12);
	monthlypayment = (costofitem * 0.05);

	runningbalance = costofitem;

	//------------------------------------------------------------------------
	//	printout the loan information

	cout << setprecision(2);
	cout << endl << endl;
	cout << "------------------------------------------------------------------------------------" << endl;
	cout << "\t\t\t\tJNC Personal Finance" << endl << endl;
	cout << "\t\tItem: " << itemyoupurchased << endl;
	cout << "\t\tInterest PA: " << fixed << interestrateperyear << "%" << endl;
	cout << "\t\tMonthly Interest: " << fixed << (interestratepermonth * 100) << "%" << endl;
	cout << "\t\tMinimum Monthly Payment: " << fixed << monthlypayment << endl;
	cout << endl << endl;
	cout << "\t\t\t\t\tPayment Structure" << endl;
	cout << "------------------------------------------------------------------------------------" << endl;
	cout << "\t\tMonth\t\tBalance\t\tInterest\tPrincipal" << endl;
	cout << "------------------------------------------------------------------------------------" << endl;
	do {
		monthnumber++;
		runninginterest = runningbalance * interestratepermonth;
		principal = monthlypayment - runninginterest;
		runningbalance = runningbalance - (monthlypayment - runninginterest);
		cout << "\t\t" << fixed << monthnumber << "\t\t" << fixed << runningbalance << "\t\t" << fixed << runninginterest << "\t\t" << fixed << principal << endl;
	} while (runningbalance > 0);
	cout << "------------------------------------------------------------------------------------" << endl;
}
