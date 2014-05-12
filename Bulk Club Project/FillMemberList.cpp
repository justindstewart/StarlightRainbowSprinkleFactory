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
 *	This function receives a basic members vector list and a
 *	 preferred members vector list. It then uses the file name to populate
 *	 these lists. -returns nothing
 * _______________________________________________________________________
 * PRE-CONDITIONS
 * 		fileName	: File name has to be previously defined
 * 		basicList	: Basic member vector has to be previously defined
 * 		prefList	: Preferred member vector has to be previously defined
 *
 * POST-CONDTIONS
 * 		This function returns nothing
 ************************************************************************/
void FillMemberList(vector<Basic>& basicList,	 // IN - Basic list
					vector<Preferred> & prefList)// IN - Preferred list
{
	ifstream inFile;	//IN	- Input file variable
	Basic tempBasic;	//IN	- Temporary basic list
	Preferred tempPref;	//IN	- Temporary preferred list
	string tempName;	//IN 	- Temporary name variable
	int    tempId;		//IN 	- Temporary id variable
	string tempStatus;	//IN	- Temporary status variable
	string tempMo;		//IN	- Temporary month variable
	string tempDa;		//IN	- Temporary day variable
	string tempYe;		//IN	- Temporary year variable
	int monthExp;		//CALC	- Month variable post string conversion
	int dayExp;			//CALC	- Day variable post string conversion
	int yearExp;		//CALC  - Year variable post string conversion

	inFile.open("warehouse shoppers.txt");
	//WHILE - Loops through file until no longer in file boundary
	while(getline(inFile, tempName))
	{
		inFile >> tempId;
		inFile.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(inFile, tempStatus);
		getline(inFile, tempMo, '/');
		getline(inFile, tempDa, '/');
		getline(inFile, tempYe);
		monthExp = atoi(tempMo.c_str());
		dayExp = atoi(tempDa.c_str());
		yearExp = atoi(tempYe.c_str());

		//IF - Checks if status is preferred or basic, inputs into correct
		//		list.
		if(tempStatus == "Preferred")
		{
			tempPref.setName(tempName);
			tempPref.setNumber(tempId);
			tempPref.setMemType(1);
			tempPref.setExp(monthExp, dayExp, yearExp);
			prefList.push_back(tempPref);
		}
		else if(tempStatus == "Basic")
		{
			tempBasic.setName(tempName);
			tempBasic.setNumber(tempId);
			tempBasic.setMemType(0);
			tempBasic.setExp(monthExp, dayExp, yearExp);
			basicList.push_back(tempBasic);
		}//END IF
	}//END WHILE

	inFile.close();
}
