#include "stdafx.h"
#include "ModifyEmployeeNameTrans.h"

ModifyEmployeeNameTrans::ModifyEmployeeNameTrans(int employeeID, const std::string &name)
	:ModifyEmployeeTransaction(employeeID)
{
	m_employeeID = employeeID;
	m_name = name;
}


ModifyEmployeeNameTrans::~ModifyEmployeeNameTrans()
{
}

void ModifyEmployeeNameTrans::changeEmployee(Employee & employee)
{
	employee.setName(m_name);
}

