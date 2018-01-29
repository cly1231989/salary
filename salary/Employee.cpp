#include "stdafx.h"
#include "Employee.h"
#include "PaySchedule.h"
#include "PayMethod.h"
#include "PayClassification.h"
#include "Affiliation.h"

Employee::Employee(int employeeID, std::string name, std::string address)
{
	m_employeeID = employeeID;
	m_name = name;
	m_address = address;
}


Employee::~Employee()
{
}

int Employee::getID()
{
	return m_employeeID;
}

std::string Employee::getName() const
{
	return m_name;
}

std::string Employee::getAddress() const
{
	return m_address;
}

void Employee::setName(const std::string & name)
{
	m_name = name;
}

void Employee::setAddress(const std::string & address)
{
	m_address = address;
}

void Employee::setAffiliation(std::unique_ptr<Affiliation> affiliation)
{
	m_affiliation = std::move(affiliation);
}

void Employee::setPayMethod(std::unique_ptr<PayMethod> payMethod)
{
	m_payMethod = std::move(payMethod);
}

void Employee::setPaySchedule(std::unique_ptr<PaySchedule> paySchedule)
{
	m_paySchedule = std::move(paySchedule);
}

void Employee::setPayClassification(std::unique_ptr<PayClassification> payClassification)
{
	m_payClassification = std::move(payClassification);
}

std::unique_ptr<Affiliation>& Employee::getAffiliation()
{
	return m_affiliation;
}

std::unique_ptr<PayMethod>& Employee::getPayMethod()
{
	return m_payMethod;
}

std::unique_ptr<PaySchedule>& Employee::getPaySchedule()
{
	return m_paySchedule;
}

std::unique_ptr<PayClassification>& Employee::getPayClassification()
{
	return m_payClassification;
}

bool Employee::isPayDay(const Date & date)
{
	return m_paySchedule->isPayDay(date);
}

void Employee::payday(PayCheck & payCheck)
{
	float gross = m_payClassification->payday(payCheck);
	float dedution = m_affiliation->getAllFees(payCheck);
	float netPay = gross - dedution;

	payCheck.setDeduction(dedution);
	payCheck.setGross(gross);
	payCheck.setNetPay(netPay);

	m_payMethod->pay(payCheck);
}

Date Employee::getBeginDate(const Date & endDate)
{
	return m_paySchedule->getBeginDate(endDate);
}
