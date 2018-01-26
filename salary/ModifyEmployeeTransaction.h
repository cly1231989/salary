#pragma once
#include "Transaction.h"
#include "Employee.h"

class ModifyEmployeeTransaction :
	public Transaction
{
public:
	ModifyEmployeeTransaction(int employeeID);
	~ModifyEmployeeTransaction();

	// Inherited via Transaction
	virtual void excute() override;

protected:
	virtual void changeEmployee(Employee &employee) = 0;

private:
	int m_employeeID;
};

