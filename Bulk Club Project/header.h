/*************************************************************************
 * AUTHOR		: Andrea Velazquez & Justin Stewart
 * STUDENT ID	: 994759
 * FINAL PROJECT: Super Warehouse Store
 * CLASS 		: CS1C
 * SECTION		: TTH: 8:30a - 9:50a
 * DUE DATE		: May 13th, 2014
 ************************************************************************/

#ifndef HEADER_H_
#define HEADER_H_


// Preprocessor directives
#include <iostream>
#include <iomanip>
#include <string.h>
#include <fstream>
#include <ios>
#include <limits>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iterator>
#include "Date.h"
#include "Preferred.h"
#include "Basic.h"
#include "History.h"


//#define NDEBUG // I tested this, but didn't print output. It works.
#include <cassert>

using namespace std;

const string USEROPTION  = "Welcome to Bulk Club Database!\n"
					       "What type of user are you? (Input 0 to exit)\n"
						   "1 - Manager\n"
						   "2 - General Associate\n"
						   "Enter an option: ";
const string MANAGERMENU = "What would you like to do? (Input 0 to exit)\n"
						   "1 - Print sales report for certain day\n"
						   "2 - Print list of items purchased by specific"
						   " member\n"
						   "3 - Print report of total purchases by ALL "
						   "members\n"
						   "4 - Print quantity of specific Item sold\n"
						   "5 - Print quantity of EACH item sold\n"
						   "6 - Print preferred member rebate report\n"
						   "7 - Print membership dues report\n"
						   "Enter an option: ";
const string GENERALMENU = "What would you like to do? (Input 0 to exit)\n"
						   "1 - Find out whose membership expires this "
						   "month\n"
						   "2 - Add member\n"
						   "3 - Delete member\n"
						   "4 - Add purchase\n"
						   "5 - Basic to preferred inquiries\n"
						   "6 - Preferred to basic inquiries\n"
						   "7 - Print Preferred List\n"
						   "8 - Print Basic List\n"
						   "9 - Print Member List\n"
						   "Enter an option: ";
const string CONTINUE    = "Would you like to do something else? ";
//const string PRINTOPTION = "Would you like to print report for preferred, "
//						   "basic, or all members?\n"
//						   "1 - Preferred\n"
//						   "2 - Basic\n"
//						   "3 - All\n"
//		                   "Enter an option: ";

enum UserOption
{
	EXIT,
	MANAGER,
	GENERAL
};

enum ManagerMenu
{
	MANAGEREXIT,
	PRINTSALESREPORT,
	PRINTITEMSBYMEMBER,
	PRINTTOTALPURCHASES,
	PRINTQUANTITYOFITEM,
	PRINTQUANTITYOFALLITEMS,
	PRINTREBATE,
	PRINTDUESREPORT
};

enum GeneralMenu
{
	GENERALEXIT,
	EXPIRATIONS,
	ADDMEMBER,
	DELETEMEMBER,
	ADDPURCHASE,
	BASICTOPREF,
	PREFTOBASIC,
	PRINTPREFERRED,
	PRINTBASIC,
	PRINTALL
};

struct CustomerNode
{
	string name;
	int    idNumber;
	CustomerNode* next;
	CustomerNode* previous;
};

/*************************************************************************
 * ErrorCheckInt
 *	This function Reads in, an upper and lower bound for an integer
 *	 input, as well as a string to prompt the user for that integer input,
 *	 it error checks and then returns that input
 ************************************************************************/
int ErrorCheckInt(const int upperLim,	//IN - Upper bound for input
				  const int lowerLim, 	//IN - Lower bound for input
				  string prompt);		//IN - String containing prompt
										//     for user input

/*************************************************************************
 * ErrorCheckChar
 *	 This function Reads in, a two chars, it then reads in a char input
 *	 as well as a string to prompt the user for that selection of inputs,
 *	 it error checks and then returns that input
 ************************************************************************/
char ErrorCheckChar(const char CHAR1,	 //IN -First Char for input
					const char CHAR2,    //IN - Second Char for input
					string prompt);		 //IN - String containing prompt

/*************************************************************************
 * ErrorCheckFloat
 *	This function Reads in, an upper and lower bound for a float
 *	 input, as well as a string to prompt the user for that float input,
 *	 it error checks and then returns that input
 ************************************************************************/
float ErrorCheckFloat(const float upperLim,	//IN - Upper bound for input
					  const float lowerLim, //IN - Lower bound for input
					  string prompt);		//IN - String containing prompt
											//     for user input

/*************************************************************************
 * PrintHeader
 *	This function receives an assignment name, type and number then
 *	outputs the appropriate header.
 *	- returns nothing -> This will output the class heading.
 ************************************************************************/
void PrintHeader(ostream &oFile,	// IN - Output type
				 string asName,		// IN - assignment Name
				 char asType,		// IN - assignment type
				 	 	 	 	 	// 		(LAB or ASSIGNMENT)
				 int asNum);		// IN - assignment number

