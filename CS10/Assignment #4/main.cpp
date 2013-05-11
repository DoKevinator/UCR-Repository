// Course: CS 10 Fall 2012
//
// First Name: Kevin
// Last Name:Do
// Course username: kdo009
// Email address: kdo009@ucr.edu
//
// Lecture Section: 002
// Lab Section: 029
// TA: Adam Koehler
//
// Assignment: assn4
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
// KEVIN DO
// =================================================================

#include <iostream>
#include <iomanip>  //for the ability to calculate the readability value
#include "assn.h"   //imports the ability to use is_vowel() function

using namespace std;

int main() {    //main method
    
    int wordCount = 0, sentenceCount = 0, syllableCount = 0;
          //counts the amount of words, sentences, and syllables and stores here
    string textInput;
            //obtains input from user and stores it in here
    double index;   //index is stored in here
    bool no_vowels = true;  //used for determining if word has no vowels
    
    while (cin >> textInput) {  //while to capture each separate word every time
        wordCount++;    //for every word it captures, increase wordCount by 1
        
        no_vowels = true;   //resets the no_vowels to assume no vowels exist
        
        if (textInput.at(textInput.size() - 1) == '.' || //checks last char
            textInput.at(textInput.size() - 1) == ':' || //and if it is
            textInput.at(textInput.size() - 1) == ';' || //period or whatever
            textInput.at(textInput.size() - 1) == '?' || //it will count as
            textInput.at(textInput.size() - 1) == '!') { //a sentence
            
            sentenceCount++;    //increases sentence count by 1 each time
        }
        
        int i = 0;      //counter for while loop to sort through characters
        
        while (i <= textInput.size() - 1) { //sorts through the chars
            
            if (is_vowel(textInput.at(i))) {    //if vowel, add one
                syllableCount++;
                
                no_vowels = false;  //means there are vowels    
                
                if( i != textInput.size() - 1) {    //goes up to last char
                    
                    if (is_vowel(textInput.at(i+1))) { //subtracts if two vowels
                        syllableCount--;
                    }
                }
            }
            
            i++;    //increments i to go through the word.
        }
        
        if( no_vowels ) {       //if no vowels, adds one to syllableCount
            syllableCount++;    
        }
    }
    
    index = 206.835 - 84.6 * syllableCount / wordCount - 1.105 *
            wordCount / sentenceCount;      //calculates the index
    
    cout << "Words: " << wordCount << endl;         //outputs the results to
    cout << "Syllables: " << syllableCount << endl; //the screen. 
    cout << "Sentences: " << sentenceCount << endl;
    
    cout << fixed << setprecision(0);   //used for rounding the index up or down
    cout << "Legibility Index: " << index << endl;

    return 0;   //ends the program
}