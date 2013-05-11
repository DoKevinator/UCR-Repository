//ex4.cpp

#include <iostream>

using namespace std;


string string_sort( const string& s ) {
    if (s.size() == 0) {
        return "";
    }
    
    string temp = string_sort(s);
    
    for (unsigned i = 0; i < temp.size(); i++) {
        if (temp.at(i) > s.at(0)) {
            temp = temp.substr(0,i) + s.at(0) + temp.substr(i);
        }
    }
    
    return temp;
    
}


int main() {
    
    string temp = "bga";
    
    cout << string_sort( temp ) << endl;
    
    return 0;
}