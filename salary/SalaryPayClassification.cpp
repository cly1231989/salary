#include "stdafx.h"
#include "SalaryPayClassification.h"


SalaryPayClassification::SalaryPayClassification(int salary)
{
	m_salary = salary;
}


SalaryPayClassification::~SalaryPayClassification()
{
}

int SalaryPayClassification::getSalary()
{
	return m_salary;
}

float SalaryPayClassification::payday(PayCheck & payCheck)
{
	return 0.0f;
}
