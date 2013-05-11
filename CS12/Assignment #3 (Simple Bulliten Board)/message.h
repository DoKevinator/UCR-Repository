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


//Message.h


#ifndef __MESSAGE_H_
#define __MESSAGE_H_

#include <iostream>

using namespace std;

class Message {
private:
    
    string author;
    string subject;
    string body;
    
public:
    
    //default constructor
    Message();
    
    //Constructor with parameters
    Message(const string& athr, const string& sbjct, const string& body);
    
    
    //displays the message in the given format. See output specs.
    void display() const;
};


#endif //__MESSAGE_H_
