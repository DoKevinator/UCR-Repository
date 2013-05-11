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
// Assignment: assn4
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//
// =================================================================


#include "intvector.h"

#include <iostream>
#include <vector>
using namespace std;

ostream& operator <<(ostream& out, const  IntVector& iv)
{
    for(unsigned i = 0; i < iv.size(); ++i)
		out << iv.at(i) << " ";
    return out;
}

int main()
{
    {
        IntVector v1;
        cout << "Default:\n\tsize: " << v1.size()
		<< "\n\tcapacity: " << v1.capacity()
		<< "\n\tempty?: " << v1.empty()
		<< endl << endl;
        
        IntVector v2(10);
        cout << "Size 10:\n\tsize: " << v2.size()
		<< "\n\tcapacity: " << v2.capacity()
		<< "\n\tempty?: " << v2.empty()
		<< endl << endl;
        
        IntVector v3(15,2);
        cout << "Size 15 - value 2:\n\tsize: " << v3.size()
		<< "\n\tcapacity: " << v3.capacity()
		<< "\n\tempty?: " << v3.empty()
		<< endl << endl;
        
        cout << "const at functions:\n";
        cout << "v1 at: \n\t" << v1;
        cout << endl << endl;
        
        cout << "v2 at: \n\t" << v2;
        cout << endl << endl;
        
        cout << "v3 at: \n\t" << v3;
        cout << endl << endl;
        
        cout << "const front/back  v3:";
        cout << "\n\tfront: " << v3.front()
		<< "\n\tback: " << v3.back()
		<< endl << endl;
        
        cout << "push_back:";
        v1.push_back(1);
        cout << "\n\tv1.push_back(1): " << flush << v1.at(v1.size()-1);
        v1.push_back(100);
        cout << "\n\tv1.push_back(100): " << flush << v1.at(v1.size()-1);
        cout << "\n\tv1.size(): " << v1.size()
		<< " -  v1.capacity(): " << v1.capacity();
        v1.push_back(1000);
        cout << "\n\tv1.push_back(1000): " << flush << v1.at(v1.size()-1);
        cout << "\n\tv1.size(): " << v1.size()
		<< " -  v1.capacity(): " << v1.capacity();
        
        v2.push_back(1);
        cout << "\n\tv2.push_back(1): " << flush << v2.at(v2.size()-1);
        v2.push_back(100);
        cout << "\n\tv2.push_back(100): " << flush << v2.at(v2.size()-1);
        cout << "\n\tv2.size(): " << v2.size()
		<< " -  v2.capacity(): " << v2.capacity();
        v2.push_back(1000);
        cout << "\n\tv2.push_back(1000): " << flush << v2.at(v2.size()-1);
        cout << "\n\tv2.size(): " << v2.size()
		<< " -  v2.capacity(): " << v2.capacity();
        cout << endl << endl;
        
        cout << "pop_back:";
        cout << "\n\tv1.size() - " << v1.size();
        v1.pop_back();
        cout << "\n\tv1.pop_back(): " << flush
		<< "  v1.size() - " << v1.size();
        v1.pop_back();
        cout << "\n\tv1.pop_back(): " << flush
		<< "  v1.size() - " << v1.size();
        v1.pop_back();
        cout << "\n\tv1.pop_back(): " << flush
		<< "  v1.size() - " << v1.size();
        cout << endl << endl;
        
        cout << "reserve:";
        cout << "\n\tv2.size() - " << v2.size();
        cout << "\n\tv2.capacity() - " << v2.capacity();
        v2.reserve(2);
        cout << "\n\tv2.reserve(2)"
		<< "\n\tv2.capacity() - " << v2.capacity();
        v2.reserve(30);
        cout << "\n\tv2.reserve(30)"
		<< "\n\tv2.capacity() - " << v2.capacity();
        v2.reserve(85);
        cout << "\n\tv2.reserve(85)"
		<< "\n\tv2.capacity() - " << v2.capacity()
		<< "\n\tv2.size() - " << v2.size();
        cout << endl << endl;
        
        cout << "resize(sz,val):";
        cout << "\n\tv3.size() - " << v3.size();
        cout << "\n\tv3.capacity() - " << v3.capacity();
        cout << "\n\tv3.at(11) - " << v3.at(11);
        v3.resize( 12, 50 );
        cout << "\n\n\tv3.resize( 12, 50 )"
		<< "\n\t\tv3.size() - " << v3.size()
		<< "\n\t\tv3.capacity() - " << v3.capacity()
		<< "\n\t\tv3.at(11) - " << v3.at(11);
        v3.resize( 14, 500 );
        cout << "\n\n\tv3.resize( 14, 500 )"
		<< "\n\t\tv3.size() - " << v3.size()
		<< "\n\t\tv3.capacity() - " << v3.capacity()
		<< "\n\t\tv3.at(11) - " << v3.at(11)
		<< "\n\t\tv3.at(12) - " << v3.at(12)
		<< "\n\t\tv3.at(13) - " << v3.at(13);
        v3.resize( 32, 5000 );
        cout << "\n\n\tv3.resize( 32, 5000 )"
		<< "\n\t\tv3.size() - " << v3.size()
		<< "\n\t\tv3.capacity() - " << v3.capacity()
		<< "\n\t\tv3.at(11) - " << v3.at(11)
		<< "\n\t\tv3.at(13) - " << v3.at(13)
		<< "\n\t\tv3.at(14) - " << v3.at(14)
		<< "\n\t\tv3.at(30) - " << v3.at(30)
		<< "\n\t\tv3.at(31) - " << v3.at(31);
        v3.resize( 34, 50000 );
        cout << "\n\n\tv3.resize( 34, 50000 )"
		<< "\n\t\tv3.size() - " << v3.size()
		<< "\n\t\tv3.capacity() - " << v3.capacity()
		<< "\n\t\tv3.at(11) - " << v3.at(11)
		<< "\n\t\tv3.at(13) - " << v3.at(13)
		<< "\n\t\tv3.at(14) - " << v3.at(14)
		<< "\n\t\tv3.at(31) - " << v3.at(31)
		<< "\n\t\tv3.at(32) - " << v3.at(32)
		<< "\n\t\tv3.at(33) - " << v3.at(33);
        cout << endl << endl;
        
        cout << "resize(sz):";
        IntVector v4( 15, 2 );
        cout << "\n\tv4.size() - " << v4.size();
        cout << "\n\tv4.capacity() - " << v4.capacity();
        cout << "\n\tv4.at(11) - " << v4.at(11);
        v4.resize( 12, 50 );
        cout << "\n\n\tv4.resize( 12, 50 )"
		<< "\n\t\tv4.size() - " << v4.size()
		<< "\n\t\tv4.capacity() - " << v4.capacity()
		<< "\n\t\tv4.at(11) - " << v4.at(11);
        v4.resize( 14, 500 );
        cout << "\n\n\tv4.resize( 14, 500 )"
		<< "\n\t\tv4.size() - " << v4.size()
		<< "\n\t\tv4.capacity() - " << v4.capacity()
		<< "\n\t\tv4.at(11) - " << v4.at(11)
		<< "\n\t\tv4.at(12) - " << v4.at(12)
		<< "\n\t\tv4.at(13) - " << v4.at(13);
        v4.resize( 32, 5000 );
        cout << "\n\n\tv4.resize( 32, 5000 )"
		<< "\n\t\tv4.size() - " << v4.size()
		<< "\n\t\tv4.capacity() - " << v4.capacity()
		<< "\n\t\tv4.at(11) - " << v4.at(11)
		<< "\n\t\tv4.at(13) - " << v4.at(13)
		<< "\n\t\tv4.at(14) - " << v4.at(14)
		<< "\n\t\tv4.at(30) - " << v4.at(30)
		<< "\n\t\tv4.at(31) - " << v4.at(31);
        v4.resize( 34, 50000 );
        cout << "\n\n\tv4.resize( 34, 50000 )"
		<< "\n\t\tv4.size() - " << v4.size()
		<< "\n\t\tv4.capacity() - " << v4.capacity()
		<< "\n\t\tv4.at(11) - " << v4.at(11)
		<< "\n\t\tv4.at(13) - " << v4.at(13)
		<< "\n\t\tv4.at(14) - " << v4.at(14)
		<< "\n\t\tv4.at(31) - " << v4.at(31)
		<< "\n\t\tv4.at(32) - " << v4.at(32)
		<< "\n\t\tv4.at(33) - " << v4.at(33);
        cout << endl << endl;
        
        cout << "clear():";
        cout << "\n\tv4.size() - " << v4.size();
        cout << "\n\tv4.capacity() - " << v4.capacity();
        v4.clear();
        cout << "\n\n\tv4.clear()"
		<< "\n\t\tv4.size() - " << v4.size()
		<< "\n\t\tv4.capacity() - " << v4.capacity();
        
        cout << endl << endl;
        
        cout << "insert:";
        IntVector v5;
        cout << "\n\tv5.size() - " << v5.size();
        cout << "\n\tv5.capacity() - " << v5.capacity();
        v5.insert( 0, 10 );
        cout << "\n\n\tv5.insert( 0, 10 )"
		<< "\n\t\tv5.size() - " << v5.size()
		<< "\n\t\tv5.capacity() - " << v5.capacity()
		<< "\n\t\tv5.at(0) - " << v5.at(0);
        v5.insert( 0, 20 );
        cout << "\n\n\tv5.insert( 0, 20 )"
		<< "\n\t\tv5.size() - " << v5.size()
		<< "\n\t\tv5.capacity() - " << v5.capacity()
		<< "\n\t\tv5.at(0) - " << v5.at(0)
		<< "\n\t\tv5.at(1) - " << v5.at(1);
        v5.insert( 1, 30 );
        cout << "\n\n\tv5.insert( 1, 30 )"
		<< "\n\t\tv5.size() - " << v5.size()
		<< "\n\t\tv5.capacity() - " << v5.capacity()
		<< "\n\t\tv5.at(0) - " << v5.at(0)
		<< "\n\t\tv5.at(1) - " << v5.at(1)
		<< "\n\t\tv5.at(2) - " << v5.at(2);
        v5.insert( 3, 40 );
        cout << "\n\n\tv5.insert( 3, 40 )"
		<< "\n\t\tv5.size() - " << v5.size()
		<< "\n\t\tv5.capacity() - " << v5.capacity()
		<< "\n\t\tv5.at(0) - " << v5.at(0)
		<< "\n\t\tv5.at(1) - " << v5.at(1)
		<< "\n\t\tv5.at(2) - " << v5.at(2)
		<< "\n\t\tv5.at(3) - " << v5.at(3);
        cout << endl << endl;
        
        
        cout << "erase:";
        cout << "\n\tv5.size() - " << v5.size();
        cout << "\n\tv5.capacity() - " << v5.capacity();
        v5.erase(1);
        cout << "\n\n\tv5.erase(1)"
		<< "\n\t\tv5.size() - " << v5.size()
		<< "\n\t\tv5.capacity() - " << v5.capacity()
		<< "\n\t\tv5.at(0) - " << v5.at(0)
		<< "\n\t\tv5.at(1) - " << v5.at(1)
		<< "\n\t\tv5.at(2) - " << v5.at(2);
        v5.erase(2);
        cout << "\n\n\tv5.erase(2)"
		<< "\n\t\tv5.size() - " << v5.size()
		<< "\n\t\tv5.capacity() - " << v5.capacity()
		<< "\n\t\tv5.at(0) - " << v5.at(0)
		<< "\n\t\tv5.at(1) - " << v5.at(1);
        v5.erase(0);
        cout << "\n\n\tv5.erase(0)"
		<< "\n\t\tv5.size() - " << v5.size()
		<< "\n\t\tv5.capacity() - " << v5.capacity()
		<< "\n\t\tv5.at(0) - " << v5.at(0);
        v5.erase(0);
        cout << "\n\n\tv5.erase(0)"
		<< "\n\t\tv5.size() - " << v5.size()
		<< "\n\t\tv5.capacity() - " << v5.capacity();
        cout << endl << endl;
        
        cout << "assign:";
        IntVector v6;
        cout << "\n\tv6.size() - " << v6.size();
        cout << "\n\tv6.capacity() - " << v6.capacity();
        v6.assign( 5, 10 );
        cout << "\n\n\tv6.assign( 5, 10 )"
		<< "\n\t\tv6.size() - " << v6.size()
		<< "\n\t\tv6.capacity() - " << v6.capacity()
		<< "\n\t\tv6.at(0) - " << v6.at(0)
		<< "\n\t\tv6.at(4) - " << v6.at(4);
        v6.assign( 9, 20 );
        cout << "\n\n\tv6.assign( 9, 20 )"
		<< "\n\t\tv6.size() - " << v6.size()
		<< "\n\t\tv6.capacity() - " << v6.capacity()
		<< "\n\t\tv6.at(0) - " << v6.at(0)
		<< "\n\t\tv6.at(4) - " << v6.at(4)
		<< "\n\t\tv6.at(5) - " << v6.at(5)
		<< "\n\t\tv6.at(8) - " << v6.at(8);
        v6.assign( 3, 30 );
        cout << "\n\n\tv6.assign( 3, 30 )"
		<< "\n\t\tv6.size() - " << v6.size()
		<< "\n\t\tv6.capacity() - " << v6.capacity()
		<< "\n\t\tv6.at(0) - " << v6.at(0)
		<< "\n\t\tv6.at(1) - " << v6.at(1)
		<< "\n\t\tv6.at(2) - " << v6.at(2);
        v6.assign( 23, 40 );
        cout << "\n\n\tv6.assign( 23, 40 )"
		<< "\n\t\tv6.size() - " << v6.size()
		<< "\n\t\tv6.capacity() - " << v6.capacity()
		<< "\n\t\tv6.at(0) - " << v6.at(0)
		<< "\n\t\tv6.at(2) - " << v6.at(2)
		<< "\n\t\tv6.at(3) - " << v6.at(3)
		<< "\n\t\tv6.at(22) - " << v6.at(22);
        cout << endl << endl;
        
        cout << "front/back/at mutators:";
        IntVector v7(8);
        cout << "\n\tv7.size() - " << v7.size();
        cout << "\n\tv7.capacity() - " << v7.capacity();
        cout << "\n\tv7 = " << v7;
        v7.front() = 10;
        cout << "\n\n\tv7.front() = 10\n\tv7 = " << v7;
        v7.back() = 20;
        cout << "\n\n\tv7.back() = 20\n\tv7 = " << v7;
        v7.at(3) = 30;
        cout << "\n\n\tv7.at(3) = 30\n\tv7 = " << v7;
        
        cout << endl << endl;
        
    }
    cout << "Destructors called on all IntVector objects"
    << endl << endl;
    
    return 0;
}




