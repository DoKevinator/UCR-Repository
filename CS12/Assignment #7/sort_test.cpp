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
// Assignment: assn7
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//
// =================================================================

//main.cpp

#include <iostream>
#include <vector>
#include <iomanip>
#include <ctime>
#include <algorithm>

using namespace std;


void generate_data_set( vector<int> & v, unsigned n );
int rand_gen( int min, int max ); //see random generator below
void selection_sort( vector<int> & v );
void bubble_sort( vector<int> & v );
void op_bubble_sort( vector<int> & v );
void insertion_sort( vector<int> & v );
void merge_sort( vector<int>& v );
int binary_search( const vector<int>& v, int start, int end, int num );


int main ()
{
    clock_t start;
    clock_t end;
    double dif;
    
    int dataset;
    char input;
    vector<int> v;
    int method;
    
    cout << "Enter data set amount: ";
    cin >> dataset;
    
    generate_data_set( v, dataset );
    
    vector<int> v2 = v;
    
    cout << "Do you want to ouput the set? (y or n) ";
    cin >> input;
    if( input == 'y' ) {
        for( unsigned i = 0; i < v.size(); i++ ) {
            cout << v.at(i) << ", ";
        }
        cout << endl;
    }
    
    cout << "What sort method do you want to use? " << endl;
    cout << '\t' << "1 for Selection" << endl;
    cout << '\t' << "2 for Bubble" << endl;
    cout << '\t' << "3 for Optimized Bubble" << endl;
    cout << '\t' << "4 for Insertion" << endl;
    cout << '\t' << "5 for Merge" << endl;
    cin >> method;
    
    if( method == 1 ) {
        start = clock();
        selection_sort( v );    //calls selection sort method
        end = clock();
    } else if( method == 2 ) {
        start = clock();
        bubble_sort( v );   //calls bubble sort method
        end = clock();
    } else if( method == 3 ) {
        start = clock();
        op_bubble_sort( v );    //calls optimized bubble sort method
        end = clock();
    } else if( method == 4 ) {
        start = clock();
        insertion_sort( v );    //calls insertion sort method
        end = clock();
    } else if( method == 5 ) {
        start = clock();
        merge_sort( v );    //calls merge sort method
        end = clock();
    }
    
    cout << "Output vector again? ";
    cin >> input;
    
    if( input == 'y' ) {
        for( unsigned i = 0; i < v.size(); i++ ) {
            cout << v.at(i) << ", ";
        }
        cout << endl;
    }
    
    
    
    /*
     In your code, instead of the above loop, you would have something like:
     start = clock();
     bubble_sort( my_test_vec );
     end = clock();
     */
    
    dif = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    
    cout << fixed << setprecision(3);
    cout << "\nThe loop took " << dif << " seconds\n";
    cout << endl;
    
    start = clock();
    sort( v2.begin(), v2.end() );   //C++ STL sort time
    end = clock();
    
    dif = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    
    cout << "The C++ STL sort took " << dif << " seconds\n";
    cout << endl;
    
    int binary;
    cout << "Use Binary Search to find an integer: ";
    cin >> binary;  
    
    cout << "Number is at index: " << binary_search(v, 0, v.size() - 1, binary);
    cout << endl;   //uses binary search to find a number
    
    return 0;
}


int binary_search( const vector<int>& v, int start, int end, int num ) {
    if (start > end) {
        return -1;  //base case if the number was not found
    }
    
    int mid = (end - start)/2 + start;  //find the middle of vector
    
    if (v.at(mid) == num) { //if the number is in middle, return mid
        return mid;
    } else if (v.at(mid) < num) {   //if its less, only search bottom half
        return binary_search(v, mid+1, end, num);
    } else if(v.at(mid) > num) {    //if its more, only search top half
        return binary_search(v, start, mid-1, num);
    }
    
    return -1;
}


//~~~~~~~~~~~~~~~~ Merge Sort ~~~~~~~~~~~~~~~~~~~~~~


void merge( vector<int>& v1, vector<int>& v2, vector<int>& v3 ) {
	if( v1.size() == 0 && v2.size() == 0 ) {
		return; //base case when both are empty
	}
    
	if( v1.size() == 0 && v2.size() != 0 ) {
        
        for (unsigned i = 0; i < v2.size(); i++) {
            v3.push_back( v2.at(i) );
        }   //if left is empty but the other isnt, add the rest
        
		return; //break from function
	}
	
	if( v1.size() != 0 && v2.size() == 0 ) {
        
        for (unsigned i = 0; i < v1.size(); i++) {
            v3.push_back( v1.at(i) );
        }   //if right is empty but the other isnt, add the rest
        
		return; //break from function
	}
    
	if( v1.at(0) < v2.at(0) ) { //if the first value in left is less, add it
        v3.push_back( v1.at(0) );
        
        v1.erase(v1.begin());   //gets rid of first element
        
		merge( v1, v2, v3 );    //recursive call on merge to keep merging
	} else {
        v3.push_back( v2.at(0) );   //otherwise, add the second value
        
        v2.erase(v2.begin());   //gets rid of first element
        
		merge( v1, v2, v3 );    //merges both left and right to v3
	} 
	
}


