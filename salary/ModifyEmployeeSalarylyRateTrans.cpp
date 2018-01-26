#include "stdafx.h"
#include "ModifyEmployeeSalarylyRateTrans.h"
#include "SalaryPayClassification.h"
#include "MonthlyPaySchedule.h"
#include <memory>

ModifyEmployeeSalarylyRateTrans::ModifyEmployeeSalarylyRateTrans(int employeeID, int salary)
	:ModifyEmployeeTransaction(employeeID)
{
	m_salary = salary;
}


ModifyEmployeeSalarylyRateTrans::~ModifyEmployeeSalarylyRateTrans()
{
}

void ModifyEmployeeSalarylyRateTrans::changeEmployee(Employee & employee)
{
	employee.setPayClassification(std::make_unique<SalaryPayClassification>(m_salary));
	employee.setPaySchedule(std::make_unique<MonthlyPaySchedule>());
}
