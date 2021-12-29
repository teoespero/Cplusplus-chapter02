// ConsumerLoan.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Teodulfo Espero
// BS Cloud and Systems Administration
// BS Software Development
// Western Governors University

#include <cstdlib>
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    //  define the variables that we will be using

    float
        loanAmount = 0.00,
        loanReceived = 0.00,
        interestRate = 0.00,
        interestAmount = 0.00,
        totalInterest = 0.00,
        monthlyPayments = 0.00,
        monthsToPay = 0;

    bool
        validLoanAmount = false,
        validLoanInterestRate = false,
        validMonthsToPay = false,
        validInputs = false,
        again = true;

    char
        yesno = 'y';


    //  get the loan information from the user
    //  validate the inputs at each step

    do {
        do {
            cout << "Enter loan amount: ";
            cin >> loanAmount;

            if (loanAmount > 0)
                validLoanAmount = true;
            else
                cout << "Invalid loan amount." << endl;
        } while (!(validLoanAmount));

        do {
            cout << "Enter interest rate: ";
            cin >> interestRate;

            if (interestRate > 0)
                validLoanInterestRate = true;
            else
                cout << "Invalid loan amount." << endl;
        } while (!(validLoanInterestRate));

        do {
            cout << "Enter number of months to pay: ";
            cin >> monthsToPay;

            if (monthsToPay > 0)
                validMonthsToPay = true;
            else
                cout << "Invalid number of months to pay." << endl;
        } while (!(validMonthsToPay));

        //   compute the loan infos

        interestAmount = loanAmount * (interestRate / 100.00);
        totalInterest = interestAmount * (monthsToPay / 12);
        loanReceived = loanAmount - totalInterest;
        monthlyPayments = loanAmount / monthsToPay;

        //  print the loan re-payment info
        cout << setprecision(2);

        cout << endl << endl << "JNC Personal Loans" << endl;
        cout << "--------------------------------------------------------------" << endl;
        cout << "\t" << "Loan amount: " << fixed << loanAmount << endl;
        cout << "\t" << "Months to pay: " << fixed << monthsToPay << endl;
        cout << "\t" << "Interest rate: " << fixed << interestRate << endl;
        cout << "\t" << "Interest amount: " << fixed << interestAmount << endl;
        cout << "\t" << "Total Interest: " << fixed << totalInterest << endl;
        cout << "\t" << "Loan received: " << fixed << loanReceived << endl;
        cout << "\t" << "Monthly payments: " << fixed << monthlyPayments << endl;
        cout << "--------------------------------------------------------------" << endl;

        //  ask for repeats
        do {
            cout << "Would you like to run the app again [y/n]? ";
            cin >> yesno;
        } while (!(yesno == 'y' || yesno == 'Y' || yesno == 'n' || yesno == 'N'));
        
        if (yesno == 'n' || yesno == 'N') 
            again = false;
        else {
            cout << "--------------------------------------------------------------" << endl;
            cout << endl << endl;
        }
    } while ((again));
    
    //  quit it, the user wants to end running the app

}

