//ex1.cpp

#include <iostream>
#include <vector>

using namespace std;


int vsum( const vector<int>& v ) {
    if( v.size() == 0 ) {
        return 0;
    }
    
    vector<int> temp;
    
    for( unsigned i = 1; i < v.size(); i++ ) {
        temp.push_back(v.at(i));
    }
    
    return v.at(0) + vsum( temp );
    
}


int main() {
    
    vector<int> v;
    
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(15);
    
    cout << "Sum: " << vsum(v) << endl;
    
    return 0;
}