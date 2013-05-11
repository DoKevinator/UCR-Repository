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
// Assignment: assn6
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
// 
// =================================================================

#include <iostream> //include iostream for input output
#include <iomanip>  //setprecision
#include "assn.h"   //header file

using namespace std;

int main() {
    //the current tax rate
    const double TAX = .075;
    
    string itemOfWeek;  //stores item of week
    string transNum, cashierID, itemTrans;  //grabs transaction log line
    double itemPrice;   //price of item
    string itemNum;     //item number
    int noCommas;       //while loop sentinel
    double totalAmount = 0; //total amount for transaction
    double cashier1total = 0, cashier2total = 0, cashier3total = 0;
                            //total for each cashier
    int cashier1IOW = 0, cashier2IOW = 0, cashier3IOW = 0;
                            //cashier item of week count
    double cash1LargeSale = 0, cash2LargeSale = 0, cash3LargeSale = 0;
                            //each cashier's largest transaction
    
	
    cin >> itemOfWeek;  //grab item of week
    
    while( cin >> transNum >> cashierID >> itemTrans ) {    //loop through trans
        
        totalAmount = 0;    //resets all values to zero
        itemPrice = 0;
        noCommas = 0;
        
        while (noCommas != -1 ) {   
            noCommas = itemTrans.find(",");
            itemNum = itemTrans.substr(0, itemTrans.find(","));
            itemTrans = itemTrans.substr(itemTrans.find(",") + 1);
            itemPrice = getItemPrice( itemNum );
                        //parses the transactions of items
        
            if( isTaxed( itemNum ) ) {
                itemPrice = itemPrice + itemPrice * TAX;    //calculates tax
            }
        
            totalAmount = totalAmount + itemPrice;  //accumulates total trans
             
            if( itemNum == itemOfWeek && cashierID == "0" ) {
                cashier1IOW++;
            } else if( itemNum == itemOfWeek && cashierID == "1" ) {
                cashier2IOW++;
            } else if( itemNum == itemOfWeek && cashierID == "2" ) {
                cashier3IOW++;
            }                     //counts item of week for each cashier
            
            if (cashierID == "0" && totalAmount > cash1LargeSale) {
                cash1LargeSale = totalAmount;
            } else if( cashierID == "1" && totalAmount > cash2LargeSale) {
                cash2LargeSale = totalAmount;
            } else if( cashierID == "2" && totalAmount > cash3LargeSale) {
                cash3LargeSale = totalAmount;
            }                   //accumulates largest sale for each cashier
        
        }
        
        if( cashierID == "0" ) {
            cashier1total += totalAmount;
        } else if( cashierID == "1" ) {
            cashier2total += totalAmount;
        } else if( cashierID == "2" ) {
            cashier3total += totalAmount;
        }           //accumulates total amount for each cashier
        
    }
        
    cout << fixed << setprecision(2);   //sets precision to 2 decimals
    
    cout << "Item of the Week: " << itemOfWeek << endl;
    cout << "Largest Single Sale Seller: "
         << getCashierName( determineWinner( cash1LargeSale, cash2LargeSale,
                                             cash3LargeSale) ) << endl;
    cout << "Best Item of the Week Sales: "
         << getCashierName( determineWinner( cashier1IOW, cashier2IOW,
                                             cashier3IOW) ) << endl;
    cout << "Best at total sales: "
         << getCashierName( determineWinner( cashier1total, cashier2total,
                                             cashier3total) ) << endl;
    
    cout << endl;
    
    cout << "Individual\t\t" << getCashierName("0")
         << "\t\t" << getCashierName("1")
         << "\t\t" << getCashierName("2") << endl;
    cout << "Total Sales\t\t" << cashier1total << "\t\t" << cashier2total
         << "\t\t"<< cashier3total << endl;
    cout << "Largest Single Sale\t" << cash1LargeSale << "\t\t"
         << cash2LargeSale << "\t\t" << cash3LargeSale << endl;
    cout << "Item of Week Sales\t" << cashier1IOW << "\t\t" << cashier2IOW
         << "\t\t" << cashier3IOW << endl;
            //outputs the statistics of the cashiers in a formatted manner
    
	return 0;
}