/*************************************************************************
 * FillMemberList
 *	This function receives a file name, a basic members vector list and a
 *	 preferred members vector list. It then uses the file name to populate
 *	 these lists. -returns nothing
 ************************************************************************/
void FillMemberList(vector<Basic>& basicList,	  // IN - Basic list
					vector<Preferred> & prefList);// IN - Preferred list

/*************************************************************************
 * FillHistoryList
 *	This function receives a file name and a history vector. It then fills
 *	 the vector using the file specified by the program. -returns nothing.
 ************************************************************************/
void FillHistoryList(vector<History>& histList);   // IN - History list

/*************************************************************************
 * AddMember
 *	This function receives  a basic members vector list and a preferred
 *   members vector list. It then prompts the user for some basic info
 *   and adds a member to the appropriate list.
 ************************************************************************/
void AddMember(vector<Basic>& basicList,	 // IN - Basic list
			   vector<Preferred>& prefList); // IN - Preferred list

/*************************************************************************
 * DeleteMember
 *	This function receives  a basic members vector list and a preferred
 *   members vector list. It then prompts the user for some basic info
 *   and deletes a member from the list.
 ************************************************************************/
void DeleteMember(vector<Basic>& basicList,	 	// IN - Basic list
			      vector<Preferred>& prefList); // IN - Preferred list

/*************************************************************************
 * FillTotals
 *	This function receives  a basic members vector list, a preferred
 *   members vector list and a history vector list. It then calculates the
 *   total amount spent for the member classes.
 ************************************************************************/
void FillTotals(vector<Basic>& basicList,	//IN - Basic list
			   vector<Preferred>& prefList,	//IN - Preferred list
			   vector<History>& histList);	//IN - History list

/*************************************************************************
 * CheckUniqueInt
 *	This function receives  a basic members vector list, a preferred
 *	 members vector list and a value to search for. It then searches each
 *	 list for another instance of the value and returns a boolean.
 ************************************************************************/
bool CheckUniqueInt(vector<Basic>& basicList,	// IN - Basic list
			   	    vector<Preferred>& prefList,// IN - Preferred list
			   	    int value);					// IN - Search value

/*************************************************************************
 * StatusCheckBasic
 *	This function receives  a basic members vector list and goes through
 *	the list to find any members that would benefit from upgrading their
 *	membership to premium. It then outputs that list
 ************************************************************************/
void StatusCheckBasic(vector<Basic>& list);	//IN - Basic List

/*************************************************************************
 * StatusCheckPreferred
 *	This function receives a preferred members vector list and goes through
 *	the list to find any members that would benefit from down-grading their
 *	membership to basic. It then outputs that list
 ************************************************************************/
void StatusCheckPreferred(vector<Preferred>& list); //IN - Preferred list

/*************************************************************************
 * FillMemberFile
 *	This function receives a basic members vector list and a preferred
 *	members vector list. At the end of the program it then populates the
 *	file for future use. - returns nothing
 ************************************************************************/
void FillMemberFile(vector<Basic>& basicList,	 // IN - Basic list
					vector<Preferred>& prefList);// IN - Preferred list

/*************************************************************************
 * FillHistoryFile
 *	This function receives a file name and a history vector. It then fills
 *	 the file using the file specified by the program. -returns nothing.
 ************************************************************************/
void FillHistoryFile(vector<History>& histList);   // IN - History list

/*************************************************************************
 * AddPurchase
 *	This function receives  a basic members vector list, a preferred
 *   members vector list and a history vector list. It then prompts the
 *   user for some basic info and adds a purchase to the appropriate list.
 ************************************************************************/
void AddPurchase(vector<Basic>& basicList,	 // IN - Basic list
			     vector<Preferred>& prefList,// IN - Preferred list
			     vector<History>& histList); // IN - History list

/*************************************************************************
 * PrintRebates
 *	This function receives a preferred vector list and outputs the rebate
 *	amounts of each member sorted by membership number.
 ************************************************************************/
void PrintRebates(vector<Preferred> prefList);// IN - Preferred List

/*************************************************************************
 * MembershipDues
 *	This function receives a basic vector list and a preferred vector list
 *	and outputs the membership dues of each member sorted by membership
 *	name.
 ************************************************************************/
void MembershipDues(vector<Basic> basicList,	// IN - Basic List
				    vector<Preferred> prefList);// IN - Preferred List

/*************************************************************************
 * CompareNamesPreferred
 *	This function receives two preferred member names and compares them
 *	alphabetically.
 ************************************************************************/
bool CompareNamesPref(const Preferred& first, 	// IN - First name to compare
					  const Preferred& second);	// IN - Second name to compare

/*************************************************************************
 * CompareNamesBasic
 *	This function receives two basic member names and compares them
 *	alphabetically.
 ************************************************************************/
bool CompareNamesBasic(const Basic& first,	// IN - First name to compare
					   const Basic& second);// IN - Second name to compare

#endif /* HEADER_H_ */
