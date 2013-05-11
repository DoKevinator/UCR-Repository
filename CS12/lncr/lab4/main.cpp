//main.cpp

#include "intset.h"
#include <iostream>

using namespace std;

int main() {
    
    IntSet s1, s2, s3;
    
    s1.push_back(1);
    s1.push_back(2);
    s1.push_back(3);
    
    s2.push_back(3);
    s2.push_back(4);
    s2.push_back(5);
    
    s3 = s1 + s2;
    
    s3.print();
    
    
    return 0;
}