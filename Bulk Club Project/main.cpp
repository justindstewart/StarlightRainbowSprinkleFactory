/*************************************************************************
 * AUTHOR		: Andrea Velazquez & Justin Stewart
 * STUDENT ID	: 994759
 * FINAL PROJECT: Super Warehouse Store
 * CLASS 		: CS1C
 * SECTION		: TTH: 8:30a - 9:50a
 * DUE DATE		: May 13th, 2014
 ************************************************************************/
#include "header.h"

/*************************************************************************
 *	SUPER WAREHOUSE STORE
 * _______________________________________________________________________
 *	This program builds a database of members and purchase histories for a
 *	 retail store and allows users to generate reports and adjust
 *	 memberships based on the data it provides.
 * _______________________________________________________________________
 * INPUTS:
 *
 * OUTPUTS:
 *
 ************************************************************************/

int main()
{
	//PrintHeader - Prints a heading for the project to a specified output
	PrintHeader(cout, "Super Warehouse Store", 'A', 0);

	//VARIABLES
	int userType;
	int managerCommand;
	int generalCommand; // could these all be merged into one variable?
	vector<Basic> basicList;
	vector<Preferred> prefList;
	vector<History> histList;
	Basic basicObj;
	Preferred prefObj;
	History histObj;

	int searchMonth;
	int searchDay;
	int searchYear;
	Date searchDate;

	int searchID;

	FillMemberList("warehouse shoppers.txt", basicList, prefList);
	FillHistoryList("day1.txt", histList);
	FillHistoryList("day2.txt", histList);
	FillHistoryList("day3.txt", histList);
	FillHistoryList("day4.txt", histList);
	FillHistoryList("day5.txt", histList);


//	cout << basicList.size() << endl;
//	cout << prefList.size() << endl;
//	cout << histList.size() << endl;
//
//	basicObj.print(basicList);
//
//	prefObj.print(prefList);
//
//	histObj.print(histList);

	char yesOrNo;

	do
	{
		userType = ErrorCheckInt(2, 0, USEROPTION);
		cout << endl;

		switch(userType)
		{
		case EXIT: break;
		case MANAGER: managerCommand = ErrorCheckInt(7, 0, MANAGERMENU);
					  cout << endl;
					  break;
		case GENERAL: generalCommand = ErrorCheckInt(4, 0, GENERALMENU);
					  cout << endl;
					  break;
		}

		if(userType == 1)
		{
			switch(managerCommand)
			{
			case MANAGEREXIT: break;
			case PRINTSALESREPORT:
				// PUT THIS WHOLE CHUNK IN ITS OWN FUNCTION {
			cout << "Print sales report for which date?\n";

            searchMonth = ErrorCheckInt(  12,    1, "Enter a month : ");
			searchDay   = ErrorCheckInt(  31,    1, "Enter a day   : ");
			searchYear  = ErrorCheckInt(2014, 1990, "Enter a year  : ");

			searchDate.SetDate(searchMonth, searchDay, searchYear);
					// }
			// call print function here
			histObj.PrintSalesReportByDate(searchDate, histList);

			break;
			case PRINTITEMSBYMEMBER: cout <<"Printing items purchased by "
									 "which member?\n";
									cout << "Please enter a member "
											"ID number: ";
									cin >> searchID;
									// call function here
									 break;
			case PRINTTOTALPURCHASES: cout << "Printing purchases\n";
									 // call function here
									   break;
			case PRINTQUANTITYOFITEM: cout << "Printing quantities of an "
					                  "item\n";
										// call function here
									   break;
			case PRINTQUANTITYOFALLITEMS: cout << "Printing quantities of "
					                      "all items\n";
										// call function here
										  break;
			case PRINTREBATE: cout << "Printing rebate\n";
								// call function here
								break;
			case PRINTDUESREPORT: cout << "Printing dues report\n";
								// call function here
								   break;
			}
		}

		if(userType == 2)
		{
			switch(generalCommand)
			{
			case GENERALEXIT: break;
			case EXPIRATIONS: cout << "\nChecking whose membership "
					          "expires\n";
							  // call function here
							  break;
			case ADDORDELETE: cout << "Adding or deleting members\n";
							  // call function here
							  break;
			case BASICTOPREF: cout << "Basic to Preferred?\n";
							  // call function here
							  break;
			case PREFTOBASIC: cout << "Preferred to Basic?\n";
						  	  // call function here
							  break;
			}
		}

		cout << endl;

		if (userType == 0 || managerCommand == 0 || generalCommand == 0)
		{
			yesOrNo = 'N';
		}
		else
		{
			yesOrNo = ErrorCheckChar('Y','N', CONTINUE);
			cout << endl;
		}

	} while (toupper(yesOrNo) == 'Y');

	return 0;

//TEST//
}



