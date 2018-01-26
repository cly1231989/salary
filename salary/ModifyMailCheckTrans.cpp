#include "stdafx.h"
#include "ModifyMailCheckTrans.h"
#include "MailPayMethod.h"
#include <memory>

ModifyMailCheckTrans::ModifyMailCheckTrans(int employeeID, const std::string &mailAddress)
	:ModifyEmployeeTransaction(employeeID)
{
	m_mailAddress = mailAddress;
}


ModifyMailCheckTrans::~ModifyMailCheckTrans()
{
}

void ModifyMailCheckTrans::changeEmployee(Employee & employee)
{
	employee.setPayMethod(std::make_unique<MailPayMethod>(m_mailAddress));
}
