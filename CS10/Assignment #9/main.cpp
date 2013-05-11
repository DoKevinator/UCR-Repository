// Course: CS 10 Fall 2012
//
// First Name: Kevin
// Last Name: Do
// Course username: kdo009
// Email address: kdo009@ucr.edu
//
// Lecture Section: 002
// Lab Section: 029
// TA: Adam Koehlerc
//
// Assignment: assn9
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//
// =================================================================

#include <vector>
#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;


const bool CLEAR_SCREEN = true;


/**
    @brief Utilizes an escape character sequence to clear the screen
*/
void clearScreen() {
	cout << endl;

	if (CLEAR_SCREEN)
	{
		cout << "\033c" << endl;
    }

    cout << endl;
}


/** 
 *  @brief Draws the provided tic-tac-toe board to the screen
 *  @param board is the tic-tac-toe board that should be drawn
 */
void drawBoard(const vector<char> &board) {
    clearScreen();
    for (int i=0; i<9; i+=3)
    {
        cout << "  " << board.at(i) << "  |  " << board.at(i+1) << "  |  "
             << board.at(i+2) << "  " << endl;
        if (i < 6)
            cout << "-----|-----|-----" << endl;
    }
    cout << endl;
}


/**
 *  @brief Converts character position to appropriate vector index for board
 *
 *      For example, 'a' is converted to 0, 'd' is converted to 3, etc.
 *
 *  @param position the character to be converted to a vector index
 *  @return the integer index in the vector, should be 0 to (vector size - 1)
 */
int convertPosition(char position) {
   
    if( position == 'a' ) {
        return 0;
    } else if( position == 'b' ) {
        return 1;
    } else if( position == 'c' ) {
        return 2;
    } else if( position == 'd' ) {
        return 3;
    } else if( position == 'e' ) {
        return 4;
    } else if( position == 'f' ) {
        return 5;
    } else if( position == 'g' ) {
        return 6;
    } else if( position == 'h' ) {
        return 7;
    } else if( position == 'i' ) {
        return 8;
    } else {
        return -1;
    }
    
}


/**
 *  @brief Predicate function to determine if a spot in board is available.
 *  @param board the current tic-tac-toe board 
 *  @param position is an index into vector to check if available
 *  @return true if position's state is available (not marked) AND is in bounds
 */
bool validPlacement(const vector<char> &board, int position) {
    
    if ( position != -1 ) {
        if (board.at(position) != 'X' && board.at(position) != 'O') {
            return true;
        }
    }
    return false;
}


/**
 *  @brief Acquires a play from the user as to where to put her mark
 *
 *      Utilizes convertPosition and validPlacement functions to convert the
 *      user input and then determine if the converted input is a valid play.
 *
 *  @param board the current tic-tac-toe board 
 *  @return an integer index in board vector of a chosen available board spot
 */
int getPlay(const vector<char> &board) {
    char input;
    
    do {
        cout << "Please choose a position: " << endl;
        cin >> input;
    } while( validPlacement(board,convertPosition(input) ) == false );
    
    return convertPosition( input );
}


/**
 *  @brief Predicate function to determine if the game has been won
 *
 *  Winning conditions in tic-tac-toe require three marks from same 
 *  player in a single row, column or diagonal.
 *
 *  @param board the current tic-tac-toe board 
 *  @return true if the game has been won, false otherwise
 */
bool gameWon(const vector<char> &board) {
    if(board.at(0) == 'X' && board.at(1) == 'X' && board.at(2) == 'X' ||
       board.at(0) == 'O' && board.at(1) == 'O' && board.at(2) == 'O' ) {
        return true;
    }
    
    else if(board.at(3) == 'X' && board.at(4) == 'X' && board.at(5) == 'X' ||
       board.at(3) == 'O' && board.at(4) == 'O' && board.at(5) == 'O' ) {
        return true;
    }
    
    else if(board.at(6) == 'X' && board.at(7) == 'X' && board.at(8) == 'X' ||
       board.at(6) == 'O' && board.at(7) == 'O' && board.at(8) == 'O' ) {
        return true;
    }
    
    else if(board.at(0) == 'X' && board.at(3) == 'X' && board.at(6) == 'X' ||
       board.at(0) == 'O' && board.at(3) == 'O' && board.at(6) == 'O' ) {
        return true;
    }
    
    else if(board.at(1) == 'X' && board.at(4) == 'X' && board.at(7) == 'X' ||
       board.at(1) == 'O' && board.at(4) == 'O' && board.at(7) == 'O' ) {
        return true;
    }
    
    else if(board.at(2) == 'X' && board.at(5) == 'X' && board.at(8) == 'X' ||
       board.at(2) == 'O' && board.at(5) == 'O' && board.at(8) == 'O' ) {
        return true;
    }
    
    else if(board.at(0) == 'X' && board.at(4) == 'X' && board.at(8) == 'X' ||
       board.at(0) == 'O' && board.at(4) == 'O' && board.at(8) == 'O' ) {
        return true;
    }
    
    else if(board.at(2) == 'X' && board.at(4) == 'X' && board.at(6) == 'X' ||
       board.at(2) == 'O' && board.at(4) == 'O' && board.at(6) == 'O' ) {
        return true;
    }
    
    else {
        return false;
    }
}


/**
 *  @brief Predicate function to determine if the board is full
 *  @param board the current tic-tac-toe board 
 *  @return true iff the board is full (no cell is available)
 */
bool boardFull(const vector<char> &board) {
        
    for (int i = 0; i < board.size(); i++) {
        if (board.at(i) != 'X' && board.at(i) != 'O') {
            return false;
        } 
    }
    
    return true;
}


// Global constants for player representation
const int PLAYER1 = 0;
const int PLAYER2 = 1;                                                                  

int main() {
    
    bool gameOver = false;
    int userInput;
    
    // use the following variables to store the tic-tac-toe board 
    vector<char> board(9);

    // the current position to play, acquired from player
    // is a valid tic-tac-toe board index 
    int cur_play;

    // whose turn it currently is, changes at end of a turn
    int turn = PLAYER1;
     

    //Initialize board to empty (places 'a' through 'i' in board)
    for (int i = 'a'; i <= 'i'; i++) {
        board.at(i - 'a') = i;
    }

    // Display empty board
    drawBoard( board );

    // keep performing turns until game over
    while (!gameWon(board) && !boardFull(board) ) {

        // TODO: Get a play
        cur_play = getPlay(board);
        

        // TODO: Update proper board spot with current player's marking
        if (turn == PLAYER1) {
            board.at( cur_play ) = 'X';
        } else if( turn == PLAYER2 ) {
            board.at( cur_play ) = 'O';
        }

        // TODO: Switch the turn to the other player
        if (turn == PLAYER1) {
            turn = PLAYER2;
        } else if( turn == PLAYER2) {
            turn = PLAYER1;
        }

        // TODO: Output the updated board
        drawBoard(board);
    }

    if( gameWon(board) && turn == PLAYER1 ) {
        cout << "Player 2 (O's) wins!" << endl;
    } else if( gameWon(board) && turn == PLAYER2 ) {
        cout << "Player 1 (X's) wins!" << endl;
    } else {
        cout << "No one wins" << endl;
    }
    
    // Game Over - Output who won, if someone did.
    // Output must be one of these 3 options (exactly like these)
         // "Player 1 (X's) wins!"
         // "Player 2 (O's) wins!"
         // "No one wins"
       
    return 0;
}
