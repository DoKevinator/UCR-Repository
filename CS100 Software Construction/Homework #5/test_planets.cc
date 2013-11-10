/*
* Course: CS 100 Fall 2013 *
* First Name: Kevin
* Last Name: Do
* Username: kdo009
* email address: kdo009@well.cs.ucr.edu
*
* Assignment: Homework #5
* I hereby certify that the contents of this file represent
* my own original individual work. Nowhere herein is there
* code from any outside resources such as another individual,
* a website, or publishings unless specifically designated as
* permissible by the instructor or TA. */

//test_planets.cc

#include <iostream>
#include "planet.cc"
#include "earth.cc"
#include "mars.cc"
#include "neptune.cc"

using namespace std;

int main() {

	Earth e;
	Mars m;
	Neptune n;

	Planet arr[3] = { e, m, n };

	for( int i = 0; i < 3; i++ ) {
		cout << arr[i].get_surface_area() << endl;
	}

	return 0;
}



