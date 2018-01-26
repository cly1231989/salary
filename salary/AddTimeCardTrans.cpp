#include "stdafx.h"
#include "AddTimeCardTrans.h"
#include "HourlyPayClassification.h"

AddTimeCardTrans::AddTimeCardTrans(int employeeID, const Date& date, float hours):
	ModifyEmployeeTransaction(employeeID),
	m_date(date)
{
	m_hours = hours;
}


AddTimeCardTrans::~AddTimeCardTrans()
{
}

void AddTimeCardTrans::changeEmployee(Employee & employee)
{
	auto &payClassification = employee.getPayClassification();
	auto hourlyPayClassification = dynamic_cast<HourlyPayClassification *>(payClassification.get());
	if (hourlyPayClassification != nullptr)
	{
		hourlyPayClassification->addTimeCard(m_date, m_hours);
	}

}
