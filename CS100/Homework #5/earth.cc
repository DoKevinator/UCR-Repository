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


//earth.cc

#include "planet.cc"
#include <iostream>

const double pi = 3.14159;

class Earth : public Planet {

private:
	long long population;

public:
	Earth()
	:radius(3959.0), orbit(365.0), population(7000000000) { }
	
	virtual double get_orbit() const {
		return orbit;
	}

	virtual double get_radius() const {
		return radius;
	}

	virtual bool has_inhabitance() const {
		return true;
	}

	virtual double get_surface_area() const {
		std::cout << "Earth's surface area is: " << std::flush;
		return 4 * pi * radius * radius;
	}

	void supply_oxygen() {
		std::cout << "Earth's inhabitants are happy to live with oxygen!" 
		 		  << std::endl;
	}

	void water() {
		std::cout << "Earth's surface is make of 70% water." << std::endl;
	}

	~Earth();


};


