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
		                              vector<History> histVector,
		                              vector<Basic> basicVector,
		                              vector<Preferred> preferredVector,
		                              Basic basicObj,
		                              Preferred prefObj)
	{
	bool found;
	found = false;

	int preferredCount;
	int basicCount;

	preferredCount = 0;
	basicCount = 0;

	vector<History>::iterator index;

	for(index = histVector.begin(); index != histVector.end(); index++)
	{
	if (searchDateF == index->buyDate)
		{

			found = true;
		}
	}

	if(found)
	{
	cout << "\nPrinting sales report for ";
	searchDateF.PrintDate();
	cout << endl;

// SORT VECTOR BY DATE
//	sort(histVector.begin(), histVector.end());

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
		}
	}

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
			vector<Basic>::iterator count;
			for(count = basicVector.begin(); count != basicVector.end(); count++)
			{
				if(index->memNumber == count->getNumber())
				{
					cout << left << setw(30) << count->getName()<< setw(30)
								 << index->memNumber;
					basicCount = basicCount + 1;
					cout << endl;
				}
			}

			vector<Preferred>::iterator counter;
			for(counter = preferredVector.begin(); counter != preferredVector.end(); counter++)
			{
				if(index->memNumber == counter->getNumber())
				{
					cout << left << setw(30) << counter->getName()<< setw(30)
								 << index->memNumber;
					preferredCount = preferredCount + 1;
					cout << endl;
				}
			}

		// I NEED TO FIND A WAY TO LINK THE NAMES WITH THE NUMBERS
//		cout << left << setw(30) << "Bulk Club Member" << setw(30)
//			 << index->memNumber << endl;

		}
	}

	cout << "\nThere were " << preferredCount;
	// number of preferred members
	cout << " preferred members and " << basicCount;
	// number of basic members
	cout << " basic members shopping on this date.\n";

	} // end while
	else
	{
		cout << "\nError, we have no information stored for that date.\n";
	}

}

void History::PrintPurchasesByMember(int searchIdF,
								     vector<History> histVector,
        						     vector<Basic> basicVector,
        						     vector<Preferred> preferredVector)
{
	bool found;
	found = false;

	vector<History>::iterator index;

	for(index = histVector.begin(); index != histVector.end(); index++)
	{
	if (searchIdF == index->memNumber)
		{
			found = true;

		}

	}

	if(found)
	{
	cout << "Printing purchases made by " << searchIdF << endl;
	// FIND A WAY TO LINK THE NUMBER TO THE NAME

	cout << endl;
	cout << left << setw(30) << "ITEM NAME" << setw(15) << "QUANTITY SOLD";
	cout << endl;
	cout << "----------------------------- " << "--------------";
	cout << right << endl;


	for(index = histVector.begin(); index != histVector.end(); index++)
		{
	if (searchIdF== index->memNumber)
		{
			vector<Basic>::iterator count;
			for(count = basicVector.begin(); count != basicVector.end(); count++)
			{
				if(index->memNumber == count->getNumber())
				{
					cout << left << setw(30) << index->itemName;
					cout << setw(15) << index->quantity;
					cout << right;
					cout << endl;
				}
			}

			vector<Preferred>::iterator counter;
			for(counter = preferredVector.begin(); counter != preferredVector.end(); counter++)
			{
				if(index->memNumber == counter->getNumber())
				{
					cout << left << setw(30) << index->itemName;
					cout << setw(15) << index->quantity;
					cout << right;
					cout << endl;
				}
			}
		}

		}
	}
	else
	{
		cout << "\nError, no data stored for member you entered\n";
	}

		// I NEED TO FIND A WAY TO LINK THE NAMES WITH THE NUMBERS
//		cout << left << setw(30) << "Bulk Club Member" << setw(30)
//			 << index->memNumber << endl;

}

