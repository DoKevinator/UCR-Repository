//dog.h

#ifndef _DOG_H_
#define _DOG_H_
#include <iostream>

using namespace std;

class Dog {
    
private:
    string name;
    string breed;
    
public:
    Dog();
    Dog(const string &n, const string &b);
    
    void setName( const string &n );
    void printDog() const;
    
};
