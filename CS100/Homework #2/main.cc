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

// main.cc  /// The name of this file
#include "Coins.h"
#include <iostream>

using namespace std;

const int CENTS_FOR_CANDYBAR = 482;

int main() {
       ///  Creates a Coins object called 'pocket.'
    Coins pocket( 100, 10, 10, 100 );

    cout << "I started with " << pocket << " in my pocket" << endl;

       ///  Creates a Coins object called payForCandy and initializes it.
    Coins payForCandy = pocket.extractChange( CENTS_FOR_CANDYBAR );

    cout << "I bought a candy bar for " << CENTS_FOR_CANDYBAR
         << " cents using " << payForCandy << endl;
    cout << "I have " << pocket << " left in my pocket" << endl;

    return 0;
}


