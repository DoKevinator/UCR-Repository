//ex2.cpp

#include <iostream>

using namespace std;


double pow( double base, int exponent ) {
    
    if (exponent == 0) {
        return 1;
    }
    
    if (exponent > 0) {
        return base * pow(base, exponent - 1 );
    } else if( exponent < 0 ) {
        return 1/base * pow(base,exponent + 1) ;
    }
}


int main() {
    
    cout << "output (2^3): " << pow( 2, 3 ) << endl;
    cout << "output (2^-3): " << pow( 2, -3 ) << endl;
    
    return 0;
}