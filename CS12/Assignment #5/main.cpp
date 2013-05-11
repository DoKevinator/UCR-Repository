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
// Assignment: assn5
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//
// =================================================================


//main.cpp

#include "intlist.h"
#include <iostream>

using namespace std;

int main() {
    
    IntList list;
    
    
    
    list.push_back(1);
    list.push_back(2);
    list.push_back(5);
    list.push_back(4);
    list.push_back(6);
    list.push_back(5);
     
    
    
    list.print();
    cout << endl;
    
    list.select_sort();
    
    list.print();
    cout << endl;
    
    list.insert_sorted( 3 );
    
    list.print();
    cout << endl;
    
    
    
    return 0;
}


