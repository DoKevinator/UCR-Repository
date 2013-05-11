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
// Assignment: assn3
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//=================================================================

//main.cpp

#include "map.h"

#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    
    if (argc == 0) {
        cout << "Not enough parameters." << endl;
        exit(1);
    }
    
    Map<string,string>* tmp = new Map<string,string>;
    
    string word_to_translate;
    
    tmp -> loadFromFile( argv[1] );
    /*
    tmp -> insert( "hello", "world" );
    tmp -> insert( "test", "testing" );
    tmp -> insert( "abacus", "testing2" );
    tmp -> insert( "bakery", "" );
    tmp -> insert( "cake", "" );
    tmp -> insert( "dog", "" );
    
    cout << tmp -> size() << endl;
    
    tmp -> structure_print();
    
    cout << endl << endl;
    
    tmp -> erase( "abacus" );
    
    cout << "hahhaa" << endl;
    
    tmp -> structure_print();
    */
    while (cin) {
        cout << "> ";
        cin >> word_to_translate;
        cout << tmp -> lookup( word_to_translate ) << endl;
    }
     
     
    return 0;
}


