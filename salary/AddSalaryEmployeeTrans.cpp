#include "stdafx.h"
#include "AddSalaryEmployeeTrans.h"
#include "SalaryPayClassification.h"
#include "MonthlyPaySchedule.h"
#include <memory>

AddSalaryEmployeeTrans::AddSalaryEmployeeTrans(int employeeID, const std::string &name, const std::string &address, int salary)
	:AddEmployeeTrans(employeeID, name, address)
{
	m_salary = salary;
}


AddSalaryEmployeeTrans::~AddSalaryEmployeeTrans()
{
}

std::unique_ptr<PayClassification> AddSalaryEmployeeTrans::getPayClassification()
{
	return std::make_unique<SalaryPayClassification>(m_salary);
}

std::unique_ptr<PaySchedule> AddSalaryEmployeeTrans::getPaySchedule()
{
	return std::make_unique<MonthlyPaySchedule>();
}
