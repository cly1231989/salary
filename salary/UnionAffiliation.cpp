#include "stdafx.h"
#include "Affiliation.h"
#include "UnionAffiliation.h"
#include <algorithm>

UnionAffiliation::UnionAffiliation(int memberID, float memberRate)
{
	m_memberID = memberID;
	m_memberRate = memberRate;
}

UnionAffiliation::~UnionAffiliation()
{
}

int UnionAffiliation::getMemberID() const
{
	return m_memberID;
}

float UnionAffiliation::getMemberRate() const
{
	return m_memberRate;
}

void UnionAffiliation::addServiceCharge(float amount, const Date & date)
{
	ServiceCharge serviceCharge = {amount, date};
	m_serviceCharges[date] = serviceCharge;
}

float UnionAffiliation::getAllFees()
{
	float allFees = m_memberRate;
	std::for_each(std::begin(m_serviceCharges), std::end(m_serviceCharges), [&allFees](const std::pair<Date, ServiceCharge>& serviceCharge)
	{
		allFees += serviceCharge.second.amount;
	});
	
	return allFees;
}
