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
// Assignment: assn8
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//
// =================================================================

#include <iostream>     //library for input/output
#include <cstdlib>      //library for srand() and rand()

using namespace std;    

//monster room function gets passed bananas/oranges and name
void monsterRoom( int &bananas, int &oranges, string monsterName) {
    
    bananas = 0;        //steals all the bananas/oranges
    oranges = 0;
    
    cout << "WATCH OUT!!" << endl
         << monsterName << " attacks you and steals all of your bananas"
         << " and oranges." << endl << endl;    //ouputs what happens
}


//genie room function
void genieRoom( int &bananas, int &oranges ) {
    
    bananas = bananas + 2;      //gives user two bananas and 1 orange
    oranges = oranges + 1;
    
    cout << "!!POOF!!" << endl
         << "A genie pops out and grants you 2 bananas and 1 orange." << endl;
    cout << endl;       //outputs what happened
}


//picture room function
void drawPicture() {
    
    cout << "       _--~~--_" << endl;
    cout << "     /~/_|  |_\\~\\" << endl;
    cout << "    |____________|" << endl;
    cout << "    |[][][][][][]|" << endl;
    cout << "  __| __         |__" << endl;
    cout << " |  ||. |   ==   |  |" << endl;    //draws the picture
    cout << "(|  ||__|   ==   |  |)" << endl;
    cout << " |  |[] []  ==   |  |" << endl;
    cout << " |  |____________|  |" << endl;
    cout << " /__\\            /__\\" << endl;
    cout << "  ~~              ~~" << endl;
    cout << endl;
    
}


void pictureRoom() {
    
    cout << "You found a picture!" << endl << endl;
    drawPicture();
}

int main() {    //main function
    
    int alignmentPath = 0;  //chooses the alignment path
    string name;    //name of user
    string scariestMonster; //name of monster
    int bananas = 5, oranges = 3;   //starts out with 5 bananas and 3 oranges
    char doorChoice;    //user input for door choice
    int score = 0;  //score of total fruits
    bool keepGoing = true;
    
    srand( time(NULL) ); //seeds random value
    
    //alignmentPath = rand() % 2;     //chooses random value of 0 or 1
    
    cout << "Please enter your name: " << endl; //prompts for user name
    cin >> name;
    
    cout << "Name your scariest monster: " << endl; //prompts for monster name
    cin >> scariestMonster;

    while ( keepGoing ) {
        alignmentPath = rand() % 2;
        
        if (alignmentPath == 0) {   //alignment 0
            
                cout << name << ", you are in a room with 4 doors." << endl
                << "You are carrying " << bananas << " bananas and "
                << oranges << " oranges." << endl << endl;
                //tells user how many bananas and oranges are left
                
                cout << "Pick a door to enter by typing the direction it "
                << "is in (N/E/S/W):" << endl; //prompts for door choice
                cin >> doorChoice;
                
                while (doorChoice != 'N' && doorChoice != 'E'
                       && doorChoice != 'S'
                       && doorChoice != 'W') {
                    cout << "Pick a door to enter by typing the direction it "
                         << "is in (N/E/S/W):" << endl; 
                    cin >> doorChoice;  //prompts for door choice
                }
                
                if (doorChoice == 'N') {    //if N, monster room
                    monsterRoom( bananas, oranges, scariestMonster);
                } else if( doorChoice == 'E') {     //if E, picture room
                    pictureRoom();
                } else if( doorChoice == 'S') {     //if S, genie room
                    genieRoom( bananas, oranges );
                } else if( doorChoice == 'W') {
                    keepGoing = false;
                }
            
        } else if( alignmentPath == 1 ) {   //alignment 1
            
                cout << name << ", you are in a room with 4 doors." << endl
                << "You are carrying " << bananas << " bananas and "
                << oranges << " oranges." << endl;  //# of bananas and oranges
                
                cout << "Pick a door to enter by typing the direction it "
                << "is in (N/E/S/W):" << endl; //prompt for door choice
                cin >> doorChoice;
                
                while (doorChoice != 'N' && doorChoice != 'E'
                       && doorChoice != 'S'
                       && doorChoice != 'W') {
                    cout << "Pick a door to enter by typing the direction it "
                         << "is in (N/E/S/W):" << endl; 
                    cin >> doorChoice;      //prompts for door choice
                }
                
                if (doorChoice == 'S') {    //if S, monster room
                    monsterRoom( bananas, oranges, scariestMonster);
                } else if( doorChoice == 'W') { //if W, picture room
                    pictureRoom();
                } else if( doorChoice == 'E') { //if E, genie room
                    genieRoom( bananas, oranges );
                } else if( doorChoice == 'N') {
                    keepGoing = false;
                }
        }
    }
    
    score = bananas + oranges;  //counts up total score
    
    cout << "You found the exit!" << endl;  //output # of fruit and exit
    cout << "Your score is " << score << " ( " << bananas
         << " bananas and " << oranges << " oranges)." << endl;
    cout << "Bye bye!!!" << endl;
    
    return 0;
}




