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
	int buyMonth;		//CALC	- Month variable post string conversion
	int buyDay;			//CALC	- Day variable post string conversion
	int buyYear;		//CALC  - Year variable post string conversion
	bool validId;		//CALC  - Checks for repeating member numbers
	History obj;		//IN 	- History object for adding purchase
	int itemCount;
	bool addMore;

	//DO - Checks to make sure member ID is valid and exists
	do
	{
		validId = false;
		tempId = ErrorCheckInt(99999, 10000, "Please enter a 5 digit member ID: ");
		validId = CheckUniqueInt(basicList, prefList, tempId);

		//IF - Outputs error message if member ID is not found
		if(!validId)
		{
			cout << "ID number does not exist - please try again." << endl;
		}//END IF

	}while(!validId);//END DO WHILE

	itemCount = 0;

	do
	{
		addMore = true;

		cout << "Please enter an item name: ";
		getline(cin, tempName);

		cout << "Please enter a sale date: " << endl;
		buyMonth = ErrorCheckInt(12, 1, "Month: ");
		buyDay = ErrorCheckInt(31, 1, "Day: ");
		buyYear = ErrorCheckInt(2014, 2013, "Year: ");

		tempCost = ErrorCheckFloat(10000, .01, "Please enter a cost: ");

		tempQuantity = ErrorCheckInt(100 - itemCount, 1, "Please enter a quantity(MAX 100 PER DAY): ");

		itemCount += tempQuantity;

		obj.setName(tempName);
		obj.setNumber(tempId);
		obj.setCost(tempCost);
		obj.setQuantity(tempQuantity);
		obj.setBuyDate(buyMonth, buyDay, buyYear);
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

		if(itemCount == 100)
		{
			cout << "Maximum quantity reached!" << endl;
			addMore = false;
		}
		else if(ErrorCheckChar('Y', 'N', "Would you like to add another? ") == 'N')
		{
			addMore = false;
		}

	}while(addMore);

}
