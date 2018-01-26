#include "stdafx.h"
#include "ModifyDirectPayTrans.h"
#include "DirectPayMethod.h"
#include <memory>


ModifyDirectPayTrans::ModifyDirectPayTrans(int employeeID, const std::string &bank, const std::string &account)
	:ModifyEmployeeTransaction(employeeID)
{
	m_account = account;
	m_bank = bank;
}


ModifyDirectPayTrans::~ModifyDirectPayTrans()
{
}

void ModifyDirectPayTrans::changeEmployee(Employee & employee)
{
	employee.setPayMethod(std::make_unique<DirectPayMethod>(m_bank, m_account));
}
