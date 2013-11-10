// Course: CS 12 Winter 2013
//
// First Name: Kevin
// Last Name: Do
// Course username: kdo009
// email address: kdo009@ucr.edu
//
// Lecture Section: 001
// Lab Section: 021
// TA: Sean Allen
//
// Assignment: assn5
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//
// =================================================================


//intlist.cpp

#include "intlist.h"
#include <iostream>

using namespace std;

//----------begin constructor and deconstructor----------//
IntList::IntList()
:head(NULL), tail(NULL), sz(0) {
    //default constructor
}

IntList::~IntList() {
    IntNode* temp;
    
    while( head ) {     //destructor that loops through entire list and deletes
        temp = head; //grabs head by temp, then reassigns head, and deletes temp
        head = head -> next;
        delete temp;
	}
}
//----------end constructor and deconstructor----------//


void IntList::print() const {
    IntNode* temp = head;   
    
    while (temp) {  //loops til the pointer is NULL
        cout << temp -> data << " ";
        temp = temp -> next;    //outputs and advances
    }
}

void IntList::push_front( int value ) {
    if (head == NULL) { //checks if the head is NULL
        head = new IntNode( value );    //if it is, just add a node at the front
        tail = head;
        sz++;//increment size
    } else {
        IntNode* temp = new IntNode( value );
        temp -> next = head;
        head = temp;    //uses temp to hold the new node, and reassigns head
        sz++;//increment size
    }
    
}

void IntList::push_back( int value ) {
    if (head == NULL) {
        head = new IntNode( value );
        tail = head;    //checks if head is NULL and adds it as the only node
        sz++;//increment size
    } else {
        tail -> next = new IntNode( value );
        tail = tail -> next;  //makes tail point to new node, and reassign tail
        sz++;//increment size
    }
}

void IntList::pop_front() {
    if (head != NULL) {
        IntNode* temp = head;   //checks if head is NULL, if it is, do nothing
        head = head -> next;    //reassigns head and deletes temp
        delete temp;//fixed?
        sz--;   //decrement size
    } 
}

void IntList::select_sort() {   //given function
    
    for (IntNode* cur = head; cur != NULL; cur = cur -> next) {
        IntNode* smallest = cur;
        
        for (IntNode* n_min = cur; n_min != NULL; n_min = n_min -> next) {
            if (n_min -> data < smallest -> data) {
                smallest = n_min;
            }
        }
        
        int temp = cur -> data;
        cur -> data = smallest -> data;
        smallest -> data = temp;
        
    }
    
}

unsigned int IntList::size() const {
    return sz;  //returns the current size
}


void IntList::insert_sorted( int value ) {
    if (head == NULL) { //if there is nothing in list, just add it
        push_front(value);
    } else if( find_sorted_location(value) == tail ) {
        push_back( value ); //if the value is at the very end, push_back
    } else if( value < head -> data) {
        push_front(value);  //if the value is less than the head, push_front
    } else {
        IntNode* temp = new IntNode(value);
        temp -> next = find_sorted_location(value) -> next;
        find_sorted_location(value) -> next = temp;
        sz++;   //else, it puts it into the list by using a temp variable
    }           //uses temp to hold new node, and reassigns the ->next
}

void IntList::remove_duplicates() {
    IntNode* temp;
    IntNode* s;
    
    for (IntNode* i = head; i != NULL; i = i -> next) {
        s = i;      //loops through entire list
        
        while( s -> next ) {    //loops until tracker is NULL
            if( s -> next -> data == i -> data ) {
                //removes the node.
                temp = s -> next -> next;
                delete s -> next;   //temp grabs the next next one and deletes
                s -> next = temp;   //the one in the middle
                sz--;   //reduces the size
            } else {
                s = s -> next;  //goes to the next node
            }
            
        }
    }
}


bool IntList::is_sorted() const {   //loops through twice
    for (IntNode* i = head; i != NULL; i = i -> next) {
        for (IntNode* j = i; j != NULL; j = j -> next) {
            if (i -> data > j -> data) { //if the next is greater, its not in
                return false;            //correct order
            }
        }
    }
    
    return true;    //anything else, it is in order.
}


//private function to help with the insert_sorted function
IntNode* IntList::find_sorted_location( int v ) const {
    IntNode* tracker = head;    //tracker to loop through list
    
	if( !tracker ) {
		return tracker; //if the tracker is NULL, nothing to loop through
	}
	
	while( tracker ) {  //while the tracker isnt null, loop
		if( tracker -> next -> data > v ) {
			return tracker;     //finds a spot where it can fit in order
		}
		tracker = tracker -> next;  //tracker moves onto the next node
	}
    
    return tracker; //without this, reaches end of void function warning
}




