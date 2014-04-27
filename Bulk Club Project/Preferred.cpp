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
	cout << "Rebate Amount: " << rebateAmount << endl;
}

void Preferred::print(vector<Preferred> prefVector)
{
	vector<Preferred>::iterator index;

	for(index = prefVector.begin(); index != prefVector.end(); index++)
	{
		index->display();
	}
}
