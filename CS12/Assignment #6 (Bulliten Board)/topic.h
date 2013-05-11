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


//inclusion guards
#ifndef __TOPIC_H_
#define __TOPIC_H_
//includes
#include "message.h"

class Topic: public Message
{
    // no new member variables
public:
    
    //default constructor
    Topic();
    
    //Parameterized constructor
    Topic(const string& athr, const string& sbjct,
          const string& body, unsigned id);
    
    /* this function will print the Topic as in the previous assignment.
     * Then it invokes print_subtree(1) on each of the messages in child_list
     * (which are all "first-level" Reply objects).
     */
    virtual void print() const; // Major Change!!
    
    virtual bool is_reply() const;
    
    /* to_formatted_string writes the contents of the Topic to a string in the following format:
     <begin_topic>
     :id: 4
     :subject: single line
     :from: author
     :children: 5 6 [this line should not be printed if there are no children.]
     :body: multiple lines - line 1
     line 2
     line 3
     <end>
     * line starting with :children: has the id's of all children (See file specs. for details)
     */
    virtual string to_formatted_string() const;  // New !!
    
private:
    string int_to_string(const unsigned& number) const;
    
};

//end inc guards
#endif

