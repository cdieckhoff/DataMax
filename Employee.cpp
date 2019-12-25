/*	
		File:				Classes.cpp
		Date:				09/02/2014
		Author:				Chris Dieckhoff
		Decription:			Source code for Employee class
*/

// PayCalculator is already included in Employee file
#include "Employee.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;


#pragma region EmployeeClassCode

Employee::Employee()
{
	this->_sName = "";
	this->_hours = 0.0;
	this->_rate = 0.0;
	this->_othours = 0.0;
	this->_hasOvertime = false;
}

Employee::Employee(string ename, double rate, double hours)
{
	this->_sName = ename;
	this->_hours = hours;
	this->_rate = rate;

	// Calculate regular and overtime hours
	if(hours > 40)
	{
		this->_othours = hours - 40;
		this->_reghours = 40;
		this->_hasOvertime = true;
	}
	else
	{
		this->_othours = 0.0;
		this->_reghours = hours;
		this->_hasOvertime = false;
	}
}

double Employee::getOvertimeHours(void)
{
	return this->_othours;
}

double Employee::getOvertimePay(void)
{
	return (this->_rate * 1.5 * _othours);
}

double Employee::getRegularHours(void)
{
	return this->_reghours;
}

double Employee::getRegularPay(void)
{
	return (this->_rate * this->_reghours);
}

double Employee::getTotalHours(void)
{
	return (getRegularHours() + getOvertimeHours());
}

double Employee::getTotalPay(void)
{
	return (getRegularPay() + getOvertimePay());
}

double Employee::getHourlyRate(void)
{
	return this->_rate;
}

string Employee::ToString(void)
{
	stringstream ss;
	ss << setprecision(2) << fixed << left;
	ss << setw(5) << "" << setw(20) << "Employee Name:" << setw(5) << "" << setw(10) << this->_sName << endl;
	ss << setw(5) << "" << setw(20) << "Regular Hours:" << setw(5) << "" << setw(10) << this->getRegularHours() << endl;
	ss << setw(5) << "" << setw(20) << "Regular Pay:" << setw(5) << "" << setw(10) << this->getRegularPay() << endl;
	if(this->_hasOvertime)
	{
		ss << setw(5) << "" << setw(20) << "Overtime Hours:" << setw(5) << "" << setw(10) << this->getOvertimeHours() << endl;
		ss << setw(5) << "" << setw(20) << "Overtime Pay:" << setw(5) << "" << setw(10) << this->getOvertimePay() << endl;
	}
	ss << setw(5) << "" << setw(20) << "Total Pay:" << setw(5) << "" << setw(10) << this->getTotalPay() << endl;
	return ss.str();
}

#pragma endregion EmployeeClassCode
