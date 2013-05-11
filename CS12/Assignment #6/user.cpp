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
// Assignment: assn6
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//
// =================================================================


//user.cpp

#include "user.h"
#include <iostream>

using namespace std;

User::User()    //default constructor
:username(""), password("") {
    
}

//constrcutor initialized username and password
User::User(const string &uname, const string &pass )
:username(uname), password(pass) {
    
}

//gets the username 
string User::get_username() const {
    return username;
}


//checks if the passed in parameters matches the username and password
//returns true if matches
//returns false otherwise
bool User::check(const string& uname, const string& pass) const {
    
    if (uname == username && pass == password) {
        return true;
    } else {
        return false;
    }
    
}


