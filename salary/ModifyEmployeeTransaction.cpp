#include "stdafx.h"
#include "ModifyEmployeeTransaction.h"
#include "EmployeeDatabase.h"
#include "Employee.h"

extern EmployeeDatabase gEmployeeDatabase;

ModifyEmployeeTransaction::ModifyEmployeeTransaction(int employeeID)
{
	m_employeeID = employeeID;
}


ModifyEmployeeTransaction::~ModifyEmployeeTransaction()
{
}

void ModifyEmployeeTransaction::excute()
{
	auto employee = gEmployeeDatabase.getEmployee(m_employeeID);
	changeEmployee(*employee);
	gEmployeeDatabase.addEmployee(employee->getID(), employee);
}
