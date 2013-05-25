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
// Assignment: assn4
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//=================================================================

//main.cpp

#include "syntaxtree.h"
#include <iostream>

using namespace std;

int main() {
	
    SyntaxTree tree;
    string formula;
    
    while( cin ) {		//loops until the user wants to end program
    	cout << "> ";
    	getline( cin, formula );
    	
    	formula = formula + " ";	//adds a space for my formatting sake.
    	
    	if( tree.load_formula( formula ) ) {
    		double answer = tree.evaluate_tree( tree.getRoot() );
    			//outputs the answer to the LISP formula
    		if( answer != -999999999 ) {
    			cout << answer << endl;
    		}
    	}
    }
    
    return 0;
}



