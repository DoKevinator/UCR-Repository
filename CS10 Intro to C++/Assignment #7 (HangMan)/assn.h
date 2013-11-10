/** 
 *  header file for clear screen function
 */

#include <iostream>

using namespace std;


const bool CLEAR_SCREEN = true;

/**
    @brief Utilizes an escape character sequence to clear the screen
*/
void clearScreen()
{
	cout << endl;

	if (CLEAR_SCREEN)
	{
		cout << "\033c";
    }

    cout << endl;
}

