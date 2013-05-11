// Course: CS 14 Spring 2013
//
// First name: Kevin
// Last name: Do
// Course username: kdo009
// Email address: kdo009@ucr.edu
//
// Lecture section: 001
// Lab section: 021
// TA: Steve Cook
//
// Assignment: assn3
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//=================================================================

//map.cpp

#include "map.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;


template< typename K, typename V >
Map<K,V>::Map()
:key(""), value(""), left(NULL), right(NULL) {
        //default constructor
}


template< typename K, typename V >
Map<K,V>::Map( const K& word, const V& def )
:key(word), value(def), left(NULL), right(NULL) {
        //constructor to make a new Map
}


template< typename K, typename V >
Map<K,V>::Map( Map<K,V> *tmp)
:key(tmp -> key), value(tmp -> value), left(tmp -> left), right(tmp -> right) {
    //copy constructor to make a copy of the Map node
}


template< typename K, typename V >
void Map<K,V>::operator=( Map<K,V>* tmp) {
    this->key = tmp -> key;
    this->value = tmp -> value;
    this->left = tmp -> left;    //overloaded assignment operator to make
    this->right = tmp -> right;  //copy of a Map node
}


template< typename K, typename V >
Map<K,V>::~Map() {
    //burn the entire tree
    delete left;    //delete is recursively called to delete everything in tree
    delete right;
}



//~~~~~~~~~~~~load/save~~~~~~~~~~~~~~~~~~~~~~~~~~~//

template< typename K, typename V >
void Map<K,V>::loadFromFile(std::string file) {
    
    ifstream ipfile;
    ipfile.open( file.c_str() );    //opens the file to read in
    
    if (ipfile.fail()) {
        cout << "File not found. " << endl;
        exit(1);    //if the file is not found
    }
    
    string line;
    string word;
    string translated;
    
    while (getline( ipfile, line )) {
        if (line[0] != '#') {   //ignores all lines with a # in front
            word = line.substr(0, line.find('\t'));
            translated = line.substr( line.find('\t') + 1 );
            insert( word, translated ); //inserts maps with keys and values
        }
    }
    
    ipfile.close(); //close the filestream
}


template< typename K, typename V >
void Map<K,V>::saveToFile(std::string file) {
    ofstream opfile;
    opfile.open( file.c_str() );
    
    outputstream( opfile ); //ouputs to the file recursively
    
    opfile.close();
}


//~~~~~~~~~~~~~load/save~~~~~~~~~~~~~~~~~~~~~~~~~~//



//~~~~~~~~~~~~~~~~~~ MUTATORS ~~~~~~~~~~~~~~~~~~~~//
template< typename K, typename V >
void Map<K,V>::insert (const K& word, const V& def) {
    
    if (key == "") {
        key = word;
        value = def;    //this is a cheapskate way of fixing this.
        return;
    }
    
    if( word == key ) {
        value = def;    //if its the same, overwrite the definition
        return;
    }
    
    if (word < key) {   //if its less than key,
        if (left) {     //check if left is NULL
            left -> insert( word, def );  //continues searching for insert spot
        } else {
            left = new Map<K,V>( word, def );   //inserts it to left
        }
    }
    
    if (word > key) {   //if its more than key
        if (right) {    //checks if right is NULL
            right -> insert( word, def ); //continues searching for insert spot
        } else {
            right = new Map<K,V>( word, def );  //inserts to the right
        }
    }
     
    
    if (balanceFactor() > 1) {  //tree is heavy on left
        if (left -> balanceFactor() > 0) {
            rotateLeftLeft();
        } else {                //readjusts the tree with LL or LR
            rotateLeftRight();
        }
    } else if( balanceFactor() < -1 ) { //tree is heavy on right
        if (right -> balanceFactor() > 0) {
            rotateRightLeft();
        } else {                //readjusts tree with RR or RL
            rotateRightRight();
        }
    }
    
}


