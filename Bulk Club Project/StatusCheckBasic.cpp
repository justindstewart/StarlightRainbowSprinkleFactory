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
 * FUNCTION StatusCheckBasic
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
void StatusCheckBasic(vector<Basic>& list)
{
	vector<Basic>::iterator basicIter;
	vector<Basic>::iterator outputIter;
	vector<Basic> outputList;
	Basic obj;

	for(basicIter = list.begin(); basicIter != list.end(); basicIter++)
	{
		if(basicIter->checkStatus())
		{
			obj.setName(basicIter->getName());
			outputList.push_back(obj);
		}
	}

	if(outputList.size() != 0)
	{
		for(outputIter = outputList.begin(); outputIter != outputList.end(); outputIter++)
		{
			cout << outputIter->getName();
			cout << endl;
		}
	}

}
