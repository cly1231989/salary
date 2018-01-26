#include "stdafx.h"
#include "ModifyEmployeeCommissionlyRateTrans.h"
#include "CommissionPayClassification.h"
#include "CommissionPaySchedule.h"
#include <memory>

ModifyEmployeeCommissionlyRateTrans::ModifyEmployeeCommissionlyRateTrans(int employeeID, int salary, float commissionRate)
	:ModifyEmployeeTransaction(employeeID)
{
	m_salary = salary;
	m_commissionRate = commissionRate;
}


ModifyEmployeeCommissionlyRateTrans::~ModifyEmployeeCommissionlyRateTrans()
{
}

void ModifyEmployeeCommissionlyRateTrans::changeEmployee(Employee & employee)
{
	employee.setPayClassification(std::make_unique<CommissionPayClassification>(m_salary, m_commissionRate));
	employee.setPaySchedule(std::make_unique<CommissionPaySchedule>());
}
