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

#include "stack.h"
#include <iostream>

using namespace std;

//main() is where the central looping of the program takes place. 
//it keeps looping until the user presses ^D to exit the program.
int main() {

	Stack s;
	string input;

	cout << "Enter a word: ";

	while( cin >> input ) {

		for(string::iterator i = input.begin(); i != input.end(); i++) {
			s.push( *i );
		}

		while( s.isEmpty() ) {
			cout << s.pop();
		}

		cout << endl;
		cout << "Enter a word: ";
	}

	return 0;
}
