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
 * FUNCTION PrintRebates
 * _______________________________________________________________________
 *	This function receives a preferred vector list and outputs the rebate
 *	amounts of each member sorted by membership number.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 		prefList	: Assignment Name has to be previously defined
 *
 * POST-CONDTIONS
 * 		This function will output preferred member rebates.
 ************************************************************************/
void PrintRebates(vector<Preferred> prefList)// IN - Preferred List
{
	vector<Preferred>::iterator prefIter;	//CALC - Preferred iterator

	sort(prefList.begin(), prefList.end());

	cout << left;
	cout << setw(28) << "NAME";
	cout << setw(12) << "MEMBER ID";
	cout << right;
	cout << setw(15) << "REBATE AMT" << endl;
	cout << setfill('-') << setw(55) << "-" << endl;
	cout << setfill(' ');

	//FOR - Loops through preferred list and outputs each instance
	for(prefIter = prefList.begin(); prefIter != prefList.end(); prefIter++)
	{
		cout << left << fixed << setprecision(2);
		cout << setw(30) << prefIter->getName();
		cout << setw(10) << prefIter->getNumber();
		cout << right;
		cout << setw(15) << prefIter->getRebate() << endl;
	}//END FOR
}
