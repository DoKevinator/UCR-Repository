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


//Message.h


//inclusion guards
#ifndef __MESSAGE_H_
#define __MESSAGE_H_
//includes
#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Message  // abstract base class
{
protected:  // allow access to these members by objects of derived classes
    string author;
    string subject;
    string body;
    unsigned id;  // New !!
    // This will be the size of the message_list vector to which the
    // newly constructed Message* is being pushed_back
    vector<Message*> child_list; // New !!
    // This is how a Message is able to keep track of its Replies
    
public:
    
    //default constructor
    Message();
    
//Parameterized constructor; id will be the size of current Bboard message_list
    Message(const string& athr, const string& sbjct,
            const string& body, unsigned id);
    
    //be careful here, you must invoke delete on pointers to objects
    //How many Message/Reply/Topic objects do you have in your program?
    virtual ~Message();
    
    virtual void print() const = 0;
    
    // returns true if the object is reply.
    virtual bool is_reply() const = 0;
    
    //returns the subject string.
    string get_subject() const;
    
    // returns the id.
    unsigned get_id() const; // New !!
    
    virtual string to_formatted_string() const = 0;  // New !!
    
    // Adds a pointer to the child to child_list.
    void add_child(Message* child); // New !!
    
};

//end inc guards
#endif

