// #include "filename.h" at the top of your .cpp file near other includes
// for access to these functions and the constant value TAX

using namespace std;

// The current Tax rate for taxable items
const double TAX = .075;

/**
   @brief Acquires the price of a specified item.
   @param number a string value that contains the number of an item
   @return the price before tax of that item   
*/
double getItemPrice(string number)
{
    // Convert ascii string to integer number
    int item_number = atoi(number.c_str());


    // Dollar menu items
    if (item_number >= 0 && item_number < 5)
        return 1.00;

    // Single scoop items
    else if (item_number >= 5 && item_number <= 10)
        return 2.25;

    // Double scoop items
    else if (item_number > 10 && item_number <= 15)
        return 3.75;

    // Shakes and Malts
    else if (item_number > 15 && item_number < 20)
        return 4.25;

    // Menu item not found
    return -1;
}

/**
   @brief Determines if an item is taxable.
   @param number a string value that contains the number of an item
   @return true if the item is taxable, false if it is not taxable   
*/
bool isTaxed(string number)
{
    // Convert ascii string to integer number
    int item_number = atoi(number.c_str());

    // Dollar menu items have tax built in so they are exactly $1
    return item_number >=0 && item_number < 5;
}

/**
   @brief Gets the name of the cashier based on specified ID number.
   @param number a string value that contains the cashier's numeric id
   @return the name of the cashier or tie if there is a tie   
*/
string getCashierName(string number)
{
    string s = number;
    
    if (number == "0")
    {
        s = "Penny";
    }
    else if (number == "1")
    {
        s = "Leonard";
    }
    else if (number == "2")
    {
        s = "Sheldon";
    }
    
	//returns originl contents of number if none of the above
    return s;
}

/**
   @brief Determines the winner ID or a tie if no clear winner exists.
   @param one the amount associated with cashier 1
   @param two the amount associated with cashier 2
   @param three the amount associated with cashier 3
   @return a string containing the winning cashier's numerical ID
           or the word tie if there is a tie between 2 or more of the cashiers   
*/
string determineWinner(double one, double two, double three)
{
    if (one > two && one > three)
        return "0";
    else if (two > one && two > three)
        return "1";
    else if (three > one && three > two)
        return "2";

    return "tie";
}
