//main.cpp

#include "person.h"
#include "dog.h"

#include <iostream>

using namespace std;

int main() {
    
    Dog dog1( "Fido" , "Border Collie" );
    
    Person p1( "Sally", &dog1 );
    Person p2( "Bob", &dog1 );
    Person p3( "Tron", NULL );
    
    p1.print();
    p2.print();
    p3.print();
    
    dog1.setName( "Clifford" );
    
    p1.print();
    p2.print();
    p3.print();
    
    
    return 0;
}
