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

//myfork.cc

#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

using namespace std;

const int LOOPTIMES = 10000;

void print(char x) {
	for( int i = 0; i < LOOPTIMES; i++ ) {
			cout << x << flush;
	}
}

int main() {

	int parent_pid = getpid();
	int pid1, pid2, pid3;

	if( getpid() == parent_pid ) {
		pid1 = fork();
	}

	if( getpid() == parent_pid ) {
		pid2 = fork();
	} 

	if( getpid() == parent_pid ) {
		pid3 = fork();
	}
	
	if( getpid() == parent_pid ) {
		cout << "parent pid: " << parent_pid << endl;
		cout << "child pid: " << pid1 << endl;
		cout << "child pid: " << pid2 << endl;
		cout << "child pid: " << pid3 << endl;
	}

	//sleep(1);

	if( pid1 == 0 ) {
		print('B');
		return 0;
	}

	if( pid2 == 0 ) {
		print('C');
		return 0;
	}

	if( pid3 == 0 ) {
		print('D');
		return 0;
	}

	print('A');

	int tmp;
	while( wait(&tmp) > 0 );

	return 0;
}