template< typename K, typename V >
void Map<K,V>::erase( const K& word ) {
    
    if (this == NULL) {
        cout << "error: not in dictionary" << endl;
        return;     //the word is not found to erase
    }
    
    if (word < key) {
            left -> erase( word );  //keeps searching for the key
    } else if (word > key) {
            right -> erase( word );
    } else {
        
        if (left == NULL && right == NULL) {
            //node has no children. its a leaf node.
            
            //Map<K,V>* parent = findParent( this -> key );
            
            delete this;
            //need to change to NULL but dont know how
            this = NULL;
            
            return;
            
        } else if ( (right == NULL || left == NULL) && !(right && left) ) {
            //node has one child
            if (left) {
                K keytemp = key;
                V valtemp = value;
                
                key = left -> key;
                value = left -> value;  //swaps the values of the current node
                                        //with the one on the left
                left -> key = keytemp;
                left -> value = valtemp;
                
                left -> erase( word );  
            } else if (right) {
                K keytemp = key;
                V valtemp = value;
                
                key = right -> key;
                value = right -> value; //swaps the values of the current node
                                        //with the one on the right;
                right -> key = keytemp;
                right -> value = valtemp;
                
                right -> erase( word );
            }
        } else {
            //node has two children
            
            Map<K,V>* monkey = left;
            for (; monkey -> right != NULL; monkey = monkey -> right) {
                //monkey climbs down the left substree to the right to find
                //the largest value in the left subtree
            }
            
            K keytemp = key;
            V valtemp = value;
            
            key = right -> key;
            value = right -> value; //swaps the values of the current node
                                    //with the largest on the left subtree
            right -> key = keytemp; //that the monkey found.
            right -> value = valtemp;
            
            monkey -> erase( word );
        }
        
        
        //balance factor stuff goes here;
        
        if (balanceFactor() > 1) {
            if (left -> balanceFactor() > 0) {
                rotateLeftLeft();
            } else {
                rotateLeftRight();              //adjusts the tree so that its
            }                                   //balanced either LL, LR,
        } else if( balanceFactor() < -1 ) {     //RR, or RL
            if (right -> balanceFactor() > 0) {
                rotateRightLeft();
            } else {
                rotateRightRight();
            }
        }
        
        return;
    }
    
}


template< typename K, typename V >
void Map<K,V>::clear() {
    //burn the entire tree
    
    if (left) {
        left -> clear();    //goes down entire tree before deleting
    }
    
    if (right) {
        right -> clear();
    }
    
    delete this;
}



//~~~~~~~~~~~~~~~~~~ MUTATORS ~~~~~~~~~~~~~~~~~~~~//


template< typename K, typename V >
void Map<K,V>::rotateLeftLeft() {
    
    //part 1 of LL rotation
    K curkeytemp = this -> key;
    V curvaluetemp = this -> value;
    Map<K,V>* temp = this -> right;     //temporary values to hold current info
    
    this -> key = this -> left -> key;
    this -> value = this -> left -> value;
    this -> right = this -> left -> right;  //swaps it with the left node
    
    this -> left -> key = curkeytemp;   
    this -> left -> value = curvaluetemp;   //reassigns values to other node
    this -> left -> right = temp;
    temp = NULL;
    
    //~~~~ part 2 of the LL rotation.
    Map<K,V>* temp2 = this -> right;
    this -> right = this -> left;       // rotates the nodes after swapping
    this -> left = this-> left -> left;
    this -> right -> left = temp2;
    
}


template< typename K, typename V >
void Map<K,V>::rotateRightRight() {
    //part 1 of RR rotation
    K curkeytemp = this -> key;
    V curvaluetemp = this -> value;     //same as the LL rotation but reversed
    Map<K,V>* temp = this -> left;
    
    this -> key = this -> right -> key;
    this -> value = this -> right -> value;
    this -> left = this -> right -> left;
    
    this -> right -> key = curkeytemp;
    this -> right -> value = curvaluetemp;
    this -> right -> left = temp;
    temp = NULL;
    
    //~~~~ part 2 of the LR rotation.
    Map<K,V>* temp2 = this -> left;
    this -> left = this -> right;
    this -> right = this-> right -> right;
    this -> left -> right = temp2;
    temp2 = NULL;
}


template< typename K, typename V >
void Map<K,V>::rotateLeftRight() {
    left -> rotateRightRight(); //rotate left RR and then current by LL
    rotateLeftLeft();
}


template< typename K, typename V >
void Map<K,V>::rotateRightLeft() {
    right -> rotateLeftLeft();  //rotate right by LL and then current by RR
    rotateRightRight();
}


