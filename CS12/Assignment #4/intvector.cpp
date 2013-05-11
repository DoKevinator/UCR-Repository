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

//intvector.cpp

#include "intvector.h"

#include <iostream>

using namespace std;

//~~~~~~~~~~begin constructors~~~~~~~~~~//
IntVector::IntVector()
:vsize(0), vcapacity(0), data(NULL) {
        //default constructor
}

IntVector::IntVector( unsigned size )
:vsize(size), vcapacity(size), data( new int[size] ) {
    for(unsigned int i = 0; i < size; i++ ) {
        data[i] = 0;    //initializes array to given size and
    }                   //contents to 0
}

IntVector::IntVector( unsigned size, int value )
:vsize(size), vcapacity(size), data( new int[size] ) {
    for (unsigned i = 0; i < size; i++) {
        data[i] = value;    //initializes array to given size
    }                       //and contents to given value
}

IntVector::~IntVector() {
    delete [] data; //destructor that deletes the dynamic array
}
//~~~~~~~~~~end constructors~~~~~~~~~~//



//~~~~~~~~~~begin private member functions~~~~~~~~~~//
void IntVector::expand() { //expands the vector by 2 times
    
        //create a temporary array 2 times bigger than original
    int* temp = new int[vcapacity * 2];
    
    for( unsigned int i = 0; i < vcapacity; i++ ) {
        temp[i] = data[i];  //copies data from original to temporary array
    }
    
    delete [] data; // delete original
    
    data = temp;    //assign the address of temp to data
    
    vcapacity *= 2; //make capacity times 2
}


void IntVector::expand( unsigned amount ) { //expands vector by given amount
    
        //creates temp array with given amount expanded
    int* temp = new int[vcapacity + amount];
    
    for( unsigned int i = 0; i < vcapacity; i++ ) {
        temp[i] = data[i];  //copies data into temp
    }
    
    delete [] data; //delete original
    
    data = temp;    //assign new address of temp
    
    vcapacity += amount;    //increase capacity by amount
}
//~~~~~~~~~~end private member functions~~~~~~~~~~//



//~~~~~~~~~~begin accessors~~~~~~~~~~//
unsigned int IntVector::size() const {
    return vsize;   //returns the current size of the vector
}


unsigned IntVector::capacity() const {
    return vcapacity;   //returns current capacity of vector
}


bool IntVector::empty() const {
    if (vsize != 0) {
        return false;   //if the vector is empty, return true
    } else {            //if its not empty, return false
        return true;
    }
}


int& IntVector::at( unsigned index ) {
    if( index >= vsize ) {  //checks if index is in bounds.
        exit(1);
    }
    
    return data[index];     //returns the value at given index
}


const int& IntVector::at( unsigned index ) const {
    
    if( index >= vsize ) {  //checks if index is in bounds
        exit(1);
    }
    
    return data[index]; //returns value at given index
}


const int & IntVector::operator[]( unsigned index ) const {
    return data[index]; //returns value at given index
                        //operator overloads []
}


const int& IntVector::front() const {
    return data[0];   //returns value in first index
}


const int & IntVector::back() const {
    return data[vsize-1];   //returns value at last index
}
//~~~~~~~~~~end accessors~~~~~~~~~~//



///~~~~~~~~~~begin mutators~~~~~~~~~//

void IntVector::insert( unsigned index, int data ) {
    if (index > vsize) {
        exit(1);        //checks if its in bounds
    }
    
    if( vsize == 0 ) {
        expand(1);      //checks if vector needs to be expanded or not  
    } else if (vsize >= vcapacity) {
        expand();
    }
    
    this->data[vsize] = data;   //adds value to end of vector
    vsize++;                    //similar to push_back
    
    for (unsigned i = (vsize-1); i > index; i--) {
        swap( this->data[i], this->data[i-1]);  //swaps value til it is
    }                                           //in the right index

}


void IntVector::erase( unsigned index ) {
    if (index >= vsize) {   //checks if index is in bounds
        exit(1);
    }
    
    for (unsigned i = index; i < vsize - 1; i++) {
        swap( data[i], data[i + 1] );   //swaps until value is in the
    }                                   //right index
    
    vsize--;    //decrements size (similar to pop_back)
}


void IntVector::push_back( int data ) {
    if (vcapacity == 0) {   //checks if the vector needs to be expanded
        expand(1);
    } else if( vsize >= vcapacity ) {
        expand();
    }
    
    this->data[vsize] = data;   //adds data to the end of the vector
    vsize++;                    //increments size
}


void IntVector::pop_back() {
    if (vsize == 0) {   //checks if there is anything to pop_back
        exit(1);
    }
    
    vsize--;    //decrements size so user cannot access anymore
}


void IntVector::clear() {
    vsize = 0;  //clears the entire vector and sets size to 0
}               //user cannot access anything anymore. size is 0


void IntVector::resize( unsigned sz ) {
    if (sz <= vsize) {  //changes size if its less than current size
        vsize = sz;
    } else if( sz > vsize ) {
        if (sz > (vcapacity * 2)) {     //determines which method to use when
            expand(sz - vcapacity);     //expanding the vector
        } else if( sz > vcapacity && sz <= (vcapacity * 2)) {
            expand();
        }
        
        for (unsigned i = vsize; i < sz; i++) {
            data[i] = 0;    //initializes the newly created indexes with 0
        }
    }
}


void IntVector::resize( unsigned sz, int value ) {
    if (sz <= vsize) {  //changes size if its is less than current size
        vsize = sz;
    } else if( sz > vsize ) {
        if (sz > (vcapacity * 2)) {     //determines which method to use when
            expand(sz - vcapacity);     //expanding the vector
        } else if( sz > vcapacity && sz <= (vcapacity * 2)) {
            expand();
        }
        
        for (unsigned i = vsize; i < sz; i++) {
            data[i] = value;    //initializes newly created indexes to value
        }
        
        vsize = sz; //adjust the current size 
    }
}


void IntVector::assign( unsigned n, int value ) {
    if (n > (vcapacity * 2)) {  //determines which method of expand to use
        expand(n - vcapacity);
    } else if( n > vcapacity && n <= (vcapacity * 2)) {
        expand();
    }
    
    vsize = n;  //adjusts the current size to size being passed in
    
    for (unsigned i = 0; i < vsize; i++) {
        data[i] = value;    //changes all values to new value passed in
    }
    
}


int & IntVector::operator[]( unsigned index ) {
    return data[index]; //returns value at the given index
}


int & IntVector::front() {
    return data[0]; //returns the first value in the vector
}


int & IntVector::back() {
    return data[vsize-1];   //returns the last value in the vector
}


void IntVector::reserve( unsigned n ) {
    if (n > vcapacity * 2) {    //determines which method to use to
        expand(n - vcapacity);  //expand the capacity 
    } else if( n > vcapacity && n <= (vcapacity * 2) ) {
        expand();
    }
}
//~~~~~~~~~~ end mutators ~~~~~~~~~~~//












