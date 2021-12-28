// TreadmillDashboard.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Teodulfo Espero
// BS Cloud and Systems Administration
// BS Software Development
// Western Governors University

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    //  define the variables that we need to use

    float   milesperhour = 0.00,
            minutessecondspermile = 0.0,
            minutespermile = 0.00,
            secondspermile = 0.00;
    
    char    again = 'y';

    do {
        //  get the mph info from the user

        cout << "Enter miles per hour (mph): ";
        cin >> milesperhour;

        // perform the calculations needed
        minutessecondspermile = 60 / milesperhour;

        // remove the seconds from the minute part
        minutespermile = trunc(minutessecondspermile);

        // remove the minutes so we can just calculate the seconds
        secondspermile = (minutessecondspermile - minutespermile) * 60.00;

        // define how we will be rounding the result
        cout << setprecision(3);

        // display the result
        cout << "That is " << minutespermile << " minutes and " << secondspermile 
             << " seconds per mile." << endl;

        // check if the user wants ti try again
        cout << "Try again (Y/N)? ";
        cin >> again;
    } while (!(again == 'n' || again == 'N'));
}

