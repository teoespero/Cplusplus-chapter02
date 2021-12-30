// HiLowNumbers.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
    //------------------------------------------------------------------
    //  define the vars
    int
        high = 0,
        low = 0,
        current = 0,
        previous = 0,
        number = 0;

    bool
        negative = false;

    //------------------------------------------------------------------
    //  ask for a series of numbers
    //  until the user hits -1
    cout << "give me a number..... " << endl;
    do {
        cin >> number;

        //  check if the number is negative
        if (number < 0)
            negative = true;
        else
            //  determine the high and low
            if (high == 0 && low == 0) {
                //  at the start of the run
                //  assume that the current number
                //  is the high and low

                high = number;
                low = number;
                previous = number;
                current = number;
            }
            else {
                //  test each number entered 
                //  current vs the previous
                current = number;
                if (current >= high)
                    high = current;
                if (current <= low)
                    low = current;
                previous = number;
            }
    } while (!(negative));

    //  print out the results
    cout << "Largest..... " << high << endl;
    cout << "Lowest..... " << low << endl;

}
