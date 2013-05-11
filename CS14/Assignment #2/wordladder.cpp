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

//wordladder.cpp

#include "wordladder.h"

#include <iostream>
#include <fstream>
#include <list>
#include <queue>
#include <stack>

using namespace std;

//constructor that reads in all the words from words5.dict with an ifstream
WordLadder::WordLadder( const string& listFile ) {
    
    ifstream ipfile;
    ipfile.open( listFile.c_str() );
    
    if (ipfile.fail()) {
        cout << "No input file." << endl;
        exit(1);
    }
    
    string temp;
    
    while( ipfile >> temp ) {
        dictionary.push_back( temp );
    }
    
    ipfile.close();
    
}


//outputs the wordladder
void WordLadder::outputLadder( const string &start, const string &end ) {
    
    if ( !is_in_dict( start ) || !is_in_dict( end ) ) {
        cout << "Please enter a valid word(s)." << endl;
        exit(1);    //checks if the words are valid or not
    }
    
    if (start == end) {
        cout << start << endl;
        return;     //if both start and end are the same, just output one word
    }
    
    stack<string> words;
    words.push( start );    //stack of strings to hold combinations
    
    queue< stack<string> > ladders;
    ladders.push( words );  //queue to hold all the different combinations
    
    while (!ladders.empty()) {  //while queue not empty, keep running
        for(list<string>::iterator i=dictionary.begin(); i != dictionary.end();
            i++ ) { //loop through all the words in the dictionary
            
            //checks if the word is 1 letter different from previous
            if ( is_one_diff(ladders.front().top(), *i) ) { 
                if (*i == end) {    //if its the end word, print it all out
                    
                    stack<string> outputStack;  //temp stack for output in
                                                //correct order
                    while ( !ladders.front().empty() ) {
                        outputStack.push( ladders.front().top() );
                        ladders.front().pop();  //switches all stack words in
                    }                           //opposite order in temp stack
                    
                    while ( !outputStack.empty() ) {//while the stack isnt empty
                        
                        cout << outputStack.top() << ' ';
                        outputStack.pop();  //output all words with space
                    }
                    
                    cout << *i << endl; //output the last word in the ladder
                    
                    return;
                    //done!
                }
                
                stack<string> temp = ladders.front();
                temp.push( *i );        //pushes a new combination of words
                ladders.push(temp);     //onto the queue
                
                dictionary.erase(i);    //erases the word from dictionary
                i--;                    //decrements to avoid seg faulting
            }
        }
                
        ladders.pop();  //pops off the older combination in the queue
    }
}


//checks if two words are different by 1 letter
bool WordLadder::is_one_diff( const string& word, const string& compare ) {
    
    int counter = 0;    //counter to count the number of letters different
    
    for (unsigned i = 0; i < word.size(); i++) {
        if (compare.at(i) != word.at(i)) {
            counter++;  //goes through each character and compares it
        }
    }
    
    if (counter > 1) {  //if more than 1 letter is different, return false
        return false;
    }
    
    return true;        //else return true;
}


//checks if word is in the dictionary
bool WordLadder::is_in_dict( const string& s) {
    
    for( list<string>::iterator i = dictionary.begin();
         i != dictionary.end();i++ ) {
        if (s == *i) {  //loops through dictionary to see if word is in dict
            return true;//returns true if it is
        }
    }
    
    return false;   //else returns false;
}


