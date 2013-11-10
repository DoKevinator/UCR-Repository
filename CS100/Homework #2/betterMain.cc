/*
* Course: CS 100 Fall 2013 *
* First Name: Kevin
* Last Name: Do
* Username: kdo009
* email address: kdo009@well.cs.ucr.edu
*
* Assignment: Homework #2
* I hereby certify that the contents of this file represent
* my own original individual work. Nowhere herein is there
* code from any outside resources such as another individual,
* a website, or publishings unless specifically designated as
* permissible by the instructor or TA. */

//betterMain.cc

#include <iostream>
#include "Coins.h"

using namespace std;

int main() {
	Coins pocket( 5, 3, 6, 8 );
	Coins piggyBank( 50, 50, 50, 50 );

	const int bag_of_chips = 68;

	Coins pay_for_chips = pocket.extractChange(bag_of_chips);
	cout << "I bought a bag of chips for " << bag_of_chips
         << " cents using " << pay_for_chips << endl;
    cout << "I have " << pocket << " left in my pocket." << endl << endl;

    cout << "I currently have " << piggyBank << " in my piggy bank." << endl;
	Coins extracted = piggyBank.extractChange( 2050 );
    pocket.depositChange( extracted );
    cout << "I now deposited all my change in the piggy bank to my pocket. "
    	 << "I now have " << pocket << "." << endl;
    cout << "I have " << piggyBank << " left in my piggy bank." << endl << endl;

    Coins sofa_change( 8, 24, 3, 56 );
    cout << "I found " << sofa_change << " in my sofa. " << endl << endl;

    piggyBank.depositChange( sofa_change );
    cout << "I deposited all the sofa change into my piggy bank. " << endl;
    cout << "I now have " << piggyBank << " in my piggy bank. " << endl;



	return 0;
}




