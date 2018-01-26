#include "stdafx.h"
#include "AddHourlyEmployeeTrans.h"
#include "HourlyPayClassification.h"
#include "HourlyPaySchedule.h"


AddHourlyEmployeeTrans::AddHourlyEmployeeTrans(int employeeID, const std::string &name, const std::string &address, float hourlyRate)
	:AddEmployeeTrans(employeeID, name, address)
{
	m_hourlyRate = hourlyRate;
}


AddHourlyEmployeeTrans::~AddHourlyEmployeeTrans()
{
}

std::unique_ptr<PayClassification> AddHourlyEmployeeTrans::getPayClassification()
{
	return std::make_unique<HourlyPayClassification>(m_hourlyRate);
}

std::unique_ptr<PaySchedule> AddHourlyEmployeeTrans::getPaySchedule()
{
	return std::make_unique<HourlyPaySchedule>();
}
