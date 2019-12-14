/******************************************************************************
 * Program Name: Project 2 - Zoo Tycoon - Menus Header
 * Date: 7/20/19
 * Name: Nicole Reynoldson
 * Description: Contains menus used by main including the initial start menu,
 * the difficulty screen and the menu to exit the program.
 *****************************************************************************/
#include <iostream>
#include "getInput.hpp"
#include "menus.hpp"
#include <string>
using std::string;
using std::cout;
using std::endl;

// Start menu
void playMenu()
{
	cout << "\n1. Play game " << endl;
	cout << "2. Quit " << endl;
}

//Possible starting difficulties, the value chosen is returned to main
//to instantiate the zoo
int chooseDifficulty(void)
{
	cout << "\nDIFFICULTY" << endl;
	cout << string(12, '-') << endl;
	cout << "1. Easy - $1,000,000" << endl;
	cout << "2. Standard - $100,000" << endl;
	cout << "3. Hard - $20,000" << endl;

	int choice = getInt(1, 3);
	
	if(choice == 1)
	{
		return 1000000;
	}
	else if(choice == 2)
	{
		return 100000;
	}
	else
	{
		return 20000;
	}	
}

//Exit menu displayed to user at the end of each day
bool exitMenu()
{
	cout << "\n1. Continue playing" << endl;
	cout << "2. Exit" << endl;

	int choice = getInt(1, 2);
	
	if(choice == 1)
	{
		return false;
	}
	else
	{
		return true;
	}
}
