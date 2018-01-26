#pragma once
#include <string>
#include "ModifyEmployeeTransaction.h"

class ModifyEmployeeNameTrans :
	public ModifyEmployeeTransaction
{
public:
	ModifyEmployeeNameTrans(int employeeID, const std::string &name);
	virtual ~ModifyEmployeeNameTrans();

	// Inherited via ModifyEmployeeTransaction
	virtual void changeEmployee(Employee & employee) override;

private:
	int m_employeeID;
	std::string m_name;
};

