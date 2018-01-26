#include "stdafx.h"
#include "DelEmployeeTrans.h"
#include "EmployeeDatabase.h"

extern EmployeeDatabase gEmployeeDatabase;

DelEmployeeTrans::DelEmployeeTrans(int employeeID)
{
	m_employeeID = employeeID;
}


DelEmployeeTrans::~DelEmployeeTrans()
{
}

void DelEmployeeTrans::excute()
{
	gEmployeeDatabase.delEmployee(m_employeeID);
}
