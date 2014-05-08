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
 * FUNCTION StatusCheck
 * _______________________________________________________________________
 *	This function receives  a basic members vector list and goes through
 *	the list to find any members that would benefit from upgrading their
 *	membership to premium. It then outputs that list
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 		basicList	: Basic member vector has to be previously defined
 *
 * POST-CONDTIONS
 * 		This function returns nothing
 ************************************************************************/
template<typename Type>
void StatusCheck(vector<Type>& list)
{
	typename Type::iterator listIndex;
	typename Type::iterator outputIndex;
	vector<Type> outputList;

	for(listIndex = list.begin(); listIndex != list.end(); listIndex++)
	{
		if(listIndex->checkUpgrade())
		{
			outputList.push_back(listIndex);
		}
	}

	if(outputList.size() != 0)
	{
		if(outputIndex->getMemType)
		{
			cout << "Recommended Membership Down-grade: " << endl;
		}
		else
		{
			cout << "Recommended Membership Upgrade: " << endl;
		}

		for(outputIndex = outputList.begin(); outputIndex != outputList; outputIndex++)
		{
			cout << outputIndex.getName();
			cout << endl;
		}
	}

}
