#include "stdafx.h"
#include "ModifyEmployeeHourlyRateTrans.h"
#include "HourlyPayClassification.h"
#include "HourlyPaySchedule.h"
#include <memory>

ModifyEmployeeHourlyRateTrans::ModifyEmployeeHourlyRateTrans(int employeeID, float hourlyRate)
	:ModifyEmployeeTransaction(employeeID)
{
	m_hourlyRate = hourlyRate;
}


ModifyEmployeeHourlyRateTrans::~ModifyEmployeeHourlyRateTrans()
{
}

void ModifyEmployeeHourlyRateTrans::changeEmployee(Employee & employee)
{
	employee.setPayClassification(std::make_unique<HourlyPayClassification>(m_hourlyRate));
	employee.setPaySchedule(std::make_unique<HourlyPaySchedule>());
}
