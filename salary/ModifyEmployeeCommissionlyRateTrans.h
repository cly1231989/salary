#pragma once
#include "ModifyEmployeeTransaction.h"
class ModifyEmployeeCommissionlyRateTrans :
	public ModifyEmployeeTransaction
{
public:
	ModifyEmployeeCommissionlyRateTrans(int employeeID, int salary, float commissionRate);
	virtual ~ModifyEmployeeCommissionlyRateTrans();

	// Inherited via ModifyEmployeeTransaction
	virtual void changeEmployee(Employee & employee) override;

private:
	int m_salary;
	float m_commissionRate;
};

