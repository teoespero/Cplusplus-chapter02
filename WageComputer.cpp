// WageComputer.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Teodulfo Espero
// BS Cloud and Systems Administration
// BS Software Development
// Western Governors University

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    //------------------------------------------------------------------------
    //   define the CONSTANTS that we will be using in this program
    const double 
        SOCIALSECURITYTAXRATE = (6.00 / 100.00),
        STATEINCOMETAXRATE = (5.00 / 100.00),
        HEALTHCOVERAGECOSTPERDEPENDENT = 35.00,
        WAGE = 16.78,
        FEDERALINCOMETAXRATE = (14.00 / 100.00);


    //------------------------------------------------------------------------
    //   define the vars that we will be using in this program

    char
        again = 'y';

    double
        hoursworked = 0.00,
        numberofdependents = 0.00,
        overtimehours = 0.00,
        overtimerate = 0.00,
        overtimepay = 0.00,
        regularpay = 0.00,
        socialsecuritytax = 0.00,
        federalincometax = 0.00,
        stateincometax = 0.00,
        uniondues = 10.00,
        additionalhealthcoveragecost = 0.00,
        grosspay = 0.00,
        regularhoursworked = 0.00,
        netpay = 0.00,
        deductions = 0.00;

    bool
        valihoursworked = false,
        validenumberofdependents = false,
        endtask = false;



    //------------------------------------------------------------------------
    //  start

    do {
        cout << "-----------------------------------------------------" << endl;
        cout << "JNC Credit and Financing" << endl << endl;
        cout << "Payroll program" << endl;

        //  get number of hours worked
        do {
            cout << endl << "\t" << "Hours worked: ";
            cin >> hoursworked;
            if (hoursworked <= 0.00)
                cout << endl << "\t" << "*** Hours worked should be > 0." << endl;
            else
                valihoursworked = true;
        } while (!(valihoursworked));

        //  get number of dependents
        do {
            cout << "\t" << "Number of dependents: ";
            cin >> numberofdependents;
            if (numberofdependents < 0.00)
                cout << endl << "\t" << "*** Number of dependents should be 0 or more." << endl;
            else
                validenumberofdependents = true;
        } while (!(validenumberofdependents));

        cout << endl << endl << endl << endl << endl << "Processing... ";
        cout << endl << endl << endl;

        //  does the employee have OT
        if (hoursworked > 40) {
            overtimehours = hoursworked - 40;
            regularhoursworked = hoursworked - overtimehours;
            overtimerate = WAGE * 1.5;
            overtimepay = overtimehours * overtimerate;
        }
        else
            regularhoursworked = hoursworked;

        //------------------------------------------------------------------------
        //  compute the gross pay
        regularpay = regularhoursworked * WAGE;
        grosspay = regularpay + overtimepay;

        //------------------------------------------------------------------------
        //  compute the deductions
        socialsecuritytax = grosspay * SOCIALSECURITYTAXRATE;
        federalincometax = grosspay * FEDERALINCOMETAXRATE;
        stateincometax = grosspay * STATEINCOMETAXRATE;
        additionalhealthcoveragecost = numberofdependents * HEALTHCOVERAGECOSTPERDEPENDENT;

        deductions = (socialsecuritytax + federalincometax + stateincometax + additionalhealthcoveragecost);

        //------------------------------------------------------------------------
        //  netpay computations
        netpay = grosspay - deductions;


        //------------------------------------------------------------------------
        //  print the pay stub

        cout << endl << endl << endl << endl << "\t" << "\t" << "-----------------------------------------------------" << endl;
        cout << "\t\t" << "   JNC Credit and Financing" << endl << endl;
        cout << "\t\t" << "   Pay Stub" << endl;
        cout << "\t\t" << "-----------------------------------------------------" << endl;
        cout << setprecision(2);
        cout << "\t\t\t" << "Regular Hours worked: " << fixed << regularhoursworked << endl;
        cout << "\t\t\t" << "Overtime Hours worked: " << fixed << overtimehours << endl;
        cout << "\t\t\t" << "Gross Pay: " << endl;
        cout << "\t\t\t\t" << "Regular Pay: " << fixed << regularpay << endl;
        cout << "\t\t\t\t" << "Overtime Pay: " << fixed << overtimepay << endl;

        cout << "\t\t\t" << "Deductions: " << endl;
        cout << "\t\t\t\t" << "Federal Income Tax: " << fixed << federalincometax << endl;
        cout << "\t\t\t\t" << "State Income Tax: " << fixed << stateincometax << endl;
        cout << "\t\t\t\t" << "Social Security Tax: " << fixed << socialsecuritytax << endl;
        if (additionalhealthcoveragecost > 0) 
            cout << "\t\t\t\t" << "Additional health coverage cost: " << fixed << additionalhealthcoveragecost << endl;
        cout << "\t\t\t" << "Net Pay: " << netpay << endl;
        cout << "\t\t" << "-----------------------------------------------------" << endl;

        //  ask if user wants to run app again
        do {
            cout << endl << "\t\t\t" << "Run the payroll program again [y/n]? ";
            cin >> again;
        } while (!(again == 'y' || again == 'Y' || again == 'n' || again == 'N'));

        if (again == 'n' || again == 'N') endtask = true;
    }while (!(endtask));
}
