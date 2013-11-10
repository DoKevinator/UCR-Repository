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



//message.cpp

#include "message.h"
#include <iostream>

using namespace std;

Message::Message()  //default constructor
:author(""), subject(""), body("") {
    
}

//constructor that initializes everything
Message::Message(const string& athr, const string& sbjct, const string& body)
:author(athr), subject(sbjct), body(body) {
    
}


//display function for message 
void Message::display() const {
    cout << subject << endl;
    cout << "from " << author << ": " << body << endl;
}
