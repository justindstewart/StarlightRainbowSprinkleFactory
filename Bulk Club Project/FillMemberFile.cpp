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
 * FUNCTION FillMemberList
 * _______________________________________________________________________
 *	This function receives a basic members vector list and a preferred
 *	members vector list. At the end of the program it then populates the
 *	file for future use. - returns nothing
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 		basicList	: Basic member vector has to be previously defined
 * 		prefList	: Preferred member vector has to be previously defined
 *
 * POST-CONDTIONS
 * 		This function returns nothing
 ************************************************************************/
void FillMemberFile(vector<Basic>& basicList,	// IN - Basic list
					vector<Preferred>& prefList)// IN - Preferred list
{
	ofstream oFile;		//IN	- Input file variable
	vector<Basic>::iterator basicIter;
	vector<Preferred>::iterator prefIter;

	sort(basicList.begin(), basicList.end());
	sort(prefList.begin(), prefList.end());

	oFile.open("warehouse shoppers.txt");

	for(basicIter = basicList.begin(); basicIter != basicList.end(); basicIter++)
	{
		oFile << basicIter->getName() << endl;
		oFile << basicIter->getNumber() << endl;
		oFile << "Basic" << endl;
		oFile << basicIter->getMonth() << "/" << basicIter->getDay() << "/" << basicIter->getYear() << endl;
	}

	for(prefIter = prefList.begin(); prefIter != prefList.end(); prefIter++)
	{
		oFile << prefIter->getName() << endl;
		oFile << prefIter->getNumber() << endl;
		oFile << "Preferred" << endl;
		oFile << prefIter->getMonth() << "/" << prefIter->getDay() << "/" << prefIter->getYear() << endl;
	}

	oFile.close();
}
