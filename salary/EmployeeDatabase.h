#pragma once
#include <map>
#include <memory>
#include <vector>

class Employee;

class EmployeeDatabase
{
public:
	EmployeeDatabase();
	~EmployeeDatabase();

	void addEmployee(int employeeID, std::shared_ptr<Employee> employee);
	std::shared_ptr<Employee> getEmployee(int employeeID);
	void delEmployee(int employeeID);

	void addUnionMember(int memberID, Employee *employee);
	Employee* getEmployeeByMemberID(int memberID);
	void delMember(int memberID);

	std::vector<int> getAllEmployeeID();

private:
	std::map<int, std::shared_ptr<Employee>> m_employees;
	std::map<int, Employee*> m_members;
};

