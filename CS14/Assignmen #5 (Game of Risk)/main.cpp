// Course: CS 14 Spring 2013
//
// First name: Kevin
// Last name: Do
// Course username: kdo009
// Email address: kdo009@ucr.edu
//
// Lecture section: 001
// Lab section: 021
// TA: Steve Cook
//
// Assignment: assn5
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//=================================================================

//main.cpp


#include <iostream>
#include "graph.h"
#include <stack>

using namespace std;

int main() {
    
    Graph g;
    g.load_graph( "risk-board.graph" );
    
    string start;
    string end;
    stack<string> pathway;
    
    while(cin) {
        cout << endl;
    
        cout << "start territory: ";
        getline( cin, start );
        
        cout << "end territory: ";
        getline( cin, end );
        
        pathway = g.shortest_path( start, end );
        
        if( pathway.size() > 0 ) {
            cout << endl << "shortest path: " << endl;
            while( pathway.size() != 0 ) {
                cout << pathway.top() << endl;
                pathway.pop();
            }
        }
        
    }

    g.reset();
    
    return 0;
}


