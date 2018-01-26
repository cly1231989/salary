#pragma once
#include "ModifyEmployeeTransaction.h"

class ModifyEmployeeUnmemberTrans :
	public ModifyEmployeeTransaction
{
public:
	ModifyEmployeeUnmemberTrans(int employeeID);
	virtual ~ModifyEmployeeUnmemberTrans();

	// Inherited via ModifyEmployeeTransaction
	virtual void changeEmployee(Employee & employee) override;

private:
	int m_employeeID;
};

