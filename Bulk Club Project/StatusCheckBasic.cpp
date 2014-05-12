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
void StatusCheckBasic(vector<Basic>& list)	//IN - Basic List
{
	vector<Basic>::iterator basicIter;	//CALC - Basic Iterator
	vector<Basic>::iterator outputIter;	//CALC - Output iterator
	vector<Basic> outputList;			//IN - Vector list to output
	Basic obj;							//IN - Basic object to push

	//FOR - Loops through basic list and fills alternate list
	for(basicIter = list.begin(); basicIter != list.end(); basicIter++)
	{
		//IF - Checks if upgrading would be beneficial
		if(basicIter->checkStatus())
		{
			obj.setName(basicIter->getName());
			outputList.push_back(obj);
		}//END IF
	}//END FOR

	//IF - Checks if there is someone in the list who could upgrade
	if(outputList.size() != 0)
	{
		//FOR - Outputs each instance in new ouput list
		for(outputIter = outputList.begin(); outputIter != outputList.end(); outputIter++)
		{
			cout << outputIter->getName();
			cout << endl;
		}//END FOR
	}//END IF

}
