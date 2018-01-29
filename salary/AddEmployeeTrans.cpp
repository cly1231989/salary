#include "stdafx.h"
#include "AddEmployeeTrans.h"
#include "MailPayMethod.h"
#include "EmployeeDatabase.h"
#include "PayClassification.h"
#include "PaySchedule.h"
#include "employee.h"
#include "NoAffiliation.h"
#include <memory>

extern EmployeeDatabase gEmployeeDatabase;

AddEmployeeTrans::AddEmployeeTrans(int employeeID, const std::string &name, const std::string &address)
{
	m_employeeID = employeeID;
	m_name = name;
	m_address = address;
}


AddEmployeeTrans::~AddEmployeeTrans()
{
}

void AddEmployeeTrans::excute()
{
	auto employee = std::make_shared<Employee>(m_employeeID, m_name, m_address);
	employee->setPayMethod(std::make_unique<MailPayMethod>("123"));
	employee->setPayClassification(getPayClassification());
	employee->setPaySchedule(getPaySchedule());
	employee->setAffiliation(std::make_unique<NoAffiliation>());

	gEmployeeDatabase.addEmployee(m_employeeID, employee);
}
