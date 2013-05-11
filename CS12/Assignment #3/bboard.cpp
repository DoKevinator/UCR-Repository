// Course: CS 12 Winter 2013
//
// First Name: Kevin
// Last Name: Do
// Course username: kdo009
// email address: kdo009@ucr.edu
//
// Lecture Section: 001
// Lab Section: 021
// TA: Sean Allen
//
// Assignment: assn3
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//
// =================================================================


//bboard.cpp

#include "bboard.h"     //include bboard.h
#include <iostream>
    
using namespace std;    //standard namespace

//begin constructors
Bboard::Bboard()
:title("Kevin's Bulletin Board"), current_user( User() ) {
            //default constructor
}

Bboard::Bboard( const string &ttl )     //constructor for setting title
:title(ttl), current_user( User() ) {
    
}
//end constructors


void Bboard::setup() {  //setup function
    string name;    //input for username
    string pass;    //input for password
    
    while (name != "end") {     //loops til it reaches the word "end"
        
        cin >> name;        //takes in input
        
        if( name != "end" ) {  //checks if its not "end" to continue to get pass
            cin >> pass;
            add_user( name, pass);  //adds user to the vector
        }
        
    }
}


void Bboard::login() {  //login function    
    
    string name, pass;  //username and password variables
    
    cout << "Welcome to "<< title << endl;  //starting title
    
    while ( !user_exists(name,pass) ) {//loops til it gets correct input
        cout << "Enter your username ('Q' or 'q' to quit): ";
        cin >> name;    //takes input, Q or q to quit
        
        if (name == "Q" || name == "q") {   //if Q or q, quit the program
            cout << "Bye!" << endl;
            exit(0);
        } else {      //else, take in the password
            cout << "Enter your password: ";
            cin >> pass;
            
            if (!user_exists(name,pass)) {  //tells user wrong password/user
                cout << "Invalid Username or Password!" << endl << endl;
            } else {    //tells user if they logged in
                cout << "Welcome back " << name << "!" << endl << endl;
                current_user = get_user(name);
            }
        }
        
    }
    
}


void Bboard::run() {    //run function
    
    char input; //input variable
    
    do {
        
        cout << "Menu" << endl; //display the entire menu
        cout << "  " << "- Display Messages ('D' or 'd')" << endl
             << "  " << "- Add New Message ('N' or 'n')" << endl
             << "  " << "- Quit ('Q' or 'q')" << endl;
        cout << "Choose an action: ";
        cin >> input;   //takes in input
        
        cout << endl;
        
        if (input == 'D' || input == 'd') { //if D or d, display the bulletin
            display();
        } else if( input == 'N' || input == 'n' ) { //writes a new bulletin
            add_message( current_user.get_username() );
        } else if( input == 'Q' || input == 'q' ) { //quits the program
            cout << "Bye!" << endl;
            exit(0);
        } else {    //tells user that the input is invalid
            cout << "Invalid action. Please try again." << endl << endl;
        }
        
        
        
    } while( input != 'Q' || input != 'q' );    //breaks when input is Q or q
    
}


void Bboard::add_user( const string &name, const string &pass ) {
    user_list.push_back( User(name,pass) ); //adds user into user_list vector
}

bool Bboard::user_exists( const string &name, const string &pass ) const {
    
    for (unsigned i = 0; i < user_list.size(); i++) {
        if( user_list.at(i).check(name,pass) ) {
            return true;
        }       //returns true when it finds a matching 
    }
    
    return false;
}

User Bboard::get_user( const string &name ) const {
    for (unsigned i = 0; i < user_list.size(); i++) {
        if (name == user_list.at(i).get_username()) {
            return user_list.at(i); //returns a User if the username matches
        }
    }
    
    return User("","");
}


void Bboard::display() const {  //display function
    
    if (message_list.size() == 0) { //displays nothing if there is no messages
        cout << "Nothing to Display." << endl << endl;
    } else {
        for (unsigned i = 0; i < message_list.size(); i++) {
            cout << "-----------------------------------------------" << endl;
            cout << "Message #" << i+1 << ": "; //displays the format
            
            message_list.at(i).display();   //uses message display function
        }
        
        cout << "-----------------------------------------------" << endl;
    }
    
    
}


void Bboard::add_message( const string &name ) {    //adds message to vector
    string subject; 
    string body;
    
    cout << "Enter Subject: ";
    cin.ignore(1000, '\n'); //takes in subject line
    getline(cin, subject);
    
    cout << "Enter Body: "; //takes in body of the message
    getline(cin,body);
    
    cout << "Message recorded!" << endl << endl;  //signals message is recorded
    
    message_list.push_back( Message(name, subject, body) );
    //pushes the message into the message vector
    
}


