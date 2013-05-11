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


//User.h


#ifndef __USER_H_
#define __USER_H_

#include <iostream>

using namespace std;

class User
{
    
private:
    
    string username;
    string password;
    
public:
    
    //creates a user with empty name and password.
    User();
    
    // creates a user with given username and password.
    User(const string& uname, const string& pass);
    
    
    //returns the username
    string get_username() const;
    
    // returns true if the stored username/password matches with the parameters.
    // Otherwise returns false.
    // Note that, even though a User with emptyl name and password is actually a valid User object
    // (it is the default User), this function must still return false if given a empty uname string.
    bool check(const string& uname, const string& pass) const;
    
    // sets a new password. This function will not be used in the current assignment.
    void set_password(const string& newpass);
    
};


#endif //__USER_H_

