/*************************************************************************
 * AUTHOR		: Andrea Velazquez & Justin Stewart
 * STUDENT ID	: 994759
 * FINAL PROJECT: Super Warehouse Store
 * CLASS 		: CS1C
 * SECTION		: TTH: 8:30a - 9:50a
 * DUE DATE		: May 13th, 2014
 ************************************************************************/

#include "header.h"

//Constructor - Default constructor
Date::Date() : month(1), day(1), year(2014)
{
	//Empty Block
}
//Constructor - Non-Default, sets values to whatever specified in client
Date::Date(int newMonth, int newDay, int newYear) :
	month(newMonth),
	day(newDay),
	year(newYear)
{
	//Empty Block
}
//Destructor - Destroy object
Date::~Date()
{

}
//SetDate - Sets date values
void Date::SetDate(int newMonth, int newDay, int newYear)
{
	month = newMonth;
	day   = newDay;
	year  = newYear;
}
//SetMonth - Sets the value for month
void Date::SetMonth(int newMonth)
{
	month = newMonth;
}
//SetDay - Sets the value for day
void Date::SetDay(int newDay)
{
	day = newDay;
}
//SetYear - Sets the value for the year
void Date::SetYear(int newYear)
{
	year = newYear;
}
//GetMonth - Gets the current month value and returns to client
int Date::GetMonth() const
{
	return month;
}
//GetDay - Gets the current day and returns to client
int Date::GetDay() const
{
	return day;
}
//GetYear - Gets the current year and returns to client
int Date::GetYear() const
{
	return year;
}
//PrintDate - Prints all the details from the date class
void Date::PrintDate() const
{
	if(month < 10)
	{
		cout << '0';
	}

	cout << month <<  "/";

	if(day < 10)
	{
		cout << '0';
	}

	cout << day << "/" << year;
}

// can i do multiple returns with &&s? is that allowed? does it work?

bool Date::operator==(const Date&obj) const
{
	return (month== obj.month && day == obj.day && year == obj.year);
}

bool Date::operator!=(const Date&obj) const
{
	return (month!= obj.month && day != obj.day && year != obj.year);
}
