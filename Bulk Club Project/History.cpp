/*************************************************************************
 * AUTHOR		: Andrea Velazquez & Justin Stewart
 * STUDENT ID	: 994759
 * FINAL PROJECT: Super Warehouse Store
 * CLASS 		: CS1C
 * SECTION		: TTH: 8:30a - 9:50a
 * DUE DATE		: May 13th, 2014
 ************************************************************************/

#include "header.h"

History::History() : itemName("SomeItem"), memNumber(0), cost(0),
				 quantity(0)
{
	//Empty Block
}//End Default Constructor

History::History(string newName, int newNumber, float newCost,
				 int newQuantity, int newMonth, int newDay, int newYear) :
				 buyDate(newMonth, newDay, newYear)
{
	itemName = newName;
	memNumber = newNumber;
	cost = newCost;
	quantity = newQuantity;

}//End Non-Default Constructor

History::~History()
{

}//End Destructor

void History::setName(string newName)
{
	itemName = newName;
}//End setName

void History::setNumber(int newNumber)
{
	memNumber = newNumber;
}//End setNumber

void History::setCost(float newCost)
{
	cost = newCost;
}//End setCost

void History::setQuantity(int newQuantity)
{
	quantity = newQuantity;
}//End setQuantity

void History::setBuyDate(int newMonth, int newDay, int newYear)
{
	buyDate.SetDate(newMonth, newDay, newYear);
}
string History::getName() const
{
	return itemName;
}//End getName

int History::getNumber() const
{
	return memNumber;
}//End getNumber

float History::getCost() const
{
	return cost;
}//End getCost

int History::getQuantity() const
{
	return quantity;
}//End getQuantity

void History::display(void) const
{
	cout << "Item Name          : " << itemName << endl;
	cout << "Member Id          : " << memNumber << endl;
	cout << "Cost               : " << cost << endl;
	cout << "Purchase Date      : ";
	buyDate.PrintDate();
	cout << endl;
	cout << "Quantity Purchased : " << quantity << endl << endl;
}//End display

void History::print(vector<History> histVector)
{
	vector<History>::iterator index;

	for(index = histVector.begin(); index != histVector.end(); index++)
	{
		index->display();
	}
}//End print

bool History::operator==(const History&obj) const
{
	return (buyDate== obj.buyDate);
}

bool History::operator!=(const History&obj) const
{
	return (buyDate!=obj.buyDate);
}


// PRINT SALES REPORT BY DATE
void History::PrintSalesReportByDate (Date searchDateF,
		                              vector<History> histVector)
	{
	bool found;
	found = false;

	vector<History>::iterator index;

	cout << "\nPrinting sales report for ";
	searchDateF.PrintDate();
	cout << endl;

	// SORT VECTOR BY DATE
//	sort(histVector.begin(), histVector.end(), buyDate);

// OUTPUT THE VECTOR TO SEE IF THE SORT WORKED

// SEARCH THING BY DATE (Binary search? sort first)

//	find(histVector.back(), histVector.end(), searchDateF);

	// PRINT OUT INFO ON ITEMS BOUGHT ON THIS DATE (output file or console?)
	cout << "\nItems purchased on ";
	searchDateF.PrintDate();
	cout << ": " << endl;
	cout << endl;
	cout << left << setw(30) << "ITEM NAME" << setw(15) << "QUANTITY SOLD";
	cout << endl;
	cout << "----------------------------- " << "--------------";
	cout << right << endl;
	// output items and quantities


	for(index = histVector.begin(); index != histVector.end(); index++)
	{
	if (searchDateF == index->buyDate)
		{

			cout << left << setw(30) << index->itemName << setw(30)
				 << index->quantity << endl;

// TEST IF DATE IS CORRECT
//index->buyDate.PrintDate();
//			cout << endl;
		}
	}

	// while (date found && within vector range)

	cout << "\nThese people shopped here on ";
	searchDateF.PrintDate();
	cout << ": " << endl << endl;

	cout << left << setw(30) << "MEMBER NAME" << setw(15) << "MEMBER NUMBER";
	cout << endl;
	cout << "----------------------------- " << "--------------";
	cout << endl;
	for(index = histVector.begin(); index != histVector.end(); index++)
	{
	if (searchDateF == index->buyDate)
		{

		// I NEED TO FIND A WAY TO LINK THE NAMES WITH THE NUMBERS
		cout << left << setw(30) << "Bulk Club Member" << setw(30)
			 << index->memNumber << endl;

// TEST IF DATE IS CORRECT
//index->buyDate.PrintDate();
//cout << endl<< endl;

		}
	}

	// will need a way to tally/keep track of basic and preferred people

	cout << "\nThere were ";
	// number of preferred members
	cout << " preferred members and ";
	// number of basic members
	cout << " basic members shopping on this date.\n";

	// INCLUDE NAMES OF MEMBERS THAT SHOPPED THAT DAY
	// INCLUDE NUMBER OF PREFERRED MEMBERS AND BASIC MEMBERS
}
