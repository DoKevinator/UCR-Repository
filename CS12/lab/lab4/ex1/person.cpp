//person.cpp

#include "person.h"
#include <iostream>

using namespace std;

Person::Person()
:name(""), dog( NULL ) {
    
}

Person::Person(const string &n, Dog* d)
:name(n), dog(d) {
    
}

void Person::print() const {
    cout << name << endl;
    cout << "\t";
    
    if( dog == NULL ) {
        cout << "No pet." << endl;
    } else {
        dog -> printDog();
    }
    
}