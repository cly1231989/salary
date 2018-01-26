#include "stdafx.h"
#include "ModifyEmployeeAddressTrans.h"


ModifyEmployeeAddressTrans::ModifyEmployeeAddressTrans(int employeeID, const std::string &address)
	:ModifyEmployeeTransaction(employeeID)
{
	m_address = address;
}


ModifyEmployeeAddressTrans::~ModifyEmployeeAddressTrans()
{
}

void ModifyEmployeeAddressTrans::changeEmployee(Employee & employee)
{
	employee.setAddress(m_address);
}
