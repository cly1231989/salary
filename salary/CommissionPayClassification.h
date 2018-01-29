#pragma once
#include "PayClassification.h"
#include "Date.h"
#include <map>

class CommissionPayClassification :
	public PayClassification
{
public:
	CommissionPayClassification(int salary, float commissionRate);
	virtual ~CommissionPayClassification();

	int getSalary();
	float getCommissionRate();

	void addSalesReceipt(const Date &date, int amount);
	int getSalesReceiptAmount(const Date &date);

	// Inherited via PayClassification
	virtual float payday(PayCheck & payCheck) override;

private:
	struct SalesReceipt
	{
		Date date;
		int amount;
	};

	int m_salary;
	float m_commissionRate;
	std::map<Date, SalesReceipt> m_salesReceipts;

};


