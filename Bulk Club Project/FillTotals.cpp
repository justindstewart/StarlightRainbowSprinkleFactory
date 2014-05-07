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
 * FUNCTION FillTotals
 * _______________________________________________________________________
 *	This function receives  a basic members vector list, a preferred
 *   members vector list and a history vector list. It then calculates the
 *   total amount spent for the member classes.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 		basicList	: Basic member vector has to be previously defined
 * 		prefList	: Preferred member vector has to be previously defined
 * 		histList	: History vector has to be previously defined
 *
 * POST-CONDTIONS
 * 		This function returns nothing
 ************************************************************************/
void FillTotals(vector<Basic>& basicList,	//IN - Basic list
			   vector<Preferred>& prefList,	//IN - Preferred list
			   vector<History>& histList)	//IN - History list
{
	History histObj;					//CALC - Object to access
	vector<Basic>::iterator basicIter;	//CALC - Basic Iterator
	vector<Preferred>::iterator prefIter;//CALC - Preferred Iterator

	//FOR - Loops through basic list and fills each instance with total
	//		spent
	for(basicIter = basicList.begin(); basicIter != basicList.end(); basicIter++)
	{
		basicIter->setAmtSpent(histObj.calculateTotal(histList, basicIter->getNumber()));
	}//End for

	//FOR - Loops through preferred list and fils each instance with total
	//		spent and calculates the rebate.
	for(prefIter = prefList.begin(); prefIter != prefList.end(); prefIter++)
	{
		prefIter->setAmtSpent(histObj.calculateTotal(histList, prefIter->getNumber()));
		prefIter->calculateRebate(prefIter->getAmtSpent());
	}//End for
}
