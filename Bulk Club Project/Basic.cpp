/*************************************************************************
 * AUTHOR		: Andrea Velazquez & Justin Stewart
 * STUDENT ID	: 994759
 * FINAL PROJECT: Super Warehouse Store
 * CLASS 		: CS1C
 * SECTION		: TTH: 8:30a - 9:50a
 * DUE DATE		: May 13th, 2014
 ************************************************************************/

#include "header.h"

Basic::Basic() : name("Pat Doe"), memNumber(11111), memType(0),
				 totalSpent(0)
{
	//Empty Block
}//End Default Constructor

Basic::Basic(string newName, int newNumber, bool newMemType,
			 float newAmtSpent, int newMonth, int newDay, int newYear) :
			 expDate(newMonth, newDay, newYear)
{
	name = newName;
	memNumber = newNumber;
	memType = newMemType;
	totalSpent = newAmtSpent;
}//End Non-Default Constructor

Basic::~Basic()
{

}//End Destructor

void Basic::setName(string newName)
{
	name = newName;
}//End setName

void Basic::setNumber(int newNumber)
{
	memNumber = newNumber;
}//End setNumber

void Basic::setMemType(bool newMemType)
{
	memType = newMemType;
}//End setMemType

void Basic::setAmtSpent(float newAmtSpent)
{
	totalSpent = newAmtSpent;
}//End setAmtSpent

void Basic::setExp(int newMonth, int newDay, int newYear)
{
	expDate.SetDate(newMonth, newDay, newYear);
}
string Basic::getName() const
{
	return name;
}//End getName

int Basic::getNumber() const
{
	return memNumber;
}//End getNumber

bool Basic::getType() const
{
	return memType;
}//End getType

bool Basic::checkStatus() const
{
	bool upgrade;			//CALC - Boolean
	upgrade = false;

	//IF - Checks to see if the rebate amount is more then the cost of the
	//		upgrade.
	if((totalSpent * .05) > 15)
	{
		upgrade = true;
	}

	return upgrade;
}//End checkUpgrade

float Basic::getAmtSpent() const
{
	return totalSpent;
}//End getAmtSpent

void Basic::display(void) const
{
	cout << setw(30) << name;
	cout << setw(15) << memNumber;
	cout << setw(15);
	//IF - Checks for member type and outputs
	if(memType == 0)
	{
		cout << "Basic";
	}
	else
	{
		cout << "Preferred";
	}//End if
	cout << "$" << setw(14) << totalSpent;
	cout << left;
	expDate.PrintDate();
}//End display

bool Basic::operator==(const Basic& obj) const
{
	return(memNumber==obj.memNumber);
}//End overload == operator

bool Basic::operator!=(const Basic& obj) const
{
	return(memNumber!=obj.memNumber);
}//End overload != operator

bool Basic::operator<(const Basic& obj) const
{
	return(memNumber < obj.memNumber);
}//End overload < operator

void Basic::findAndDelete(vector<Basic> &basicVector, int tempId)
{
	vector<Basic>::iterator index;		//CALC - Iterator
	bool found;							//CALC - Boolean

	found = false;
	index = basicVector.begin();
	//WHILE - Loops through vector until member is found
	while(!found && index != basicVector.end())
	{
		//IF - Checks if the passed ID is identical to the current index
		if(tempId == index->memNumber)
		{
			cout << "Deleting member number: " << tempId;
			basicVector.erase(index);
			found = true;
		}//End if

		index++;
	}//End while
}

void Basic::print(vector<Basic> basicVector)
{
	vector<Basic>::iterator index;	//CALC - Iterator

	cout << left;
	cout << endl;
	cout << setw(30) << "MEMBER NAME";
	cout << setw(15) << "MEMBER NUMBER";
	cout << setw(15) << "MEMBER STATUS";
	cout << setw(15) << "TOTAL SPENT";
	cout << setw(15) << "EXP DATE";
	cout << endl;
	cout << setfill('-') << setw(90) << "-" << endl;
	cout << setfill(' ');

	//FOR - Loops through vector list and displays each element
	for(index = basicVector.begin(); index != basicVector.end(); index++)
	{
		cout << endl;
		index->display();
	}
}
