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

//map.h

#ifndef _MAP_H_
#define _MAP_H_

#include <string>
//#include <iostream>

using namespace std;

template <typename K, typename V>
class Map {
private:
    K key;
    V value;
    Map<K,V> *left, *right;
    
    void rotateLeftLeft();
    void rotateRightRight();
    void rotateLeftRight();
    void rotateRightLeft();
    
    Map<K,V>* findParent( const K& x );
    
    void outputstream( ofstream& opfile );
    
    //void structure_print_helper( int level ) const; //get rid before turnin. only used for tesing;
    
public:
    Map();
    Map(const K&, const V&);
    
    // add the big 3 functions
    Map( Map<K,V>* );
    void operator=( Map<K,V>* );
    ~Map();
    
    //void structure_print() const;   //get rid before turn in. only testing
    
    
    // IO ///////////////////////////////////////
    
    /*
     You will use the file format of the "Internet Dictionary Project"
     You can find details at: http://www.june29.com/idp/IDPfileformat.html
     */
    void loadFromFile(std::string file);
    void saveToFile(std::string file);
    
    // mutators /////////////////////////////////
    
    /* adds (K,V) into the map, overwriting the previous value if it exists */
    void insert (const K&, const V&);
    
    /* erases (K,V) from the map */
    void erase (const K&);
    
    /* erases all elements from the map */
    void clear();
    
    // accessors ////////////////////////////////
    
    /* returns the number of (K,V) pairs stored in the map */
    int size() const;
    
    /* returns the height of the tree */
    int height() const;
    
    /* returns the tree's balance factor */
    int balanceFactor() const;
    
    /* return true if K is a valid key, false otherwise */
    bool isMember (const K&);
    
    /* returns the V associated with K; if K is not a valid key, then print an error and abort the program */
    V lookup (const K&) const;
    
    /* returns the key that is most similar to the key passed in */
    K closestKey(const K&) const;
    
    /* returns the value of the key that is most similar to the key passed in.  Like lookup, but never aborts */
    V lookupSimilar (const K &k) const { return lookup(closestKey(k)); }
};


#endif

