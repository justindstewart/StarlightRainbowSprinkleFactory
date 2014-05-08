/*************************************************************************
 * AUTHOR		: Andrea Velazquez & Justin Stewart
 * STUDENT ID	: 994759
 * FINAL PROJECT: Super Warehouse Store
 * CLASS 		: CS1C
 * SECTION		: TTH: 8:30a - 9:50a
 * DUE DATE		: May 13th, 2014
 ************************************************************************/

#ifndef PREFERRED_H_
#define PREFERRED_H_

#include "Basic.h"

class Preferred: public Basic
{
public:
	Preferred();
		//Constructor
	Preferred(string newName, int newNumber, bool newMemType,
			  float totalAmountSpent, float newRebateAmount, int newMonth,
			  int newDay, int newYear);
		//Non-Default Constructor
	~Preferred();
		//Destructor
	void calculateRebate(float totalAmountSpent);
		//Function to calculate the rebate owed
	void setRebate(float newRebateAmt);
		//Function to manually set a rebate amount
	float getRebate() const;
		//Function to return the rebate amount to the calling function.
	bool checkStatus() const;
		//Function to check if member did not have a large enough rebate
		//amount to warrant preferred status.
	void display(void) const;
		//Function to display the preferred member data
	bool operator==(const Preferred& obj) const;
		//Function to overload the == operator
	bool operator!=(const Preferred& obj) const;
		//Function to overload the != operator
	void findAndDelete(vector<Preferred>& prefVector, int tempId);
		//Function to find a delete an instance
	void print(vector<Preferred> prefVector);
		//Function to loop through the vector with display function
private:
	float rebateAmount;		//Variable to hold the owed rebate amount
};

#endif /* PREFERRED_H_ */
