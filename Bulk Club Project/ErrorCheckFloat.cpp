/*************************************************************************
 * AUTHOR		: Justin Stewart & Dennis Dooley
 * STUDENT ID	: 994759 & 759693
 * LAB #13		: Inheritance and Polymorphism
 * CLASS 		: CS1B
 * SECTION		: MW: 8:00a - 9:50a
 * DUE DATE		: December 11, 2013
 ************************************************************************/

#include "header.h"

/*************************************************************************
 * FUNCTION  ErrorCheckFloat
 * _______________________________________________________________________
 *	This function Reads in, an upper and lower bound for a float
 *	 input, as well as a string to prompt the user for that float input,
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
float ErrorCheckFloat(const float upperLim,	//IN - Upper bound for input
					  const float lowerLim, //IN - Lower bound for input
					  string prompt)		//IN - String containing prompt
											//     for user input
{
	bool done;			//CALC - Boolean value to check against valid input
	float  input;		//IN   - User input
	int  setWAdj;		//CALC - Adjusts setw according to output message

	done = false;

	//DO - Loops until user input is validated
	do
	{
		cout << prompt;
		try
		{
			//IF - Checks for char input and range input.
			if(!(cin >> input))
			{
				throw string("The input stream is in the fail state.");

			}
			else if(input < lowerLim || input > upperLim)
			{
				throw input;

			}
			else
			{
				done = true;
			}//END IF - Input check
		}
		catch(string& s)
		{
			cout << "\n**** ";
			cout << "Please input a number between " << int(lowerLim);
			cout << " to " << int(upperLim) << " ****\n";

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		catch(int& i)
		{
			cout << "\n**** The number " << input;
			cout << left;

			//IF - Adjusts setw according to output message
			if(input > 0)
			{
				setWAdj = log10(input) + 1;
			}
			else
			{
				input = input * (-1);
				setWAdj = log10(input) + 2;
			}//END IF - Adjust setw

			cout << setw(32 - setWAdj);

			cout << " is an invalid entry";
			cout <<  "****\n";

			cout << "**** Please input a number between " << int(lowerLim);
			cout << " and " << setw((log10(upperLim) + 1) + 1);
			cout << left << int(upperLim) << "****\n";
		}
	}while(!done);//END DO WHILE - Loop user validation

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	return input;
}
