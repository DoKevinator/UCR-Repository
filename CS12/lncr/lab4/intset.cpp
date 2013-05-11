//intset.cpp

#include "intset.h"
#include <iostream>

using namespace std;


//~~~~~~~~~~ begin constructors ~~~~~~~~~~//
IntSet::IntSet()
:numbers( new int[10] ), size(0), capacity(10) {
    
}

IntSet::IntSet( unsigned int size )
:numbers( new int[size] ), size(0), capacity(size) {
    
}

IntSet::~IntSet() {
    delete [] numbers;
}
//~~~~~~~~~~ end constructors ~~~~~~~~~~//




void IntSet::print() const{
    for (unsigned i = 0; i < size; i++) {
        cout << numbers[i] << " ";
    }
    
    cout << endl;
}


int& IntSet::at( unsigned index ) const {
    
    if (index > size) {
        cout << "Invalid index. Program terminating." << endl;
        exit(1);
    }
    
    return numbers[index];
}


void IntSet::push_back( unsigned int n ) {
    
    if (size == capacity) {
        cout << "The set is full. Program terminating." << endl;
        exit(1);
    }
    
    numbers[size] = n;
    size++;
}



IntSet IntSet::operator+ ( const IntSet &x ) const {
    
    IntSet temp( size + x.size );
    
    for (unsigned i = 0; i < size; i++) {
        temp.at(i) = numbers[i];
    }
    
    for (unsigned i = 0; i < size; i++) {
        for (unsigned j = 0; j < x.size; i++) {
            if (numbers[i] != x.at(j)) {
                temp.push_back(x.at(j));
            }
        }
    }
    
    return temp;
    
    
}
 
 












