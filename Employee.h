/*
	File:			Classes.h
	Data:			09/02/2014
	Author:			Chris Dieckhoff
	Description:	Class definitions for DataMax Payroll Classes

*/

#ifndef _CLASSES_H_
#define	_CLASSES_H_

#include <iostream>
using std::string;

class PayCalculator
{
private:
	double hourlyWage;
	double totalHours;
	double regHours;
	double otHours;

public:
	PayCalculator(double, double);

	double getRegularHours(void);
	double getOvertimeHours(void);
	double getRegularPay(void);
	double getOvertimePay(void);
	double getTotalPay(void);
	double getHourlyRate(void);
	double getTotalHours(void);

};

class Employee
{
protected :
	double _othours;
	double _reghours;
	bool _hasOvertime;

private:
	string _sName;
	double _rate;
	double _hours;

public:
	Employee();
	Employee(string, double, double);
	double getRegularHours(void);
	double getRegularPay(void);
	double getOvertimeHours(void);
	double getOvertimePay(void);
	double getTotalPay(void);
	double getHourlyRate(void);
	double getTotalHours(void);
	string ToString(void);

};

#endif // !_CLASSES_H_
