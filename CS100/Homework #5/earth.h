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


//earth.h

#ifndef _EARTH_H_
#define _EARTH_H_

#include "planet.h"

class Earth : Planet {

private:

public:
	Earth();
	int get_orbit();
	int get_radius();

	~Earth();


};

#endif

