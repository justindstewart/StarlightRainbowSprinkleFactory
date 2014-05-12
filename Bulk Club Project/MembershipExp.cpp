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
 * FUNCTION MembershipExp
 * _______________________________________________________________________
 *	This function receives a basic vector list and a preferred vector list
 *	and prompts the user for a month to search membership expirations for.
 *	Outputs a list of members whose expiration expires.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 		basicList	: Basic List has to be previously defined
 * 		prefList	: Preferred list has to be previously defined
 *
 * POST-CONDTIONS
 * 		This function will output the membership dues
 ************************************************************************/
void MembershipExp(vector<Basic>& basicList,	// IN - Basic List
				   vector<Preferred>& prefList) // IN - Preferred List
{
	vector<Basic>::iterator basicIter;		//CALC - Basic iterator
	vector<Preferred>::iterator prefIter;	//CALC - Preferred iterator
	int expMonth;							//IN -   Input month

	expMonth = ErrorCheckInt(12, 1, "Please enter a month to search for : ");

	cout << left;
	cout << setw(28) << "NAME";
	cout << setw(12) << "MEMBER ID";
	cout << right;
	cout << setw(15) << "DUES AMT";
	cout << setw(14) << "EXP DATE" << endl;
	cout << setfill('-') << setw(70) << "-" << endl;
	cout << setfill(' ');

	//FOR - Loops through preferred list and outputs each instance
	for(basicIter = basicList.begin(); basicIter != basicList.end(); basicIter++)
	{
		//IF - Checks if current membership is expiring in inputed month
		if(basicIter->getMonth() == expMonth)
		{
			cout << left;
			cout << setw(30) << basicIter->getName();
			cout << setw(10) << basicIter->getNumber();
			cout << right;
			cout << setw(14) << "$60.00";
			cout << setw(8);
			basicIter->displayDate();
			cout << endl;
		}//END IF
	}//END FOR

	//FOR - Loops through preferred list and outputs each instance
	for(prefIter = prefList.begin(); prefIter != prefList.end(); prefIter++)
	{
		//IF - Checks if current membership is expiring in inputed month
		if(prefIter->getMonth() == expMonth)
		{
			cout << left;
			cout << setw(30) << prefIter->getName();
			cout << setw(10) << prefIter->getNumber();
			cout << right;
			cout << setw(14) << "$75.00";
			cout << setw(8);
			prefIter->displayDate();
			cout << endl;
		}//END IF
	}//END FOR
}
