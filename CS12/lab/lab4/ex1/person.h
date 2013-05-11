//person.h

#ifndef _PERSON_H_
#define _PERSON_H_

#include "dog.h"
#include <iostream>

using namespace std;

class Person {
    
private:
    string name;
    Dog* dog;
public:
    Person();
    Person( const string &n, Dog* d );
    
    void print() const;
    
};

