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
 * 		list	: Preferred member vector has to be previously defined
 *
 * POST-CONDTIONS
 * 		This function returns nothing
 ************************************************************************/
void StatusCheckPreferred(vector<Preferred>& list) //IN - Preferred list
{
	vector<Preferred>::iterator prefIter;	//CALC - Preferred iterator
	vector<Preferred>::iterator outputIter;	//CALC - Output iterator
	vector<Preferred> outputList;			//IN   - Output vector
	Preferred obj;							//IN   - Object to push

	//FOR - Loops through preferred list and fills output vector
	for(prefIter = list.begin(); prefIter != list.end(); prefIter++)
	{
		//IF - Checks if downgrading would benefit, puts them in a list
		if(prefIter->checkStatus())
		{
			obj.setName(prefIter->getName());
			outputList.push_back(obj);
		}//END IF
	}//END FOR

	//IF - Checks if output list has someone to output
	if(outputList.size() != 0)
	{
		//FOR - Loops through output list and outputs each instance
		for(outputIter = outputList.begin(); outputIter != outputList.end(); outputIter++)
		{
			cout << outputIter->getName();
			cout << endl;
		}//END FOR
	}//END IF

}
