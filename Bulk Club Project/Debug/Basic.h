/*************************************************************************
 * AUTHOR		: Andrea Velazquez & Justin Stewart
 * STUDENT ID	: 994759
 * FINAL PROJECT: Super Warehouse Store
 * CLASS 		: CS1C
 * SECTION		: TTH: 8:30a - 9:50a
 * DUE DATE		: May 13th, 2014
 ************************************************************************/

#ifndef BASIC_H_
#define BASIC_H_

#include <string>
#include "Date.h"
using namespace std;

class Basic
{
	public:
		Basic();
			//Constructor
		Basic(string newName, int newNumber, bool newMemType,
			  float newAmtSpent, int newMonth, int newDay, int newYear);
			//Non-Default Constructor
		~Basic();
			//Destructor
		void setName(string newName);
			//Function to set the name of the member
		void setNumber(int newNumber);
			//Function to set the member number
		void setMemType(bool newMemType);
			//Function to set the member type
		void setAmtSpent(float newAmtSpent);
			//Function to manually set amount spent
		void setExp(int newMonth, int newDay, int newYear);
			//Function to manually set the expiration date
		string getName() const;
			//Function to get the member name
		int getNumber() const;
			//Function to get the member number
		bool getType() const;
			//Function to get the member type
		float getAmtSpent() const;
			//Function to get the amount spent
		void display(void) const;

		bool operator==(const Basic&obj) const;

		bool operator!=(const Basic&obj) const;

//		void findAndDelete(vector<Basic>& basicVector);

		void print(vector<Basic> myVector);
			//Function to print the data

	private:
		string  name;		//Variable to hold the member name
		int 	memNumber;	//Variable to hold the member number
		bool    memType; 	//Boolean to hold the membership type
		float	totalSpent;	//Variable to hold thet total spent
		Date 	expDate;	//Variable to hold the expiration date
};

#endif /* HEADER_H_ */
