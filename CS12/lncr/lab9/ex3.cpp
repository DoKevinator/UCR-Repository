//ex3.cpp

#include <iostream>
#include <vector>

using namespace std;


vector<string> permutations( const string& s ) {
    
    if (s.size() == 0) {
        vector<string> v;
        v.push_back( "" );
        return v;
    }
    
    vector<string> v = permutations( s.substr(1) );
    
    vector<string> temp;
    
    for (unsigned i = 0; i < v.size(); i++) {
        for (unsigned j = 0; j < v.at(i).size()+1; j++) {
            temp.push_back( v.at(i).substr(0,j) + s.at(0) + v.at(i).substr(j));
        }
    }
    
    return temp;
    
}


int main() {
    
    string s = "cat";
    
    vector<string> v = permutations(s);
    
    for (unsigned i = 0; i < v.size(); i++) {
        cout << v.at(i) << ' ';
    }
    
    cout << endl;
    
    return 0;
}