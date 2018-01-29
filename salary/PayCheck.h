#pragma once
#include "Date.h"

class PayCheck
{
public:
	PayCheck();
	PayCheck(const Date &beginDate, const Date &endDate);
	~PayCheck();

	void setGross(float gross);
	float getGross();

	void setDeduction(float deduction);
	float getDeduction();

	void setNetPay(float netPay);
	float getNetPay();

	void setBeginDate(Date beginDate);
	Date getBeginDate() const;

	void setEndDate(Date endDate);
	Date getEndDate() const;

private:
	float m_gross;
	float m_deduction;
	float m_netPay;

	Date m_beginDate;
	Date m_endDate;
};

