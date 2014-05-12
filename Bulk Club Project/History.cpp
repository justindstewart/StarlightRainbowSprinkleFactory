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
}//End setBuyDate

int History::getDay() const
{
	return buyDate.GetDay();
}//End getDay

int History::getMonth() const
{
	return buyDate.GetMonth();
}//End getMonth

int History::getYear() const
{
	return buyDate.GetYear();
}//End getYear

float History::calculateTotal(vector<History> histVector, int memberId) const
{
	float totalSpent;	//CALC & OUT - Calculates and outputs total spent
	vector<History>::iterator index;	//CALC - Iterator

	totalSpent = 0;

	//FOR - Loops through history vector list until index is at end
	for(index = histVector.begin(); index != histVector.end(); index++)
	{
		//IF - Compares member ID to passed ID and adds up total spent
		if(index->memNumber == memberId)
		{
			totalSpent += (index->cost * index->quantity);
		}//End if
	}//End for

	return totalSpent;
}//End calculateTotal

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
	vector<History>::iterator index;	//CALC - Iterator

	//FOR - Loops through history vector until index is at the end,
	//		displays each instance.
	for(index = histVector.begin(); index != histVector.end(); index++)
	{
		index->display();
	}
}//End print

bool History::operator==(const History& obj) const
{
	return (buyDate== obj.buyDate);
}//End overload == operator

bool History::operator!=(const History& obj) const
{
	return (buyDate!=obj.buyDate);
}//End overload != operator

bool History::operator<(const History& obj) const
{
	return(memNumber < obj.memNumber);
}//End overload < operator

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

			cout << left << setw(30) << index->itemName << setw(15)
				 << index->quantity << endl;
		}
	}

// OUTPUT THE LIST OF SHOPPERS FOR THIS DATE
	cout << "\nThese people shopped here on ";
	searchDateF.PrintDate();
	cout << ": " << endl << endl;

	cout << left << setw(30) << "MEMBER NAME" << setw(15) << "MEMBER NUMBER";
	cout << endl;
	cout << "----------------------------- " << "--------------";
	cout << endl;


	bool temp;
//	temp = false;

	CustomerNode* head;
	CustomerNode* tail;
	CustomerNode* customerPtr;
	CustomerNode* searchPtr;

	tail = NULL;
	head = NULL;
	searchPtr = head;

	for(index = histVector.begin(); index != histVector.end(); index++)
	{
		if (searchDateF == index->buyDate)
		{
			vector<Basic>::iterator count;
			for(count = basicVector.begin(); count != basicVector.end(); count++)
			{
				if(index->memNumber == count->getNumber())
				{
					if(head == NULL)
					{

						// linked list stuff
						customerPtr = new CustomerNode;
						customerPtr->name = count->getName();
						customerPtr->idNumber = count->getNumber();
						customerPtr->next = tail;
						head = customerPtr;
						tail = head;
//						customerPtr = new CustomerNode;
						head->previous = customerPtr;

						basicCount = basicCount + 1;
					}
					else
					{
						temp = false;
						searchPtr = head;
						while(searchPtr != NULL && !temp)
						{
							if(searchPtr->name == count->getName())
							{
								temp = true;
							}
							else
							{
								searchPtr = searchPtr->next;
							}
						}

						if(!temp)
						{
							// linked list stuff
							customerPtr = new CustomerNode;
							customerPtr->name = count->getName();
							customerPtr->idNumber = count->getNumber();
							customerPtr->next = tail;
							head = customerPtr;
							tail = head;
//							customerPtr = new CustomerNode;
							head->previous = customerPtr;

							basicCount = basicCount + 1;
						}
					}
				}
			}

			vector<Preferred>::iterator counter;
			for(counter = preferredVector.begin(); counter != preferredVector.end(); counter++)
			{
				if(index->memNumber == counter->getNumber())
				{
					if(head == NULL)
					{
						// linked list stuff
						customerPtr = new CustomerNode;
						customerPtr->name = counter->getName();
						customerPtr->idNumber = counter->getNumber();
						customerPtr->next = tail;
						head = customerPtr;
						tail = head;
//						customerPtr = new CustomerNode;
						head->previous = customerPtr;

						preferredCount = preferredCount + 1;
					}
					else
					{
						searchPtr = head;
						temp = false;
						while(searchPtr != NULL && !temp)
						{
							if(searchPtr->name == counter->getName())
							{
								temp = true;
							}
							else
							{
								searchPtr = searchPtr->next;
							}
						}

						if(!temp)
						{
							// linked list stuff
							customerPtr = new CustomerNode;
							customerPtr->name = counter->getName();
							customerPtr->idNumber = counter->getNumber();
							customerPtr->next = tail;
							head = customerPtr;
							tail = head;
//							customerPtr = new CustomerNode;
							head->previous = customerPtr;

							preferredCount = preferredCount + 1;
						}
					}
				}
			}
		}
	}

	customerPtr = head;
	while (customerPtr != NULL)
	{
		cout << left;

		cout << setw(30) << customerPtr->name;
		cout << setw(15) << customerPtr->idNumber;


		cout << right;
		cout << endl;
		customerPtr = customerPtr->next;
	}


// RE- COUNT PREFERRED AND BASIC MEMBERS

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

		// I NEED TO FIND A WAY TO LINK THE NAMES WITH THE NUMBER
}


