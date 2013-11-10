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
// Assignment: assn2
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//
// =================================================================


#include <iostream>     //for input and output

using namespace std;        //standard namespace


class Date {        //Date class
    
private:
    unsigned day;   //holds the day of the month
    unsigned month; //holds month value
    unsigned year;  //hold year value
    string month_name;  //name of the month
    
    bool is_leap( unsigned ) const; //checks if the year is leap year
    unsigned days_per_month( unsigned m, unsigned y ) const;//days of month
    string name( unsigned m ) const;    //converts month # to name
    unsigned number( const string &mn ) const;  //converts month name to #
    
public:
    Date(); //default constructor
    Date( unsigned m, unsigned d, unsigned y ); //other constructors
    Date( const string &mn, unsigned d, unsigned y );
    
    void print_numeric( ) const;    //prints numeric 0/0/0000
    void print_alpha( ) const;      //prints alpha jan 1, 2000
    
};

//begin test harnesses ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void test1(){
	cout << "1. Invalid Numeric Date: 4.0.2005 -> 4.1.2005" << endl;
	Date x = Date(4,0,2005);
	cout << "numeric:\t" ;
	x.print_numeric();
	cout << endl;
	cout << "alpha:\t";
	x.print_alpha();
	cout << endl;
	cout << "-------------" << endl;
}

void test2(){
	cout << "2. Numeric Date: 2.29.2001" << endl;
	Date x = Date(2,29,2001);
	cout << "numeric:\t" ;
	x.print_numeric();
	cout << endl;
	cout << "alpha:\t";
	x.print_alpha();
	cout << endl;
	cout << "-------------" << endl;
}

void test3(){
	cout << "3. Numeric Date: 2.29.2000" << endl;
	Date x  =  Date(2,29,2000);
	cout << "numeric:\t" ;
	x.print_numeric();
	cout << endl;
    cout << "alpha:\t";
	x.print_alpha();
	cout << endl;
	cout << "-------------" << endl;
}

void test4(){
	cout << "4. Invalid Numeric Date: 0.3.1991 -> 1.3.1991" << endl;
	Date x = Date(0,3,1991);
	cout << "numeric:\t" ;
	x.print_numeric();
	cout << endl;
	cout << "alpha:\t";
	x.print_alpha();
	cout << endl;
	cout << "-------------" << endl;
}

void test5(){
	cout << "5. Alpha Date: october 12, 24" << endl;
	Date x = Date("october",12,24);
	cout << "numeric:\t" ;
	x.print_numeric();
	cout << endl;
	cout << "alpha:\t";
	x.print_alpha();
	cout << endl;
	cout << "-------------" << endl;
}

void test6(){
	cout << "6. Invalid Alpha Date: Septembre 10, 2010 -> 1/1/2000" << endl;
	Date x = Date("Septembre",10,2010);
	cout << "numeric:\t" ;
	x.print_numeric();
	cout << endl;
	cout << "alpha:\t";
	x.print_alpha();
	cout << endl;
	cout << "-------------" << endl;
}

void test7(){
	cout << "7. Invalid Alpha Date: January 1, 0 -> January 1, 1" << endl;
	Date x = Date("January",1,0);
	cout << "numeric:\t" ;
	x.print_numeric();
	cout << endl;
	cout << "alpha:\t";
	x.print_alpha();
	cout << endl;
	cout << "-------------" << endl;
}

void test8(){
	cout << "8. Invalid Numeric Date: 5.35.2012 -> 5.31.2012" << endl;
	Date x = Date(5,35,2012);
	cout << "numeric:\t" ;
	x.print_numeric();
	cout << endl;
	cout << "alpha:\t";
	x.print_alpha();
	cout << endl;
	cout << "-------------" << endl;
}

void test9(){
	cout << "9. Invalid Alpha Date: May 37, 2012 -> May 31, 2012" << endl;
	Date x = Date("May",37,2012);
	cout << "numeric:\t" ;
	x.print_numeric();
	cout << endl;
	cout << "alpha:\t";
	x.print_alpha();
	cout << endl;
	cout << "-------------" << endl;
}

void test10(){
	cout << "10. Invalid Alpha Date: january 0, 0 -> January 1, 1" << endl;
	Date x = Date("january",0,0);
	cout << "numeric:\t" ;
	x.print_numeric();
	cout << endl;
	cout << "alpha:\t";
	x.print_alpha();
	cout << endl;
	cout << "-------------" << endl;
}

//end test harnesses~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~



int main() {    //testing the test harnesses
    
    test1();
	test2();
	test3();
	test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    test10();
    
    
    return 0;
}



Date::Date()        //defaul constructor
:day(1), month(1), year(2000), month_name( "January" )
{
}


