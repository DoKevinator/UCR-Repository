/*
* Course: CS 100 Fall 2013
*
* First Name: Kevin
* Last Name: Do
* Username: kdo009
* email address: kdo009@ucr.edu
*
*
* Assignment: Homework #1
*
* I hereby certify that the contents of this file represent
* my own original individual work. Nowhere herein is there
* code from any outside resources such as another individual,
* a website, or publishings unless specifically designated as
* permissible by the instructor or TA.
*/

#include <fstream>
#include <iostream>

using namespace std;

//person struct to hold all the information of each address in the rolodex
struct Person {
	Person()
	:first_name(""), last_name(""), address(""), phone_number("") { }

	Person(const string& fn, const string& ln, const string& addr, 
											   const string& pn)
	:first_name(fn), last_name(ln), address(addr), phone_number(pn) { }

	string first_name;
	string last_name;
	string address;
	string phone_number;
};

class Rolodex {

private:
	Person* rolodex;	//dynamic array to hold all addresses
	int size;			//keeps track of size of rolodex
	int capacity;		//keeps track of capacity of rolodex
	bool saved;			//checks if the rolodex is saved or not
	bool is_sorted;		//checks if the rolodex is sorted or not

	void sort_alphabetically() {
		//bubble sort because the rolodex isn't that big and doesn't require
		//a very complex sorting algorithm
	    unsigned end = size-1;
	    bool swapped = true;
	    
	    while( swapped ) {
	        swapped = false;
	        
	        for( unsigned i = 0; i < end; i++ ) {
	            if( rolodex[i+1].last_name < rolodex[i].last_name ) {
	                swap(rolodex[i+1], rolodex[i] );
	                swapped = true;
	            }
	        }
	        
	        end = end - 1;
	    }

	}

	void expand_capacity() {
		Person* tmp = new Person[capacity*2];
		for( int i = 0; i < size; i++ ) {
			tmp[i] = rolodex[i];
		}								//expands the capacity of the array by
		capacity = capacity * 2;		//2 times so it can hold more addresses
		delete[] rolodex;
		rolodex = tmp;
	}

public:
	Rolodex()
	:rolodex( new Person[1] ), size(0), capacity(1), 
							   saved(false), is_sorted(true) { }

	~Rolodex() {
		delete [] rolodex;
	}

	//inserts an address into the rolodex
	void insert_address(const string& first_name, const string& last_name, 
						const string& address, const string& phone_number) {
		if( size >= capacity ) {
			expand_capacity();			//checks if we need to expand capacity
		}								//before we insert 

		saved = false;
		is_sorted = false;

		rolodex[size] =  Person(first_name, last_name, address, phone_number);
		size++;
	}

	//finds an address in the rolodex by last name and prints the info
	void find_address( const string& ln ) const {
		for (int i = 0; i < size; ++i) {
			if( ln == rolodex[i].last_name ) {
				cout << "-------------------------------------------\n";
				cout << rolodex[i].first_name << "'s address is " 
					 << rolodex[i].address << endl << endl;
				cout << rolodex[i].first_name << "'s phone number is " 
					 << rolodex[i].phone_number << endl << endl;
				return;
			}
		}

		cerr << "Error: invalid last name." << endl;
	}

	//Deletes an address by swapping out the address with the last address in
	//the rolodex, and then decreasing the size by one to get rid of the 
	//address we want to delete.
	void delete_address( const string& ln ) {

		saved = false;
		is_sorted = false;

		for (int i = 0; i < size; ++i) {
			if( ln == rolodex[i].last_name ) {
				swap( rolodex[i], rolodex[size-1] );
				size--;
				return;
			}
		}

		cout << "Error: invalid last name." << endl << endl;
	}

	//Checks if the rolodex is empty and checks if the rolodex is sorted before
	//it starts to loop through the rolodex to print out all the information
	//of the addresses.
	void print_address() {
		if( size == 0 ) {
			cout << "Nothing in the rolodex." << endl;
			return;
		}

		if (!is_sorted) {
			sort_alphabetically();
		}

		cout << "-------------------------------------------\n";

		for (int i = 0; i < size; ++i) {
			cout << rolodex[i].last_name << ", " 
				 << rolodex[i].first_name << endl;
			cout << "\t" << rolodex[i].address << endl
				 << "\t" << rolodex[i].phone_number << endl << endl;
		}
	}

