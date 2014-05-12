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
 * FUNCTION AddPurchase
 * _______________________________________________________________________
 *	This function receives  a basic members vector list, a preferred
 *   members vector list and a history vector list. It then prompts the
 *   user for some basic info and adds a purchase to the appropriate list.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 		basicList	: Basic member vector has to be previously defined
 * 		prefList	: Preferred member vector has to be previously defined
 * 		histList	: History member vector has to be previously defined
 *
 * POST-CONDTIONS
 * 		This function returns nothing
 ************************************************************************/
void AddPurchase(vector<Basic>& basicList,	 // IN - Basic list
			     vector<Preferred>& prefList,// IN - Preferred list
			     vector<History>& histList)	 // IN - History list
{
	string tempName;	//IN 	- Temporary name variable
	int    tempId;		//IN 	- Temporary id variable
	float  tempCost;	//IN 	- Temporary cost variable
	int    tempQuantity;//IN	- Temporary quantity variable
	int monthExp;		//CALC	- Month variable post string conversion
	int dayExp;			//CALC	- Day variable post string conversion
	int yearExp;		//CALC  - Year variable post string conversion
	bool validId;		//CALC  - Checks for repeating member numbers
	History obj;		//IN 	- History object for adding purchase

	//DO - Checks to make sure member ID is valid and exists
	do
	{
		validId = false;
		tempId = ErrorCheckInt(99999, 10000, "Please enter a 5 digit member ID: ");
		validId = CheckUniqueInt(basicList, prefList, tempId);

		if(!validId)
		{
			cout << "ID number does not exist - please try again." << endl;
		}

	}while(!validId);

	cout << "Please enter an item name: ";
	getline(cin, tempName);

	cout << "Please enter an expiration date: " << endl;
	monthExp = ErrorCheckInt(12, 1, "Month: ");
	dayExp = ErrorCheckInt(31, 1, "Day: ");
	yearExp = ErrorCheckInt(2031, 2014, "Year: ");

	tempCost = ErrorCheckFloat(10000, .01, "Please enter a cost: ");

	tempQuantity = ErrorCheckInt(10000, 1, "Please enter a quantity: ");

	obj.setName(tempName);
	obj.setNumber(tempId);
	obj.setCost(tempCost);
	obj.setQuantity(tempQuantity);
	obj.setBuyDate(monthExp, dayExp, yearExp);
	histList.push_back(obj);

	//IF - Searches member lists to find member ID and updates total spent
	if(find(basicList.begin(), basicList.end(), Basic(tempId)) != basicList.end())
	{
		vector<Basic>::iterator basicIter;	//IN - Iterator for basic class
		basicIter = find(basicList.begin(), basicList.end(), Basic(tempId));
		basicIter->increaseAmtSpent(tempCost * tempQuantity);
	}
	else
	{
		vector<Preferred>::iterator prefIter; //IN - Iterator for preferred class
		prefIter = find(prefList.begin(), prefList.end(), tempId);
		prefIter->increaseAmtSpent(tempCost * tempQuantity);
	}//END If
}
