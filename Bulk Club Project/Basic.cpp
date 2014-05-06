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

float Basic::getAmtSpent() const
{
	return totalSpent;
}//End getAmtSpent

void Basic::display(void) const
{
	cout << setw(30) << name;
	cout << setw(15) << memNumber;
	cout << setw(15);
	if(memType == 0)
	{
		cout << "Basic";
	}
	else
	{
		cout << "Preferred";
	}
	cout << "$" << setw(14) << totalSpent;
	cout << left;
	expDate.PrintDate();
}

bool Basic::operator==(const Basic& obj) const
{
	return(memNumber==obj.memNumber);
}

bool Basic::operator!=(const Basic& obj) const
{
	return(memNumber!=obj.memNumber);
}

void Basic::findAndDelete(vector<Basic> &basicVector, int tempId)
{
	vector<Basic>::iterator index;
	Basic obj;

	for(index = basicVector.begin(); index != basicVector.end(); index++)
	{
		if(tempId == index->memNumber)
		{
			cout << "Found item: " << index->memNumber;
			basicVector.erase(index);
		}
	}
//	Basic obj;
//	index = find(basicVector.begin(), basicVector.end());
//	if(index != basicVector.end())
//	{
//		cout << "Found item "  << endl;
//		index=basicVector.erase(index);
//		cout << "\nNumber of items in the vector = " << basicVector.size() << endl;
//		cout << "Delete complete" << endl;
//	}
}

void Basic::print(vector<Basic> basicVector)
{
	vector<Basic>::iterator index;

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

	for(index = basicVector.begin(); index != basicVector.end(); index++)
	{
		cout << endl;
		index->display();
	}
}
