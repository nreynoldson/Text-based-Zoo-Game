/*****************************************************************************
 * Program Name: Project 2 - Zoo Tycoon -  getInput() Source File
 * Name: Nicole Reynoldson
 * Date: 7/20/19
 * Description: A collection of input validation functions. Some functions
 * previously used in Lab 1 through Lab 3 and project 1.
 * ***************************************************************************/
#include <iostream>
#include <cstdlib>
#include <string>
#include "getInput.hpp"
#include <cctype>

using std::cout;
using std::cin;
using std::endl;
using std::string;

/******************************************************************************
 * Description: Two ints are taken as parameters and are used to determine the 
 * range of valid values. The target type must be an integer. Once validated, 
 * the integer value is returned from the function.
 * ***************************************************************************/
int getInt(int min, int max)
{
	string input; //User choice is taken as a string
	char * endPtr;
	int integerVal;
	bool isValid = false; // Set to false while input is not valid

// Adapted from:  https://arstechnica.com/civis/viewtopic.php?f=20&t=868003
	while(isValid == false)
	{
		// Get the full line of input and convert to an integer value
		getline(cin, input);
		integerVal = static_cast<int>(strtol(input.c_str(), &endPtr, 10));
	
		// endPtr points to last non-digit value, if it is anything other
		// than the null character, it is not a valid input
		if(*endPtr == '\0')
		{
			// Then check that converted type is within the specified range
			if(integerVal <= max && integerVal >= min)
			{
				isValid = true;
			}
			else
			{
				cout << "You must enter an integer value between " << min
					  << " and " << max << ". Try again." << endl;
			}
		}
		else
		{
			cout << "Incorrect data type. You must enter an integer between "
				  << min << " and " << max << ". Try again. " << endl;
		}
	}
	
	return integerVal;
}


/******************************************************************************
 * Description: Takes no parameters and will return a string. Strings that 
 * contain numbers or punctuation are rejected, but spaces are allowed. The
 * validated string is then returned from the function. 
 * ***************************************************************************/
string getString()
{
	string input;
	bool isValid = false;
	
	while(isValid == false)
	{
		getline(cin, input);
		
		for(unsigned int i = 0; i < input.size() && !isValid; i++)
		{
			char ch = input.at(i);
			if (isalpha(ch) || isspace(ch))
			{
				isValid = true;
			}
			else
			{
				isValid = false;
				cout << "No digits or punctuation are allowed. Please try again." << endl;
			}	
		}
	}

	return input;
}

/******************************************************************************
 * Description: Takes two doubles as parameters for the maximum and minimum
 * allowable values. A variable is used to keep count of the number of decimal
 * points in the string. If the number of points exceeds 1 or the individual
 * char is not an alphabetical character the input is rejected.
 * ***************************************************************************/
double getDouble(double min, double max)
{
	string input;
	bool isValid = false;
	int dcount = 0;
	double doubleVal;
	
	while(isValid == false)
	{
		getline(cin, input);
	
		for(unsigned int i = 0; i < input.size() && !isValid && dcount <= 1; i++)
		{
			char ch = input.at(i);
			if(isdigit(ch) || ch == '.')
			{
				isValid = true;
				if(ch == '.')
				{
					dcount++;
				}
			}
			else
			{
				isValid = false;
			}
		}

		doubleVal = atof(input.c_str());
		if(isValid == true)
		{
			// Then check that converted type is within the specified range
			if(doubleVal <= max && doubleVal >= min)
			{
				isValid = true;
			}
			else
			{
				cout << "You must enter a value between " << min
					  << " and " << max << ". Try again." << endl;
				isValid = false;
			}
		}
		else
		{
			cout << "Incorrect data type. You must enter a value between "
				  << min << " and " << max << ". Try again. " << endl;
		}
	}	

	return doubleVal;
}

/******************************************************************************
 * Description: Takes two chars as allowable entries. Function takes the input
 * as a string, checks that the string is only 1 char long and that the char
 * is an alpahbetical character. If so, it will check that the char is one
 * of the two options entered as parameters and return it as a lowercase char
 * from the function.
 * ***************************************************************************/
char getChar(char ch1, char ch2)
{
	string input;
	bool isValid = false;
	
	while(isValid == false)
	{
		getline(cin, input);
		
		if((input.size() == 1) && (isalpha(input[0])))
		{
			if(tolower(input[0]) == ch1 || tolower(input[0]) == ch2)
			{
				isValid = true;
			}
			else
			{ 
				cout << "You must enter either " << ch1 << " or " << ch2 << " . Try again. " << endl;
			}
		}
		
		else
		{
			cout << "You must enter a single alphabetical character. Try again." << endl;
		}
	}

	return input[0];
} 
