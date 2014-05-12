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
 * FUNCTION FillHistoryFile
 * _______________________________________________________________________
 *	This function receives a file name and a history vector. It then fills
 *	 the file using the file specified by the program. -returns nothing.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 		fileName	: File name has to be previously defined
 * 		histList	: History vector has to be previously defined
 *
 * POST-CONDTIONS
 * 		This function will output the class heading.
 ************************************************************************/
void FillHistoryFile(vector<History>& histList)   // IN - History list
{
	ofstream oFile;						//IN - Input file variable
	vector<History>::iterator histIter;	//IN - History iterator

	oFile.open("purchase history.txt");

	//FOR - Loops through history list and outputs the data to a file
	for(histIter = histList.begin(); histIter != histList.end(); histIter++)
	{
		oFile << histIter->getMonth() << "/" << histIter->getDay() << "/" << histIter->getYear() << endl;
		oFile << histIter->getNumber() << endl;
		oFile << histIter->getName() << endl;
		oFile << histIter->getCost() << " " << histIter->getQuantity() << endl;
	}

	oFile.close();
}
