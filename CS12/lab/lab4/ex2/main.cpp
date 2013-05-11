//main.cpp

#include <iostream>

using namespace std;


void extend( string* & str_array, int &capacity) {
    
        string* temp = new string[capacity * 2];
    
        for( int i = 0; i < capacity; i++ ) {
            temp[i] = str_array[i];
        }
    
        delete [] str_array;
    
        str_array = temp;
    
        capacity *= 2;
}


void push_back( const string& str, string* & str_array, int&size, int&capacity ) {
    if( size == capacity ) {
        extend( str_array, capacity );
    }
    
    str_array[size] = str;
    size++;
}



double average_size( string* str_array, int size ) {
    
    int sum;
    
    for(int i = 0; i < size; i++ ) {
        for( int j = 0; j < str_array[i].size(); j++ ) {
            sum++;
        }
    }
    
    return (static_cast<double>(sum) / size);
}


void print( string* str_array, int size ) {
    for(int i = 0; i < size; i++ ) {
        cout << str_array[i] << ' ';
    }
    
    cout << endl;
}


int main() {
    
    int size = 0;
    int capacity = 3;
    string input;
    
    string* s_array = new string[capacity];
    
    do {
        
        cout << "Input a string: ";
        cin >> input;
        
        if( input != "." ) {
            push_back(input,s_array,size,capacity);
        }
        
    } while( input != "." );
    
    print(s_array, size);
    cout << "Average string size: " << average_size(s_array,size) << endl;
    
    return 0;
}
