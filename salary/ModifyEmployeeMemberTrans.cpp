#include "stdafx.h"
#include "ModifyEmployeeMemberTrans.h"
#include "UnionAffiliation.h"
#include "EmployeeDatabase.h"
#include <memory>

extern EmployeeDatabase gEmployeeDatabase;

ModifyEmployeeMemberTrans::ModifyEmployeeMemberTrans(int employeeID, int memberID, float memberRate)
	:ModifyEmployeeTransaction(employeeID)
{
	m_memberID = memberID;
	m_memberRate = memberRate;
}


ModifyEmployeeMemberTrans::~ModifyEmployeeMemberTrans()
{
}

void ModifyEmployeeMemberTrans::changeEmployee(Employee &employee)
{
	gEmployeeDatabase.addUnionMember(m_memberID, &employee);
	employee.setAffiliation(std::make_unique<UnionAffiliation>(m_memberID, m_memberRate));
}
