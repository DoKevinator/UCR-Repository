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
// Assignment: assn5
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//
// =================================================================


//intlist.h

#ifndef __INTLIST_H_    //inclusion guards
#define __INTLIST_H_


struct IntNode {
    int data;   //holds the node data
    IntNode* next;  //holds the upcoming node in list
    IntNode( int data ) : data( data ), next( 0 ) {}//constructor
    IntNode( ) : data( 0 ), next( 0 ) {}//default constructor
};


class IntList {
    
private:
    IntNode * head; //represents the beginning of list
    IntNode * tail; //represents end of the list
    unsigned int sz;    //current size of the list
    IntNode* find_sorted_location(int v) const;
        //helper function for inser_sorted
    
public:
    IntList();  // default constructor
    ~IntList();  // destructor deletes list, which also deletes nodes
    unsigned int size() const;  // returns the given size
    void print() const;  //prints the list with spaces inbetween
    void push_front( int value );  //adds value to the beginning of list
    void push_back( int value );  //adds value to end of list
    void pop_front();  //deletes the first value in list
    void select_sort();  //given function that sorts the list in order
    void insert_sorted( int value );  //inserts a value in correct order
    void remove_duplicates();  //removes all duplicates in the list
    bool is_sorted() const;     //checks if the list is sorted or not
    
};

#endif






