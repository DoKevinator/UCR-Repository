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

#ifndef __LINKED_STRING_H_
#define __LINKED_STRING_H_

#include <iostream>

using namespace std;

class String {

public:
/// Both constructors should construct 
/// from the parameter s
	String( const char * s = "");
	String( const String & s );
	String operator = ( const String & s );
	char & operator [] ( const int index );
	int length() const;
	int indexOf( char c ) const;
	bool operator == ( const String & s ) const; /// concatenates this and s
	String operator + ( const String & s ) const; /// concatenates s onto end of this
	String operator += ( const String & s ); 
	void print( ostream & out );
	void read( istream & in );
	~String();

private:
	bool inBounds( int i ) {
		return i >= 0 && i < length();
	}

	struct ListNode {
		char info;
		ListNode * next;

		ListNode(char newInfo, ListNode * newNext)
		: info( newInfo ), next( newNext ) { }

		// you may add static methods here 
	};
	ListNode * head; 
};

ostream & operator << ( ostream & out, String str ); 
istream & operator >> ( istream & in, String & str );

#endif










