#pragma once
#include "ModifyEmployeeTransaction.h"
class ModifyEmployeeHourlyRateTrans :
	public ModifyEmployeeTransaction
{
public:
	ModifyEmployeeHourlyRateTrans(int employeeID, float hourlyRate);
	virtual ~ModifyEmployeeHourlyRateTrans();

	// Inherited via ModifyEmployeeTransaction
	virtual void changeEmployee(Employee & employee) override;

private:
	float m_hourlyRate;
};

