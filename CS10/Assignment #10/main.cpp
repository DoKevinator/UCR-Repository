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
// Assignment: assn10
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//
// =================================================================

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//gets the puzzle 
void getPuzzle( vector< vector<char> > &wordPuzzle ) {
    
    vector<char> rowOfChars;
    string lineOfChars;
    
    do {
        getline( cin, lineOfChars );
        
        if ( lineOfChars.empty() ) {
            return;
        }
        
        for( int i = 0; i < lineOfChars.size(); i++ ) {
            if( isalpha( lineOfChars.at(i) ) ) {
                rowOfChars.push_back( lineOfChars.at(i) );
            }
        }
               
        wordPuzzle.push_back( rowOfChars );
               
        rowOfChars.clear();
               
    } while( true );
    
}


//checks the entire puzzle from left to right
bool checkLeftRight( const vector< vector<char> > &wordPuzzle,
                     const string &word ) {
    
    for (int row = 0; row < wordPuzzle.size(); row++) {
        for (int col = 0; col < wordPuzzle.at(0).size(); col++) {
            if ( wordPuzzle.at(row).at(col) == word.at(0) ) {
                if (wordPuzzle.at(0).size() - col >= word.size()) {                    
                    for (int k = 1; k < word.size(); k++) {
                        if ( wordPuzzle.at(row).at(col+k) != word.at(k) )
                            break;
                        if (k == word.size() - 1 &&
                            wordPuzzle.at(row).at(col + k ) ==
                            word.at( k ) ) {
                                return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}


//checks the enire puzzle from right to left
bool checkRightLeft( const vector< vector<char> > &wordPuzzle,
                     const string &word ) {
    
    for (int row = 0; row < wordPuzzle.size(); row++) {
        for (int col = 0; col < wordPuzzle.at(0).size(); col++) {
            if ( wordPuzzle.at(row).at(col) == word.at(word.size()-1) ) {
                if (wordPuzzle.at(0).size() - col >= word.size()) {
                    for (int k = 1; k < word.size(); k++) {
                        if ( wordPuzzle.at(row).at(col+k) !=
                             word.at(word.size() - 1 - k) )
                            break;
                        if (k == word.size() - 1 &&
                            wordPuzzle.at(row).at(col + k ) ==
                            word.at( 0 ) ) {
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}


//checks the entire puzzle from top to bottom
bool checkTopDown( const vector< vector<char> > &wordPuzzle,
                   const string &word ) {
    
    for (int col = 0; col < wordPuzzle.at(0).size(); col++) {
        for (int row = 0; row < wordPuzzle.size(); row++) {
            if ( wordPuzzle.at(row).at(col) == word.at(0) ) {
                if (wordPuzzle.size() - row >= word.size()) {
                    for (int k = 1; k < word.size(); k++) {
                        if ( wordPuzzle.at(row+k).at(col) != word.at(k) )
                            break;
                        if (k == word.size() - 1 &&
                            wordPuzzle.at(row + k ).at(col) ==
                            word.at( k ) ) {
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}


//checks the puzzle from bottom to top
bool checkDownTop( const vector< vector<char> > &wordPuzzle,
                   const string &word ) {
    
    for (int col = 0; col < wordPuzzle.at(0).size(); col++) {
        for (int row = 0; row < wordPuzzle.size(); row++) {
            if ( wordPuzzle.at(row).at(col) == word.at(word.size()-1) ) {
                if (wordPuzzle.size() - row >= word.size()) {                    
                    for (int k = 1; k < word.size(); k++) {
                        if ( wordPuzzle.at(row+k).at(col) !=
                             word.at( word.size() - 1 - k) )
                            break;
                        if (k == word.size() - 1 &&
                            wordPuzzle.at(row + k ).at(col) ==
                            word.at( 0 ) ) {
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}


//checks the diagonal from top to bottom goind right
bool checkTopDownDiagonal( const vector< vector<char> > &wordPuzzle,
                           const string &word ) {
    
    for ( int row = 0; row < wordPuzzle.size(); row++) {
        for (int col = 0; col < wordPuzzle.at(0).size(); col++) {
            if (wordPuzzle.at(row).at(col) == word.at(0) ) {
                if (wordPuzzle.size() - row >= word.size() &&
                    wordPuzzle.at(0).size() - col >= word.size() ) {
                    for (int k = 1; k < word.size(); k++) {
                        if (wordPuzzle.at(row+k).at(col+k) != word.at(k)) {
                            break;
                        }
                        if (k == word.size() - 1 &&
                            wordPuzzle.at(row+k).at(col+k) == word.at(k)) {
                            return true;
                        }
                    }
                }
            }
        }
    }
    
    return false;
    
}

//incorrect *fixed
//checks the puzzle from above, but backwards
bool checkTopDownDiagonalBackwards( const vector< vector<char> > &wordPuzzle,
                                    const string &word ) {
    
    for ( int row = 0; row < wordPuzzle.size(); row++) {
        for (int col = 0; col < wordPuzzle.at(0).size(); col++) {
            if (wordPuzzle.at(row).at(col) == word.at(0) ) {
                if (row >= word.size() - 1 && col >= word.size() - 1 ) {
                    for (int k = 1; k < word.size(); k++) {
                        if (wordPuzzle.at(row-k).at(col-k) !=
                            word.at(k)) {
                            break;
                        }
                        if (k == word.size() - 1 &&
                            wordPuzzle.at(row-k).at(col-k) == word.at(k)) {
                            return true;
                        }
                    }
                }
            }
        }
    }
    
    return false;
}


//checks puzzle from bottom to top diagonally
bool checkDownTopDiagonal( const vector< vector<char> > &wordPuzzle,
                           const string &word ) {
    
    for ( int row = 0; row < wordPuzzle.size(); row++) {
        for (int col = 0; col < wordPuzzle.at(0).size(); col++) {
            if (wordPuzzle.at(row).at(col) == word.at(0) ) {
                if (row >= word.size() &&
                    wordPuzzle.at(0).size() - col >= word.size() ) {
                    for (int k = 1; k < word.size(); k++) {
                        if (wordPuzzle.at(row-k).at(col+k) != word.at(k)) {
                            break;
                        }
                        if (k == word.size() - 1 &&
                            wordPuzzle.at(row-k).at(col+k) == word.at(k)) {
                            return true;
                        }
                    }
                }
            }
        }
    }
    
    return false;
}

//incorrect *fixed
//checks above, but backwards
bool checkDownTopDiagonalBackwards( const vector< vector<char> > &wordPuzzle,
                                    const string &word) {
    
    for ( int row = 0; row < wordPuzzle.size(); row++) {
        for (int col = 0; col < wordPuzzle.at(0).size(); col++) {
            if (wordPuzzle.at(row).at(col) == word.at(word.size()-1) ) {
                if (row >= word.size() &&
                    wordPuzzle.at(0).size() - col >= word.size() ) {
                    for (int k = 1; k < word.size(); k++) {
                        if (wordPuzzle.at(row-k).at(col+k) !=
                            word.at(word.size() - 1 - k)) {
                            break;
                        }
                        if (k == word.size() - 1 &&
                            wordPuzzle.at(row-k).at(col+k) == word.at(0)) {
                            return true;
                        }
                    }
                }
            }
        }
    }
    
    return false;
}

int main() {
    
    vector< vector<char> > wordPuzzle;  //word puzzle 2D vector
    string word;        //storing words to find
    vector<string> correct;     //storing found words
    
    getPuzzle( wordPuzzle );    //get the puzzle
    
    while (cin >> word ) {      //input all the words
        
        for (int i = 0; i < word.size(); i++) {
            word.at(i) = toupper( word.at(i) );     //changes all words to
        }                                           //upper case
        
        
        if( checkTopDown( wordPuzzle, word ) ) {   //checks all possibilites
            correct.push_back( word );             //to see if they are there
        }
        else if( checkDownTop( wordPuzzle, word ) ) {
            correct.push_back( word );
        }
        else if( checkLeftRight(wordPuzzle, word ) ) {
            correct.push_back( word );
        }
        else if( checkRightLeft( wordPuzzle, word ) ) {
            correct.push_back( word );
        }
        else if( checkTopDownDiagonal( wordPuzzle, word ) ) {
            correct.push_back( word );
        }
        else if( checkTopDownDiagonalBackwards( wordPuzzle, word )) {
            correct.push_back( word );
        }
        else if( checkDownTopDiagonal(wordPuzzle,word) ) {
            correct.push_back( word );
        }
        else if( checkDownTopDiagonalBackwards(wordPuzzle, word ) ) {
            correct.push_back( word );
        }
         
    }
    
    //sorts the vector alphabetically
    sort( correct.begin(), correct.end() );
    
    for (int i = 0; i < correct.size() ; i++) {     //outputs the found words.
        cout << correct.at(i) << endl;
    }
    return 0;
}




