#pragma once
#include "AddEmployeeTrans.h"

class AddHourlyEmployeeTrans :
	public AddEmployeeTrans
{
public:
	AddHourlyEmployeeTrans(int employeeID, const std::string &name, const std::string &address, float hourlyRate);
	virtual ~AddHourlyEmployeeTrans();

protected:
	// Inherited via AddEmployeeTrans
	virtual std::unique_ptr<PayClassification> getPayClassification() override;
	virtual std::unique_ptr<PaySchedule> getPaySchedule() override;

private:
	float m_hourlyRate;
};

