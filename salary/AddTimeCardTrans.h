#pragma once
#include "ModifyEmployeeTransaction.h"
#include "Date.h"

class AddTimeCardTrans :
	public ModifyEmployeeTransaction
{
public:
	AddTimeCardTrans(int employeeID, const Date& date, float hours);
	virtual ~AddTimeCardTrans();

	// Inherited via ModifyEmployeeTransaction
	virtual void changeEmployee(Employee & employee) override;

private:
	Date m_date;
	float m_hours;
};

