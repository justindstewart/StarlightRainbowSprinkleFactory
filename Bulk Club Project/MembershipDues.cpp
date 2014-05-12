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
 * FUNCTION MembershipDues
 * _______________________________________________________________________
 *	This function receives a basic vector list and a preferred vector list
 *	and outputs the membership dues of each member sorted by membership
 *	name.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 		basicList	: Basic List has to be previously defined
 * 		prefList	: Preferred list has to be previously defined
 *
 * POST-CONDTIONS
 * 		This function will output the membership dues
 ************************************************************************/
void MembershipDues(vector<Basic> basicList,	// IN - Basic List
				    vector<Preferred> prefList)	// IN - Preferred List
{
	vector<Basic>::iterator basicIter;		//CALC - Basic iterator
	vector<Preferred>::iterator prefIter;	//CALC - Preferred iterator

	sort(prefList.begin(), prefList.end(), CompareNamesPref);
	sort(basicList.begin(), basicList.end(), CompareNamesBasic);

	cout << left;
	cout << setw(28) << "NAME";
	cout << setw(12) << "MEMBER ID";
	cout << right;
	cout << setw(15) << "DUES" << endl;
	cout << setfill('-') << setw(55) << "-" << endl;
	cout << setfill(' ');

	//FOR - Loops through preferred list and outputs each instance
	for(basicIter = basicList.begin(); basicIter != basicList.end(); basicIter++)
	{
		cout << left << fixed << setprecision(2);
		cout << setw(30) << basicIter->getName();
		cout << setw(10) << basicIter->getNumber();
		cout << right;
		cout << setw(15) << "$60.00" << endl;
	}//END FOR

	//FOR - Loops through preferred list and outputs each instance
	for(prefIter = prefList.begin(); prefIter != prefList.end(); prefIter++)
	{
		cout << left << fixed << setprecision(2);
		cout << setw(30) << prefIter->getName();
		cout << setw(10) << prefIter->getNumber();
		cout << right;
		cout << setw(15) << "$75.00" << endl;
	}//END FOR
}
