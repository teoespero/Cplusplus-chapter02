//  CarpetStore.cpp : This file contains the 'main' function. Program execution begins and ends there.
//  Teodulfo Espero
//  BS Cloud and Systems Administration
//  BS Software Development
//  Western Governors University

#include <cstdlib>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
	
	//	define the variables that we will be using
	double	
		baseCarpetPrice = 2.75,
		carpetBought = 0.00,
		length = 0.00,
		width = 0.00,
		moreThanTen = 0.00,
		discounts = 0.00,
		discountPrice = 0.00,
		totalPrice = 0.00;

	//	get the area bought by the user
	cout << "Enter the length: ";
	cin >> length;

	cout << "Enter the width: ";
	cin >> width;

	//	compute for the area
	carpetBought = length * width;

	//	carpet bought > 10 m, price is discounted
	if (carpetBought > 10.00) {
		moreThanTen = carpetBought - 10.00;

		discounts = 2.75 - (2.75 * 0.15);
		discountPrice = (moreThanTen * discounts);
	}

	totalPrice = 2.75 + discountPrice;

	//	print the receipt

	cout << setprecision(3);
	cout << "-----------------------------------------------------" << endl;
	cout << "\tCarpet Area:\t\t" << setw(15) << left << carpetBought << endl;
	cout << "\tBase area: \t\t" << setw(15) << left << carpetBought - moreThanTen << endl;
	cout << "\tBase price: \t\t$" << setw(15) << left << baseCarpetPrice << endl;
	cout << "\tDiscounted cost: \t$" << setw(15) << left << discounts << endl;
	cout << "\tDiscounted price: \t$" << setw(15) << left << discountPrice << endl;
	cout << "\tTotal price: \t\t$" << setw(15) << left << totalPrice << endl;
	cout << "-----------------------------------------------------" << endl;






}

