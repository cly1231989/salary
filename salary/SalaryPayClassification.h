#pragma once
#include "PayClassification.h"
class SalaryPayClassification :
	public PayClassification
{
public:
	SalaryPayClassification(int salary);
	virtual ~SalaryPayClassification();

	int getSalary();

	// Inherited via PayClassification
	virtual float payday(PayCheck & payCheck) override;

private:
	int m_salary;
};

