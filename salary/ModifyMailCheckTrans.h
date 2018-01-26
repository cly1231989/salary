#pragma once
#include "ModifyEmployeeTransaction.h"
class ModifyMailCheckTrans :
	public ModifyEmployeeTransaction
{
public:
	ModifyMailCheckTrans(int employeeID, const std::string &mailAddress);
	virtual ~ModifyMailCheckTrans();

	// Inherited via ModifyEmployeeTransaction
	virtual void changeEmployee(Employee & employee) override;

private:
	std::string m_mailAddress;
};

