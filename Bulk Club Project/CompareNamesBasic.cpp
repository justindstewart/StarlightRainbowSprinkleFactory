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
 * FUNCTION CompareNamesBasic
 * _______________________________________________________________________
 *	This function receives two basic member names and compares them
 *	alphabetically.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 		first		: first has to be previously defined
 * 		second		: second has to be previously defined
 *
 * POST-CONDTIONS
 * 		none
 ************************************************************************/
bool CompareNamesBasic(const Basic& first,	// IN - First name to compare
					   const Basic& second)	// IN - Second name to compare
{
	return first.getName() < second.getName();
}
