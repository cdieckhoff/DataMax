/*
		File:				main.cpp
		Date:				09/02/2014
		Author:				Chris Dieckhoff
		Description:		A program that calculates employees pay from user entered data
*/

#include "Employee.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

// FOR CREATING TEST PLANS
//#define _TEST_PLAN_

string summary(Employee *employee, int length)
{
	stringstream ss;
	double tsalaries = 0.0;
	double thours = 0.0;
	double tothours = 0.0;

	// Calculate total of all pay, hours and othours
	if(length > 0)
	{
		for(int i = 0; i < length; i++)
		{
			tsalaries += employee[i].getTotalPay();
			thours += employee[i].getRegularHours();
			tothours += employee[i].getOvertimeHours();
		}
	}

	ss << setprecision(2) << fixed << left;
	ss << setfill('#');
	ss << setw(50) << "" << endl;
	ss << setw(5) << "" << setfill(' ') << setw(10) << "" << setw(20) << "DataMax Pay Summary" << setfill(' ') << setw(10) << "" << setfill('#') << setw(5) << "" << endl;
	ss << setw(50) << "" << endl;
	ss << setw(1) << "" << setfill(' ') << setw(9) << "" << setw(20) << left << "Total Salaries" << setw(10) << right << tsalaries << setw(9) << "" << setfill('#') << setw(1) << "" << endl;
	ss << setw(1) << "" << setfill(' ') << setw(9) << "" << setw(20) << left << "Total Hours" << setw(10) <<  right << thours + tothours << setw(9) << "" << setfill('#') << setw(1) << "" << endl;
	ss << setw(1) << "" << setfill(' ') << setw(9) << "" << setw(20) << left << "Total Overtime" << setw(10) << right << tothours << setw(9) << "" << setfill('#') << setw(1) << "" << endl;
	ss << setw(50) << "" << endl << setw(50) << "" << endl;
	return ss.str();
}

void main()
{
	string ename;			// holds the temp value of employee's name
	double dhours;			// holds the temp value of employee's hours
	double dwage;			// holds the temp value of employee's rate

	// For future when employees > 3
	// make _employees a pointer, and put a menu on the while loop
	Employee _employees[] =  {Employee(), Employee(), Employee()};  // holds the values of the 3 employees entered
	int eindex;
	eindex = 0;

#pragma region TESTPLANCHK

#ifdef _TEST_PLAN_
	goto _test_plan;
#endif

#pragma endregion TESTPLANCHK

	// Output a friendly message
	cout << "Welcome to DataMax Payroll Calculator" << endl;

	while(eindex < 3)
	{
		// Reset local variables
		ename = "";
		dhours = 0.0;
		dwage = 0.0;

		// Get Employee info
		cout << "\n\nEnter the employee's name = ";
		cin >> ename;

		cout << "Enter the hours worked for " << ename << " = ";
		cin >> dhours;

		cout << "Enter the hourly rate for " << ename << " = ";
		cin >> dwage;
		_employees[eindex++]  = Employee(ename, dwage, dhours);

	}

	// Output Employee pay info
	cout << endl << endl;
	for(int i = 0; i < 3; i++)
		cout << _employees[i].ToString() << endl;

	// Output DataMax Pay summary
	cout << summary(_employees, 3) << endl;
	system("pause");

#pragma region TESTPLANCODE

#ifdef _TEST_PLAN_
_test_plan:
	cout << "\n\nEnter employees's name = " ;
	cin >> ename;
	cout << "Enter the hours worked for " << ename << " = ";
	cin >> dhours;
	cout << "Enter the hourly rate for " << ename << " = ";
	cin >> dwage;
	_employees[0] = Employee(ename, dwage, dhours);
	cout << "\n\n" << _employees[0].ToString() << endl;
	system("pause");
#endif

#pragma endregion TESTPLANCODE

}