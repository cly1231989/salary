#include "stdafx.h"
#include "AddServiceChargeTrans.h"
#include "EmployeeDatabase.h"
#include "Employee.h"
#include "UnionAffiliation.h"

extern EmployeeDatabase gEmployeeDatabase;

AddServiceChargeTrans::AddServiceChargeTrans(int memberID, float amount, const Date &date)
{
	m_memberID = memberID;
	m_amount = amount;
	m_date = date;
}


AddServiceChargeTrans::~AddServiceChargeTrans()
{
}

void AddServiceChargeTrans::excute()
{
	auto employee = gEmployeeDatabase.getEmployeeByMemberID(m_memberID);
	if (employee)
	{
		auto unionAffiliation = dynamic_cast<UnionAffiliation*>(employee->getAffiliation().get());
		if (unionAffiliation != nullptr)
		{
			unionAffiliation->addServiceCharge(m_amount, m_date);
		}
	}
}
