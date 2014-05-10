/*************************************************************************
 * AUTHOR		: Andrea Velazquez & Justin Stewart
 * STUDENT ID	: 994759
 * FINAL PROJECT: Super Warehouse Store
 * CLASS 		: CS1C
 * SECTION		: TTH: 8:30a - 9:50a
 * DUE DATE		: May 13th, 2014
 ************************************************************************/

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
	bool done;	//CALC - Holds boolean value for valid check

	done = false;

	//DO - Loops until user input is validated
	do
	{
		cout << prompt;
		try
		{
			cin.get(input);
			input = toupper(input);
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			//IF - Checks user input against set character choice.
			if (input != CHAR1 && input != CHAR2)
			{
				throw input;
			}
			else
			{
				done = true;
			}//END IF - User input check
		}
		catch(char& c)
		{
			cout << "****  " << input << " is an invalid Entry ****\n";
			cout << "****   Please input " << CHAR1 << " or " << CHAR2;
			cout << "  ****" << endl;
		}

	}while(!done); //WHILE - Loop until valid info input

	return input;
}