//month NUMBER constructor
Date::Date( unsigned m, unsigned d, unsigned y )
:month(m), month_name( name(m) ), day(d), year(y) //initialization list
{
    
    //if-statement checks if there is something wrong
    /** 2000000000 is the threshold number to check if the inputted number is a
        negative number because of the unsigned integers **/
    if( (m > 12) || (m==0)|| (d > days_per_month( m, y ) ) || (d>2000000000) ||
         (d < 1) || (y > 2000000000) || y < 1) {
        
        if( (m > 12)  && (m < 2000000000) ) {   //if month is >12, change to Dec
            month = 12;
            month_name = "December";
        } else if( m > 2000000000 || m == 0) {  //if month < 1, change to Jan
            month = 1;
            month_name = "January";
        } 
        
        if( d > days_per_month( month, y ) ) { //if day > dayPerMonth, 
            day = days_per_month( month, y ); //change days to max days in month
        } else if( d > 2000000000 ) {
            day = 1;                //if day is < 1, change to 1.
        } else if( d < 1 ) {
            day = 1;
        }
        
        if( y > 2000000000 || y < 1 ) {     //if year is <1, make year 1
            year = 1;
        }
        
    //outputs the that the date inputted was invalid and changed to something
        cout << "Invalid date values: Date corrected to "
             << month << "/" << day << "/" << year << endl;
    }
    
}



//month NAME constructor
Date::Date( const string &mn, unsigned d, unsigned y )
:month( number(mn) ), month_name(name(month)), day(d), year(y)
{
    
    //checks if something is wrong
    //again, 2000000000 is the threshold for checking negative inputted values
    if( number(mn) == 0 || (d > days_per_month( month, y ) ) || (d>2000000000)
        || (y > 2000000000) || y < 1) {
        
        if( d > days_per_month( month, y ) ) {  //checks for maximum days in
            day = days_per_month( month , y );  //a month
        } else if( d > 2000000000 || d < 1 ) {
            day = 1;                    //if day is <1, change it to 1
        }
        
        if( number(mn) == 0 ) {     //changes date to default when month name is
            month = 1;              //inputted incorrectly
            month_name = "January";
            day = 1;
            year = 2000;
        }
        
        if( y > 2000000000 || y < 1 ) { //changes year to 1 if <1
            year = 1;
        }
        
        if (month_name != name(number(mn))) {   //output invalid month name
            cout << "Invalid month name: Date set to "
            << month << "/" << day << "/" << year << endl;
        } else {
            cout << "Invalid date values: Date corrected to "   //invalid date
            << month << "/" << day << "/" << year << endl;      //value
        }
    }
}



void Date::print_numeric() const {
    cout << month << "/" << day << "/" << year;     //prints in numeric form
}


void Date::print_alpha() const {            //prints in alpha form
    cout << month_name << " " << day << ", " << year;
}


bool Date::is_leap( unsigned y ) const {    //function that checks for leap year
    
    if ( (y % 4 == 0) && (y % 100 != 0 || y % 400 == 0) ) {
        return true;
    } else {
        return false;
    }
}


//returns the maximum number of days corresponding to month
unsigned Date::days_per_month( unsigned m, unsigned y ) const {
    
    if( m == 1) {    
        return 31;
    } else if( m == 2  && is_leap( y )) {
        return 29;
    } else if( m == 2 && !is_leap( y ) ) {
        return 28;
    } else if( m == 3 ) {
        return 31;
    } else if( m == 4 ) {
        return 30;
    } else if( m == 5 ) {
        return 31;
    } else if( m == 6 ) {
        return 30;
    } else if( m == 7 ) {
        return 31;
    } else if( m == 8 ) {
        return 31;
    } else if( m == 9 ) {
        return 30;
    } else if( m == 10 ) {
        return 31;
    } else if( m == 11 ) {
        return 30;
    } else if( m == 12 ) {
        return 31;
    } else if( m < 1 ) {
        return 31;
    }
}


//converts the month number into a month name
string Date::name( unsigned m ) const {
    
    if( m == 1 || m == 0 ) {
        return "January";
    } else if( m == 2 ) {
        return "February";
    } else if( m == 3 ) {
        return "March";
    } else if( m == 4 ) {
        return "April";
    } else if( m == 5 ) {
        return "May";
    } else if( m == 6 ) {
        return "June";
    } else if( m == 7 ) {
        return "July";
    } else if( m == 8 ) {
        return "August";
    } else if( m == 9 ) {
        return "September";
    } else if( m == 10 ) {
        return "October";
    } else if( m == 11 ) {
        return "November";
    } else if( m == 12 ) {
        return "December";
    } 
}


//converts a month name into a month number
unsigned Date::number( const string &mn ) const {
    if( mn == "January" || mn == "january" ) {
        return 1;
    } else if( mn == "February" || mn == "february" ) {
        return 2;
    } else if( mn == "March" || mn == "march" ) {
        return 3;
    } else if( mn == "April" || mn == "april" ) {
        return 4;
    } else if( mn == "May" || mn == "may" ) {
        return 5;
    } else if( mn == "June" || mn == "june" ) {
        return 6;
    } else if( mn == "July" || mn == "july" ) {
        return 7;
    } else if( mn == "August" || mn == "august" ) {
        return 8;
    } else if( mn == "September" || mn == "september" ) {
        return 9;
    } else if( mn == "October" || mn == "october" ) {
        return 10;
    } else if( mn == "November" || mn == "november" ) {
        return 11;
    } else if( mn == "December" || mn == "december" ) {
        return 12;
    } else {
        return 0;
    }
}


