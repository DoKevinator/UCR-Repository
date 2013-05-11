// Course: CS 14 Spring 2013
//
// First name: Kevin
// Last name: Do
// Course username: kdo009
// Email address: kdo009@ucr.edu
//
// Lecture section: 001
// Lab section: 021
// TA: Steve Cook
//
// Assignment: assn2
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//=================================================================

//main.cpp

#include "wordladder.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    
    if (argc < 4) {     //outputs an error when not sufficient parameters
        cout << "Not enough parameters." << endl;
        exit(1);
    }
    
    string filename = argv[1];  //retrieves the command line arguments
    string start = argv[2];
    string end = argv[3];
    
    WordLadder w_l( filename ); //constructs the wordladder class
    
    for (unsigned i = 0; i < start.size(); i++) {
        start.at(i) = tolower( start.at(i) );
        end.at(i) = tolower( end.at(i) );
    }
    
    
    w_l.outputLadder( start, end );     //runs the program
    
    return 0;
}


