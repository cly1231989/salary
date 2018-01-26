#pragma once
#include "ModifyEmployeeTransaction.h"
#include "Date.h"

class AddSalesReceiptTrans :
	public ModifyEmployeeTransaction
{
public:
	AddSalesReceiptTrans(int employeeID, const Date &date, int amount);
	virtual ~AddSalesReceiptTrans();

	// Inherited via ModifyEmployeeTransaction
	virtual void changeEmployee(Employee & employee) override;

private:
	int m_amount;
	Date m_date;
};

