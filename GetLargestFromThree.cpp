// GetLargestFromThree.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
        number01 = 0,
        number02 = 0,
        number03 = 0,
        largestnum = 0,
        smallestnum = 0;

    //------------------------------------------------------------------
    //  get some numbers from th user
    cout << "Give me 3 numbers separated by spaces" << endl;
    cin >> number01 >> number02 >> number03;

    //------------------------------------------------------------------
    //  get the highest
    if (number01 >= number02 && number01 >= number03) largestnum = number01;
    if (number02 >= number01 && number02 >= number03) largestnum = number02;
    if (number03 >= number02 && number02 >=number01) largestnum = number03;

    //------------------------------------------------------------------
    //  get the lowest
    if (number01 <= number02 && number01 <= number03) smallestnum = number01;
    if (number02 <= number01 && number02 <= number03) smallestnum = number02;
    if (number03 <= number02 && number03 <= number01) smallestnum = number03;
            
    //------------------------------------------------------------------
    //  print the result
    cout << endl
        << "Series" << endl
        << number01 << endl
        << number02 << endl
        << number03 << endl
        << "Largest: " << largestnum << endl
        << "Smallest: " << smallestnum << endl;

}

