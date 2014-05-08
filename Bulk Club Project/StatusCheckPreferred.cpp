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
 * FUNCTION StatusCheckPreferred
 * _______________________________________________________________________
 *	This function receives a preferred members vector list and goes through
 *	the list to find any members that would benefit from down-grading their
 *	membership to basic. It then outputs that list
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 		basicList	: Basic member vector has to be previously defined
 *
 * POST-CONDTIONS
 * 		This function returns nothing
 ************************************************************************/
void StatusCheckPreferred(vector<Preferred>& list)
{
	vector<Preferred>::iterator prefIter;
	vector<Preferred>::iterator outputIter;
	vector<Preferred> outputList;
	Preferred obj;

	for(prefIter = list.begin(); prefIter != list.end(); prefIter++)
	{
		if(prefIter->checkStatus())
		{
			obj.setName(prefIter->getName());
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
