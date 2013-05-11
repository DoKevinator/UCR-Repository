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
// Assignment: assn6
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//
// =================================================================


//bboard.cpp

#include "bboard.h"     //include bboard.h
#include <iostream>
#include <fstream>
#include <sstream>
    
using namespace std;    //standard namespace

//begin constructors
Bboard::Bboard()
:title("Kevin's Bulletin Board"), current_user( NULL ) {
            //default constructor
}

Bboard::Bboard( const string &ttl )     //constructor for setting title
:title(ttl), current_user( NULL ) {
    
}

Bboard::~Bboard() {
    for (unsigned i = 0; i < message_list.size(); i++) {
        delete message_list.at(i);
    }
    
}
//end constructors


bool Bboard::load_users(const string& userfile) {  //setup function
    string name;    //input for username
    string pass;    //input for password
    
    ifstream input;
    input.open( userfile.c_str() );
    
    if( input.fail() ) {
        input.close();
        return false;
    }
    
    while (name != "end") {     //loops til it reaches the word "end"
        
        input >> name;        //takes in input
        
        if( name != "end" ) {  //checks if its not "end" to continue to get pass
            input >> pass;
            add_user( name, pass);  //adds user to the vector
        }
        
    }
    
    input.close();
    return true;
}


void Bboard::login() {  //login function    
    
    string name, pass;  //username and password variables
    
    cout << "Welcome to " << title << endl;  //starting title
    
    while ( get_user(name,pass) == NULL ) {//loops til it gets correct input
        cout << "Enter your username ('Q' or 'q' to quit): ";
        cin >> name;    //takes input, Q or q to quit
        
        if (name == "Q" || name == "q") {   //if Q or q, quit the program
            cout << "Bye!" << endl;
            exit(0);
        } else {      //else, take in the password
            cout << "Enter your password: ";
            cin >> pass;
            
            if (get_user(name,pass) == NULL) {  //tells user wrong password/user
                cout << "Invalid Username or Password!" << endl << endl;
            } else {    //tells user if they logged in
                cout << "Welcome back " << name << "!" << endl << endl;
                current_user = get_user(name,pass);
            }
        }
        
    }
    
}


void Bboard::run() {    //run function
    
    char input; //input variable
    
    if (current_user == NULL) {
        exit(1);
    }
    
    do {
        
        cout << "Menu" << endl; //display the entire menu
        cout << "  " << "- Display Messages ('D' or 'd')" << endl
             << "  " << "- Add New Topic ('N' or 'n')" << endl
             << "  " << "- Add Reply ('R' or 'r')" << endl
             << "  " << "- Quit ('Q' or 'q')" << endl;
        cout << "Choose an action: ";
        cin >> input;   //takes in input
        
        cout << endl;
        
        if (input == 'D' || input == 'd') { //if D or d, display the bulletin
            display();
        } else if( input == 'N' || input == 'n' ) { //writes a new bulletin
            add_topic();
        } else if( input == 'R' || input == 'r' ) {
            add_reply();
        } else if( input == 'Q' || input == 'q' ) { //quits the program
            cout << "Bye!" << endl;
            return;
        } else {    //tells user that the input is invalid
            cout << "Invalid action. Please try again." << endl << endl;
        }
        
        
        
    } while( input != 'Q' || input != 'q' );    //breaks when input is Q or q
    
}


bool Bboard::load_messages(const string& datafile) {
    string athr, sbjct, bdy, children, topic_or_reply, input;
    unsigned id, numOfMessages; //initialie variables
    
    ifstream ipfile;
    ipfile.open( datafile.c_str() );    //open datafile
    
    if (ipfile.fail()) {
        return false;   //checks if its opened or not
    }
    
    ipfile >> numOfMessages;    //reads in number of messages and makes vector
    vector< vector<int> > temp_children(numOfMessages);
    
    while (numOfMessages != 0) {    //loops until all messages are read in
        ipfile >> topic_or_reply;   //takes in <begin_????> thing
        
        input = ""; //re-sets all the variables for a new input
        id = 0;
        sbjct = "";
        athr = "";
        bdy = "";
        children = "";
        
        while (input != "<end>") {  //loops til it gets to end of message
            
            ipfile >> input;    //takes in a header (:???:)
            
            if (input == ":id:") {  //takes in id
                ipfile >> id;
            } else if (input == ":subject:") {  //takes in subject
                getline( ipfile, sbjct );
                sbjct = sbjct.substr(1);
            } else if (input == ":from:") { //takes in author
                ipfile >> athr;
            } else if (input == ":children:") { //takes in children (replies)
                getline( ipfile, children);
                children = children.substr(1);  //gets a string of children
                
                int temp;
                
                stringstream iss( children );   //separates them and pushes to
                while (iss >> temp) {           //temporary vector
                    temp_children.at(id-1).push_back(temp);
                }
                
            } else if (input == ":body:") { //takes in body
                while (input != "<end>") {  //loops til it reaches <end>
                    
                    getline( ipfile, input );   //gets 1 line at a time
                    
                    if (input == "<end>") {
                        break;  //if it reaches <end>, its done
                    }
                    
                    bdy = bdy + input + '\n';   //concatenates to bdy
                }
                
                bdy = bdy.substr(1);    //gets rid of whitespace and stuff
                bdy = bdy.substr(0, bdy.size()-1);
            }
            
        }
            //pushes it into message_list vector according to class
        if (topic_or_reply == "<begin_topic>") {
            message_list.push_back( new Topic(athr, sbjct, bdy, id) );
        } else if( topic_or_reply == "<begin_reply>" ) {
            message_list.push_back( new Reply(athr, sbjct, bdy, id) );
        }
        
        numOfMessages--;//decrements number of messages til 0
    }
    
    ipfile.close();//close the input file
    
    for (unsigned i = 0; i < message_list.size(); i++) {
        for (unsigned j = 0; j < temp_children.at(i).size(); j++) {
            message_list.at(i) ->   //assigns all the pointers to chidren
            add_child( message_list.at( temp_children.at(i).at(j) - 1 ) );
        }
    }
    
    return true;    //returns true when all actions are done
}


