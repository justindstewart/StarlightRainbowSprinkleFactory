/*************************************************************************
 * AUTHOR		: Andrea Velazquez & Justin Stewart
 * STUDENT ID	: 994759
 * FINAL PROJECT: Super Warehouse Store
 * CLASS 		: CS1C
 * SECTION		: TTH: 8:30a - 9:50a
 * DUE DATE		: May 13th, 2014
 ************************************************************************/
//hi
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
	cout << "Name: " << name << endl;
	cout << "Id: "	<< memNumber << endl;
	cout << "Status: ";
	if(memType == 0)
	{
		cout << "Basic";
	}
	else
	{
		cout << "Preferred";
	}
	cout << endl;
	cout << "Total Spent: " << totalSpent << endl;
	cout << "Exp. Date: ";
	expDate.PrintDate();
	cout << endl;
}

bool Basic::operator==(const Basic&obj) const
{
	return(memNumber==obj.memNumber);
}

bool Basic::operator!=(const Basic&obj) const
{
	return(memNumber!=obj.memNumber);
}

void Basic::findAndDelete(vector<Basic> &basicVector)
{
	vector<Basic>::iterator index;
	Basic obj;
	index = find(basicVector.begin(), basicVector.end(), *this);
	cout << "Found item: " << index->memNumber << endl;
	index=basicVector.erase(index);
	cout << "\nNumber of items in the vector = " << basicVector.size() << endl;
	cout << "Delete complete" << endl;
}

void Basic::print(vector<Basic> basicVector)
{
	vector<Basic>::iterator index;

	for(index = basicVector.begin(); index != basicVector.end(); index++)
	{
		index->display();
	}
}
