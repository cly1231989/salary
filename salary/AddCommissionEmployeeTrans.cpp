#include "stdafx.h"
#include "AddCommissionEmployeeTrans.h"
#include "CommissionPayClassification.h"
#include "CommissionPaySchedule.h"
#include <memory>


AddCommissionEmployeeTrans::AddCommissionEmployeeTrans(int employeeID, const std::string &name, const std::string &address, int salary, float commissionRate)
	:AddEmployeeTrans(employeeID, name, address)
{
	m_salary = salary;
	m_commissionRate = commissionRate;
}


AddCommissionEmployeeTrans::~AddCommissionEmployeeTrans()
{
}

std::unique_ptr<PayClassification> AddCommissionEmployeeTrans::getPayClassification()
{
	return std::make_unique<CommissionPayClassification>(m_salary, m_commissionRate);
}

std::unique_ptr<PaySchedule> AddCommissionEmployeeTrans::getPaySchedule()
{
	return std::make_unique<CommissionPaySchedule>();
}
