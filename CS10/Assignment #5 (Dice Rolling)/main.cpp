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
// Assignment: assn5
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
// KEVIN DO
// =================================================================

#include <iostream>     //input output library
#include <cstdlib>      //random library
#include <iomanip>      //setprecision library

using namespace std;    

int main() {    //main function
    
    srand( 1000 );  //seeds the random function with a value of 1000
    
    int timesToSimulate;    //input from user 
    int score = 0;  //score for each simulation
    int roll;       //random number generated from each roll
    int score20 = 0, score21 = 0, score22 = 0, score23 = 0, score24 = 0;
    int score25 = 0, score0 = 0;    //keeps count of each score value
    
    cout << "Hold-at-20 turn simulations? ";    //prompts the user for input
    cin >> timesToSimulate; //stores input here
    cout << endl << endl;       //two endls for formatting
    
    for (int i = 0; i < timesToSimulate; i++) {     //loops inputted times
    
        roll = 0;    //resets roll to zero after each loop
        score = 0;  //resets score to zero
        
        while (score < 20 && roll != 1) {   //makes sure score is atleast 20
                                            //and makes sure roll isnt 1
            roll = rand() % 6 + 1; //random number into roll
            
            if (roll == 1) {    //if roll is 1, reset score to zero
                score = 0;
            } else {
                score = score + roll;   //accumulator 
            }
            
        }
        
        if(score == 20) {          //this whole block determines what the final
            score20++;             //score is of each round and adds one to each
        } else if(score == 21) {   //category
            score21++;
        } else if(score == 22) {
            score22++;
        } else if(score == 23) {
            score23++;
        } else if(score == 24) {
            score24++;
        } else if(score == 25) {
            score25++;
        } else if(score == 0)  {
            score0++;
        }
    }
    
    cout << fixed << setprecision(6);
    cout << "Score\t" << "Estimated Probability" << endl;
    cout << "0\t"  << static_cast<double>(score0)  / timesToSimulate << endl;
    cout << "20\t" << static_cast<double>(score20) / timesToSimulate << endl;
    cout << "21\t" << static_cast<double>(score21) / timesToSimulate << endl;
    cout << "22\t" << static_cast<double>(score22) / timesToSimulate << endl;
    cout << "23\t" << static_cast<double>(score23) / timesToSimulate << endl;
    cout << "24\t" << static_cast<double>(score24) / timesToSimulate << endl;
    cout << "25\t" << static_cast<double>(score25) / timesToSimulate << endl;
                //outputs all the values and probablities in a formatted table
    return 0;
}