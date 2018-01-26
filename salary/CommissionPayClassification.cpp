#include "stdafx.h"
#include "CommissionPayClassification.h"


CommissionPayClassification::CommissionPayClassification(int salary, float commissionRate)
{
	m_salary = salary;
	m_commissionRate = commissionRate;
}


CommissionPayClassification::~CommissionPayClassification()
{
}

int CommissionPayClassification::getSalary()
{
	return m_salary;
}

float CommissionPayClassification::getCommissionRate()
{
	return m_commissionRate;
}

void CommissionPayClassification::addSalesReceipt(const Date & date, int amount)
{
	SalesReceipt salesReceipt = {date, amount};
	m_salesReceipts[date] = salesReceipt;
}

int CommissionPayClassification::getSalesReceiptAmount(const Date & date)
{
	return m_salesReceipts[date].amount;
}

