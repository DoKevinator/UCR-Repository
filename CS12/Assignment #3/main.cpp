// Course: CS 12 Winter 2013
//
// First Name: Kevin
// Last Name: Do
// Course username: kdo009
// email address: kdo009@ucr.edu
//
// Lecture Section: 001
// Lab Section: 021
// TA: Sean Allen
//
// Assignment: assn3
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//
// =================================================================

#include "bboard.h"
#include <iostream>

using namespace std;

int main() {
    
    Bboard bb( "Kevin's Amazing Bulletin Board" );
    
    bb.setup();
    bb.login();
    bb.run();
    
    return 0;
}

