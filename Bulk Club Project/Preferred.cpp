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

void Preferred::display() const
{
	Basic::display();
	cout << setw(5) << " ";
	cout << "$" << setw(15) << rebateAmount;

}

bool Preferred::operator==(const Preferred& obj) const
{
	return(getNumber()==obj.getNumber());
}

bool Preferred::operator!=(const Preferred& obj) const
{
	return(getNumber()!=obj.getNumber());
}


void Preferred::findAndDelete(vector<Preferred>& prefVector, int tempId)
{
	vector<Preferred>::iterator index;
	Preferred obj;

	for(index = prefVector.begin(); index != prefVector.end(); index++)
	{
		if(tempId == index->getNumber())
		{
			cout << "Found item: " << index->getNumber();
			prefVector.erase(index);
		}
	}
//	vector<Preferred>::iterator index;
//	Preferred obj;
//	index = find(prefVector.begin(), prefVector.end());
//	if(index != prefVector.end())
//	{
//		cout << "Found item " << endl;
//		index=prefVector.erase(index);
//		cout << "\nNumber of items in the vector = " << prefVector.size() << endl;
//		cout << "Delete complete" << endl;
//	}
}

void Preferred::print(vector<Preferred> prefVector)
{
	vector<Preferred>::iterator index;

	cout << left;
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


	for(index = prefVector.begin(); index != prefVector.end(); index++)
	{
		cout << endl;
		index->display();
	}
}
