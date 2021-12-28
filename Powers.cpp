// Powers.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Teodulfo Espero
// BS Cloud and Systems Administration
// BS Software Development
// Western Governors University

#include <iostream>

using namespace std;

int main()
{
    //  define the vars that we will be using

    double theBase = 0.00,
            raisedValue = 0.00;
    int thePower = 0;
    char again = 'y';

    //  the loop that will repeat until the 
    //  user presses n
    do {

        //  get the inputs
        cout << "Enter the base: ";
        cin >> theBase;

        cout << "Enter the power to use: ";
        cin >> thePower;

        //  a number raised to 0
        raisedValue = 1.00;

        // compute for the raised value
        for (int initialD = 1; initialD <= abs(thePower); initialD++) 
            raisedValue = raisedValue * theBase;
        
        //  this part is performed if the exponent
        //  is negative
        if (thePower < 0) 
            raisedValue = 1 / raisedValue;

        //  display the results
        cout << "The resulting number is: " << raisedValue << endl;

        // check if the user wants to end the run
        cout << "Try again (y/n)? ";
        cin >> again;
    } while (!((again == 'n') || (again == 'N')));
}
