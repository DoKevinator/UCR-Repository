//dog.cpp

#include "dog.h"
#include <iostream>

using namespace std;

Dog::Dog()
:name(""), breed("") {
    
}

Dog::Dog( const string &n, const string &b )
:name(n), breed(b) {
    
}


void Dog::setName( const string &n ) {
    name = n;
}


void Dog::printDog() const {
    
    cout << name << " : " << breed << endl;
    
}

