// Course: CS 10 Fall 2012
//
// First Name: Kevin
// Last Name: Do
// Course username: kdo009
// Email address: kdo009@ucr.edu
//
// Lecture Section: 002
// Lab Section: 029
// TA: Adam Koehler
//
// Assignment: assn7
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//
// =================================================================

#include <iostream>
#include "assn.h"       //for functions in other file

using namespace std;    //standard namespace


string setupUnsolvedPhrase( string phrase ) {       //function for unsolved
    
    string unsolvedPhrase;
    
    for (int i = 0; i < phrase.size() ; i++) {  //loops through the phrase
        
        if (isalpha( phrase.at(i) )) {
            unsolvedPhrase = unsolvedPhrase + "-";
        } else {        //replaces alphabet with dashes
            unsolvedPhrase = unsolvedPhrase + phrase.at(i);
        }
    }
    
    return unsolvedPhrase;  //return
}


char getNewGuess( string prevGuesses ) {    //checks if guess is valid
    
    bool isValid = false;   //is its valid, true, if not false
    char character;     //input from user
    
    while (isValid == false) {  //loop until the input is valid
        cout << "Enter a guess: ";
        cin >> character;       //takes in a input from user
        cout << endl;
        
        while (isValid == false) {
            if (prevGuesses.find( character ) == string::npos ) {
                isValid = true;     //if it cant find a letter, its valid
            } else {
                cout << "Invalid guess! Please re-enter a guess: ";
                cin >> character;
            }
        }
    }
    
    return character;       //return character
}


string updateUnsolvedPhrase( string phrase, string unsolved, char guess ) {
        //function to update the hangman answer
    for (int i=0; i < phrase.size(); i++) {
        //loops through the phrase and replaces correct guesses
        if (phrase.at(i) == guess) {
            unsolved.at(i) = guess;
        }
        
    }
    
    return unsolved;
}


int main() {        //main function
    
    string unsolvedPhrase;          //string for unsolved phrase
    string hangmanAnswer;           //the true answer
    string prevGuesses;         //all previous guesses that have been guessed
    char guess;     //variable to hold the user input
    int wrongGuessesLeft = 7;       //number of incorrect guesses left
    bool congratulations = false;   //if the player guesses all, he/she wins
    
    cout << "Enter phrase: ";
    getline( cin, hangmanAnswer );      //get the phrase from user
    clearScreen();  //clears screen
    unsolvedPhrase = setupUnsolvedPhrase( hangmanAnswer );//sets phrase to dash
    
    cout << "Phrase: " << unsolvedPhrase << endl << endl; //print phrase
    
    guess = getNewGuess( prevGuesses ); //get a new guess from user
    prevGuesses = prevGuesses + guess;  //adds guess to previous guesses
    
    unsolvedPhrase = updateUnsolvedPhrase( hangmanAnswer, unsolvedPhrase,
                                          guess );//update phrase
    
    if (hangmanAnswer.find( guess ) == string::npos) {
        wrongGuessesLeft--;                 //if wrong, take away one life
    }
    
    if (unsolvedPhrase == hangmanAnswer) {
        congratulations = true;     //if the phrase is complete, winner
    }
    
    while (wrongGuessesLeft > 0 && congratulations == false ) {
        clearScreen();      //loops the same code above 
        
        cout << "Phrase: " << unsolvedPhrase << endl << endl;
        cout << "Guessed so far: " << prevGuesses << endl;//guessed so far
        cout << "Wrong guesses left: " << wrongGuessesLeft << endl << endl;
        
        guess = getNewGuess( prevGuesses );
        prevGuesses = prevGuesses + guess;
        
        unsolvedPhrase = updateUnsolvedPhrase( hangmanAnswer, unsolvedPhrase,
                                               guess );
        
        if (hangmanAnswer.find( guess ) == string::npos) {
            wrongGuessesLeft--;
        }
        
        if (unsolvedPhrase == hangmanAnswer) {
            congratulations = true;
        }
    }
    
    clearScreen();  //clears the screen
    cout << "Phrase: " << unsolvedPhrase << endl << endl;   //prints everything
    cout << "Guessed so far: " << prevGuesses << endl;
    cout << "Wrong guesses left: " << wrongGuessesLeft << endl << endl;
    
    if (congratulations == false) {         //if the player runs out of lives
        cout << "You lost!" << endl;        //print that he/she lost
    } else {
        cout << "Congratulations!!" << endl;    //prints winner if they win
    }
    
    return 0;
}