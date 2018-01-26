#pragma once
#include "ModifyEmployeeTransaction.h"
class ModifyEmployeeMemberTrans :
	public ModifyEmployeeTransaction
{
public:
	ModifyEmployeeMemberTrans(int employeeID, int memberID, float memberRate);
	virtual ~ModifyEmployeeMemberTrans();

private:
	int m_memberID;
	float m_memberRate;

	// Inherited via ModifyEmployeeTransaction
	virtual void changeEmployee(Employee & employee) override;
};

