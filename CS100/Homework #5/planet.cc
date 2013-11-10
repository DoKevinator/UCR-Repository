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

//planet.cc

#ifndef _PLANET_H_
#define _PLANET_H_

class Planet {

protected:
	double radius;
	double orbit;

public:
	Planet(double r, double o)
	:radius(r), orbit(o) { }

	virtual double get_orbit() = 0;
	virtual double get_radius();
	virtual bool has_inhabitance();
	virtual double get_surface_area();

	~Planet();

};


#endif

