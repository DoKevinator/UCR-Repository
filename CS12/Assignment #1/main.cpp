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
// Assignment: assn1
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
// 
// =================================================================


#include <iostream>     //used for input output
#include <cmath>        //included for pow() function

using namespace std;    //standard namespace


int powers_of_2( int marbleCount ) {    //calculates if 2^n-1 is applicable 
    
    double power;
    
    for (double i = 6; i > 0; i -= 1) { //loops through possible powers
        
        power = pow( 2, i ) - 1;
        
        if ( (marbleCount - power) <= (marbleCount/2)
              && (marbleCount-power) > 0) {     //checks if power is legal move
            return static_cast<int>( power );   //if so, return power
        }
    }
    
    power = rand() % (marbleCount/2) + 1;
    
    return static_cast<int>(power);     //if not, return a random legal move
}


void computer_play( int &marbleCount, string gameMode ) {   //computer's play
    
    int marblesTakenByComputer = 0; 
    
    if( gameMode == "n" || gameMode == "naive" ) {  //chooses naive/smart modes
        
        if (marbleCount == 1) {//if the marble count is 1, take the last marble
            marblesTakenByComputer = 1;
            
            marbleCount = marbleCount - marblesTakenByComputer;
        } else {    //otherwise, make a random legal move (naive)
            
            marblesTakenByComputer = rand() % (marbleCount/2) + 1;
            
            marbleCount = marbleCount - (marblesTakenByComputer);
            
            cout << "The computer took " << marblesTakenByComputer
                 << " marble(s).\n";
        }
        
    } else {
        //smart mode
        
        if (marbleCount == 1) {     //takes the last marble if comp loses
            marblesTakenByComputer = 1;
            
            marbleCount = marbleCount - marblesTakenByComputer;
        } else {    //otherwise, use powers_of_2 to calculate strategic move
            
            marblesTakenByComputer = marbleCount - powers_of_2( marbleCount );
            
            marbleCount = marbleCount - (marblesTakenByComputer);
            
            cout << "The computer took " << marblesTakenByComputer
            << " marble(s).\n";
        }
    }
    
}


void user_play( int &marbleCount ) {    //user's play function
    
    int marblesTaken = 0;   
    
    int marblecheck = marbleCount; //used in the do-while loop to guard against
                                   //changing marbleCount
    
    if (marbleCount == 1) {     //if the marbleCount is 1, user has to take it
        
        do {
            cout << "Enter amount of marbles to take: ";
            cin >> marblesTaken;    //user input
            
            if (marblesTaken == 1) {
                marbleCount = marbleCount - marblesTaken;
            } else {
                cout << "Can only be greater than 1 and less than half"
                << " the pile." << endl;    //prompts user its an invalid move
            }

        } while (marblesTaken != 1);    //breaks loop once a valid move is made
        
    } else {   //if the marbleCount is anything but 1, user can choose anything
        
        do {
            cout << "Enter amount of marbles to take: ";
            cin >> marblesTaken;    //prompts user input
            
            //if statement guards if user tries to make an illegal move
            if( marblesTaken > 0 && marblesTaken <= marbleCount/2 ) {
                marbleCount = marbleCount - marblesTaken;
            } else {
                cout << "Can only be greater than 1 and less than half"
                     << " the pile." << endl;   //prompt user invalid move
            }
            
        } while ( !(marblesTaken > 0 && marblesTaken <= marblecheck/2) );
    }       //breaks loop once user makes a valid move
}


int main() {        //main function
    
    int marbleCount = 0;    //marble pile count
    int computerGameMode = 0;   //game mode (smart or naive)
    string gameMode;    //user chooses what game mode
    string playAgain;   //user chooses if he/she wants to play again
    int turn;           //determines if computer or user's turn
    const int COMP_TURN = 0;    //constant computer turn (0)
    const int USER_TURN = 1;   //constant user turn (1)
    int marblesTaken;   //determines how many marbles were taken per round
    bool gameOver = false;      //determines if the game is over
    
    do {    //do-while loop to determine if player wants to play again
        
        cout << "We are now playing Nim!" << endl;
        
        gameOver = false;   //initialize the game to play
        
        cout << "Select game mode (naive/smart): ";
        cin >> gameMode;    //user chooses game mode   
        
        marbleCount = rand() % 91 + 10;//random initial marbleCount (10-100)
        
        turn = rand() % 2;      //randomly assigns who goes first
        
        while (!gameOver) {     //loop to determine if game is over or not
            
            cout << "Marbles: " << marbleCount << endl;
            
            if( turn == USER_TURN ) {
                cout << "User's turn" << endl;  //the user's turn
                user_play( marbleCount);
                
            } else if( turn == COMP_TURN ) {
                cout << "Computer's turn" << endl;      //computer's turn
                computer_play(marbleCount, gameMode );
            }
            
            if( marbleCount == 0 ) {
                gameOver = true;        //if no more marbles, game is over
            }
            
            if (turn == USER_TURN) {
                turn = COMP_TURN;    //changes the turn at the end of each play
            } else if( turn == COMP_TURN ) {
                turn = USER_TURN;
            }
        }
        
        if (turn == COMP_TURN) {    //outputs if the user won or lost
            cout << "Too bad - the Computer beat you :(" << endl;
        } else if( turn == USER_TURN ) {
            cout << "Congratulations! You Won!" << endl;
        }
        
        cout << "Do you wish to play again? (yes or no)" << endl;
        cin >> playAgain;       //prompts user if he/she wants to play again
        
    } while( playAgain == "y" || playAgain == "yes" );  //loops to break out of
                                                        //playAgain loop
    
    return 0;   //ends program.
}

