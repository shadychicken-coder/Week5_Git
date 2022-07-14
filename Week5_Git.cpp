// Week5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <cctype>
using namespace std;

/*Johnny Utah owns a surf shop on the beach called �Point Break Surf Shop�. Johnny sells surfboards in 3 three sizes:
small (2 meters), medium (3 meters), and large (4 meters).
The cost of one small surfboard is $175.00, one medium is $190.00, and one large is $200.00.


Write a program that will make the surf shop operational.  Your program should allow the user to do the following:

Buy any surfboard in any size and in any quanity.
At any time show the total number of surfboards of each size sold.
At any time show the total money made.

In your program you must define the functions as they are defined above. Do not change the signature (the name, parameters or the return value) or you will be marked down considerably.

Your program should not use any global variables and the cost of the surfboards must be declared as named constants.

Your program should look and perform identically as the example below.
*/

//Defining constants
#define xSmallSurfboard 2000.00;
#define smallSurfboard 175.00;
#define mediumSurfboard 190.00;
#define largeSurfboard 200.00;

void ShowUsage() {
	//a function to show the user how to use the program.
	cout << endl;
	cout << "To show program usage 'S'" << endl;
	cout << "To purchase a surfboard press 'P'" << endl;
	cout << "To display current purchases press 'C'" << endl;
	cout << "To display total amount due press 'T'" << endl;
	cout << "To quit the program press 'Q'" << endl;
	cout << endl;
}

void MakePurchase(int& totalXSmall, int& totalSmall, int& totalMedium, int& totalLarge) {
	//a function to sell surfboards.
	//declare variables
	int quantity = 0;
	char size{};
	//Prompt user to enter quantity and type
	cout << endl;
	cout << "Please enter the quantity and type (X=XSmall, S=small, M=medium, L=large) of surfboard you would like to to purchase: ";
	cin >> quantity >> size;
	//Adds quantity to total small surfboards
	if (size == 'S') {
		totalSmall = totalSmall + quantity;
	}
	//Repeating the same for the other sizes;
	else if (size == 'M') {
		totalMedium = totalMedium + quantity;
	}
	else if (size == 'L') {
		totalLarge = totalLarge + quantity;
	}
	else if (size == 'X') {
		totalXSmall = totalXSmall + quantity;
	}
	else {
		cout << "Invalid Input" << endl;
	}


}

void DisplayPurchase(const int totalXSmall, const int totalSmall, const int totalMedium, const int totalLarge) {
	// function to show the number of surfboards of each size sold.

	cout << endl;
	cout << "Number of XSmall Surfboards: " << totalXSmall << endl;
	cout << "Number of Small Surfboards: " << totalSmall << endl;
	cout << "Number of Medium Surfboards: " << totalMedium << endl;
	cout << "Number of Large Surfboards: " << totalLarge << endl;
	cout << endl;
}


void DisplayTotal(const int totalXSmall, const int totalSmall, const int totalMedium, const int totalLarge) {
	//a function to show the total amount of money made.
	//Declaring variables
	double soldXSmalls = 0.0;
	double soldSmalls = 0.0;
	double soldMediums = 0.0;
	double soldLarges = 0.0;
	double grandTotal = 0;
	//Performing calculations
	soldXSmalls = totalXSmall * xSmallSurfboard;
	soldSmalls = totalSmall * smallSurfboard;
	soldMediums = totalMedium * mediumSurfboard;
	soldLarges = totalLarge * largeSurfboard;
	//Calculating Grand Total
	grandTotal = soldXSmalls + soldSmalls + soldMediums + soldLarges;

	cout << fixed << setprecision(2);
	//Displaying Smalls
	if (totalXSmall > 0) {
		cout << "The total number of small surfboards is " << totalXSmall <<
			" at a total of $" << soldXSmalls << endl;

	}
	if (totalSmall > 0) {
		cout << "The total number of small surfboards is " << totalSmall <<
			" at a total of $" << soldSmalls << endl;

	}
	if (totalMedium > 0) {
		cout << "The total number of medium surfboards is " << totalMedium <<
			" at a total of $" << soldMediums << endl;

	}
	if (totalLarge > 0) {
		cout << "The total number of large surfboards is " << totalLarge <<
			" at a total of $" << soldLarges << endl;

	}
	cout << "Amount due: $" << grandTotal << endl;

}








int main()
{
	//Declaring variables
	char input;
	char size;
	int quantity = 0;
	int totalXSmall = 0;
	int totalSmall = 0;
	int totalMedium = 0;
	int totalLarge = 0;

	//Displaying the header
	cout << string(61, '*') << endl;
	cout << "***** Welcome to my Johnny Utah's PointBreak Surf Shop  *****" << endl;
	cout << string(61, '*') << endl << endl << endl;

	//Displaying the Usage Screen
	ShowUsage();

	//Asking for input
	cout << endl;
	cout << "Please enter selection:";
	cin >> input;

	//Starting the 'Q' loop
	while (input != 'Q') {
		if (input == 'S') {
			ShowUsage();
		}
		else if (input == 'P') {
			MakePurchase(totalXSmall, totalSmall, totalMedium, totalLarge);
		}
		else if (input == 'C') {
			DisplayPurchase(totalXSmall, totalSmall, totalMedium, totalLarge);
		}
		else if (input == 'T') {
			DisplayTotal(totalXSmall, totalSmall, totalMedium, totalLarge);
		}
		else {
			cout << "Invalid Input" << endl;
		}
		//Repeat Loop condition
		cout << endl;
		cout << "Please enter selection:";
		cin >> input;
	}
	//End Loop
	cout << "Thank you" << endl;
}
