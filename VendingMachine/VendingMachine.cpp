// VendingMachine.cpp : Defines the entry point for the console application.
//
//Created by: Pierre Randall

#include "stdafx.h"
#include "iostream"

using namespace std;

int ChangeCalc(double intialCost, double amtPaided){
	int changeInt = 0;
	double returnTotal;
	const double DOLLAR = 1.0;
	const double QUARTER = 0.25;
	const double DIME = 0.10;
	const double NICKLE = 0.05;

	returnTotal = (amtPaided - intialCost);
	cout << "\nItem price: $" << intialCost << " amount Paid: $";
	cout << amtPaided << " Change Due: $" << returnTotal << endl;
	cout << "Your Change: " << endl;
	
	for (int i = 0; returnTotal >= DOLLAR;){		
		returnTotal = (returnTotal - DOLLAR);
		i++;
		changeInt = i;
	}

	if (changeInt != 0){
		cout << changeInt << " Dollar(s)" << endl;
		changeInt = 0;
	}

	for (int i = 0; returnTotal >= QUARTER;){
		returnTotal = (returnTotal - QUARTER);
		i++;
		changeInt = i;
	}

	if (changeInt != 0){
		cout << changeInt << " Quarter(s)" << endl;
		changeInt = 0;
	}

	for (int i = 0; returnTotal >= DIME;){
		returnTotal = (returnTotal - DIME);
		i++;
		changeInt = i;
	}

	if (changeInt != 0){
		cout << changeInt << " Dime(s)" << endl;
		changeInt = 0;
	}

	for (int i = 0; returnTotal >= NICKLE;){
		returnTotal = (returnTotal - NICKLE);
		i++;
		changeInt = i;
	}

	if (changeInt != 0){
		cout << changeInt << " Nickel(s)" << endl;
		changeInt = 0;
	}
	cout << " " << endl;
	return 0;
}
int CreateVendingMachine(){
	int x, y; //variables used to parse the intial value and cost to check for pennies.
	double intialCost,cost,amtPaided,amtAdded;
	double userinput = 1;
	
	cout << "~Vending Machine Make Change~\n"<<endl;
	
	while((true) && (userinput != 0)) {
			
			cout << "Please enter the cost of the Item (enter 0 to exit): " << endl;
			cin >> intialCost;
			x = intialCost;
			y = (intialCost - x) * 100;
			
			while ((y % 5) != 0)
			{
				cout << "Sorry this vending machine doesn't except pennies" << endl;
				cout << "Please enter another Cost" << endl;
				cin >> intialCost;
				x = intialCost;
				y = (intialCost - x) * 100;
			}

			userinput = intialCost;

			if (userinput != 0) {

				cost = intialCost;

				cout << "Please enter the amount you paid: " << endl;
				cin >> amtPaided;
				x = amtPaided;
				y = (amtPaided - x) * 100;
				 
				while ((y % 5) != 0)
				{
					cout << "Sorry this vending machine doesn't except pennies" << endl;
					cout << "Please enter another amount that you paid: " << endl;
					cin >> amtPaided;
					x = amtPaided;
					y = (amtPaided - x) * 100;
				}

				if (amtPaided < intialCost){
					amtAdded = amtPaided;
					do{
						cost = intialCost - amtPaided;

						cout << "That's not enough! You still need " << cost << " more!" << endl;
						cout << "Please enter additional amount: ";

						cin >> amtAdded;

						amtPaided += amtAdded;
					} while (intialCost > amtPaided);
					ChangeCalc(intialCost, amtPaided);
				}
				else{
					ChangeCalc(intialCost, amtPaided);
				}
			}
		}
	return 0;
}

int main(){
	CreateVendingMachine();
	return 0;
}

