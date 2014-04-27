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
 * FUNCTION FillHistoryList
 * _______________________________________________________________________
 *	This function receives a file name and a history vector. It then fills
 *	 the vector using the file specified by the program. -returns nothing.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 		fileName	: File name has to be previously defined
 * 		histList	: History vector has to be previously defined
 *
 * POST-CONDTIONS
 * 		This function will output the class heading.
 ************************************************************************/
void FillHistoryList(string fileName,			 // IN - File name
					vector<History>& histList)   // IN - History list
{
	ifstream inFile;	//IN	- Input file variable
	History tempHist;	//IN	- Temporary history vector
	string tempName;	//IN 	- Temporary name variable
	int    tempId;		//IN 	- Temporary id variable
	string tempMo;		//IN	- Temporary month variable
	string tempDa;		//IN	- Temporary day variable
	string tempYe;		//IN	- Temporary year variable
	int monthExp;		//CALC	- Month variable post string conversion
	int dayExp;			//CALC	- Day variable post string conversion
	int yearExp;		//CALC  - Year variable post string conversion
	float tempCost;		//IN	- Temporary cost variable
	int	tempQuantity;	//IN	- Temporary quantity variable

	inFile.open(fileName.c_str());

	//WHILE - Loops through file and fills vector list until end of file.
	while(getline(inFile, tempMo, '/'))
	{
		getline(inFile, tempDa, '/');
		getline(inFile, tempYe);
		monthExp = atoi(tempMo.c_str());
		dayExp = atoi(tempDa.c_str());
		yearExp = atoi(tempYe.c_str());
		inFile >> tempId;
		inFile.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(inFile, tempName);
		inFile >> tempCost;
		inFile >> tempQuantity;
		inFile.ignore(numeric_limits<streamsize>::max(), '\n');

		tempHist.setName(tempName);
		tempHist.setNumber(tempId);
		tempHist.setCost(tempCost);
		tempHist.setQuantity(tempQuantity);
		tempHist.setBuyDate(monthExp, dayExp, yearExp);
		histList.push_back(tempHist);
	}

	inFile.close();
}
