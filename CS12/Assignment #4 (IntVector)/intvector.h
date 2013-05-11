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
// Assignment: assn4
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//
// =================================================================


//intvector.h


#ifndef _INTVECTOR_H_
#define _INTVECTOR_H_
#include <iostream>

using namespace std;

class IntVector {
    
private:
    unsigned vsize; //current size of the vector
    unsigned vcapacity; //current capacity of the vector
    int* data;  //dynamic array for vector
    
    void expand();  //expands vector by 2 times 
    void expand(unsigned amount);   //expands vector by given amount
    
public:
    IntVector();    //default constructor
    IntVector( unsigned size );
    IntVector( unsigned size, int value );
    ~IntVector();   //destructor
    
    //~accessors~
    unsigned int size() const;  //returns the size of the vector
    unsigned capacity() const;  //returns capacity of the vector
    bool empty() const; //checks if the vector is empty or not
    const int &at( unsigned index) const;   //returns value at index  r-value
    const int & operator[]( unsigned index )const;//returns value at index r-val
    const int & front() const;//returns the first value in vector
    const int & back() const;//returns last value in vector
    
    //~mutators~
    void insert( unsigned index, int data );//inserts value into an index
    void erase( unsigned index );   //gets rid of a value in an index
    void push_back( int data ); //adds a value to the end of a vector
    void pop_back();    //deletes a value at the end of a vectors
    void clear();   //clears the entire vector
    void resize( unsigned sz ); //resizes and initialize new indexes to 0
    void resize( unsigned sz, int value );//resize and initialize to value
    void reserve( unsigned n ); //reserves a minimum amount of capacity
    void assign( unsigned n, int value ); //assigns a new size and index values
    int & at( unsigned index ); //returns value at given index  l-value
    int & operator[]( unsigned index );//returns value at given index   l-value
    int & front();//returns first value in vector
    int & back();   //returns last value in vector
    
    
    
};

#endif




