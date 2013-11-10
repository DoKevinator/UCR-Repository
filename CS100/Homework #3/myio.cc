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

//myio.cc

#include <iostream>
#include <fstream>
#include <sys/file.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "Timer.h"
#include <sstream>

using namespace std;

void function1( const string& input, const string& output ) {
	ifstream in( input.c_str() );
	ofstream out( output.c_str() );

	if( in.fail() || out.fail() ) {
		cerr << "Error opening file." << endl;
		exit(1);
	}

	while( in.good() ) {
		char tmp = in.get();
		if( in.good() ) {
			out.put(tmp);
		}
	}

	in.close();
	out.close();
}

void function2( const string& input, const string& output ) {

	int fd1 = open( input.c_str(), O_RDONLY );
	int fd2 = open( output.c_str(), O_WRONLY | O_CREAT | O_TRUNC, 0666 );

	char buf[1];

	while( read(fd1, buf, 1) != 0 ) {
		write( fd2, buf, 1 );
	}
	
	close(fd1);
	close(fd2);

}


void function3( const string& input, const string& output ) {

	int fd1 = open( input.c_str(), O_RDONLY );
	int fd2 = open( output.c_str(), O_WRONLY | O_CREAT | O_TRUNC, 0666 );

	char buf[BUFSIZ];
	int size_read;

	while( (size_read = read(fd1, buf, BUFSIZ)) > 0 ) {
		write(fd2, buf, size_read);
	}
	
	close(fd1);
	close(fd2);

}



int main(int argc, char* argv[]) {

	if( argc != 4 ) {
		cerr << "Usage: \"./myio <input> <output> <iterations>\" " << endl;
		exit(1);
	}

	string input = argv[1];
	string output = argv[2];
	int iterations;

	stringstream s;
	s << argv[3];
	s >> iterations;

	cout << endl;



	Timer t;
	double eTime;
	t.start();
	for( int i = 0; i < iterations; i++ ) {
		function1( input, output );
	}
	t.elapsedUserTime(eTime);
	cout << "user time for fstream: " << eTime << endl;
	t.elapsedWallclockTime(eTime);
	cout << "wall clock time for fstream: " << eTime << endl;
	t.elapsedSystemTime(eTime);
	cout << "system time for fstream: " << eTime << endl << endl;


	Timer t2;
	double eTime2;
	t.start();
	for( int i = 0; i < iterations; i++ ) {
		function2( input, output );
	}
	t2.elapsedUserTime(eTime2);
	cout << "user time for fstream: " << eTime2 << endl;
	t2.elapsedWallclockTime(eTime2);
	cout << "wall clock time for fstream: " << eTime2 << endl;
	t2.elapsedSystemTime(eTime2);
	cout << "system time for fstream: " << eTime2 << endl << endl;


	Timer t3;
	double eTime3;
	t3.start();
	for( int i = 0; i < iterations; i++ ) {
		function3( input, output );
	}
	t3.elapsedUserTime(eTime3);
	cout << "user time for fstream: " << eTime3 << endl;
	t3.elapsedWallclockTime(eTime3);
	cout << "wall clock time for fstream: " << eTime3 << endl;
	t3.elapsedSystemTime(eTime3);
	cout << "system time for fstream: " << eTime3 << endl << endl;

	return 0;
}





