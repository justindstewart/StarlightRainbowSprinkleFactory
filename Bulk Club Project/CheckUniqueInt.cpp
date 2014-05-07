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
 *	This function receives  a basic members vector list, a preferred
 *	 members vector list and a value to search for. It then prompts the
 *	 user for some basic info and adds a member to the appropriate list.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 		basicList	: Basic member vector has to be previously defined
 * 		prefList	: Preferred member vector has to be previously defined
 *
 * POST-CONDTIONS
 * 		This function returns nothing
 ************************************************************************/
bool CheckUniqueInt(vector<Basic>& basicList,	// IN - Basic list
			   	    vector<Preferred>& prefList,// IN - Preferred list
			   	    int value)					// IN - Search value
{
	bool found;
	vector<Basic>::iterator basicIter;
	vector<Preferred>::iterator prefIter;

	found = false;

	prefIter = prefList.begin();
	basicIter = basicList.begin();

	while(!found && basicIter != basicList.end())
	{
		if(basicIter->getNumber() == value)
		{
			found = true;
		}
	}

	while(!found && prefIter != prefList.end())
	{
		if(prefIter->getNumber() == value)
		{
			found = true;
		}
	}

	return found;
}
