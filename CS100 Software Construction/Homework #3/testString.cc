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

#include <iostream>
#include "String.h"

using namespace std;

int main() {

	cout << endl;
	
	cout << "Constructor: " << endl;
	cout << "String s(\"Hello\")" << endl;
	String s("Hello");
	cout << s << endl;
	cout << "-----------------" << endl;

	cout << "Copy constructor: " << endl;
	cout << "String s_copy(s)" << endl;
	String s_copy(s);
	cout << s_copy << endl;
	cout << "-----------------" << endl;

	cout << "Assignment operator: " << endl;
	cout << "String assn_cpy = s" << endl;
	String assn_cpy;
	assn_cpy = s;
	cout << assn_cpy << endl;
	cout << "-----------------" << endl;

	cout << "operator[] test: " << endl;
	cout << "s[0]: " << s[0] << endl;
	cout << "s[1]: " << s[1] << endl;
	cout << "s[2]: " << s[2] << endl;
	cout << "s[3]: " << s[3] << endl;
	cout << "s[4]: " << s[4] << endl;
	cout << "-----------------" << endl;

	cout << "size() test: " << endl;
	cout << "s.size(): " << s.size() << endl;
	cout << "-----------------" << endl;

	cout << "reverse() test: " << endl;
	String rev = s.reverse();
	cout << "s.reverse(): ";
	cout << rev << endl;
	cout << "-----------------" << endl;

	cout << "indexOf(char c) test: " << endl;
	cout << "s.indexOf('H'): " << s.indexOf('H') << endl;
	cout << "s.indexOf('e'): " << s.indexOf('e') << endl;
	cout << "s.indexOf('l'): " << s.indexOf('l') << endl;
	cout << "s.indexOf('o'): " << s.indexOf('o') << endl;
	cout << "s.indexOf('z'): " << s.indexOf('z') << endl;
	cout << "-----------------" << endl;

	cout << "indexOf(String pattern) test: " << endl;
	String big( "sunglasses" );
	String small( "glasses" );
	cout << "big: sunglasses" << endl << "small: glasses" << endl;
	cout << "big.indexOf(small): " << big.indexOf(small) << endl;
	cout << "-----------------" << endl;

	cout << "operator== test: " << endl << endl;
	String same("Hello");
	String not_same("Hallo");
	cout << "same: \"Hello\" " << endl;
	cout << "not_same: \"Hallo\" " << endl;
	cout << "Does s == same? ";
	if( s == same ) cout << "true" << endl;
	else cout << "false" << endl;
	cout << "Does s == not_same? ";
	if( s == not_same ) cout << "true" << endl;
	else cout << "false" << endl;
	cout << "-----------------" << endl;

	cout << "operator!= test: " << endl << endl;
	cout << "same: \"Hello\" " << endl;
	cout << "not_same: \"Hallo\" " << endl;
	cout << "Does s != same? ";
	if( s != same ) cout << "true" << endl;
	else cout << "false" << endl;
	cout << "Does s != not_same? ";
	if( s != not_same ) cout << "true" << endl;
	else cout << "false" << endl;
	cout << "-----------------" << endl;

	cout << "operator> test: " << endl;
	String s1("apple");
	String s2("banana");
	String s3("banana");
	cout << "s1: apple" << endl << "s2: banana" << endl << "s3: banana" << endl;
	cout << "s1 > s2: ";
	if( s1 > s2 ) cout << "true" << endl;
	else cout << "false" << endl;
	cout << "s2 > s1: ";
	if( s2 > s1 ) cout << "true" << endl;
	else cout << "false" << endl;
	cout << "s2 > s3: ";
	if( s2 > s3 ) cout << "true" << endl;
	else cout << "false" << endl;
	cout << "-----------------" << endl;

	cout << "operator< test: " << endl;
	cout << "s1: apple" << endl << "s2: banana" << endl << "s3: banana" << endl;
	cout << "s1 < s2: ";
	if( s1 < s2 ) cout << "true" << endl;
	else cout << "false" << endl;
	cout << "s2 < s1: ";
	if( s2 < s1 ) cout << "true" << endl;
	else cout << "false" << endl;
	cout << "s2 < s3: ";
	if( s2 < s3 ) cout << "true" << endl;
	else cout << "false" << endl;
	cout << "-----------------" << endl;

	cout << "operator<= test: " << endl;
	cout << "s1: apple" << endl << "s2: banana" << endl << "s3: banana" << endl;
	cout << "s1 <= s2: ";
	if( s1 <= s2 ) cout << "true" << endl;
	else cout << "false" << endl;
	cout << "s2 <= s1: ";
	if( s2 <= s1 ) cout << "true" << endl;
	else cout << "false" << endl;
	cout << "s2 <= s3: ";
	if( s2 <= s3 ) cout << "true" << endl;
	else cout << "false" << endl;
	cout << "-----------------" << endl;

	cout << "operator>= test: " << endl;
	cout << "s1: apple" << endl << "s2: banana" << endl << "s3: banana" << endl;
	cout << "s1 >= s2: ";
	if( s1 >= s2 ) cout << "true" << endl;
	else cout << "false" << endl;
	cout << "s2 >= s1: ";
	if( s2 >= s1 ) cout << "true" << endl;
	else cout << "false" << endl;
	cout << "s2 >= s3: ";
	if( s2 >= s3 ) cout << "true" << endl;
	else cout << "false" << endl;
	cout << "-----------------" << endl;

	cout << "operator+ test" << endl;
	String first("cs");
	String second("100");
	cout << "first: \"cs\" " << endl << "second: \"100\" " << endl;
	cout << "first + second: ";
	String tmp = first + second;
	cout << tmp << endl;
	cout << "-----------------" << endl;

	cout << "operator+= test" << endl;
	cout << "first: \"cs\" " << endl << "second: \"100\" " << endl;
	cout << "first += second: ";
	first += second;
	cout << first << endl;
	cout << "-----------------" << endl;

	cout << "operator>> test: " << endl;
	String in;
	cin >> in;
	cout << in << endl;
	cout << "-----------------" << endl;


	return 0;
}




