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

//Coins.cc

#include "Coins.h"
#include <iostream>
#include <fstream>

using namespace std;

Coins::Coins( int q, int d, int n, int p )
:quarters(q), dimes(d), nickels(n), pennies(p) { }

void Coins::depositChange( Coins c ) {
	quarters += c.quarters;
	dimes += c.dimes;
	nickels += c.nickels;
	pennies += c.pennies;
}

bool Coins::hasSufficientAmount( int amount ) {
 	int pq = 0, pd = 0, pn = 0, pp = 0;
 	int q = quarters, d = dimes, n = nickels, p = pennies;

	//e.g. have 5 nickels and nothing else. want to pay for 18 cents. cannot.
	for( int i = quarters; i > 0; i-- ) {
		if(amount-CENTS_PER_QUARTER < 0) {
			break;
		}

		amount -= CENTS_PER_QUARTER;
		q--;
		pq++;
	}

	for( int i = dimes; i > 0; i-- ) {
		if( amount-CENTS_PER_DIME < 0) {
			break;
		}

		amount -= CENTS_PER_DIME;
		d--;
		pd++;
	}

	for( int i = nickels; i > 0; i-- ) {
		if( amount - CENTS_PER_NICKEL < 0) {
			break;
		}

		amount -= CENTS_PER_NICKEL;
		n--;
		pn++;
	}

	for( int i = pennies; i > 0; i-- ) {
		if( amount-1 < 0 ) {
			break;
		}

		amount -= 1;
		p--;
		pp++;
	}

	if(amount > 0) {
		return false;
	} 

	return true;
}

Coins Coins::extractChange( int amount ) {
	if( !hasSufficientAmount( amount ) ) {
		cerr << "Do not have sufficient amount." << endl;
		return Coins(0,0,0,0);
	}

	int pq = 0, pd = 0, pn = 0, pp = 0;

	for( int i = quarters; i > 0; i-- ) {
		if(amount-CENTS_PER_QUARTER < 0) {
			break;
		}

		amount -= CENTS_PER_QUARTER;
		quarters--;
		pq++;
	}

	for( int i = dimes; i > 0; i-- ) {
		if( amount-CENTS_PER_DIME < 0) {
			break;
		}

		amount -= CENTS_PER_DIME;
		dimes--;
		pd++;
	}

	for( int i = nickels; i > 0; i-- ) {
		if( amount - CENTS_PER_NICKEL < 0) {
			break;
		}

		amount -= CENTS_PER_NICKEL;
		nickels--;
		pn++;
	}

	for( int i = pennies; i > 0; i-- ) {
		if( amount-1 < 0 ) {
			break;
		}

		amount -= 1;
		pennies--;
		pp++;
	}

	return Coins(pq, pd, pn, pp);
}

void Coins::print( ostream & out ) {
	//out << quarters * CENTS_PER_QUARTER + dimes * CENTS_PER_DIME + 
	//		nickels * CENTS_PER_NICKEL + pennies;
	out << quarters << " quarter(s), " << dimes << " dime(s), " << nickels
		<< " nickel(s), " << pennies << " pennie(s)";
}

ostream & operator << ( ostream & out, Coins & c ) {
	c.print(out);
	return out;
}

