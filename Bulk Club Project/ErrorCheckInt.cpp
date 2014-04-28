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
 * FUNCTION ErrorCheckInt
 * _______________________________________________________________________
 *	This function Reads in, an upper and lower bound for an integer
 *	 input, as well as a string to prompt the user for that integer input,
 *	 it error checks and then returns that input
 * _______________________________________________________________________
 * PRE-CONDITIONS
 *			upperLim:	Upper bound for input
 *			lowerLim:	Lower bound for input
 *			prompt:		String containing prompt for user input
 *
 * POST-CONDTIONS
 *	This function returns the input
 ************************************************************************/
int ErrorCheckInt(const int upperLim,	//IN - Upper bound for input
				  const int lowerLim, 	//IN - Lower bound for input
				  string prompt)		//IN - String containing prompt
										//     for user input
{
	bool invalid;		//CALC - Holds boolean value for check
	int  input;			//IN   - User input
	int  setWAdj;		//CALC - Sets the setw according to string size

	invalid = true;

	//DO - Runs until user input is validated.
	do
	{
		cout << prompt;

		//IF - Checks for char input and range of input
		if(!(cin >> input))
		{
			cout << "\n**** ";
			cout << "Please input a number between " << lowerLim << " to ";
			cout << upperLim << " ****\n\n";

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			invalid = true;
		}
		else if(input < lowerLim || input > upperLim)
		{
			cout << "\n**** The number " << input;
			cout << left;
			//IF - Adjusts setw to fit message size
			if(input > 0)
			{
				setWAdj = log10(input) + 1;
			}
			else
			{
				input = input * (-1);
				setWAdj = log10(input) + 2;
			}//END IF - Setw adjustment

			cout << setw(28 - setWAdj);

			cout << " is an invalid entry";
			cout <<  "****\n";

			cout << "**** Please input a number between " << lowerLim;
			cout << " and " << setw((log10(upperLim) + 1) + 1);
			cout << left << upperLim << " ****\n\n";
		}
		else
		{
			invalid = false;
		}//END IF - Input Check
	}while(invalid);//END WHILE - Loop until valid info
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	return input;
}


