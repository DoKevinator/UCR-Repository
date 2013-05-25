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
// Assignment: assn4
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//=================================================================

//syntaxtree.h

#ifndef __SYNTAXTREE_H_
#define __SYNTAXTREE_H_

#include <list>
#include <string>

using namespace std;

struct Node {
    string data;
    double value;
    list<Node*> children;	//list of children
    
    Node( const string& d, double v )
    :data(d), value(v) { }		//constructor for Node struct
};



class SyntaxTree {
    
private:
	Node* root;		//root of the tree
	
	string reformat_formula( string& );	//reformats the formula for easier parse
    
public:
    SyntaxTree();	//constructor
    ~SyntaxTree();	//destructor
    
    bool load_formula( string& );	//loads the formula into a syntax tree
    double evaluate_tree( Node* );	//evaluates the tree to get a value
    
    Node* getRoot() const;	//gets the root of the tree
};




#endif	//__SYNTAXTREE_H_
