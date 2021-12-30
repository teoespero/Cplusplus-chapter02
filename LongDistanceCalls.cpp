// longdistancecalls.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

	//	define and initialize the variables
	int
		timeofday = 0,
		dayofweek = 0,
		callinminutes = 0;

	double
		costperminute = 0.00,
		callcost = 0.00;

	char
		computeanothercall = 'y';


	bool
		validday = false,
		validtime = false,
		validcalllength = false,
		runagain = true;

	do {
		//	print the header
		cout << endl << "JNC Calling Station" << endl << endl;

		//	get the time of day
		//	valid days can only be:
		//	Mo-1, Tu-2,  We-3, Th-4, Fr-5, Sa-6, Su-7

		do {
			cout << "Mo-1, Tu-2,  We-3, Th-4, Fr-5, Sa-6, Su-7" << endl;
			cout << "Day.....";
			cin >> dayofweek;

			if (dayofweek >= 1 && dayofweek <= 7)
				validday = true;
			else
				cout << "\t*** Invalid day entered." << endl;
		} while (!(validday));

		//	was the call made on a weekday (M-F, 1-5)?
		if (dayofweek < 6) {

			//	get the time the call was made
			//	didderent times on a week day have different rates
			do {
				cout << "Time (24-hour format, hhmm)...";
				cin >> timeofday;

				if (timeofday >= 0 && timeofday <= 2359)
					validtime = true;
				else
					cout << "\t*** Invalid time entered." << endl;
			} while (!(validtime));
		}

		//	get the call length in minutes
		do {
			cout << "Call length (mm).....";
			cin >> callinminutes;

			if (callinminutes > 0)
				validcalllength = true;
		} while (!(validcalllength));

		//	determine the cost per minute based on the
		//	day of the week, and time 
		if (dayofweek > 5)
			costperminute = 0.15;
		else if (timeofday >= 800 && timeofday <= 1800 && dayofweek < 6)
			costperminute = 0.40;
		else if ((timeofday < 800 || timeofday > 1800) && dayofweek < 6)
			costperminute = 0.25;

		//	compute for the total call cost
		callcost = callinminutes * costperminute;

		//	display the computation
		cout << setprecision(2);
		cout << "Call cost..... " << fixed << callcost << endl;

		//	ask the user if they want to run the app again
		do {
			cout << endl << "Compute another call [y/n]?.....";
			cin >> computeanothercall;

			computeanothercall = tolower(computeanothercall);
		} while (!(computeanothercall == 'n' || computeanothercall == 'y'));

		if (computeanothercall == 'n')
			runagain = false;
	} while (runagain);

	//	say good bye
	cout << endl << "Goodbye." << endl;
}