	//loads all the information into a rolodex from a file specified by the user
	//uses getline to grab an entire line and sparses it by the semicolons
	//dividing up the information for each address
	void load_address( const string& filename ) {
		is_sorted = true;

		ifstream input;
		input.open( filename.c_str() );

		string line;

		while( getline(input, line) ) {
			string first, last, addr, phone;

			first = line.substr( 0, line.find(';') );
			line = line.substr( line.find(';') + 2 );

			last = line.substr( 0, line.find(';') );
			line = line.substr( line.find(';') + 2 );

			addr = line.substr( 0, line.find(';') );
			line = line.substr( line.find(';') + 2 );

			phone = line;

			insert_address( first, last, addr, phone );
		}

		input.close();
	}

	//saves the entire rolodex into an output file specified by the user.
	//outputs all information into the same format with the sparsing semicolons
	//as the input file.
	void save_address() {
		if (!is_sorted) {
			sort_alphabetically();
		}		

		string filename;
		cout << "Enter a file name to save to: "; 
		cin >> filename;

		ofstream output;
		output.open(filename.c_str());

		for (int i = 0; i < size; ++i) {
			output << rolodex[i].first_name << "; " 
				   << rolodex[i].last_name << "; "
				   << rolodex[i].address << "; "
				   << rolodex[i].phone_number << endl;
		}

		output.close();

		saved = true;

		cout << "Saved!" << endl;
	}
	
	//quits the program. asks the user to save the rolodex if it hasnt been 
	//saved before, or if there had been changes made to the rolodex after 
	//saving it before.
	void quit( const string& filename ) {
		if( !saved ) {
			char input;
			cout << "Would you like to save before you quit? (y/n): " <<endl;
			cin >> input;

			while( true ) {
				if (input == 'y') {
					save_address();
					exit(0);
				} else if( input == 'n' ) {
					cout << "All data not saved." << endl;
					exit(0);
				} else {
					cout << "Invalid input. Please try again: ";
					cin >> input;
				}
			}
		} else {
			cout << "Closing Rolodex." << endl;
			exit(0);
		}
	}

};



void print_menu();		//prints the menu of actions to choose from

//main() is where the central branching of the program takes place. it calls 
//other functions according to what the user wants to do in specific to the 
//menu. 
//it prompts the user what he/she wants to do and reads in input, then chooses 
//what action to take and performs the desired actions. 
int main() {

	Rolodex r; 
	string first, last, addr, phone, load_filename, save_filename;
	char input;

	cout << "Welcome to Rolodex!" << endl;
	print_menu();

	while( cin >> input ) {
		switch( input ) {
			case 'i': 
				cout << "Enter a first name: "; cin >> first;
				cout << "Enter a last name: "; cin >> last;
				cin.ignore(1000,'\n');
				cout << "Enter an address: "; getline( cin, addr);
				cout << "Enter a phone number: "; getline(cin,phone);
				r.insert_address(first, last, addr, phone);
				break;
			case 'f':
				cout << "Enter a last name: "; cin >> last;
				r.find_address(last);
				break;
			case 'd':
				cout << "Enter a last name: "; cin >> last;
				r.delete_address(last);
				break;
			case 'p': 
				r.print_address();
				break;
			case 'l':
				cout << "Enter a file name: "; cin >> load_filename;
				r.load_address(load_filename);
				break;
			case 's':
				r.save_address();
				break;
			case 'q': 
				r.quit(save_filename);
				break;
			default:
				cout << "Invalid input. Please try again: " << endl;
				break;
		}

		print_menu();
	}

	return 0;
}


//prints the menu of actions to take as the user
void print_menu() {
	cout << "i - Insert an address" << endl
		 << "f - Find an address" << endl
		 << "d - Delete an address" << endl
		 << "p - Print all addresses " << endl
		 << "l - Load addresses" << endl
		 << "s - Save addresses" << endl
		 << "q - Quit" << endl;
	cout << "Enter a letter: ";
}



