#pragma once
#include <string>
#include "ModifyEmployeeTransaction.h"
#include "Employee.h"

class ModifyEmployeeAddressTrans :
	public ModifyEmployeeTransaction
{
public:
	ModifyEmployeeAddressTrans(int employeeID, const std::string &address);
	virtual ~ModifyEmployeeAddressTrans();

protected:
	// Inherited via ModifyEmployeeTransaction
	virtual void changeEmployee(Employee & employee) override;

private:
	std::string m_address;
};

