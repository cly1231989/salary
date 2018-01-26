#include "stdafx.h"
#include "EmployeeDatabase.h"
#include "Employee.h"

EmployeeDatabase gEmployeeDatabase;

EmployeeDatabase::EmployeeDatabase()
{
}


EmployeeDatabase::~EmployeeDatabase()
{
}

void EmployeeDatabase::addEmployee(int employeeID, std::shared_ptr<Employee> employee)
{
	m_employees[employeeID] = employee;
}

std::shared_ptr<Employee> EmployeeDatabase::getEmployee(int employeeID)
{
	return m_employees[employeeID];
}

void EmployeeDatabase::delEmployee(int employeeID)
{
	m_employees.erase(employeeID);
}

void EmployeeDatabase::addUnionMember(int memberID, Employee * employee)
{
	m_members[memberID] = employee;
}

Employee* EmployeeDatabase::getEmployeeByMemberID(int memberID)
{
	return m_members[memberID];
}

void EmployeeDatabase::delMember(int memberID)
{
	m_members.erase(memberID);
}
