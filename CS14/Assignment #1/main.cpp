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
// Assignment: assn1
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//=================================================================


template<typename C> class stack {  //class stack can work with list/vector
    
    typedef typename C :: value_type T; //chooses the different data types
    
private:
    C container;    //container to hold all the data in
    
public:
    
    void push(T val) {
        container.push_back(val);   //pushes a value onto top of stack
    }
    
    T pop() {
        T temp = container.back();
        container.pop_back();   //removes a value from top of stack
        return temp;            //and returns it
    }
    
    unsigned size() {  //returns the size of the stack
        return container.size();
    }
    
    T top() {
        return container.back();    //returns the value at the top of the stack
    }
    
};


#include <iostream>
//#include <stack>
#include <sstream>
#include <vector>

using namespace std;

//operation function to perform + - * / 
void operation(stack< vector<double> >& numbers, const string& temp,bool &x ) {
    
    if (numbers.size() >= 2) {
        double n1, n2;  //two variables to hold values after popping off stack
        n2 = numbers.top(); //get the first variable
        numbers.pop();      //pop it off
        n1 = numbers.top(); //get second variable
        numbers.pop();      //pop second variable off
        
        if (temp == "+") {  //if its + - * / do operation respectively
            numbers.push( n1 + n2 );
        } else if( temp == "-" ) {
            numbers.push( n1 - n2 );
        } else if( temp == "*" ) {
            numbers.push( n1 * n2 );
        } else if( temp == "/" ) {
            numbers.push( n1 / n2 );
        }
        
    } else {    //if there are less than 2 numbers in stack, output an error
        x = false;
    }
}


int main() {
    
    stack< vector<double> > numbers;  //container to hold everything
    string input;   //string to hold user input
    bool is_invalid_token = false;  //test for a valid token
    bool can_be_mod = true;         //test if the values can be mod
    bool enough_parameters = true;
    
    while (cin) {  //infinite loop the program until user does ^C or ^D
        cout << "> ";   //initial carat
        
        getline(cin, input);    //gets user input from console
        
        stringstream string_in(input);
        string temp;    //stream used to read in one value at a time from input
        
        while (string_in >> temp) { //while it reads all the values
            
            if( temp == "+" ) { //finds if the symbol is an operator or not
                operation(numbers,temp,enough_parameters);
            } else if( temp == "-" ) {
                operation(numbers,temp,enough_parameters);
            } else if( temp == "*" ) {
                operation(numbers,temp,enough_parameters);
            } else if( temp == "/" ) {
                operation(numbers,temp,enough_parameters);
            } else if( temp == "%" ) {  //special case for modulo
                
                if (numbers.size() >= 2) {  //test if enough values to mod
                    double n1, n2;
                    n2 = numbers.top();
                    numbers.pop();
                    n1 = numbers.top();
                    numbers.pop();
                    
                    if (static_cast<double>(static_cast<int>(n1)) != n1 ||
                        static_cast<double>(static_cast<int>(n2)) != n2 ) {
                        can_be_mod = false; //this checks if the values are
                    }                       //non integer types
                    
                    numbers.push(static_cast<double>(
                                 static_cast<int>(n1) % static_cast<int>(n2)));
                                //pushes the modded value into stack
                } else {
                    enough_parameters = false;
                }

            } else {
                                
                for (unsigned i = 0; i < temp.size(); i++) {
                    if ( (temp.at(i) < '0' || temp.at(i) > '9') &&
                          temp.at(i) != '.' &&
                         (temp.at(i) != '-' && i != 0) ) { //checks for foreign
                        is_invalid_token = true;//char that makes values invalid
                        break;
                    }
                }
                
                stringstream s(temp);
                double n;
                if ( !(s >> n) )    //stream used to convert strings to doubles
                    is_invalid_token = true;
                else    //validates that the value is a number and not garbage
                    numbers.push(n);    //pushes onto stack if all else is good
            }
        }
        
        if( is_invalid_token ) {    //if there was an invalid token, ouput error
            cout << "Error: invalid token" << endl;
            is_invalid_token = false;   //resets the test for next time
        } else if( !enough_parameters ) {
            cerr << "Error: not enough parameters" << endl;
            if (numbers.size() == 1) {
                numbers.pop();
            }       //clears the rest of the stack
            enough_parameters = true;   //resets test for next run
        } else if( !can_be_mod ) { //if cannot be mod, output error
            cout << "Error: cannot find remainder of a non-integer number"
                 << endl;
            can_be_mod = true;  //resets test for next time
        } else if (numbers.size() == 1) {//if theres only 1 value, output answer
            cout << numbers.top() << endl;
        } else if( numbers.size() > 1 ) {   //if no numbers in stack, error
            cout << "Error: not enough operators" << endl;
        }
        
        while (numbers.size() != 0) {
            numbers.pop();      //clears the stack for the next runthrough
        }

    }
    
    return 0;
}

