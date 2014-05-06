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
 * FUNCTION AddMember
 * _______________________________________________________________________
 *	This function receives  a basic members vector list and a preferred
 *   members vector list. It then prompts the user for some basic info
 *   and adds a member to the appropriate list.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 		basicList	: Basic member vector has to be previously defined
 * 		prefList	: Preferred member vector has to be previously defined
 *
 * POST-CONDTIONS
 * 		This function returns nothing
 ************************************************************************/
void AddMember(vector<Basic>& basicList,	 // IN - Basic list
			   vector<Preferred>& prefList)// IN - Preferred list
{
	Basic tempBasic;	//IN	- Temporary basic list
	Preferred tempPref;	//IN	- Temporary preferred list
	string tempName;	//IN 	- Temporary name variable
	int    tempId;		//IN 	- Temporary id variable
	char   tempStatus;	//IN	- Temporary status variable
	int monthExp;		//CALC	- Month variable post string conversion
	int dayExp;			//CALC	- Day variable post string conversion
	int yearExp;		//CALC  - Year variable post string conversion

	tempId = ErrorCheckInt(99999, 10000, "Please enter a 5 digit ID: ");
	tempStatus = ErrorCheckChar('B', 'P', "Basic or Preferred? (B/P): ");
	cout << "Please enter a name: ";
	getline(cin, tempName);

	cout << "Please enter an expiration date: " << endl;
	cout << "Month: ";
	cin >> monthExp;
	cout << "Day: ";
	cin >> dayExp;
	cout << "Year: ";
	cin >> yearExp;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	//IF - Checks if status is preferred or basic, inputs into correct
	//		list.
	if(tempStatus == 'P')
	{
		tempPref.setName(tempName);
		tempPref.setNumber(tempId);
		tempPref.setMemType(1);
		tempPref.setExp(monthExp, dayExp, yearExp);
		tempPref.setAmtSpent(0.0);
		tempPref.setRebate(0.0);
		prefList.push_back(tempPref);
	}
	else if(tempStatus == 'B')
	{
		tempBasic.setName(tempName);
		tempBasic.setNumber(tempId);
		tempBasic.setMemType(0);
		tempBasic.setExp(monthExp, dayExp, yearExp);
		tempBasic.setAmtSpent(0.0);
		basicList.push_back(tempBasic);
	}

}
