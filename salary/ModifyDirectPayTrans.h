#pragma once
#include "ModifyEmployeeTransaction.h"
#include <string>

class ModifyDirectPayTrans :
	public ModifyEmployeeTransaction
{
public:
	ModifyDirectPayTrans(int employeeID, const std::string &bank, const std::string &account);
	virtual ~ModifyDirectPayTrans();

	// Inherited via ModifyEmployeeTransaction
	virtual void changeEmployee(Employee & employee) override;

private:
	std::string m_bank;
	std::string m_account;
};