void History::PrintTotalPurchases (vector<History> histVector,
							       vector<Basic> basicVector,
								   vector<Preferred> preferredVector,
								   Basic basicObj,
								   Preferred prefObj)
{
	float grandTotal;
	grandTotal = 0;

	cout << endl;

	vector<History>::iterator index;

	// sort the vector by ID numbers
	sort(histVector.begin(), histVector.end());

	// names are under the purchases, fix that

		for(index = histVector.begin(); index != histVector.end(); index++)
		{
			if(index == histVector.begin() || index->memNumber != (index-1)->memNumber)
			{
				cout << endl;
				cout << left << setw(42) << "MEMBER NAME" << setw(15) << "MEMBER NUMBER";
				cout << endl;
				cout << "----------------------------------------- " << "----------------";
				cout << endl;

				vector<Basic>::iterator count;
				for(count = basicVector.begin();
					count != basicVector.end(); count++)
				{
					if(index->memNumber == count->getNumber())
					{

						cout << left;
						cout << setw(42) << count->getName() << setw(15) << index->memNumber;
						cout << endl;
						cout << right;
					}
				}

				vector<Preferred>::iterator counter;
				for(counter = preferredVector.begin();
					counter != preferredVector.end(); counter++)
				{
					if(index->memNumber == counter->getNumber())
					{

						cout << left;
						cout << setw(42) << counter->getName() << setw(15) << index->memNumber;
						cout << endl;
						cout << right;
					}
				}

				cout << endl;
				cout << left << setw(30) << "ITEM NAME" << setw(11);
				cout << "TOTAL SOLD" << setw(19) << "TOTAL SALES PRICE";
				cout << endl;
				cout << "----------------------------- " << "---------- ";
				cout << "----------------";
				cout << right << endl;

			}

			if(index->memNumber == (index+1)->memNumber)
			{
//				cout << left;
//				cout << setw(42) << "member name" << setw(15) << index->memNumber;
//				cout << endl;
//				cout << right;

//				cout << endl;
//				cout << left << setw(30) << "ITEM NAME" << setw(11);
//				cout << "TOTAL SOLD" << setw(19) << "TOTAL SALES PRICE";
//				cout << endl;
//				cout << "----------------------------- " << "---------- ";
//				cout << "----------------";
//				cout << right << endl;
			}

			cout << left  << setw(30) << index->itemName << setw(11) << index->quantity;
			cout << "$ "  << right << setw(6) << setprecision(2) << fixed << index->cost;
			cout << right << endl;

			grandTotal = grandTotal + index->cost;

		}

		cout << endl;
		cout << "The grand total of all purchases is: $" << grandTotal;
		cout << endl;

}

void History::PrintQuantityOfItem (string searchItem,
								  vector <History> histVector,
								  History histObj)
{
	char yesOrNo;

	bool found;
	found = false;

	int amount;
	amount = 0;

	float totalSalesPrice;
	totalSalesPrice = 0;

	vector<History>::iterator index;

	for(index = histVector.begin(); index != histVector.end(); index++)
	{
		if(searchItem == index->itemName)
		{
			found = true;
		}
	}


	if(found)
	{
		for(index = histVector.begin(); index != histVector.end(); index++)
		{
			if(searchItem == index->itemName)
			{
				totalSalesPrice = totalSalesPrice + index->cost;

				amount = amount + index->quantity;
			}

		}

		cout << endl;
		cout << left << setw(25) << "ITEM NAME" << setw(11);
		cout << "TOTAL SOLD" << setw(19) << "TOTAL SALES PRICE";
		cout << endl;
		cout << "------------------------ " << "---------- ";
		cout << "----------------";
		cout << right << endl;

		cout << left << setw(25) << searchItem << setw(11) << amount;
		cout << "$ " << setw(16) << totalSalesPrice;
		cout << endl;
		cout << right << endl;
	}
	else
	{
		cout << "\nError, we don't have a record of that item being sold.";
		cout << endl;
	}

	cout << endl;
	yesOrNo = ErrorCheckChar('Y','N', "Would you like to search another item? ");

	if (yesOrNo == 'Y')
	{
		// recursion?
		cout << endl;
		cout << "Print quantity of what item? "; // read in item
		getline(cin, searchItem);
		histObj.PrintQuantityOfItem(searchItem,
									histVector,
									histObj);
	}

	// write a check case function (toupper both strings)?
}
void History::PrintQuantityOfAllItems (vector <History> histVector)
{
	int nextIndex;
	nextIndex = 1;


	cout << endl;
	cout << left << setw(30) << "ITEM NAME" << setw(15) << "QUANTITY SOLD";
	cout << endl;
	cout << "----------------------------- " << "--------------";
	cout << right << endl;

	vector<History>::iterator index;

	// sort the vector by itemname
	SortVectorByItemName(histVector);


	for(index = histVector.begin(); index != histVector.end(); index++)
	{
		if(index == histVector.begin() || index->itemName != (index-1)->itemName)
		{
			cout << left;
			cout << setw(30) << index->itemName;

		while((index+nextIndex)!= histVector.end() && index->itemName == (index+nextIndex)->itemName )
		{
				index->quantity = index->quantity + (index+nextIndex)->quantity;

				nextIndex++;

		}

		nextIndex = 1;

		cout << setw(15) << index->quantity;
		cout << right << endl;

		}
	}

}
