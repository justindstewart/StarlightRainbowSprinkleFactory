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
		Basic(int newNumber);
		virtual ~Basic();
			//Destructor
		void setName(string newName);
			//Function to set the name of the member
		void setNumber(int newNumber);
			//Function to set the member number
		void setMemType(bool newMemType);
			//Function to set the member type
		void setAmtSpent(float newAmtSpent);
			//Function to manually set amount spent
		void increaseAmtSpent(float newAmt);
			//Function to manually increase the amount spent
		void setExp(int newMonth, int newDay, int newYear);
			//Function to manually set the expiration date
		string getName() const;
			//Function to get the member name
		int getNumber() const;
			//Function to get the member number
		bool getType() const;
			//Function to get the member type
		virtual bool checkStatus() const;
			//Function to check if rebate amount would be more then the
			//cost of the difference of price of the preferred status
		float getAmtSpent() const;
			//Function to get the amount spent
		void display(void) const;
			//Function to display the details of the object
		void displayDate() const;
			//Function to display the date
		int getMonth() const;
			//Function to return the month
		int getDay() const;
			//Function to return the day
		int getYear() const;
			//Function to return the year
		friend bool operator==(const Basic& obj1, const Basic& obj2);
			//Function to overload the == operator
		bool operator!=(const Basic& obj) const;
			//Function to overload the != operator
		bool operator<(const Basic& obj) const;
		 	//Function to overload the < operator
		void findAndDelete(vector<Basic>& basicVector, int tempId);
			//Function to find a delete an instance
		virtual void print(vector<Basic> myVector);
			//Function to print the data

	private:
		string  name;		//Variable to hold the member name
		int 	memNumber;	//Variable to hold the member number
		bool    memType; 	//Boolean to hold the membership type
		float	totalSpent;	//Variable to hold the total spent
		Date 	expDate;	//Variable to hold the expiration date
};

#endif /* HEADER_H_ */
