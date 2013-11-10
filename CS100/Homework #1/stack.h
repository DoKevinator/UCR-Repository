/*
* Course: CS 100 Fall 2013
*
* First Name: Kevin
* Last Name: Do
* Username: kdo009
* email address: kdo009@ucr.edu
*
*
* Assignment: Homework #1
*
* I hereby certify that the contents of this file represent
* my own original individual work. Nowhere herein is there
* code from any outside resources such as another individual,
* a website, or publishings unless specifically designated as
* permissible by the instructor or TA.
*/


#ifndef _STACK_H_
#define _STACK_H_

#include <iostream>
#include <list>
#define STACK_CAPACITY 1000

using namespace std;

class Stack {

private:
	char* container;
	int size;

public:
	Stack()
	:size(0), container(new char[STACK_CAPACITY]) { }//constructor for a stack

	//adds c to the top of the stack
	void push(char c) {

		if( size < STACK_CAPACITY) {
			container[size+1] = c;
			size++;
		} else {
			cerr << "Error: stack exceeded capacity." << endl;
			exit(0);
		}
		
	} 

	//removes the top element, returns it
	char pop() {
		char temp = container[size];
		size--;
		return temp;
		
	}		

	//returns the top element
	char top() {
		return container[size];
	}		

	//returns true iff the stack is empty
	bool isEmpty() {
		if(size) {
			return true;
		} else {
			return false;
		}
	}  

	//destructor for a stack
	~Stack() { 
		delete [] container;
	} 

};

#endif  //_STACK_H_
