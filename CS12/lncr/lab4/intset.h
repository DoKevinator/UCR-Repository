//intset.h

#ifndef __INTSET_H_
#define __INTSET_H_

#include <iostream>

using namespace std;

class IntSet {
    
private:
    int* numbers;
    unsigned int size;
    unsigned int capacity;
    
public:
    IntSet();
    IntSet( unsigned int size );
    ~IntSet();
    
    //accessors
    void print() const;
    int& at( unsigned index ) const;
    void push_back( unsigned int n );
    
    IntSet operator+ ( const IntSet &x ) const;

};

#endif