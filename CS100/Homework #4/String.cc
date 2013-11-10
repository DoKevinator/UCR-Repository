/*
* Course: CS 100 Fall 2013 *
* First Name: Kevin
* Last Name: Do
* Username: kdo009
* email address: kdo009@well.cs.ucr.edu
*
* Assignment: Homework #4
* I hereby certify that the contents of this file represent
* my own original individual work. Nowhere herein is there
* code from any outside resources such as another individual,
* a website, or publishings unless specifically designated as
* permissible by the instructor or TA. */

//LinkedString.cc

#include <iostream>
#include "String.h"

using namespace std;

//Assignment1 runtime: O(n), o(2n)
//Assignment2 runtime: O(n), o(2n)
//Assignment1 funtion calls: 0
//assignment2 function calls: n
String::String( const char * s ) {
	head = NULL;

	int i;
	for( i = 0; s[i] != '\0'; i++ ) { }

	for( ; i >= 0; i-- ) {
		ListNode* newnode = new ListNode(s[i], head);
		head = newnode;
	}
}

//Assignment1 runtime: O(n), o(n)
//Assignment2 runtime: O(n), o(n)
//assignment1 function calls: 0
//assignment2 function calls: n
String::String( const String & s ) {
	if( s.head == NULL ) {
		head = NULL;
		return;
	}

	head = new ListNode( s.head->info, NULL );
	ListNode* iterator = head;
 	
 	for(ListNode* i = s.head->next; i != NULL; i = i -> next) {
 		iterator -> next = new ListNode( i->info, NULL );
 		iterator = iterator -> next;
 	}
}

//assignment1 runtime: O(n), o(n)
//assignment2 runtime: O(n), o(2n)
//assignment1 function calls: 0
//assignment2 function calls: n
String String::operator=( const String & s ) {
	//delete everything in current String
	for( ListNode* i = head; i != NULL; i = i->next ) {
		ListNode* tmp = head->next;
		delete head;
		head = tmp;
	}

	if( s.head == NULL ) {
		head = NULL;
		return *this;
	}

	head = new ListNode( s.head->info, NULL );
	ListNode* iterator = head;
 	
 	for(ListNode* i = s.head->next; i != NULL; i = i -> next) {
 		iterator -> next = new ListNode( i->info, NULL );
 		iterator = iterator -> next;
 	}

 	return *this;
}

//assignment1 runtime: O(1), o(1)
//assignment2 runtime: O(n), o(2n)
//assignment1 function calls: 1
//assignment2 function calls: 1
char& String::operator[]( const int index ) {
	if( !inBounds(index) ) {
		cerr << "Error: out of bounds" << endl;
		exit(1);
	}

	ListNode* iterator = head;

	for( int i = 0; i < index; i++ ) {
		iterator = iterator -> next;
	}

	return iterator -> info;
}

//assignment1 runtime: O(1), o(1)
//assignment2 runtime: O(n), o(n)
//assignment1 function calls: 0
//assignment2 function calls: 0
int String::length() const {
	int i = 0;
	for( ListNode* tmp = head; tmp -> next != NULL; tmp = tmp -> next ) {
		i++;
	}

	return i;
}

//assignment1 runtime: O(n), o(n)
//assignment2 runtime: O(n), o(n)
//assignment1 function calls: 0
//assignment2 function calls: 0
int String::indexOf( char c ) const {
	int i = 0;

	for( ListNode* tmp = head; tmp != NULL; tmp = tmp -> next ) {
		if( tmp -> info == c ) {
			return i;
		}

		i++;
	}

	return -1;
}

//assignment1 runtime: O(n), o(n)
//assignment2 runtime: O(n), o(3n)
//assignment1 function calls: 0
//assignment2 function calls: 2
bool String::operator==( const String & s ) const {
	if( this -> length() != s.length() ) {
		return false;
	}

	ListNode* iter = head;

	for( ListNode* tmp = s.head; tmp != NULL; tmp = tmp -> next ) {
		if( tmp -> info != iter -> info ) {
			return false;
		}
		iter = iter -> next;
	}

	return true;
}

//assignment1 runtime: O(n), o(n)
//assignment2 runtime: O(n), o(2n)
//assignment1 function calls: 1
//assignment2 function calls: n
String String::operator+( const String & s ) const {
	String total(*this);

	ListNode* i = total.head;
	for( ; i -> next != NULL; i = i->next ) { }

	for( ListNode* tmp = s.head; tmp != NULL; tmp = tmp -> next ) {
		i -> next = new ListNode( tmp -> info, NULL );
		i = i -> next;
	}

	return total;
}

//assignment1 runtime: O(n), o(n)
//assignment2 runtime: O(n), o(2n)
//assignment1 function calls: 0
//assignment2 function calls: n
String String::operator += ( const String & s ) {
	ListNode* i = head;
	for( ; i -> next != NULL; i = i->next ) { }

	for( ListNode* tmp = s.head; tmp != NULL; tmp = tmp -> next ) {
		i -> next = new ListNode( tmp -> info, NULL );
		i = i -> next;
	}

	return *this;
} 

//assignment1 runtime: O(1), o(1)
//assignment2 runtime: O(n), o(n)
//assignment1 function calls: 0
//assignment2 function calls: 0
void String::print( ostream & out ) {
	for( ListNode* i = head; i != NULL; i = i->next ) {
		out << i -> info;
	}
}

//assignment1 runtime: O(n), o(2n)
//assignment2 runtime O(n), o(2n)
//assignment1 function calls: 1
//assignment2 function calls: 1
void String::read( istream & in ) {
	char tmp[999];
	in >> tmp;
	*this = String(tmp);
}

//assignment1 runtime: O(n), o(n)
//assignment2 runtime: O(n), o(n)
//assignment1 function calls: 0
//assignment2 function calls: 0
String::~String() {
	for( ListNode* i = head; i != NULL; i = i->next ) {
		ListNode* tmp = head->next;
		delete head;
		head = tmp;
	}
}

//assignment1 runtime: O(1), o(1)
//assignment2 runtime: O(n), o(n)
//assignment1 function calls: 1
//assignment2 function calls: 1
ostream& operator<<( ostream & out, String str ) {
	str.print(out);
	return out;
}

//assignment1 runtime: O(n), o(2n)
//assignment2 runtime: O(n), o(2n)
//assignment1 function calls: 1
//assignment2 function calls: 1
istream& operator>>( istream & in, String& str ) {
	str.read(in);
	return in;
}