void merge_sort( vector<int>& v ) {
    
    if( v.size() <= 1 ) {
        return;     //base case 
    }
    
    vector<int> left;
    vector<int> right;  //left and right vectors for diving 
    
    for( unsigned i = 0; i < v.size()/2; i++ ) {
        left.push_back( v.at(i) );  //fills the left vector
    }
    
    for( unsigned i = v.size()/2; i < v.size(); i++ ) {
        right.push_back( v.at(i) ); //fills te right vector
    }
    
    merge_sort( left );     //recursively calls left and right merge_sort
    merge_sort( right );
    
    v.clear();  //clears the original vector
    
    merge( left, right, v );    //merges left and right while sorting into v
    
}


//~~~~~~~~~~~~~~~~ Merge Sort ~~~~~~~~~~~~~~~~~~~~~~


//~~~~~~~~~~Selection Sort~~~~~~~~~~~~~~
void select_swap( vector<int>& v, int a, int b ) {
    int temp = v.at(a);
    v.at(a) = v.at(b);  //swap function for selectsort
    v.at(b) = temp;
}

int find_min( vector<int>& v, unsigned start, unsigned end ) {
    int min = v.at(start);
    int index = start;
    
    for( unsigned i = start; i < end; i++ ) {
        if( v.at(i) < min ) {   //find the minimum value in the vector
            min = v.at(i);
            index = i;
        }
    }
    
    return index;   //returns the index of minumum value
}

void selection_sort( vector<int> & v ) {
    
    unsigned start = 0;
    unsigned end = v.size();
    unsigned minIndex;
    
    for( unsigned i = start; i < end; i++ ) {
        minIndex = find_min(v, i, end); //finds min value
        
        select_swap( v, i, minIndex );  //swaps min value with current value
        
    }
}
//~~~~~~~~~~~~~~Selection Sort~~~~~~~~~~~~~~




void bubble_sort( vector<int> & v ) {
    unsigned start = 0;
    unsigned end = v.size()-1;
    bool swapped = true;
    
    while( swapped ) {  //checks if it swapped throughout the iteration
        swapped = false;    //reinitialize swapped
        for( unsigned i = start; i < end;i++ ) {
            if( v.at(i+1) < v.at(i) ) { //loop and swap if next is greater
                swap(v.at(i+1), v.at(i) );
                swapped = true; //says that it swapped throughout iteration
            }   
        }
    }
    
}


void op_bubble_sort( vector<int> & v ) {
    unsigned start = 0;
    unsigned end = v.size()-1;
    bool swapped = true;
    
    while( swapped ) {  //loops until it didnt swap in an interation
        swapped = false;    //resets swapped
        
        for( unsigned i = start; i < end;i++ ) {
            if( v.at(i+1) < v.at(i) ) { //loop and swap if next is greater
                swap(v.at(i+1), v.at(i) );
                swapped = true; //says that it swapped throughout iteration
            }
        }
        
        end = end - 1;  //stops iteration all of the sorted stuff already
    }
}


void insertion_sort( vector<int> & v ) {
    
    unsigned start = 0;
    unsigned end = v.size();
    int valueToInsert;
    int holePosition;
    
    for( unsigned i = start; i < end; i++ ) {
        valueToInsert = v.at(i);    //uses the first value and swaps its around
        holePosition = i;
        
        while( holePosition != 0 && valueToInsert < v.at(holePosition-1) ) {
            v.at(holePosition) = v.at(holePosition-1);
            holePosition -= 1;  //keeps swapping the current value back until it
        }                       //reaches the ordered index
        
        v.at(holePosition) = valueToInsert; //inserts it in ordered index
    }
    
}



int rand_gen( int min, int max ) {
    int range = max - min;
    if (range < 0) range = -range;
    range += 1;
    return min + (rand() % range);
}

void generate_data_set( vector<int>& v, unsigned n ) {
    srand( time(0) );
    
    int from = -100000;
    int to = 100000;
    
    for (unsigned i = 0; i < n; ++i)
        v.push_back( rand_gen(from, to) );
}

