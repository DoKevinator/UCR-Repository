// Course: CS 10 Fall 2012
//
// First Name:Kevin
// Last Name:Do
// Course username: kdo009
// Email address: kdo009@ucr.edu
//
// Lecture Section: 001
// Lab Section: 029
// TA: Adam Koehler
//
// Assignment: assn2
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
// KEVIN DO
// =================================================================

#include <iostream>     

using namespace std;       //standard for input and output of console

int main() {        //main function with return type int
    
    string male, female;       //two main characters of the story
    
    string adj1, adj2, adj3;    //adjecives to describe the day and how male
                                //was feeling
    
    string noun1, noun2, noun3;     //nouns to describe setting
    
    string verb1, verb2;        //verbs to describe kids at park
    
    string greeting1;       // greeting from the old man to male
    
    cout << "Male name: ";      
    cin >> male;
    
    cout << "Female name: ";
    cin >> female;
    
    cout << "Adjective #1: ";
    cin >> adj1;
    
    cout << "Adjective #2: ";         //asks the user for all 10 inputs
    cin >> adj2;
    
    cout << "Adjective #3: ";
    cin >> adj3;
    
    cout << "Noun #1: ";
    cin >> noun1;
    
    cout << "Noun #2: ";
    cin >> noun2;
    
    cout << "Noun #3: ";
    cin >> noun3;
    
    cout << "Verb #1: ";
    cin >> verb1;
    
    cout << "Verb #2: ";
    cin >> verb2;
    
    cout << "Greeting word: ";
    cin >> greeting1;
    
    cout << endl;       //new line for nicer format
    
    cout << "One day, " << male << " went to the park "
         << "to have tea and a sandwich. It was a \n" << adj1 << " day. "
         << male << " was feeing kind of " << adj2 << ". "
         << "Across the park was \n" << female << " who was playing with a "
         << noun1 << "." << endl << endl; //two endl's for space btween paragaphs
                            //paragraph #1
    
    cout << "An old person walked up to " << male << " and told him "
         << greeting1 << ". The old man then \nproceeded to "
         << verb1 << " at the kids in the park. The kids reacted "
         << verb2 << " \nand ran towards the nearest " << noun2 << "." << endl
         << endl;           //paragraph #2
    
    cout << "After a few hours, " << male << " decided to do to " << female
         << ". " << male << " really \nlikes " << female << " so " << male
         << " decided to give " << female << " some " << noun3 << ". "
         << "In \nthe end, they lived " << adj3 << " ever after." << endl
         << endl;       //paragraph #3
    
    return 0;   //returns 0 to terminate program
}
