//ex1.cpp

#include <iostream>

using namespace std;


int gcd( int num1, int num2 ) {
    if (num1 == num2) {
        return num1;
    }
    
    if (num1 > num2) {
        return gcd( num1 - num2, num2 );
    }
    
    if (num2 > num1) {
        return gcd( num1, num2 - num1 );
    }
}

int main() {
    
    cout << gcd( 54, 24 ) << endl;
    
    return 0;
}