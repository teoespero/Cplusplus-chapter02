//  GreetingsAI.cpp : This file contains the 'main' function. Program execution begins and ends there.
//  Teodulfo Espero
//  BS Cloud and Systems Administration
//  BS Software Development
//  Western Governors University

#include <iostream>

using namespace std;

int main()
{

    //  define the variables that we need

    char    response = 'n';
    bool    validResponse = false;

    //  loop until the user responds properly y,Y,n or N
    do {
        cout << "Hello" << endl;
        cout << "Are you having a good day? (y/n) " << endl;
        cin >> response;

        if ((response == 'y' || response == 'Y' || response == 'n' || response == 'N')) validResponse = true;
    } while (!(validResponse));

    //  respond depending on the user input
    if (response == 'y' || response == 'Y') 
        cout << "I'm glad to hear that..." << endl;
    else
        cout << "I hope your day gets better" << endl;
}

