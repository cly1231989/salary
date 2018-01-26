#pragma once
#include "ModifyEmployeeTransaction.h"
class ModifyEmployeeSalarylyRateTrans :
	public ModifyEmployeeTransaction
{
public:
	ModifyEmployeeSalarylyRateTrans(int employeeID, int salary);
	virtual ~ModifyEmployeeSalarylyRateTrans();

	// Inherited via ModifyEmployeeTransaction
	virtual void changeEmployee(Employee & employee) override;

private:
	int m_salary;
};

