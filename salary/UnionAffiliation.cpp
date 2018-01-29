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

float UnionAffiliation::getAllFees(const PayCheck &payCheck)
{
	float allFees = m_memberRate;

	auto firstServiceCharge = m_serviceCharges.begin();
	for (; firstServiceCharge != m_serviceCharges.end(); firstServiceCharge++)
	{
		if (Date::isInBetween(firstServiceCharge->second.date, payCheck.getBeginDate(), payCheck.getEndDate()))
		{
			allFees += firstServiceCharge->second.amount;
		}
	}
	
	return allFees;
}
