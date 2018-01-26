#pragma once
#include "AddEmployeeTrans.h"
class AddCommissionEmployeeTrans :
	public AddEmployeeTrans
{
public:
	AddCommissionEmployeeTrans(int employeeID, const std::string &name, const std::string &address, int salary, float commissionRate);
	virtual ~AddCommissionEmployeeTrans();

private:
	int m_salary;
	float m_commissionRate;

	// Inherited via AddEmployeeTrans
	virtual std::unique_ptr<PayClassification> getPayClassification() override;
	virtual std::unique_ptr<PaySchedule> getPaySchedule() override;
};

