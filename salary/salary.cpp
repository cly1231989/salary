// salary.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "HourlyPayClassification.h"
#include <typeinfo>
#include "EmployeeDatabase.h"
#include "AddHourlyEmployeeTrans.h"
#include "HourlyPayClassification.h"
#include "HourlyPaySchedule.h"
#include "MailPayMethod.h"
#include "Employee.h"
#include <string>
#include <memory>

extern EmployeeDatabase gEmployeeDatabase;

int main()
{
	int employeeID = 1;
	float hourlyRate = 40.0;
	std::string name = "bob";
	std::string address = "chongqing";

	AddHourlyEmployeeTrans addHourlyEmployeeTrans(employeeID, name, address, hourlyRate);
	addHourlyEmployeeTrans.excute();

	auto em = gEmployeeDatabase.getEmployee(employeeID);
	auto &payClassification = em->getPayClassification();
	printf(typeid(*(payClassification.get())).name());
	printf("\n");

	printf(typeid(HourlyPayClassification*).name());
    return 0;
}

