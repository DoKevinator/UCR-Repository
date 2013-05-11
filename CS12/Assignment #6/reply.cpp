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

//reply.cpp

#include "reply.h"

#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

Reply::Reply()
:Message() {    //default constructor
    
}


Reply::Reply(const string& athr, const string& sbjct,
      const string& body, unsigned id)
:Message(athr, sbjct, body, id) {
            //constructor
}


string Reply::to_formatted_string() const {
    string topic_formatted;//concatenating accumulator
    
    
    topic_formatted = "<begin_reply>\n:id: " + int_to_string(id) +
                      "\n:subject: " + subject +
                      "\n:from: " + author; //concatenates everything
    
    if (child_list.size() != 0) {   //if theres children, concatenate
        topic_formatted += "\n:children: ";
        
        for (unsigned i = 0; i < child_list.size(); i++) {
            topic_formatted = topic_formatted   //converts int to string 
            + int_to_string( child_list.at(i) -> get_id() ) + ' ';
        }   //used to concatenate to string
    }
    
    topic_formatted = topic_formatted + '\n' +
                      ":body: " + body + '\n' +
                      "<end>" + '\n';   //concatenates the body
    
    return topic_formatted; //return the accumulator
    
}


void Reply::print_subtree(unsigned indentation) const {
    
    cout << endl;
    
    for (unsigned j = 0; j < indentation; j++) {
        cout << "  ";   //prints amount of indentation
    }
    cout << "Message #" << id << ": " << subject << endl;//ID and subject prnted
    
    for (unsigned j = 0; j < indentation; j++) {
        cout << "  ";   //indentation
    }
    cout << "from " << author << ": ";
    
    for (unsigned j = 0; j < body.size(); j++) {
        cout << body.at(j);//prints each letter out one by one
                            //when it reaches new line, indent
        if (body.at(j) == '\n') {
            for (unsigned k = 0; k < indentation; k++) {
                cout << "  ";
            }
        }
    }
    
    cout << endl;
    
    for (unsigned i = 0; i < child_list.size(); i++) {
        dynamic_cast<Reply*>( child_list.at(i) ) ->
            print_subtree(indentation + 1); //recursive call to get all childs
    }
    //no base case since it is a void function.
    //when it reaches the end, it returns automatically
}



bool Reply::is_reply() const {
    return true;    //it is a reply to return true
}


void Reply::print() const { //outputs the message
    cout << "Message #" << id << ": " << subject << endl;
    cout << "from " << author << ": " << body << endl;
}


string Reply::int_to_string(const unsigned& number) const {
    stringstream ss;//create a stringstream
    ss << number;//add number to the stream
    return ss.str();//return a string with the contents of the stream
}




