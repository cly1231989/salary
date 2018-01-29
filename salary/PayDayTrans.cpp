#include "stdafx.h"
#include "PayDayTrans.h"
#include "EmployeeDatabase.h"
#include "Employee.h"
#include "PayCheck.h"

extern EmployeeDatabase gEmployeeDatabase;

PayDayTrans::PayDayTrans(Date date)
{
	m_date = date;
}


PayDayTrans::~PayDayTrans()
{
}

void PayDayTrans::excute()
{
	auto employeeIDs = gEmployeeDatabase.getAllEmployeeID();
	for (size_t i = 0; i < employeeIDs.size(); i++)
	{
		auto employee = gEmployeeDatabase.getEmployee(employeeIDs[i]);
		if (true)
		{
			if (!employee->isPayDay(m_date))
				continue;

			PayCheck payCheck(employee->getBeginDate(m_date), m_date);
			employee->payday(payCheck);
			m_payChecks[employee->getID()] = payCheck;
		}
	}
}

bool PayDayTrans::getPayCheck(int employeeID, PayCheck & payCheck)
{
	auto findIte = m_payChecks.find(employeeID);
	if (findIte == m_payChecks.end())
		return false;

	payCheck = findIte->second;
	return true;
}
