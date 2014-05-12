/*************************************************************************
 * AUTHOR		: Andrea Velazquez & Justin Stewart
 * STUDENT ID	: 838042 & 994759
 * FINAL PROJECT: Super Warehouse Store
 * CLASS 		: CS1C
 * SECTION		: TTH: 8:30a - 9:50a
 * DUE DATE		: May 13th, 2014
 ************************************************************************/

#include "header.h"

void SortVectorByItemName(vector <History> &histVector)
{
	History temp;
	unsigned vectorSize = histVector.size();

	for(unsigned iterator = 1; iterator< vectorSize; iterator++)
	{
		for (unsigned index = 0; index < (vectorSize - iterator); index++)
		{
			if(histVector[index].getName() > histVector[index+1].getName())
			{
				temp = histVector[index];
				histVector[index]= histVector[index+1];
				histVector[index+1] = temp;
			}
		}
	}
}
