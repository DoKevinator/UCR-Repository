//ex3.cpp

#include <iostream>

using namespace std;

int arithmetic_sum( int start, int diff, int n ) {
    if (n == 0) {
        return 0;
    }
    cout << start << endl;
    cout << n << endl;
    int accumulator = arithmetic_sum( start + diff, diff, n - 1 );
    
    accumulator = accumulator + start;
    
    return accumulator;
}

int main() {
    
    cout << arithmetic_sum( 3, 3, 5) << endl;
    
    return 0;
}