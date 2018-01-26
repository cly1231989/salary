#pragma once
#include "AddEmployeeTrans.h"
class AddSalaryEmployeeTrans :
	public AddEmployeeTrans
{
public:
	AddSalaryEmployeeTrans(int employeeID, const std::string &name, const std::string &address, int salary);
	virtual ~AddSalaryEmployeeTrans();

protected:
	// Inherited via AddEmployeeTrans
	virtual std::unique_ptr<PayClassification> getPayClassification() override;
	virtual std::unique_ptr<PaySchedule> getPaySchedule() override;

private:
	int m_salary;
};

