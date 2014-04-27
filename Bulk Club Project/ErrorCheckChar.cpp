/*
 * ErrorCheckChar.cpp
 *
 *  Created on: Apr 17, 2014
 *      Author: avelazquez10
 */


#include "header.h"

/*************************************************************************
 * FUNCTION ErrorCheckChar
 * _______________________________________________________________________
 *	 This function Reads in, a two chars, it then reads in a char input
 *	 as well as a string to prompt the user for that selection of inputs,
 *	 it error checks and then returns that input
 * _______________________________________________________________________
 * PRE-CONDITIONS
 *			CHAR1:	First Char for input
 *			CHAR2:	Second Char for input
 *			prompt:	String containing prompt for user input
 *
 * POST-CONDTIONS
 *	This function returns the input
 ************************************************************************/
char ErrorCheckChar(const char CHAR1,	 //IN -First Char for input
					const char CHAR2,    //IN - Second Char for input
					string prompt)		 //IN - String containing prompt
										 //     for user input
{
	char input;		//IN   - User input
	bool invalid;	//CALC - Holds boolean value for valid check

	invalid = true;

	//DO - Loops until user input is validated
	do
	{
		cout << prompt;
		cin.get(input);
		input = toupper(input);
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		//IF - Checks user input against set character choice.
		if (input != CHAR1 && input != CHAR2)
		{
			cout << "****  " << input << " is an invalid Entry ****\n";
			cout << "****   Please input " << CHAR1 << " or " << CHAR2;
			cout << "  ****" << endl;
		}
		else
		{
			invalid = false;
		}//END IF - User input check
	}while(invalid); //WHILE - Loop until valid info input

	return input;
}
