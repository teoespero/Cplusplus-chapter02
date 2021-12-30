// WhatsYourSign.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

	//	define the variables we are using
	int
		bdaymonth = 0,
		bdaydate = 0,
		bdayyear = 0;

	string
		yoursign = "",
		compatiblewith = "";

	bool
		validmonth = false,
		validyear = false,
		validday = false,
		runagain = true;

	char
		checkanotherbday = 'y';


	do {

		//	get birthday info from the user

		do {

			//	the birthday year should be > 0

			cout << "Birthday year..... ";
			cin >> bdayyear;

			if (bdayyear > 0)
				validyear = true;
			else
				cout << "\t*** Invalid birth year." << endl;
		} while (!(validyear));

		do {

			//	the month should be between 1-12
			cout << "Birthday month..... ";
			cin >> bdaymonth;

			if (bdaymonth > 0 && bdaymonth <= 12)
				validmonth = true;
			else
				cout << "\t*** Invalid birth month." << endl;
		} while (!(validmonth));

		do {

			//	depending on the month (year for leap years), the date is checked
			//	for validity

			cout << "Birthday date..... ";
			cin >> bdaydate;
			if (bdaymonth == 1 && bdaydate > 0 && bdaydate <= 31)
				validday = true;
			else if (bdaymonth == 3 && bdaydate > 0 && bdaydate <= 31)
				validday = true;
			else if (bdaymonth == 4 && bdaydate > 0 && bdaydate <= 30)
				validday = true;
			else if (bdaymonth == 5 && bdaydate > 0 && bdaydate <= 31)
				validday = true;
			else if (bdaymonth == 6 && bdaydate > 0 && bdaydate <= 30)
				validday = true;
			else if (bdaymonth == 7 && bdaydate > 0 && bdaydate <= 31)
				validday = true;
			else if (bdaymonth == 8 && bdaydate > 0 && bdaydate <= 31)
				validday = true;
			else if (bdaymonth == 9 && bdaydate > 0 && bdaydate <= 30)
				validday = true;
			else if (bdaymonth == 10 && bdaydate > 0 && bdaydate <= 31)
				validday = true;
			else if (bdaymonth == 11 && bdaydate > 0 && bdaydate <= 30)
				validday = true;
			else if (bdaymonth == 12 && bdaydate > 0 && bdaydate <= 31)
				validday = true;
			else if (bdaymonth == 2 && ((bdayyear % 2) == 0) && bdaydate > 0 && bdaydate <= 29)
				validday = true;
			else if (bdaymonth == 2 && ((bdayyear % 2) == 1) && bdaydate > 0 && bdaydate <= 28)
				validday = true;
			else
				cout << "\t*** Birthday date is invalid." << endl;
		} while (!(validday));

		//	once we have a valid birthday info
		//	we can proceed in determining the user's astrological sign

		if (bdaymonth == 3 && (bdaydate >= 21 && bdaydate <= 31) || bdaymonth == 4 && (bdaydate >= 01 && bdaydate <= 19))
			yoursign = "Aries";
		else if (bdaymonth == 4 && (bdaydate >= 20 && bdaydate <= 30) || bdaymonth == 5 && (bdaydate >= 1 && bdaydate <= 20))
			yoursign = "Taurus";
		else if (bdaymonth == 5 && (bdaydate >= 21 && bdaydate <= 31) || bdaymonth == 6 && (bdaydate >= 1 && bdaydate <= 21))
			yoursign = "Gemini";
		else if (bdaymonth == 6 && (bdaydate >= 22 && bdaydate <= 30) || bdaymonth == 7 && (bdaydate >= 1 && bdaydate <= 22))
			yoursign = "Cancer";
		else if (bdaymonth == 7 && (bdaydate >= 23 && bdaydate <= 31) || bdaymonth == 8 && (bdaydate >= 1 && bdaydate <= 22))
			yoursign = "Leo";
		else if (bdaymonth == 8 && (bdaydate >= 23 && bdaydate <= 31) || bdaymonth == 9 && (bdaydate >= 1 && bdaydate <= 22))
			yoursign = "Virgo";
		else if (bdaymonth == 9 && (bdaydate >= 23 && bdaydate <= 30) || bdaymonth == 10 && (bdaydate >= 1 && bdaydate <= 22))
			yoursign = "Libra";
		else if (bdaymonth == 10 && (bdaydate >= 20 && bdaydate <= 31) || bdaymonth == 11 && (bdaydate >= 1 && bdaydate <= 21))
			yoursign = "Scorpio";
		else if (bdaymonth == 11 && (bdaydate >= 22 && bdaydate <= 30) || bdaymonth == 12 && (bdaydate >= 1 && bdaydate <= 21))
			yoursign = "Sagittarius";
		else if (bdaymonth == 12 && (bdaydate >= 22 && bdaydate <= 31) || bdaymonth == 1 && (bdaydate >= 1 && bdaydate <= 19))
			yoursign = "Capricorn";
		else if (bdaymonth == 1 && (bdaydate >= 20 && bdaydate <= 31) || bdaymonth == 2 && (bdaydate >= 1 && bdaydate <= 18))
			yoursign = "Aquarius";
		else if (bdaymonth == 2 && (bdaydate >= 19 && bdaydate <= 29) || bdaymonth == 3 && (bdaydate >= 1 && bdaydate <= 20))
			yoursign = "Pisces";

		//	get the element that you belong in
		if (yoursign == "Aries" || yoursign == "Leo" || yoursign == "Sagitarrius")
			compatiblewith = "Fire (Aries, Leo, and Sagitarrius)";
		else if (yoursign == "Taurus" || yoursign == "Virgo" || yoursign == "Capricorn")
			compatiblewith = "Earth (Taurus, Virgo, and Capricorn)";
		else if (yoursign == "Gemini" || yoursign == "Libra" || yoursign == "Aquarius")
			compatiblewith = "Air (Gemini, Libra, and Aquarius)";
		else if (yoursign == "Cancer" || yoursign == "Scorpio" || yoursign == "Pisces")
			compatiblewith = "Water (Cancer, Scorpio, Pisces)";

		//	show the result
		cout << "Astrological sign..... " << yoursign << endl;
		cout << "Compatible with..... " << compatiblewith << endl;

		//	check if they want to check another birthday
		do {
			cout << endl << "Check another birthday [y/n]?..... ";
			cin >> checkanotherbday;

			checkanotherbday = tolower(checkanotherbday);
		} while (!(checkanotherbday == 'y' || checkanotherbday == 'n'));

		if (checkanotherbday == 'n')
			runagain = false;
		else
			cout << endl;
	} while (runagain);

	//	if they are done say good bye
	cout << endl << "Goodbye.";
}
