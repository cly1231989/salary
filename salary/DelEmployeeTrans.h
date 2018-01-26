#pragma once
#include "Transaction.h"
class DelEmployeeTrans :
	public Transaction
{
public:
	DelEmployeeTrans(int employeeID);
	virtual ~DelEmployeeTrans();

	// Inherited via Transaction
	virtual void excute() override;

private:
	int m_employeeID;
};

