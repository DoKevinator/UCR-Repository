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



//bboard.h

#ifndef __BBOARD_H_ //inclusion guard
#define __BBOARD_H_

#include "user.h"   //include user.h
#include "message.h"//include message.h

#include <iostream>//iostream and vector
#include <vector>

using namespace std;    //standard namespace

class Bboard {  //Bboard class
    
private:
    string title;   //title of Bboard
    vector<User> user_list; //vector or users
    User current_user;  //current user logged in
    vector<Message> message_list;   //message list vector
    
public:
    Bboard();   //defauly constructor
    Bboard( const string &ttl );    //constructor
    void setup();   //setup function
    void login();   //login function
    void run();     //run function
    
private:    
    void add_user(const string& name, const string& pass);
        //adds user to the user_list vector
    bool user_exists(const string& name, const string& pass) const;
        //checks if the user is a valid user
    User get_user(const string& name) const;
        //gets a user with the name
    void display() const;
        //displays the format for the messages
    void add_message( const string &name );
        //adds a message into the message vector
    
};

#endif //__BBOARD_H_