//~~~~~~~~~~~~~~~~~~ ACCESSORS ~~~~~~~~~~~~~~~~~~~//
template< typename K, typename V >
int Map<K,V>::balanceFactor() const {
    
    int leftside = 0, rightside = 0;
    
    if (left) {
        leftside = left -> height();    //gathers the left height
    }
    
    if (right) {
        rightside = right -> height();  //gathers the right height
    }
    
    return leftside - rightside;    //determines balance factor
    
}


template< typename K, typename V >
int Map<K,V>::height() const {
    
    if( left == NULL && right == NULL ) {
    	return 1;
    }    
    
    int leftside = 0;
    int rightside = 0;
    
    if( right != NULL ) {
    	rightside = right -> height();  //determines right height
    }
    
    if( left != NULL ) {
    	leftside = left -> height();    //determines left height
    }
    
    if( leftside > rightside ) {
    	return 1 + leftside;    //determines which is bigger to determine height
    } else {
    	return 1 + rightside;
    }
}


template< typename K, typename V >
int Map<K,V>::size() const {
    int leftside = 0, rightside = 0;
    
    if(left) {
        leftside = left -> size();
    }   
    
    if(right) {
        rightside = right -> size();    //gathers left and right size 
    }
    
    return 1 + leftside + rightside;    //adds them together
}


template< typename K, typename V >
bool Map<K,V>::isMember( const K& check ) {
    if( check == key ) {
        return true;    //returns true when the key is found
    }
    
    if (check < key) {
        if (left) {         //searches to the left
            return left -> isMember( check );
        } else {
            return false;
        }
    }
    
    if (check > key) {
        if (right) {        //searches to the right
            return right -> isMember( check );
        } else {
            return false;
        }
    }
    
    return false;
}


template< typename K, typename V >
V Map<K,V>::lookup(const K& find) const {
	if( find == key ) {
        return value;   //found the value
    }
    
    if (find < key) {
        if (left) {         //searches to the left
            return left -> lookup( find );
        } else {
            cout << "error: not in dictionary" << endl;
            exit(1);
        }
    }
    
    if (find > key) {
        if (right) {        //searches to the right
            return right -> lookup( find );
        } else {
            cout << "error: not in dictionary" << endl;
            exit(1);
        }
    }
    
    return value;
}


template< typename K, typename V >
K Map<K,V>::closestKey(const K& find) const {
	if( find == key ) {
        return key;     //returns actual key
    }
    
    if (find < key) {
        if (left) {         //searches the left
            return left -> closestKey( find );
        } else {
            return key; //returns thing closest to key
        }
    }
    
    if (find > key) {
        if (right) {    //searches the right    
            return right -> closestKey( find );
        } else {
            return key; //returns thing closest to key
        }
    }
    
    return key;
}
//~~~~~~~~~~~~~~~~~~~ ACCESSORS ~~~~~~~~~~~~~~~~~~~//

template< typename K, typename V >
Map<K,V>* Map<K,V>::findParent( const K& x ) {
    
    if ( left && x < key ) {
        if ( left -> key == x )
            return this;    //searches left tree to parent of x
        return left -> findParent( x );
    }
    if ( right && x > key ) {
        if ( right -> key == x )
            return this;    //searches right tree to parent of x
        return right -> findParent( x );
    }
    if ( !left && !right )
        return NULL;        //cannot find parent
    
    return NULL;
}


template< typename K, typename V >
void Map<K,V>::outputstream( ofstream& opfile ) {
    if (left) {
        left -> outputstream( opfile );
    }
        //outputs all info to the output file
    opfile << key << '\t' << value << '\n';
    
    if (right) {
        right -> outputstream ( opfile );
    }
    
}


/*
template <typename K, typename V>
void Map<K,V>::structure_print() const {
    structure_print_helper( 0 );
}
//helper functions
template <typename K, typename V>
void Map<K,V>::structure_print_helper( int level ) const {
    
    cout << key << endl;
    
    if ( left ) {
        for ( unsigned i = 0; i < level; ++i )
            cout << "--";
        cout << "L-";
        left -> structure_print_helper( level+1 );
    }
    if ( right ) {
        for ( unsigned i = 0; i < level; ++i )
            cout << "--";
        cout << "R-";
        right -> structure_print_helper( level+1);
    }
}
 */

//use this line in order for templates across files to work properly
template class Map<string,string>;

