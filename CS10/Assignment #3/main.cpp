// Course: CS 10 Fall 2012
//
// First Name: Kevin
// Last Name: Do
// Course username: kdo009
// Email address: kdo009@ucr.edu
//
// Lecture Section: 001
// Lab Section: 029
// TA: Adam Koehler
//
// Assignment: assn3
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
// KEVIN DO
// =================================================================

#include <iostream> //include library for input output

using namespace std;

int main() {    //main integer method
    
    int ISBNinput;      //user inputs the 9 digit ISBN in here
    int weightedSum = 0;    //used to calculate the weighted sum in for loop
    int checksum = 0;       //used to calculate checksum from weightedSum
    int i;      //for loop decrement
    
    //cout << "Enter first 9 digits of ISBN: ";   //ask user for input
    cin >> ISBNinput;       //stores input into ISBNinput
    cout << endl;
    
    for ( i = 9 ; i > 0 ; i-- ) {      //for loop to calculate weightedSum
        
        weightedSum = (ISBNinput % 10) * i + weightedSum;
        //picks right most number and times by algorithm and adds weightedSum
        //(weightedSum algorithm)
        
        ISBNinput = ISBNinput / 10;
        //stores the input without the right-most number for next loop
        
    }//close for loop
    
    checksum = weightedSum % 11;        //calculates checksum from weightedSum
    
    cout << checksum << endl;       //prints checksum with new line for format
    
    return 0;       //ends program by returning zero
    
}