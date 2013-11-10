/*
* Course: CS 100 Fall 2013 *
* First Name: Kevin
* Last Name: Do
* Username: kdo009
* email address: kdo009@ucr.edu
*
* Assignment: Homework #3
* I hereby certify that the contents of this file represent
* my own original individual work. Nowhere herein is there
* code from any outside resources such as another individual,
* a website, or publishings unless specifically designated as
* permissible by the instructor or TA. */

//String.cc

#include <iostream>
#include "String.h"

using namespace std;

String::String( const char * s ) {
	int i;
	for( i = 0; s[i] != '\0'; i++ ) { }
	buf = new char[i+1];
	len = i;
	
	for( int j = 0; j < len; j++ ) {
		buf[j] = s[j];
	}

	buf[i] = '\0';

}

String::String( const String & s ) {
	len = s.len;

	buf = new char[len+1];

	for( int i = 0; i < s.len; i++ ) {
		buf[i] = s.buf[i];
	}

	buf[len] = '\0';
}


String String::operator=( const String & s ) {
	delete[] buf;
	buf = NULL;

	len = s.len;

	buf = new char[len+1];

	for( int i = 0; i < s.len; i++ ) {
		buf[i] = s.buf[i];
	}

	buf[len] = '\0';

	return *this;
}

char& String::operator[]( int index ) {
	if( !inBounds(index) ) {
		cerr << "Error: exceeded string length." << endl;
		exit(1);
	}

	return buf[index];
}

int String::size() {
	return len;
}

// does not modify this String
String String::reverse() {
	String rev( *this );

	for( int i = 0; i < rev.len / 2; i++ ) {
		swap( rev.buf[i], rev.buf[rev.len - i - 1] );
	}

	return rev;
}  

int String::indexOf( char c ) {
	for( int i = 0; i < len; i++ ) {
		if( c == buf[i] ) {
			return i;
		}
	}

	return -1;
}

int String::indexOf( String pattern ) {
	for( int i = 0; i < len; i++ ) {
		if( pattern.buf[0] == buf[i] && len-i >= pattern.len ) {
			for( int j = 0; j < pattern.len; j++ ) {
				if( pattern.buf[j] != buf[i+j] ) {
					break;
				} else if( j == pattern.len-1 ) {
					return i;
				}
			}
		}
	}

	return -1;
}

bool String::operator==( String s ) {
	if( len != s.len ) {
		return false;
	}

	for( int i = 0; i < len; i++ ) {
		if( buf[i] != s.buf[i] ) {
			return false;
		}
	}

	return true;
}

bool String::operator!=( String s ) {
	return !operator==(s);	
}

bool String::operator>( String s ) {
	int min;

	if( len < s.len ) min = len;
	else  min = s.len;
	
	for( int i = 0; i < min; i++ ) {
		if( buf[i] == s.buf[i] ) {
			continue;
		} else if( buf[i] > s.buf[i] ) {
			return true;
		} else {
			return false;
		}
	}

	return false;
}

bool String::operator < ( String s ) {
	int min;

	if( len < s.len ) min = len;
	else  min = s.len;
	
	for( int i = 0; i < min; i++ ) {
		if( buf[i] == s.buf[i] ) {
			continue;
		} else if( buf[i] < s.buf[i] ) {
			return true;
		} else {
			return false;
		}
	}

	return false;
}

bool String::operator <= ( String s ) {
	int min;

	if( len < s.len ) min = len;
	else  min = s.len;
	
	for( int i = 0; i < min; i++ ) {
		if( buf[i] == s.buf[i] ) {
			continue;
		} else if( buf[i] < s.buf[i] ) {
			return true;
		} else {
			return false;
		}
	}

	return true;
}

bool String::operator >= ( String s ) {
	int min;

	if( len < s.len ) min = len;
	else  min = s.len;
	
	for( int i = 0; i < min; i++ ) {
		if( buf[i] == s.buf[i] ) {
			continue;
		} else if( buf[i] > s.buf[i] ) {
			return true;
		} else {
			return false;
		}
	}

	return true;
}

/// concatenates this and s to return result 
String String::operator+( String s ) {
	String tmp(*this);

	for( int i = 0; i < s.len; i++ ) {
		tmp.buf[ tmp.len + i] = s.buf[i];
	}

	tmp.len += s.len;

	return tmp;
}


/// concatenates s onto end of this
String String::operator+=( String s ) {

	for( int i = 0; i < s.len; i++ ) {
		buf[ len + i] = s.buf[i];
	}

	len += s.len;

	return *this;
}

void String::print( ostream & out ) {
	out << buf;
}

void String::read( istream & in ) {
	char tmp[999];
	in >> tmp;
	*this = String(tmp);
}

String::~String() {
	delete[] buf;
}

ostream& operator<<( ostream & out, String str ) {
	str.print(out);
	return out;
}

istream& operator>>( istream & in, String & str ) {
	str.read(in);
	return in;
}





