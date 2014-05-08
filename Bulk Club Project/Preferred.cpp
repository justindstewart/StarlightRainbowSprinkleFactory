/*************************************************************************
 * AUTHOR		: Andrea Velazquez & Justin Stewart
 * STUDENT ID	: 994759
 * FINAL PROJECT: Super Warehouse Store
 * CLASS 		: CS1C
 * SECTION		: TTH: 8:30a - 9:50a
 * DUE DATE		: May 13th, 2014
 ************************************************************************/

#include "header.h"

Preferred::Preferred () : rebateAmount(0.000)
{
	//Empty Block
}//End Constructor

Preferred::Preferred(string newName, int newNumber, bool newMemType,
					 float totalAmountSpent, float newRebateAmount,
					 int newMonth, int newDay, int newYear) :
					 Basic(newName, newNumber, newMemType, totalAmountSpent,
						   newMonth, newDay, newYear)
{
	rebateAmount = newRebateAmount;
}//End Non-Default Constructor

Preferred::~Preferred()
{

}//End Deconstructor

void Preferred::calculateRebate(float totalAmountSpent)
{
	rebateAmount = (totalAmountSpent * .05);
}//End calculateRebate

void Preferred::setRebate(float newRebateAmt)
{
	rebateAmount = newRebateAmt;
}//End setRebate

float Preferred::getRebate() const
{
	return rebateAmount;
}//End getRebate

bool Preferred::checkStatus() const
{
	bool downgrade;			//CALC - Boolean
	downgrade = false;

	if(rebateAmount < 10)
	{
		downgrade = true;
	}

	return downgrade;
}

void Preferred::display() const
{
	Basic::display();
	cout << setw(5) << " ";
	cout << "$" << setw(15) << rebateAmount;

}//End display

bool Preferred::operator==(const Preferred& obj) const
{
	return(getNumber()==obj.getNumber());
}//End overload == operator

bool Preferred::operator!=(const Preferred& obj) const
{
	return(getNumber()!=obj.getNumber());
}//End overload != operator

bool Preferred::operator<(const Preferred& obj) const
{
	return(getNumber() < obj.getNumber());
}

void Preferred::findAndDelete(vector<Preferred>& prefVector, int tempId)
{
	vector<Preferred>::iterator index;	//CALC - Iterator
	bool found;							//CALC - Boolean

	found = false;
	index = prefVector.begin();
	//WHILE - Loops through vector until member is found
	while(!found && index != prefVector.end())
	{
		//IF - Checks if the passed ID is identical to the current index
		if(tempId == index->getNumber())
		{
			cout << "Deleting member number: " << tempId;
			prefVector.erase(index);
			found = true;
		}//End if

		index++;
	}//End while

}//End findAndDelete

void Preferred::print(vector<Preferred> prefVector)
{
	vector<Preferred>::iterator index;	//CALC - Iterator

	cout << left;
	cout << fixed << setprecision(2);
	cout << endl;
	cout << setw(30) << "MEMBER NAME";
	cout << setw(15) << "MEMBER NUMBER";
	cout << setw(15) << "MEMBER STATUS";
	cout << setw(15) << "TOTAL SPENT";
	cout << setw(15) << "EXP DATE";
	cout << setw(15) << "REBATE AMOUNT";
	cout << endl;
	cout << setfill('-') << setw(105) << "-" << endl;
	cout << setfill(' ');

	//FOR - Loops through vector list and displays each element
	for(index = prefVector.begin(); index != prefVector.end(); index++)
	{
		cout << endl;
		index->display();
	}
}
