Bulk Club Project
===============

You are to write a program that services members of Bulk Club.  You must use -inheritance, -composition, -exception handlers, -a virtual function, -and at least one overloaded operator.  At least one class should use templates. At least one class must contain a pointer (a copy constructor needs to be written and tested).   Highlight the above.  Write at least 10 agile stories (including description, tasks, test scenarios, and story points) before you start to development software.

Bulk Club has two types of members: basic and preferred. 
Member information includes:
-	Name
-	Member number
-	Membership type
-	Membership expiration date
-	Total amount spent
-	Rebate amount (preferred members only)

A rebate of 5% of the total amount spent (not to include sales tax) is paid at the close of the year to the preferred members. Basic members pay annual dues of $60.00 and preferred members pay annual dues of $75.00. Your program will use the following files that will be provided:

-	A membership information file that will contain the member name, member number, membership type, and expiration date

-	Five sales files that contain details of member shopping for a day (member number, items purchased and prices - items not to exceed 100 on any given trip)

Your program should read from the daily sales file and update the members’ information accordingly. As the sales are processed the total amount spent and rebate data for each member should be updated. Assume a sales tax rate of 8 3/4%.

Generate the following reports/request at any time:

-1.	A sales report for any given day. It should include a list of items and quantities sold on that day as well names of the members who shopped that day.  Report the total revenue for the given day.  It should also include number of preferred members and basic members who shopped during the given day.

2.	A user should be able to enter a membership number or name and get a list of the total purchases per that member.

3.	A report that prints the total purchases by all the members sorted by membership number.  It should also include a grand total of the purchases.

4.	A user should be able to enter an item name and get the quantity of that item sold as well as the total sales price.

5.	A report that prints out the quantity of each item sold sorted by item name.

6.	A report that prints out the rebate of all the preferred members sorted by membership number.

7.	A report showing the amount per year paid by each member for the membership dues sorted by member type (basic/preferred and then by member name.)

8.	A user should be able to enter a month and get a list of all members whose memberships expire that month as well as their dues amount.

-9.	A user should be able to add/delete members.   Create purchases for the new members to validate your code.  Updates should be saved between executions.

-10.	Determine if any basic customer should convert their membership to preferred status.

-11.	Determine if any preferred customer should convert their membership to basic status.

-12.	Save all changes between executions.

A user should also be able to specify the above reports for basic members only, preferred members only, or all members.

Design a very readable, easy to use interface to demonstrate your program.  Contingency handling should include addressing invalid input such as invalid membership number, invalid member type, invalid item name, etc.  Please let me know who your partner will be by March 20th (two points will be deducted from your score if you do not meet this deadline). All projects are due by May 13th.   No late projects will be accepted. Your team must demonstrate your project to me before it will be graded.   Each teammate must identify their accomplishments on the project.  

Submit an UML class diagram with your project.

The assignment will be graded using the following scale:
 


Final Project CS1C 2014
