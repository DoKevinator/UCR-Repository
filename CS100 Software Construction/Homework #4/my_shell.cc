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

#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <iostream>

using namespace std;

void parse_arguments(char* buf, char* arguments[]) {
	//replaces all whitespace with null char
	int i;
	for( i = 0; buf[i] != '\0'; i++ ) {
		if( buf[i] == ' ' || buf[i] == '\t' || buf[i] == '\n' ) {
			buf[i] = '\0';
		}
	}

	//parses arguments into buf
	int arg_iterator = 0;
	arguments[arg_iterator] = buf;
	buf++;
	arg_iterator++;

	for( int j = 1; j < i; j++ ) {
		if( *buf == '\0' ) {
			arguments[arg_iterator] = buf+1;
			arg_iterator++;
		}
		buf++;
	}

	arguments[arg_iterator] = 0;
}

//invokes the command passed by user
void invoke_command( char* arguments[] ) {
	int PID;
	PID = fork();

	switch( PID ) {
		case -1: 	//case where creating process failed
			cerr << "Error creating process. Fork failed." << endl;
			exit(0);
			break;

		case 0:
			//make new process and overwrite to do command
			if( execvp(arguments[0], arguments) == -1 ) {
				cerr << "execvp failed" << endl;
				exit(1);
			}
			break;

		default:
			int tmp;	//parent waits to child to finish before exit
			while( wait(&tmp) > 0 );
			break;
	}
}

int main(int argc, char* argv[]) {
	string input;
	char buf[BUFSIZ];
	char* arguments[100];

	while(true) {
		cout << "> " << flush;
		cin.getline( buf, BUFSIZ );
		parse_arguments(buf, arguments);
		invoke_command( arguments );
	}

	return 0;
}