bool Bboard::save_messages(const string& datafile) {//saves messages
    ofstream opfile;    //opens datafile
    opfile.open( datafile.c_str() );
    
    if (opfile.fail()) {    //checks if the file is opened
        return false;
    }
    
    opfile << message_list.size() << endl;  //outputs number of messages
    
    for (unsigned i = 0; i < message_list.size(); i++) {
        opfile << message_list.at(i) -> to_formatted_string();
    }   //outputs the to_formatted_string
    
    opfile.close(); //close te output file
    return true;    //return true after function is executed
}


void Bboard::add_topic() {  //adds a topic to messagelist
    string author = current_user -> get_username();
    string subject; //initialize variables
    string body, temp = " ";
    int id = message_list.size() + 1;   //id is 1 after the size
    
    cin.ignore(1000, '\n'); //cin.ignore
    
    cout << "Enter Subject: ";  //gets the subject
    getline( cin, subject );
    
    cout << "Enter Body: "; //gets the body
    
    while( temp != "" ) {
        getline( cin, temp );
                //takes in body line by line until the line is blank
        if( temp == "" ) {
            break;
        }
        
        body = body + temp + '\n';  //concatenates to body
    }
    
    body = body.substr(0, body.size()-1);   //gets rid of whitespace
    
    Topic* temp_topic = new Topic( author, subject, body, id );
    message_list.push_back( temp_topic );   //pushes back to message list
}
    

void Bboard::add_reply() {  //adds a reply
    string author = current_user -> get_username();
    string subject; //initialize variables
    string body, temp = " ";
    int message_id;
    int id = message_list.size() + 1;   //id is 1 after size
    
    while( true ) {
        cout << "Enter Message ID (-1 for Menu): ";
        cin >> message_id;  //gets the message ID to reply to
        
        if (message_id == -1) { //if its -1, break out of function
            return;
        } else if( message_id == 0 || message_id > //checks the bounds
                   static_cast<int>(message_list.size()) ) {
            cout << "Invalid Message ID!!" << endl << endl;
        } else {
            break;  //else, continue with function
        }
    }
    
    subject = "Re: " + message_list.at( message_id - 1 ) -> get_subject();
        //gets subject
    cout << "Enter Body: ";
    
    cin.ignore(1000, '\n'); 
    
    while( temp != "" ) {
        getline( cin, temp );   //takes in body 1 line at a time until empty
        
        if( temp == "" ) {  //breaks out of loop when empty meaning done
            break;
        }
        
        body = body + temp + '\n';  //concatenates to body
    }
    
    body = body.substr(0, body.size()-1);   //gets rid of whitespace
    
    Reply* reply_temp = new Reply(author, subject, body, id);
    message_list.push_back( reply_temp );   //pushed back to message list
        //adds the pointer to the child
    message_list.at(message_id - 1) -> add_child( reply_temp );
}
   
   
void Bboard::add_user( const string &name, const string &pass ) {
    user_list.push_back( User(name,pass) ); //adds user into user_list vector
}


const User* Bboard::get_user(const string& name, const string& pw) const {
    for (unsigned i = 0; i < user_list.size(); i++) {
        if ( user_list.at(i).check(name, pw) ) {
            return &user_list.at(i); //returns a User if the username matches
        }
    }
    
    return NULL;
}


void Bboard::display() const {  //display function
    
    if (message_list.size() == 0) { //displays nothing if there is no messages
        cout << "Nothing to Display." << endl << endl;
    } else {
        for (unsigned i = 0; i < message_list.size(); i++) {
            
            if ( !(message_list.at(i) -> is_reply()) ) {
                cout << "-----------------------------------------------"
                     << endl;
                message_list.at(i) -> print(); //uses message display function
            }
            
        }
        
        cout << "-----------------------------------------------" << endl;
    }
    
}




