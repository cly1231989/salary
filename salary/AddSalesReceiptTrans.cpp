#include "stdafx.h"
#include "AddSalesReceiptTrans.h"
#include "CommissionPayClassification.h"

AddSalesReceiptTrans::AddSalesReceiptTrans(int employeeID, const Date &date, int amount)
	:ModifyEmployeeTransaction(employeeID)
{
	m_date = date;
	m_amount = amount;
}


AddSalesReceiptTrans::~AddSalesReceiptTrans()
{
}

void AddSalesReceiptTrans::changeEmployee(Employee & employee)
{
	CommissionPayClassification* commissionPayClassification = dynamic_cast<CommissionPayClassification*>(employee.getPayClassification().get());
	if (commissionPayClassification != nullptr)
	{
		commissionPayClassification->addSalesReceipt(m_date, m_amount);
	}
}
