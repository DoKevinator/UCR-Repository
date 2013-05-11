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



//message.cpp

#include "message.h"
#include <iostream>

using namespace std;

Message::Message()  //default constructor
:author(""), subject(""), body(""), id( 0 ) {
    
}

//constructor that initializes everything
Message::Message(const string& athr, const string& sbjct,
         const string& body, unsigned id)
:author(athr), subject(sbjct), body(body), id(id) {
    
}


string Message::get_subject() const {
    return subject; //returns subject of message
}


unsigned Message::get_id() const {
    return id;  //return ID of message
}


void Message::add_child(Message* child) {
    child_list.push_back(child);    //adds a child to child list
}


Message::~Message() {
    //delete [] child_list;   //fix
}



