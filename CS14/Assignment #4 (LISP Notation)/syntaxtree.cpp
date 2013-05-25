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

//syntaxtree.cpp

#include "syntaxtree.h"
#include <iostream>
#include <stack>
#include <sstream>

using namespace std;


SyntaxTree::SyntaxTree()
:root( NULL ) {
    	//default constructor
}

SyntaxTree::~SyntaxTree() {
    delete root;
}



bool SyntaxTree::load_formula( string& s ) {
	
	stack<Node*> tree_creator;
	
	string formula = reformat_formula(s);
	
	while( !formula.empty() ) {
		string individual;		//gets a new individual token each time
		individual = formula.substr(0, formula.find(' ') );
		formula = formula.substr( formula.find(' ') + 1 );
		
		if( individual.at(0) == '(' && 	//if the token has both ( and )
			individual.at( individual.size()-1 ) == ')' ) {
			
			individual = individual.substr(1);
			individual = individual.substr(0, individual.find(')') );
			
			stringstream ss( individual );
			double value;
			ss >> value;	//just get the value inbetween and add to tree
			
			Node* newnode = new Node("",value);
			tree_creator.push( newnode );
			
		} else if( individual.at(0) == '(' ) {
			//we know its an operator at this point.
			individual = individual.substr(1);
			//push the '(' onto the stack too. 
			Node* parennode = new Node("(",0);
			tree_creator.push( parennode );
			
			if( individual.at( individual.size()-1 ) == ')' ) {
				individual = individual.substr(0, individual.find(')') );
			}	//checks if the thing was only passed in one number
			
			//now that we've got the operator by itself, we can change it to a 
			//node and add it to the stack.
			bool forloopcompleted = false;
			for( unsigned i = 0; i < individual.size(); i++ ) {
				if( individual.at(i) < '0' || individual.at(i) > '9' ) {
					break;
				}
				if( i == individual.size()-1 ) {
					forloopcompleted = true;
				}
			}
			
			if( forloopcompleted ) {
				//we know its a number, not an operator.
				stringstream ss( individual );
				double value;
				ss >> value;
				
				Node* newnode = new Node("",value);
				
				tree_creator.push( newnode );
				
			} else {
				//we know its an operator.
				Node* newnode = new Node(individual,0);
				
				tree_creator.push( newnode );
			}
			
		} else if( individual.at( individual.size()-1 ) == ')' ) {
			//we know we have to "combine" the stuff in the stack because of the 
			//closing parenthesis. get rid of closing paren first. 
			if( individual.size() == 1 && individual.at(0) == ')' ) {
				individual = "";
			} else {
				individual = individual.substr(0, individual.find(')') );
				//first we have to add in the latest node tho. then we can
				//combine. we know this node has to be a number. 
				
				stringstream ss( individual );
				double value;
				ss >> value;
			
				Node* newnode = new Node("",value);
			
				tree_creator.push( newnode );
				
				//now we have to "combine" the latest. 
				//we keep combining til we reach an opening parenthesis: '('
			}
			
			stack<Node*> temp;
			while( tree_creator.top() -> data != "(" ) {
				temp.push( tree_creator.top() );
				tree_creator.pop();	//"combining part" to get a mini tree after
			}						//each end parenthesis
			tree_creator.pop();
			tree_creator.push( temp.top() );
			temp.pop();
			while( !temp.empty() ) {
				tree_creator.top() -> children.push_back( temp.top() );
				temp.pop();
			}
			//at this point we finished combining.
			
		} else {
			//we know its just a number at this point.
			//we ruled out all possibilities.
			stringstream ss( individual );
			double value;
			ss >> value;
			
			Node* newnode = new Node("",value);
			
			tree_creator.push( newnode );
		}
		
	}
	
	if( tree_creator.size() > 1 ) {
		cerr << "Error: Invalid tree." << endl;
		return false;
	}
	
	root = tree_creator.top();
	
	return true;
	
}



double SyntaxTree::evaluate_tree( Node* current ) {
	
	double accumulator = current -> value;
		//loops throughout the entire childrens list
	for( list<Node*>::iterator i = current->children.begin();
		 i != current->children.end(); i++ ) {
		if( (*i) -> data == "" ) {	//we know at this point the data is a number
		
			if( current -> data == "+" ) {	//does the corresponding computation
				accumulator += (*i) -> value;
			} else if( current -> data == "-" ) {
				accumulator -= (*i) -> value;
			} else if( current -> data == "*" ) {
				if( accumulator == 0 ) {
					accumulator = 1;
				}
				accumulator *= (*i) -> value;
			} else if( current -> data == "/" ) {
				if( accumulator == 0 ) {
					accumulator = 1;
				}
				accumulator /= (*i) -> value;
			} else {
				cerr << current -> data << " is not a function" << endl;
				return -999999999;	//error if its not an operator
			}
			
		} else {
					//at this point we know the data is an operator
					//so we have to recursively go through again 
					//until we reach a "leaf node"
			if( current -> data == "+" ) {
				accumulator += evaluate_tree(*i);
			} else if( current -> data == "-" ) {
				accumulator -= evaluate_tree(*i);
			} else if( current -> data == "*" ) {
				if( accumulator == 0 ) {
					accumulator = 1;
				}
				accumulator *= evaluate_tree(*i);
			} else if( current -> data == "/" ) {
				if( accumulator == 0 ) {
					accumulator = 1;
				}
				accumulator /= evaluate_tree(*i);
			} else {
				cerr << current -> data << " is not a function" << endl;
				return -999999999;	//returns if the operator is not a function
			}
			
		}
	}
	
	if( !current -> children.empty() ) {
		return accumulator;
	} else {		//checks if the operators require one parameter or not
		cerr << "Error: " << current -> data << " requires two parameters." << endl;
		return -999999999;
	}
	
	
}



Node* SyntaxTree::getRoot() const {
	return root;	//gets the root of the tree
}


string SyntaxTree::reformat_formula( string& s ) {
			//adds in spaces where i need it for the sake of my formatting.
			//i get a consistent spacing for each formula this way
	string temp = s;
	unsigned size = temp.size();

	for( unsigned i = 0; i < size-2; i++ ) {
		if( temp.at(i) == '(' && temp.at(i+1) == '(' ) {
			temp = temp.substr(0, i+1) + " " + temp.substr(i+1);
			size++;		//adds spaces with double opening parenthesis
			i = 0;
		}
		
		if( temp.at(i) == ')' && temp.at(i+1) == ')' ) {
			temp = temp.substr(0, i+1) + " " + temp.substr(i+1);
			size++;		//adds spaces with double closing parenthesis
			i = 0;
		}
	}
	
	return temp;
}


