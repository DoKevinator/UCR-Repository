//intvector.cpp

#include "intvector.h"

#include <iostream>

using namespace std;

IntVector::IntVector()
:vsize(0), vcapacity(0), data(NULL) {
    
}

IntVector::IntVector( unsigned size ) 
:vsize(size), vcapacity(size), data( new int[size] ) {
    for(int i = 0; i < size; i++ ) {
        data[i] = 0;
    }
}


unsigned int IntVector::size() {
    return vsize;
}


int IntVector::&at( unsigned index ) {
    if( index >= vsize ) {
        exit(1);
    }
    
    return data[index];
}


const int& IntVector::at( unsigned index ) const {
    
    if( index >= vsize ) {
        exit(1);
    } 
    
    return data[index];
}


