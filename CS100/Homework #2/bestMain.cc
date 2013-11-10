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

//bestMain.cc

#include <iostream>
#include "Coins.h"

using namespace std;

void print_menu();

int main() {
	Coins myCoins(0,0,0,0);
	char input;

	print_menu();

	while( cin >> input ) {
		switch( input ) {
			case 'e':
				int extract;
				cout << "Enter an amount to extract: "; cin >> extract;
				myCoins.extractChange( extract );
				break;
			case 'd':
				int q, d, n, p;
				cout << "Enter quarters to deposit: "; cin >> q;
				cout << "Enter dimes to deposit: "; cin >> d;
				cout << "Enter nickels to deposit: "; cin >> n;
				cout << "Enter pennies to deposit: "; cin >> p;
				myCoins.depositChange( Coins(q,d,n,p) );
				break;
			case 'p':
				cout << "You currently have " << myCoins << ". " << endl;
				break;
			case 'q':
				cout << "Goodbye!" << endl;
				exit(0);
				break;
			default:
				cout << "Not a valid action." << endl;

		}

		print_menu();
	}


	return 0;
}


void print_menu() {
	cout << "Menu:" << endl
		 << "e - Extract change" << endl
		 << "d - Deposit change" << endl
		 << "p - Print balance" << endl
		 << "q - Quit" << endl;
	cout << "Enter a letter: ";
}




