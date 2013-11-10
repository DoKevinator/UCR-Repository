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

//topic.cpp
#include "topic.h"
#include "reply.h"
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

Topic::Topic()
:Message() {
        //default constructor
}


Topic::Topic(const string& athr, const string& sbjct,
      const string& body, unsigned id)
:Message(athr, sbjct, body, id) {
    //constructor
}


void Topic::print() const {
    cout << "Message #" << id << ": " << subject << endl;
    cout << "from " << author << ": " << body << endl;
    //prints message id and subject and body
    
    for (unsigned i = 0; i < child_list.size(); i++) {
        dynamic_cast<Reply*>( child_list.at(i) ) -> print_subtree(1);
    }   //calls the recursive function on all children of the topic
    
}


string Topic::to_formatted_string() const {
    string topic_formatted; //string concatenating accumulator
    
    
    topic_formatted = "<begin_topic>\n:id: " + int_to_string(id) +
                      "\n:subject: " + subject +
                      "\n:from: " + author;//concatenates id, sbjct, athr
    
    if (child_list.size() != 0) {
        topic_formatted += "\n:children: ";
            //if no children, do not concatenate. if there is, do so
        for (unsigned i = 0; i < child_list.size(); i++) {
            topic_formatted = topic_formatted
            + int_to_string( child_list.at(i) -> get_id() ) + ' ';
        }
    }
    
    topic_formatted = topic_formatted + '\n' +  //concatenates body
                      ":body: " + body + '\n' +
                      "<end>" + '\n';
    
    return topic_formatted;
    
}


bool Topic::is_reply() const {
    return false;   //returns false cause its not a reply
}


string Topic::int_to_string(const unsigned& number) const {
    stringstream ss;//create a stringstream
    ss << number;//add number to the stream
    return ss.str();//return a string with the contents of the stream
}


