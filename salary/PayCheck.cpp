#include "stdafx.h"
#include "PayCheck.h"


PayCheck::PayCheck()
{
	m_gross = 0;
	m_deduction = 0;
	m_netPay = 0;
}

PayCheck::PayCheck(const Date &beginDate, const Date &endDate)
	:m_beginDate(beginDate), m_endDate(endDate)
{
	m_gross = 0;
	m_deduction = 0;
	m_netPay = 0;
}


PayCheck::~PayCheck()
{
}

void PayCheck::setGross(float gross)
{
	m_gross = gross;
}

float PayCheck::getGross()
{
	return m_gross;
}

void PayCheck::setDeduction(float deduction)
{
	m_deduction = deduction;
}

float PayCheck::getDeduction()
{
	return m_deduction;
}

void PayCheck::setNetPay(float netPay)
{
	m_netPay = netPay;
}

float PayCheck::getNetPay()
{
	return m_netPay;
}

void PayCheck::setBeginDate(Date beginDate)
{
	m_beginDate = beginDate;
}

Date PayCheck::getBeginDate() const
{
	return m_beginDate;
}

void PayCheck::setEndDate(Date endDate)
{
	m_endDate = endDate;
}

Date PayCheck::getEndDate() const
{
	return m_endDate;
}
