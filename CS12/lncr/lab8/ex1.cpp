//ex1.cpp

#include <iostream>

using namespace std;

int frequency( const char* s, char letter ) {
    
    if (s[0] == '\0') {
        return 0;
    }
    
    int count = frequency( s + 1, letter );
    
    if (s[0] == letter) {
        count++;
    }
    
    return count;
    
}


int main() {
    
    string s = "hello, cruel world!";
    cout << frequency(s.c_str(), 'r') << endl;
    
    return 0;
}