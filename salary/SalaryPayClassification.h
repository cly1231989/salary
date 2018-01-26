#pragma once
#include "PayClassification.h"
class SalaryPayClassification :
	public PayClassification
{
public:
	SalaryPayClassification(int salary);
	virtual ~SalaryPayClassification();

	int getSalary();

private:
	int m_salary;
};

