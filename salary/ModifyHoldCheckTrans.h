#pragma once
#include "ModifyEmployeeTransaction.h"
class ModifyHoldCheckTrans :
	public ModifyEmployeeTransaction
{
public:
	ModifyHoldCheckTrans(int employeeID);
	virtual ~ModifyHoldCheckTrans();

	// Inherited via ModifyEmployeeTransaction
	virtual void changeEmployee(Employee & employee) override;
};

