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

#include <iostream>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

using namespace std;

int interrupt_times = 0;
int quit_times = 0;
int stop_times = 0;

void print( int sig ) {

	switch (sig) {
        case SIGINT:
            cout << "I" << flush;   //print interrupt job and increment
            interrupt_times++;
            break;
        case SIGQUIT:
            cout << "Q" << flush;   //print quit job and increment
            quit_times++;
            break;
        case SIGTSTP:
            cout << "S" << flush; 
            if( stop_times + 1 == 3 ) {     //exits on the third STOP
            	cout << endl << "Interrupt: " << interrupt_times << endl;
            	cout << "Stop: " << stop_times << endl;
            	cout << "Quit: " << quit_times << endl;
            	exit(0);
           	}
            stop_times++;
            raise(SIGSTOP);
            break;
        default:
            break;
    }
}

int main() {

	struct sigaction act;
	act.sa_handler = print;
	sigemptyset( &act.sa_mask );
	act.sa_flags = 0;
	sigaction( SIGINT, &act, 0 );      //signal for interrupt (^C)
	sigaction( SIGQUIT, &act, 0 );     //signal for quit (^\)
	sigaction( SIGTSTP, &act, 0 );     //signal for stop (^Z)

	// Turn off output buffering here if you like init_signal_handlers();
	while (true) {
		cout << "X" << flush;
		sleep(1);
	}
	// Print an 'X' and flush the output buffer here
}



