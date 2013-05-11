// Course: CS 14 Spring 2013
//
// First name: Kevin
// Last name: Do
// Course username: kdo009
// Email address: kdo009@ucr.edu
//
// Lecture section: 001
// Lab section: 021
// TA: Steve Cook
//
// Assignment: assn2
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//=================================================================

//wordladder.h

#ifndef __WORDLADDER_H_
#define __WORDLADDER_H_

#include <list>
#include <string>

using namespace std;

class WordLadder {
    
private:
    list<string> dictionary;    //holds all the 5 letter words
    
    //finds if the word is 1 letter different or not
    bool is_one_diff( const string& word, const string& compare );
    
    //checks if the word is in the dictionary
    bool is_in_dict( const string& s );
    
public:
    
    //wordladder constructor
    WordLadder( const string &listFile );
    
    //outputs the full wordladder
    void outputLadder( const string &start, const string &end );
    
};

#endif

