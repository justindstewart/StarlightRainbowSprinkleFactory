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
	vector<Basic> basicList;	//IN - Vector to hold basic members
	vector<Preferred> prefList;	//IN - Vector to hold preferred members
	vector<History> histList;	//IN - Vector to hold shopping history
	Basic basicObj;				//IN - Basic object variable
	Preferred prefObj;			//IN - Preferred object variable
	History histObj;			//IN - History object variable
	int searchMonth;			//IN - Variable to hold month to search for
	int searchDay;				//IN - Variable to hold day to search for
	int searchYear;				//IN - Variable to hold year to search for
	Date searchDate;			//IN - Variable to hold entire date
	int searchID;				//IN - Variable to hold the ID to search

	FillMemberList(basicList, prefList);
	FillHistoryList(histList);

	FillTotals(basicList, prefList, histList);

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
		case GENERAL: generalCommand = ErrorCheckInt(9, 0, GENERALMENU);
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
			searchYear  = ErrorCheckInt(2014, 2013, "Enter a year  : ");

			searchDate.SetDate(searchMonth, searchDay, searchYear);


					// }
			//if(search date in range)
			// call print function here
			histObj.PrintSalesReportByDate(searchDate, histList, basicList, prefList, basicObj, prefObj);
			//else
			// output error not found

			break;
			case PRINTITEMSBYMEMBER: cout <<"Printing items purchased by "
									 "which member?\n";
			searchID = ErrorCheckInt( 99999,
									  10000,
									 "Please enter a member ID number: ");
									// call function here
			histObj.PrintPurchasesByMember(searchID, histList, basicList, prefList);
									 break;
			case PRINTTOTALPURCHASES: cout << "Printing purchases\n";
									 // call function here
			histObj.PrintTotalPurchases(histList,
						basicList,
						prefList,
						basicObj,
						prefObj);

						   break;
			case PRINTQUANTITYOFITEM: cout << "Print quantity of what "
					                  "item? ";
			// read in item
//			getline(cin, searchItem);
//										// call function here
//			histObj.PrintQuantityOfItem(searchItem,
//						histList,
//						histObj);
					   break;
			case PRINTQUANTITYOFALLITEMS:  cout << "Printing quantities of "
					                      "all items\n";
										// call function here
			histObj.PrintQuantityOfAllItems(histList);
							  break;
			case PRINTREBATE: cout << "Printing rebate report: \n";
							  PrintRebates(prefList);
							  break;
			case PRINTDUESREPORT: cout << "Printing dues report: \n";
								  MembershipDues(basicList, prefList);
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
							  MembershipExp(basicList, prefList);
							  break;
			case ADDMEMBER:   cout << "Adding member:\n";
							  AddMember(basicList, prefList);
							  break;
			case DELETEMEMBER:cout << "Deleting member:\n";
							  DeleteMember(basicList, prefList);
							  break;
			case ADDPURCHASE: cout << "Adding purchase:\n";
							  AddPurchase(basicList, prefList, histList);
							  break;
			case BASICTOPREF: cout << "Recommended Membership Upgrade: " << endl;
							  StatusCheckBasic(basicList);
							  break;
			case PREFTOBASIC: cout << "Recommended Membership Down-grade: " << endl;
							  StatusCheckPreferred(prefList);
							  break;
			case PRINTPREFERRED: cout << "Preferred Members: " << endl;
								 prefObj.print(prefList);
								 break;
			case PRINTBASIC: cout << "Basic Members: " << endl;
							 basicObj.print(basicList);
							 break;
			case PRINTALL: cout << "All Members: " << endl;
						   basicObj.print(basicList);
						   prefObj.print(prefList);
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

	//FillMemberFile - Fills the external member file for reuse
	FillMemberFile(basicList, prefList);
	//FillHistoryFile - Fills the external history file for reuse
	FillHistoryFile(histList);

	cout << "Lists Saved. See you next time!";

	return 0;
}



