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
 * FUNCTION PrintHeader
 * _______________________________________________________________________
 *	This function receives an assignment name, type and number then
 *		outputs the appropriate header - returns nothing.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 		asName: Assignment Name has to be previously defined
 * 		asType: Assignment Type has to be previously defined
 * 		asNum : Assignment Number has to be previously defined
 *
 * POST-CONDTIONS
 * 		This function will output the class heading.
 ************************************************************************/
void PrintHeader(ostream &oFile,
				 string asName,		// IN - assignment Name
				 char asType,		// IN - assignment type
				 	 	 	 	 	// 		(LAB or ASSIGNMENT)
				 int asNum)			// IN - assignment number
{
	oFile << left;
	oFile << "******************************************************\n";
	oFile << "*  PROGRAMMED BY : Andrea Velazquez & Justin Stewart";
	oFile << "\n*  " << setw(14) << "STUDENT ID" << ": 994759";
	oFile << "\n*  " << setw(14) << "CLASS" << ": CS1C";
	oFile << "\n*  " << setw(14) << "SECTION" << ": TTH: 8:30a - 9:50a";
	oFile << "\n*  ";
	oFile << "FINAL PROJECT : " << asName;
	oFile << "\n******************************************************\n\n";
	oFile << right;
}
