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
 * FUNCTION AddMember
 * _______________________________________________________________________
 *	This function receives  a basic members vector list and a preferred
 *   members vector list. It then prompts the user for some basic info
 *   and adds a member to the appropriate list.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 		basicList	: Basic member vector has to be previously defined
 * 		prefList	: Preferred member vector has to be previously defined
 *
 * POST-CONDTIONS
 * 		This function returns nothing
 ************************************************************************/
void DeleteMember(vector<Basic>& basicList,	 // IN - Basic list
			   vector<Preferred>& prefList)// IN - Preferred list
{
	Basic tempBasic;	//IN	- Temporary basic list
	Preferred tempPref;	//IN	- Temporary preferred list
	int    tempId;		//IN 	- Temporary id variable

	tempId = ErrorCheckInt(99999, 10000, "Please enter a 5 digit ID: ");

	tempBasic.findAndDelete(basicList, tempId);
//	tempPref.findAndDelete(prefList, tempId);

}
