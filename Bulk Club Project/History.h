/*************************************************************************
 * AUTHOR		: Andrea Velazquez & Justin Stewart
 * STUDENT ID	: 994759
 * FINAL PROJECT: Super Warehouse Store
 * CLASS 		: CS1C
 * SECTION		: TTH: 8:30a - 9:50a
 * DUE DATE		: May 13th, 2014
 ************************************************************************/

#ifndef HISTORY_H_
#define HISTORY_H_

#include <string>
#include "Date.h"
using namespace std;

class History
{
	public:
		History();
			//Constructor
		History(string newName, int newNumber, float newCost,
				int newQuantity, int newMonth, int newDay, int newYear);
			//Non-Default Constructor
		~History();
			//Destructor
		void setName(string newName);
			//Function to set the item name
		void setNumber(int newNumber);
			//Function to set the member number
		void setCost(float newCost);
			//Function to set the cost
		void setQuantity(int newQuantity);
			//Function to set the new quantity
		void setBuyDate(int newMonth, int newDay, int newYear);
			//Function to set the purchase date
		int getMonth() const;
			//Function to get the month purchased
		int getDay() const;
			//Function to get the day purchased
		int getYear() const;
			//Function to get the year purchased
		float calculateTotal(vector<History> histVector, int memberId) const;
			//Function to calculate the total
		string getName() const;
			//Function to get the item name
		int getNumber() const;
			//Function to get the member number
		float getCost() const;
			//Function to get the cost of the item
		int getQuantity() const;
			//Function to get the quantity of the items purchased
		void display(void) const;
			//Function to display the current purchase stats
		void print(vector<History> myVector);
			//Function to print the data
		bool operator==(const History& obj) const;

		bool operator!=(const History& obj) const;

		bool operator<(const History& obj) const;
		// PRINT SALES REPORT BY DATE
		void PrintSalesReportByDate (Date searchDateF,
				                     vector<History> histVector,
				                     vector<Basic> basicVector,
				                     vector<Preferred> preferredVector,
				                     Basic basicObj,
				                     Preferred prefObj);
				                     
        void PrintTotalPurchases (vector<History> histVector,
        						  vector<Basic> basicVector,
        						  vector<Preferred> preferredVector,
        						  Basic basicObj,
        						  Preferred prefObj);

        void PrintPurchasesByMemberName (string searchName,
        								 vector<History> histVector,
        								 vector<Basic> basicVector,
        								 vector<Preferred> preferredVector);
		void PrintPurchasesByMember(int searchIdF,
									vector<History> histVector,
									vector<Basic> basicVector,
									vector<Preferred> preferredVector);

		void PrintQuantityOfItem (string searchItem,
					  	  	  	  vector <History> histVector,
					  	  	  	  History histObj);

		void PrintQuantityOfAllItems (vector <History> histVector);

	private:
		string  itemName;	//Variable to hold the item name
		int 	memNumber;	//Variable to hold the member number
		float	cost;		//Variable to hold the total spent
		int 	quantity;	//Variable to hold the quantity purchased
		Date 	buyDate;	//Variable to hold the purchase date
};

#endif /* HISTORY_H_ */
