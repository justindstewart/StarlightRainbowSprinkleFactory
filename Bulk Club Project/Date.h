/*************************************************************************
 * AUTHOR		: Andrea Velazquez & Justin Stewart
 * STUDENT ID	: 994759
 * FINAL PROJECT: Super Warehouse Store
 * CLASS 		: CS1C
 * SECTION		: TTH: 8:30a - 9:50a
 * DUE DATE		: May 13th, 2014
 ************************************************************************/

#ifndef DATE_H_
#define DATE_H_

#include <iostream>
#include <string>
using namespace std;

//Date - Date class that holds the date in integer values.
class Date
{
	public:
		Date();
		Date(int newMonth, int newDay, int newYear);
		~Date();
		void SetDate(int newMonth, int newDay, int newYear);
		void SetMonth(int newMonth);
		void SetDay(int newDay);
		void SetYear(int newYear);
		int  GetMonth() const;
		int  GetDay()   const;
		int  GetYear() const;
		void PrintDate() const;

		bool operator==(const Date&obj) const;
		bool operator!=(const Date&obj) const;

	private:
		int    month;
		int    day;
		int    year;
};


#endif /* DATE_H_ */
